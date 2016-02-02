#pragma once

#include <cstdlib>

using namespace std;
typedef struct Customer
{
	int i;
	float x,y;
	float d,q,f,a;
	int *list;
} Customer;

void printCustomer(Customer *customer)
{
	printf("%d %.2f %.2f %.2f %.2f %.2f %.2f ", customer->i, customer->x, customer->y, customer->d, customer->q, customer->f, customer->a);
	for(int i=0; i<customer->a; i++)
		printf("%d ", customer->list[i]);
	printf("\n");
}

Customer *createCustomer(int i, float x, float y, float d, float q, float f, float a)
{
	Customer *customer = (Customer*) malloc(sizeof(Customer));
	customer->i = i;
	customer->x = x;
	customer->y = y;
	customer->d = d;
	customer->q = q;
	customer->f = f;
	customer->a = a;
	customer->list = (int *) malloc(sizeof(int)*a);

	return customer;
}

