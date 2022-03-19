#include<iostream>
#include"tab.h"
#include"arctan.h"
using namespace std;

double arctan(double numy)
{
	double numx = 1;
	double numx_new, numy_new;
	double poweroftwo = 1;
	double anglesum = 0;

	for (int i = 0; i < sizeof(angles) / sizeof(double); i++)
	{
		if (numy > 0)
		{
			numy_new = numy - numx * poweroftwo;
			numx_new = numx + numy * poweroftwo;
			numy = numy_new;
			numx = numx_new;
			anglesum += angles[i];
			poweroftwo = poweroftwo / 2;
		}
		else if (numy < 0)
		{
			numy_new = numy + numx * poweroftwo;
			numx_new = numx - numy * poweroftwo;
			numy = numy_new;
			numx = numx_new;
			anglesum -= angles[i];
			poweroftwo = poweroftwo / 2;
		}
		else
			break;
	}
	return anglesum;
}