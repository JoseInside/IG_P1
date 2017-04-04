#pragma once
#include <vector>
#include <GL/freeglut.h>
#include "tipos.h"

class Triangulo
{
public:
	Triangulo(GLdouble radio);
	~Triangulo();

	PVec3 vertices[3];	//Array de vértices del triángulo
	PVec3 normales[1];	//Solo una normal al estar en 2D
	CTex2 cordText[3];  // tabla de coordenadas de textura
	Color4 color;

	PVec3 centro;
	GLdouble r;
	GLdouble rotacion;

	void draw();
	void set(int n, GLdouble h);
	void drawSimple();
	void rotar();
	
	bool dentro(GLdouble x, GLdouble y);
	void posicionar(GLdouble xcentro, GLdouble ycentro);
	void cortar(GLdouble width, GLdouble height);
};
