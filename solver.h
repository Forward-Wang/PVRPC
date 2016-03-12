#pragma once

#include <cmath>
#include "instance.h"
#include "schedule.h"


double computeDistance(Customer *a, Customer *b)
{
	return sqrt(((a->x - b->x)*(a->x - b->x)) + ((a->y - b->y)*(a->y - b->y)));
}

char *decToBin(int value, int bitsCount) // decimal to binary
{
    int i;
	char *output = new char[bitsCount+1];
    output[bitsCount] = '\0';
    for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
		output[i] = (value & 1) + '0';

	return output;
}


int compare(const void *s1, const void *s2) // function for customer comparison
{
  Customer *c1 = *(Customer **)s1;
  Customer *c2 = *(Customer **)s2;
  int freqcompare = c2->f - c1->f;
  if (freqcompare == 0)  //if both frequencies are equal
    return (c2->d + c2->q) - (c1->d + c1->q); //compare d+q
  else
    return freqcompare;  //return comparison of frequencies
}

int compareQ(const void *s1, const void *s2) // function for customer comparison
{
  Customer *c1 = *(Customer **)s1;
  Customer *c2 = *(Customer **)s2;
  int freqcompare = (c2->d + c2->q) - (c1->d + c1->q);
  if (freqcompare == 0)  //if both frequencies are equal
    return c2->f - c1->f; //compare d+q
  else
    return freqcompare;  //return comparison of frequencies
}

int defaultCompare(const void *s1, const void *s2) // function for customer comparison
{
  Customer *c1 = *(Customer **)s1;
  Customer *c2 = *(Customer **)s2;
  return c1->i - c2->i;
}


void solveInstance(Instance *instance)
{
	int n = instance->n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			instance->distance[i][j] = computeDistance(instance->customers[i], instance->customers[j]); // create adj. matrix

	qsort(instance->customers, instance->n, sizeof(Customer *), compareQ); //sort customers
	/*for(int i=0; i<instance->n; i++)
        printCustomer(instance->customers[i]);*/
    //system("pause");
	int nextPossible = 0; // next possible schedule
    int trial = 0;
	for(int i=0; i<instance->n-1; i++) // exclude the depot. that is wyh i<n-1
	{

	    bool o = true;
	    bool e = true;
		nextPossible = nextPossible % instance->customers[i]->a; // take the modulo of nextPossible w.r.t. list size of customer i
		char *days = decToBin(instance->customers[i]->list[nextPossible], instance->t); // convert next possible schedule to binary
		for(int day=0; day<instance->t; day++)
		{
			if(days[day] == '1')
			{
				Truck *truck = minTruck(instance, day);
				Preseller *preseller = minPreseller(instance, day);
				if(truck->schedule[day]->load + instance->customers[i]->q <= truck->Q)
                {
                    insertWithoutBest(truck->schedule[day], instance->customers[i], instance->distance);
                    instance->customers[i]->truckVisits[day] = truck->id;
                    //printf("Customer %d was inserted into truck %d on day %d\n", instance->customers[i]->i, truck->id, day);
                    o = false;
                }


				insert(preseller->schedule[day], instance->customers[i], instance->distance);
				instance->customers[i]->presellerVisits[day] = truck->id;
			}

		}

		if(trial++ > instance->customers[i]->a)
		{
		    printf("infeasible: Customer %d\n", instance->customers[i]->i);
		    return;
		}
		if(o) i--;
		else trial=0;


		nextPossible++;
	}
	int overburdened = 0;
	int exceed = 0;

	for(int i=0; i<instance->m; i++)
	{
		bool o = false; //overloaded flag
		bool e = false; //time exceed flag
		for(int j=0; j<instance->t; j++)
		{
			if(instance->trucks[i]->schedule[j]->load > instance->trucks[i]->Q) //if load capacity is exceeded
			{
				o = true; //overloaded is true
			}
			if(instance->presellers[i]->schedule[j]->time > (float)instance->presellers[i]->D) //if time capacity is exceeded
			{
				e = true; //exceed is true
			}
		}
		if(o) overburdened++; //increase overload counter
		if(e) exceed++; //increase exceed counter
	}
	printf("Instance %d: [overloaded: %d/%d, exceeded: %d/%d]\n", instance->id, overburdened, instance->m, exceed, instance->m);
	qsort(instance->customers, instance->n, sizeof(Customer *), defaultCompare); //print analysis
}

