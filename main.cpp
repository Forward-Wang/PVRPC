
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <customer.h>
#include <vehicle.h>
#include <instance.h>
#include <solver.h>
#include <cmath>
using namespace std;


int main () {
	
	FILE *input;
	string line;
	Instance *instances[42];
	int type, m, n, t;
	int i, d, q, f, a;
	float x, y;
	
	for(int j=0; j<42; j++)
	{
		stringstream id;
		id << j+1;
		string filename = "p" + id.str() + ".txt";
		input = fopen(filename.c_str(), "r");
		fscanf(input, "%d %d %d %d\n", &type, &m, &n, &t);
//		printf("%d %d %d %d\n", type, m, n, t);
//		system("pause");
		instances[j] = createInstance(j+1, type, m, n, t);
		for(int k=0; k<m; k++)
		{
			int D, Q;
			fscanf(input, "%d %d\n", &D, &Q); // read ith instance's jth truck's D and Q
			instances[j]->trucks[k] = createTruck(k+1, D, Q, t);
		}

		for(int k=0; k<m; k++)
		{
			int D, Q;
			fscanf(input, "%d %d\n", &D, &Q); // read ith instance's jth preseller's D and Q
			instances[j]->presellers[k] = createPreseller(k+1, D, Q, t);
		}
		
		fscanf(input, "%d\t%f\t%f\t%d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
		instances[j]->customers[0] = createCustomer(i,x,y,d,q,f,a);
		for(int k=1; k<n; k++)
		{
			fscanf(input, "%d %f %f %d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
			instances[j]->customers[k] = createCustomer(i,x,y,d,q,f,a);
//			printf("reading list:\n");
			for(int l=0; l<a; l++)
			{
				int tmp;
				fscanf(input, "%d ", &tmp);
				instances[j]->customers[k]->list[l] = tmp;
				
			}
		}
		fclose(input);
	}
	
	
	
	printInstance(instances[1]);
	solveInstance(instances[1]);
	

}