#pragma once

#include "customer.h"

typedef struct Node
{
	public:
	int data;
	Node *next;
} Node;

Node *createNode(int data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}
typedef struct Schedule
{
	public:
	Node *head;
	Node *tail;
	int load;
	float time;

} Schedule;

Schedule *createSchedule()
{
	Schedule *schedule = (Schedule *)malloc(sizeof(Schedule));
	schedule->head = createNode(0);
	schedule->tail = createNode(0);
	schedule->head->next = schedule->tail;
	schedule->load = 0;
	schedule->time = 0;

	return schedule;
}

double insertCost(Node *node, Customer *customer, double **distanceMatrix)
{
	return distanceMatrix[node->data][customer->i] + distanceMatrix[node->next->data][customer->i] - distanceMatrix[node->data][node->next->data];
}

void insert(Schedule *schedule, Customer *customer, double **distanceMatrix)
{
	double best = insertCost(schedule->head, customer, distanceMatrix);
	Node *bestNode = schedule->head;

	for(Node *iter = schedule->head; iter != schedule->tail; iter = iter->next)
	{
		double cost = insertCost(iter, customer, distanceMatrix);
		if(cost < best)
		{
			best = cost;
			bestNode = iter;
		}
	}
	int data = customer->i; // data is the ID of the customer
	Node *newbie = createNode(data); // new node to be inserted
	newbie->next = bestNode->next;
	bestNode->next = newbie;
	schedule->time += best; // add travel time to total time
	schedule->time += customer->d; // add service duration to total time
	schedule->load += customer->q; // add demand to total load
}


void insertWithoutBest(Schedule *schedule, Customer *customer, double **distanceMatrix)
{
	double best = insertCost(schedule->head, customer, distanceMatrix);
	Node *bestNode = schedule->head;

	for(Node *iter = schedule->head; iter->next != schedule->tail; iter = iter->next);
	int data = customer->i; // data is the ID of the customer
	Node *newbie = createNode(data); // new node to be inserted
	newbie->next = bestNode->next;
	bestNode->next = newbie;
	schedule->time += best; // add travel time to total time
	schedule->time += customer->d; // add service duration to total time
	schedule->load += customer->q; // add demand to total load

}
string printSchedule(Schedule *schedule)
{
	stringstream ss;
	ss << schedule->head->data;
	ss<<" ";
	//cout<<head->data<<' ';
	for(Node *tmp = schedule->head->next; tmp != schedule->tail; tmp = tmp->next)
	{

		ss<<tmp->data;
		ss<<" ";
		//cout<<tmp->data<<' ';
	}
	ss<<schedule->tail->data;
	//cout<<tail->data<<endl;
	return ss.str();
}



