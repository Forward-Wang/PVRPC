#pragma once
#include <customer.h>
#include <vehicle.h>
typedef struct Instance
{
	int id, type, m, n, t;
	Customer **customers;
	Truck **trucks;
	Preseller **presellers;
} Instance;


Instance *createInstance(int id, int type, int m, int n, int t)
{
	Instance *instance = (Instance *) malloc(sizeof(Instance));
	instance->id = id;
	instance->type = type;
	instance->m = m;
	instance->n = n;
	instance->t = t;
//	instance->depot = (Customer *)malloc(sizeof(Customer));
	instance->customers = (Customer **) malloc(sizeof(Customer *)*n);
	instance->trucks = (Truck **) malloc(sizeof(Truck *)*m);
	instance->presellers = (Preseller **) malloc(sizeof(Preseller *)*m);
	
	return instance;
}

void printInstance(Instance *instance)
{
	printf("%d %d %d %d %d\n", instance->id, instance->type, instance->m, instance->n, instance->t);
	
	for(int i=0; i<instance->m; i++)
		printf("%d %d\n", instance->presellers[i]->D, instance->presellers[i]->Q);
		
	for(int i=0; i<instance->m; i++)
		printf("%d %d\n", instance->trucks[i]->D, instance->trucks[i]->Q);
	
	
		
	for(int i=0; i<instance->n; i++)
		printCustomer(instance->customers[i]);
}
