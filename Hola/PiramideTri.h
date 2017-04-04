#pragma once
#include "Triangulo.h"
#include <vector>

using namespace std;
class PiramideTri
{
public:
	PiramideTri(GLdouble radBase, GLdouble h);
	~PiramideTri();
	
	//double altura;
	vector <Triangulo*> vTri;
	void draw();
};

