#include<iostream>
#include "Cylinder.h"
using namespace std;
double pi=3.14;

double Cylinder::Area()
{return (2*pi*r*(r+len));} //�����ⶨ���Ա����Area

double Cylinder::Volume()
{return (pi*r*r*len);}     //�����ⶨ���Ա����Volume
