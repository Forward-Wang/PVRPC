#pragma once

#include <list>
typedef struct Truck
{
	int id, D, Q;
	int currentCapacity;
	list<int> *schedule;
	
} Truck;

typedef struct Preseller
{
	int id, D, Q;
	int currentTime;
	list<int> *schedule;
	
} Preseller;

Truck *createTruck(int id, int D, int Q, int t)
{
	Truck *truck = (Truck *)malloc(sizeof(Truck));
	truck->id = id;
	truck->D = D;
	truck->Q = Q;
	truck->schedule = new list<int>[t];
	
	return truck;
}

Preseller *createPreseller(int id, int D, int Q, int t)
{
	Preseller *preseller = (Preseller *)malloc(sizeof(Preseller));
	preseller->id = id;
	preseller->D = D;
	preseller->Q = Q;
	preseller->schedule = new list<int>[t];
	
	return preseller;
}