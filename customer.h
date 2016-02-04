#pragma once

#include <cstdlib>

using namespace std;
typedef struct Customer
{
	int i;
	float x,y;
	int d,q,f,a;
	int *list;
} Customer;

void printCustomer(Customer *customer)
{
	printf("%d\t%.2f\t%.2f %d %d %d %d\t\t", customer->i, customer->x, customer->y, customer->d, customer->q, customer->f, customer->a);
	for(int i=0; i<customer->a; i++)
		printf("%d ", customer->list[i]);
	printf("\n");
}

Customer *createCustomer(int i, float x, float y, int d, int q, int f, int a)
{
	Customer *customer = (Customer *)malloc(sizeof(Customer));
	customer->i = i;
	customer->x = x;
	customer->y = y;
	customer->d = d;
	customer->q = q;
	customer->f = f;
	customer->a = a;
	customer->list = new int[a];
//	printf("Customer created:\n");
//	printf("%d\t%.2f\t%.2f %d %d %d %d\n", i, x, y, d, q, f, a);
//	printf("%d\t%.2f\t%.2f %d %d %d %d\n", customer->i, customer->x, customer->y, customer->d, customer->q, customer->f, customer->a);
	
//	printCustomer(customer);

	return customer;
}

