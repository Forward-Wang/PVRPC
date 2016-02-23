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
	const char *inputPrefix = "p"; // prefix of the instance files.
	const char *outputPrefix = "sol";
	const int nbInstances = 42;
	for(int i=1; i<=nbInstances; i++)
	{
		Instance *instance = readFromFileNewFormat(inputPrefix, i); // read instance from file
		solveInstance(instance);
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