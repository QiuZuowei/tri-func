#include<iostream>
#include"tab.h"
#include"Trigonometric.h"
using namespace std;


struct Result Trigonometric(double beta, int n)
{
	struct Result ret;
	ret.cosine = 1;
	ret.sine = 0;
	int flag = 0;
	while (beta < -pi / 2)
	{
		beta = beta + pi;
		flag = 1;
	}
	while (beta > pi / 2)
	{
		beta = beta - pi;
		flag = 1;
	}
	//angles = atan(2e-(0:27));

	int i = sizeof(Kvalues) / sizeof(double) > n ? sizeof(Kvalues) / sizeof(double) : n;
	double Kn = 0.60725293500888;
	double poweroftwo = 1;
	double angle;
	double factor;
	double temp;
	double v = 0;
	double sigma = 1;
	double ina = beta;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 > sizeof(angles) / sizeof(double))
			angle = angle / 2.0;
		else
			angle = angles[i];
		beta = ina - v;
		if (beta < 0)
			sigma = -1;
		else
			sigma = 1;
		v = v + sigma * angle;
		factor = sigma * poweroftwo;
		temp = ret.cosine;
		ret.cosine = 1 * ret.cosine + (-factor) * ret.sine;
		ret.sine = factor * temp + 1 * ret.sine;
		poweroftwo = poweroftwo / 2;
	}
	ret.cosine = ret.cosine * Kn;
	ret.sine = ret.sine * Kn;
	if (flag == 1)
	{
		ret.sine = -ret.sine;
		ret.cosine = -ret.cosine;
	}
	return ret;
}

