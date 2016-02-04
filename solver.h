#pragma once

#include <instance.h>
#include <cmath>

double distance(Customer *a, Customer *b)
{
	return sqrt(((a->x - b->x)*(a->x - b->x)) + ((a->y - b->y)*(a->y - b->y)));
}

int compare(const void *s1, const void *s2)
{
  Customer *c1 = *(Customer **)s1;
  Customer *c2 = *(Customer **)s2;
  int freqcompare = c2->f - c1->f;
  if (freqcompare == 0)  //if both frequencies are equal
    return (c2->d + c2->q) - (c1->d + c1->q); //compare d+q
  else
    return freqcompare;  //return comparison of frequencies
}


void solveInstance(Instance *instance)
{
	cout<<"Solve instance"<<endl;
	int n = instance->n;
	float adj[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			adj[i][j] = distance(instance->customers[i], instance->customers[j]); // create ad

	qsort(instance->customers, instance->n, sizeof(Customer *), compare); //sort customers
	
	
	for(int i=0; i<instance->n; i++)
		printf("%d %d\n", instance->customers[i]->f, (instance->customers[i]->d + instance->customers[i]->q));
	
	for(int i=0; i<instance->m; i++) //add the depot to each truck's and preseller's schedule
		for(int j=0; j<instance->t; j++)
		{
			instance->trucks[m]->schedule[j].push_back(instance->customers[0]); //start from depot
			instance->trucks[m]->schedule[j].push_back(instance->customers[0]); //come back to depot
			instance->presellers[m]->schedule[j].push_back(instance->customers[0]); //same for presellers
			instance->presellers[m]->schedule[j].push_back(instance->customers[0]);
		}
	
	for(int i=0; i<instance->n; i++)
	{
		
	}


	
	
}

