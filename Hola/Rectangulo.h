#pragma once
#include <vector>
#include <GL/freeglut.h>
#include "tipos.h"


class Rectangulo
{
public:
	GLuint numDat;	// tabla de vértices y normales
	PVec3 vertices[4];
	PVec3 normales[1]; // también pueden ser vector<PVec3>
	CTex2 cordText[4];  // tabla de coordenadas de textura
	
	Color4 color;

	
	Rectangulo(GLdouble ancho, GLdouble alto);
	~Rectangulo(){ delete[] vertices; delete[] normales; }
	bool load(char arch[]);	// ‐> generar los datos
	void draw();
	void set(GLdouble ancho, GLdouble alto);

	GLdouble w, h;
protected:
	void activar();
	void desactivar();

};

