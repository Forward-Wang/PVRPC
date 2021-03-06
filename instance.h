#pragma once

#include "customer.h"
#include "vehicle.h"

typedef struct Instance
{
	int id, type, m, n, t;
	int D, Q;
	Customer **customers;
	Truck **trucks;
	Preseller **presellers;
	double **distance;
} Instance;


Instance *createInstance(int id, int type, int m, int n, int t, int D, int Q)
{
	n = n+1;// including depot
	Instance *instance = (Instance *) malloc(sizeof(Instance));
	instance->id = id;
	instance->type = type;
	instance->m = m;
	instance->n = n;
	instance->t = t;
	instance->D = D;
	instance->Q = Q;
	instance->distance = new double* [n];
	for(int i=0; i<n; i++)
		instance->distance[i] = new double[n];
	instance->customers = (Customer **) malloc(sizeof(Customer *)*n);
	instance->trucks = (Truck **) malloc(sizeof(Truck *)*m);
	instance->presellers = (Preseller **) malloc(sizeof(Preseller *)*m);
	for(int i=0; i<m; i++)
	{
		instance->trucks[i] = createTruck(i+1, Q, t);
		instance->presellers[i] = createPreseller(i+1, D, t);
	}


	return instance;
}

Truck *minTruck(Instance *instance, int day)
{
	int min = 0;
	for(int i=1; i<instance->m; i++)
		if(instance->trucks[i]->schedule[day]->load < instance->trucks[min]->schedule[day]->load)
			min = i;
	return instance->trucks[min];
}

Preseller *minPreseller(Instance *instance, int day)
{
	int min = 0;
	for(int i=1; i<instance->m; i++)
		if(instance->presellers[i]->schedule[day]->time < instance->presellers[min]->schedule[day]->time)
			min = i;
	return instance->presellers[min];
}

void printInstance(Instance *instance)
{
	printf("%d %d %d %d %d %d %d\n", instance->id, instance->type, instance->m, instance->n-1, instance->t, instance->D, instance->Q);

	for(int i=1; i<instance->n; i++)
		printCustomer(instance->customers[i]);
}
