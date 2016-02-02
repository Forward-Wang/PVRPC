
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <customer.h>
#include <vehicle.h>
#include <instance.h>
#include <cmath>
using namespace std;

double distance(Customer *a, Customer *b)
{
	return sqrt(((a->x - b->x)*(a->x - b->x)) + ((a->y - b->y)*(a->y - b->y)));
}

void instanceToFile(Instance *instance)
{
	stringstream id;
	id<<instance->id;
	string filename = "p" + id.str() + ".txt";
	ofstream output;
	output.open(filename.c_str());
	output<<instance->type<<" "<<instance->m<<" "<<instance->n<<" "<<instance->t<<endl;
	for(int i=0; i<instance->m; i++)
		output<<instance->trucks[i].D<<" "<<instance->trucks[i].Q<<endl;
	for(int i=0; i<instance->m; i++)
		output<<instance->presellers[i].D<<" "<<instance->presellers[i].Q<<endl;
		
}

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
		printf("%d %d %d %d\n", type, m, n, t);
		system("pause");
		instances[j] = createInstance(j+1, type, m, n, t);
		for(int k=0; k<m; k++)
			fscanf(input, "%d %d\n", &instances[j]->trucks[k].D, &instances[j]->trucks[k].Q); // read ith instance's jth truck's D and Q
		for(int k=m; k<2*m; k++)
			fscanf(input, "%d %d\n", &instances[j]->presellers[k].D, &instances[j]->presellers[k].Q); // read ith instance's jth preseller's D and Q
		fscanf(input, "%d\t%f\t%f\t%d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
		printf("%d %f %f %d %d %d %d\n", i, x, y, d, q, f, a);
		system("pause");
		instances[j]->depot = createCustomer(i,x,y,d,q,f,a);
		for(int k=1; k<n-1; k++)
		{
			fscanf(input, "%d %f %f %d %d %d %d\n", &i, &x, &y, &d, &q, &f, &a);
			printf("%d %f %f %d %d %d %d\n", i, x, y, d, q, f, a);
			printf("reading customer %d\n", k);
			system("pause");
			instances[j]->customers[k] = createCustomer(i,x,y,d,q,f,a);
			for(int l=0; l<a; l++)
				fscanf(input, "%d ", &instances[j]->customers[k]->list[l]);
		}
		fclose(input);
	}
		
	
	

}