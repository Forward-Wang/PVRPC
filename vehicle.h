#pragma once

#include <iostream>
#include <list>
typedef struct Truck
{
	int id, D, Q; // id, capacity and time of the vehicle
	int currentLoad; // current load
	list<int> *schedule; // schedule array for each day
	int lastIndex; // where to add the next customer
	
} Truck;

typedef struct Preseller
{
	int id, D, Q;
	int currentTime;
	list<int> *schedule;
	int lastIndex;
	
} Preseller;

Truck *createTruck(int id, int D, int Q, int t)
{
	Truck *truck = (Truck *)malloc(sizeof(Truck));
	truck->id = id;
	truck->currentLoad = 0;
	truck->lastIndex = 1; // first index (0) is depot. Hence, we start appending customers from 1st index.
	truck->D = D;
	truck->Q = Q;
	truck->schedule = new list<int>[t];
		
	return truck;
}

Preseller *createPreseller(int id, int D, int Q, int t)
{
	Preseller *preseller = (Preseller *)malloc(sizeof(Preseller));
	preseller->id = id;
	preseller->currentTime = 0;
	truck->lastIndex = 1;
	preseller->D = D;
	preseller->Q = Q;
	preseller->schedule = new list<int>[t];
	
	return preseller;
}

void addToSchedule(Truck *truck, int day, Customer *customer)
{
	truck->schedule[day].insert(truck->lastIndex, customer->i);
	truck->lastIndex++;
}

void addToSchedule(Preseller *preseller, int day, Customer *customer)
{
	preseller->schedule[day].push_back(preseller->lastIndex, customer->i);
	preseller->lastIndex++;
}
