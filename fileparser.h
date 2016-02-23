#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <cmath>
#include "instance.h"


void computeServiceTimes(Instance *instance, float avgEdgeWeight, float avgDemand)
{
	int n = instance->n;
	for(int i=0; i<n; i++)
	{
		int m = 0; // # of neighbors closer than the average edge weight of the graph.
		for(int j=0; j<=n; j++)
		{
			if(instance->distance[i][j] < avgEdgeWeight)
				m++;
		}
		int q = instance->customers[i]->q;
		instance->customers[i]->d = m*(q/avgDemand);
	}
	
}


Instance *readFromFileOldFormat(const char *prefix, int instanceId)
{
	Instance *instance;
	stringstream fileName;
	fileName << prefix << instanceId << ".txt";
	cout<<fileName.str()<<endl;
	FILE *file = fopen(fileName.str().c_str(), "r");
	int type, m, n, t, D, Q;
	fscanf(file, "%d %d %d %d\n", &type, &m, &n, &t);
	for(int j=0; j<t; j++)
	{
		fscanf(file, "%d %d\n", &D, &Q);
		cout<<D<<' '<<Q<<endl;
	}
	printf("%d %d %d %d\n", type, m, n, t);
	instance = createInstance(instanceId, type, m, n, t, D, Q);
	cout<<"Instance "<<instanceId<<" created"<<endl;
	instance->D = D;
	instance->Q = Q;
		
	
	int i, d, q, f, a;
	float x, y;
	fscanf(file, "%d %f %f %d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
	instance->customers[0] = createCustomer(i, x, y, d, q, f, a); // read depot
	for(int j=1; j<n+1; j++) // read customers
	{
		fscanf(file, "%d %f %f %d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
		instance->customers[j] = createCustomer(i, x, y, d, q, f, a);
		for(int k=0; k<a; k++)
			fscanf(file, "%d ", &(instance->customers[j]->list[k]));
	}
	
	float avgEdgeWeight;
	float avgDemand;
	float weightSum = 0.0; // sum of edge weights
	float demandSum = 0.0; // sum of demands
	float maxDurationSum = 0.0; // sum of (d_i*f_i)
	float nbEdges = ((instance->n)*(instance->n-1))/2; // number of edges in the graph
	for(int j=0; j<n; j++) // compute distance matrix
	{
		Customer *a = instance->customers[j];

		for(int k=j+1; k<n+1; k++)
		{
			Customer *b = instance->customers[k];
			
			//printCustomer(b);
			float distance = computeDistance(a,b);
			instance->distance[j][k] = distance;
			instance->distance[k][j] = distance;
			weightSum += (float)distance;
		}
		
		demandSum += (float)a->q;
		
	}
	
	
	
		
	avgEdgeWeight = weightSum/(2*nbEdges);
	avgDemand = demandSum/n;
	computeServiceTimes(instance, avgEdgeWeight, avgDemand);
	
	for(int j=1; j<n; j++)
		maxDurationSum += (instance->customers[j]->d*instance->customers[j]->f)*1.15;

	instance->D = maxDurationSum/(instance->t * instance->m);
	fclose(file);
	return instance;
}

Instance *readFromFileNewFormat(const char *prefix, int instanceId)
{
	Instance *instance;
	stringstream fileName;
	fileName << prefix << instanceId << ".txt";
	cout<<fileName.str()<<endl;
	FILE *file = fopen(fileName.str().c_str(), "r");
	int type, m, n, t, D, Q;
	fscanf(file, "%d %d %d %d %d %d\n", &type, &m, &n, &t, &D, &Q);
	printf("%d %d %d %d\n", type, m, n, t);
	instance = createInstance(instanceId, type, m, n, t, D, Q);
		
	
	int i, d, q, f, a;
	float x, y;
	fscanf(file, "%d %f %f %d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
	instance->customers[0] = createCustomer(i, x, y, d, q, f, a); // read depot
	for(int j=1; j<n+1; j++) // read customers
	{
		fscanf(file, "%d %f %f %d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
		instance->customers[j] = createCustomer(i, x, y, d, q, f, a);
		for(int k=0; k<a; k++)
			fscanf(file, "%d ", &(instance->customers[j]->list[k]));
	}
	
	for(int j=0; j<n; j++) // compute distance matrix
	{
		Customer *a = instance->customers[j];

		for(int k=j+1; k<n+1; k++)
		{
			Customer *b = instance->customers[k];
			float distance = computeDistance(a,b);
			instance->distance[j][k] = distance;
			instance->distance[k][j] = distance;
		}
	}
} 

void printToFile(Instance *instance, const char *prefix, int instanceId)
{
	stringstream fileName;
	fileName << prefix << instanceId << ".txt";
	FILE *file = fopen(fileName.str().c_str(), "w");
	fprintf(file, "%d %d %d %d %d %d\n", instance->type, instance->m, instance->n-1 /*excluding depot*/, instance->t, instance->D, instance->Q);
	
	Customer *customer = instance->customers[0];
	int i = customer->i;
	float x = customer->x;
	float y = customer->y;
	int d = customer->d;
	int q = customer->q;
	int f = customer->f;
	int a = customer->a;
	fprintf(file, "%3d\t% 4.2f\t% 4.2f\t%3d %4d %3d %3d\t\t", i, x, y, d, q, f, a);
	for(int j=1; j<instance->n; j++)
	{
		customer = instance->customers[j];
		i = customer->i;
		x = customer->x;
		y = customer->y;
		d = customer->d;
		q = customer->q;
		f = customer->f;
		a = customer->a;
		fprintf(file, "%3d\t% 4.2f\t% 4.2f\t%3d %4d %3d %3d\t\t", i, x, y, d, q, f, a);
		for(int k=0; k<a; k++)
			fprintf(file, "%d ", customer->list[k]);
		fprintf(file, "\n");
	}
	fclose(file);
}




