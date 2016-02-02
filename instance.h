#pragma once
#include <customer.h>
#include <vehicle.h>
typedef struct Instance
{
	int id, type, m, n, t;
	Customer **customers;
	Customer *depot;
	Truck *trucks;
	Preseller *presellers;
} Instance;


Instance *createInstance(int id, int type, int m, int n, int t)
{
	Instance *instance = (Instance *)malloc(sizeof(Instance));
	instance->id = id;
	instance->type = type;
	instance->m = m;
	instance->n = n;
	instance->t = t;
	instance->customers = (Customer **)malloc(sizeof(Customer *)*(n-1));
	instance->trucks = (Truck *)malloc(sizeof(Truck)*n);
	instance->presellers = (Preseller *)malloc(sizeof(Preseller)*n);
	
	return instance;
}
