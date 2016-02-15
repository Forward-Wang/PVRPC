/*#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <cmath>

using namespace std;
int main () {
	
	FILE *input;
	string line;
	int type, m, n, t;
	int I;
	float x, y;
	float d, q, f, a;
	int D, Q;
	
	for(int i=0; i<42; i++)
	{
		stringstream id;
		id << i+1;
		string filename = "instance" + id.str() + ".txt";
		input = fopen(filename.c_str(), "r");
		cout<<endl<<endl<<filename<<endl<<endl;
		string outfilename = "p" + id.str() + ".txt";
		FILE *output;
		output = fopen(outfilename.c_str(), "w");
		fscanf(input, "%d %d %d %d\n", &type, &m, &n, &t);
		printf("%d %d %d %d\n", type, m, n, t);
		fprintf(output, "%d %d %d %d\n", type, m, n, t);
		//cout<<"m = "<<m<<endl;
		for(int j=0; j<2*m; j++)
		{
			//cout<<"j = "<<j<<endl;
			fscanf(input, "%d %d\n", &D, &Q);
			fprintf(output, "%d %d\n", D, Q);
			cout<<D<<" "<<Q<<endl;
		}
		fscanf(input, "%d %f %f %f %f %f %f\n", &I, &x, &y, &d, &q, &f, &a);
		fprintf(output, "%3d\t% 4.2f\t% 4.2f\t%3d %3d %3d %3d\n", I, x, y, (int)d, (int)q, (int)f, (int)a);
		//printf("%3d\t% 4.2f\t% 4.2f\t%3d %3d %3d %3d\n", I, x, y, (int)d, (int)q, (int)f, (int)a);
		for(int j=0; j<n-1; j++)
		{
			fscanf(input, "%d %f %f %f %f %f %f\n", &I, &x, &y, &d, &q, &f, &a);
			int list[(int)a];
			for(int k=0; k<a; k++)
				fscanf(input, "%d ", &list[k]);
			fprintf(output, "%3d\t% 4.2f\t% 4.2f\t%3d %3d %3d %3d\t\t", I, x, y, (int)d, (int)q, (int)f, (int)a);
			for(int k=0; k<a; k++)
				fprintf(output, "%d ", list[k]);
			fprintf(output, "\n");
		}
		
		fclose(output);
		fclose(input);
	}
}*/