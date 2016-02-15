#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include "schedule.h"

typedef struct Truck
{
	int id, D, Q, t; // id, capacity and time of the vehicle
	int *currentLoad; // current load for each day
	Schedule *schedule; // schedule array for each day
	
} Truck;

typedef struct Preseller
{
	int id, D, Q, t;
	int *currentTime;
	Schedule *schedule;
} Preseller;


Truck *createTruck(int id, int Q, int t) // create new truck
{
	Truck *truck = (Truck *)malloc(sizeof(Truck));
	truck->id = id;
	truck->Q = Q;
	truck->t = t;
	truck->schedule = new Schedule[t]; // schedules for day t
	return truck;
}

Preseller *createPreseller(int id, int D, int Q, int t) // create new preseller
{
	Preseller *preseller = (Preseller *)malloc(sizeof(Preseller));
	preseller->id = id;
	preseller->D = D;
	preseller->Q = Q;
	preseller->t = t;
	preseller->schedule = new Schedule[t];

	return preseller;
}


string printSchedule(Truck *truck)
{
	
	stringstream ss;
	ss<<"Truck ";
	ss<<truck->id;
	ss<<": D = ";
	ss<<truck->D;
	ss<<" Q = ";
	ss<<truck->Q;
	ss<<"\n";
	for(int i=0; i<truck->t; i++)
	{
		//printf("Day[%d]\n", i);
		ss<<"Day[";
		ss<<i;
		ss<<"](";
		ss<<truck->schedule[i].load;
		if(truck->schedule[i].load > truck->Q)
			ss<<"*";
		ss<<")    ";
		ss<<truck->schedule[i].print();
		ss<<"\n";
		//std::cout<<endl;
	}
	return ss.str();
}

string printSchedule(Preseller *preseller)
{
	
	stringstream ss;
	ss<<"Preseller ";
	ss<<preseller->id;
	ss<<": D = ";
	ss<<preseller->D;
	ss<<" Q = ";
	ss<<preseller->Q;
	ss<<"\n";
	for(int i=0; i<preseller->t; i++)
	{
		//printf("Day[%d]\n", i);
		ss<<"Day[";
		ss<<i;
		ss<<"](";
		ss<<preseller->schedule[i].time;
		if(preseller->schedule[i].time > preseller->D)
			ss<<"*";
		ss<<")    ";
		ss<<preseller->schedule[i].print();
		ss<<"\n";
		//std::cout<<endl;
	}
	return ss.str();
}


void addToSchedule(Truck *truck, char *days, int t, Customer *customer, float **distanceMatrix){
/* days is the binary representation of customer's one of possible
 * schedules. t is the number of days in the instance. */
	for(int i=0; i<t; i++)
		if(days[i] == '1')
			truck->schedule[i].insert(customer, distanceMatrix); // add customer's id to ith day.
			

}

void addToSchedule(Preseller *preseller, char *days, int t, Customer *customer, float **distanceMatrix) // same function for preseller
{

	for(int i=0; i<t; i++)
		if(days[i] == '1')
			preseller->schedule[i].insert(customer, distanceMatrix); 
		
	
	
		
}
