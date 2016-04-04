#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <cmath>
#include "customer.h"
#include "vehicle.h"
#include "instance.h"
#include "solver.h"
#include "fileparser.h"

using namespace std;



int main ()
{
	const char *inputPrefix = "inst"; // prefix of the instance files.
	const char *outputPrefix = "inst";

	const int nbInstances = 42;
	for(int i=1; i<=nbInstances; i++)
	{
		Instance *instance = readFromFile(inputPrefix, i); // read instance from file
		
		solveInstance(instance);
		for(int i=0; i<instance->m; i++)
        {

            //cout<<printSchedule(instance->trucks[i]);
            //cout<<printSchedule(instance->presellers[i]);

        }
       /* for(int i=0; i<instance->n; i++)
        {
            printf("%2d: ",instance->customers[i]->i);
             for(int j=0; j<instance->t; j++)
                printf("%2d ", instance->customers[i]->truckVisits[j]);
             cout<<endl;
        }*/


	}
}

	/*FILE *sol;
	//printInstance(instances[1]);
	for(int j=0; j<42; j++)
	{
		stringstream ss;
		ss<<j+1;
		string fn = "sol" + ss.str() + ".txt";
		sol = fopen(fn.c_str(), "w");
		solveInstance(instances[j]);
		string write = "";
		for(int k=0; k<instances[j]->m; k++)
		{
			write += printSchedule(instances[j]->trucks[k]);
		}
		write+="\n\n";
		for(int k=0; k<instances[j]->m; k++)
		{
			write += printSchedule(instances[j]->presellers[k]);
		}
		fprintf(sol, write.c_str(), "utf8");
		fclose(sol);
	}



}*/
