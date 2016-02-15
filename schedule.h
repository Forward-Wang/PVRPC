#pragma once

#include "customer.h"

class Node
{
	public:
	int data;
	Node *next;
	
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
	
};
class Schedule
{
	public:
	Node *head;
	Node *tail;
	Node *iterator;
	int load;
	float time;
	
	Schedule()
	{
		head = new Node(0);
		tail = new Node(0);
		load = 0;
		time = 0;
		head->next = tail;
		iterator = head;
	}
	
	void insert(Customer *customer, float **distanceMatrix)
	{
		int data = customer->i; // data is the ID of the customer
		time += distanceMatrix[data][iterator->data]; // add travel time to total time
		time += customer->d; // add service duration to total time
		load += customer->q; // add demand to total load
		Node *newbie = new Node(data);
		newbie->next = iterator->next;
		iterator->next = newbie;
		iterator = iterator->next;
	}
	
	string print()
	{
		stringstream ss;
		ss << head->data;
		ss<<" ";
		//cout<<head->data<<' ';
		for(Node *tmp = head->next; tmp != tail; tmp = tmp->next)
		{
			
			ss<<tmp->data;
			ss<<" ";
			//cout<<tmp->data<<' ';
		}
		ss<<tail->data;
		//cout<<tail->data<<endl;
		return ss.str();
	}
	
	
	
};

