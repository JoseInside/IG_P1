#include "PiramideTri.h"



PiramideTri::PiramideTri(GLdouble radBase, GLdouble h) 
{
	
	vTri.push_back(new Triangulo(radBase));
		vTri[0]->vertices[0].x = radBase;
		vTri[0]->vertices[1].x = radBase* cos((2.0 * 3.14) / 3.0);
		vTri[0]->vertices[2].x = radBase* cos((2.0 * 3.14) / 3.0);
		vTri[0]->vertices[0].y = h;
		vTri[0]->vertices[1].y = h;
		vTri[0]->vertices[2].y = h;
		vTri[0]->vertices[0].z = 0;
		vTri[0]->vertices[1].z = radBase* sin((2.0 * 3.14) / 3.0);
		vTri[0]->vertices[2].z = -radBase* sin((2.0 * 3.14) / 3.0);
		vTri[0]->set(0, 0);

	vTri.push_back(new Triangulo(radBase));
		vTri[1]->vertices[0].x = radBase;
		vTri[1]->vertices[1].x = radBase* cos((2.0 * 3.14) / 3.0);
		vTri[1]->vertices[2].x = radBase* cos((2.0 * 3.14) / 3.0);
		vTri[1]->vertices[0].y = h;
		vTri[1]->vertices[1].y = h;
		vTri[1]->vertices[2].y = h;
		vTri[1]->vertices[0].z = 0;
		vTri[1]->vertices[1].z = radBase* sin((2.0 * 3.14) / 3.0);
		vTri[1]->vertices[2].z = -radBase* sin((2.0 * 3.14) / 3.0);
		vTri[1]->set(1, 0);
	
	vTri.push_back(new Triangulo(radBase));
		vTri[2]->vertices[0].x = radBase;
		vTri[2]->vertices[1].x = radBase* cos((2.0 * 3.14) / 3.0);
		vTri[2]->vertices[2].x = radBase* cos((2.0 * 3.14) / 3.0);
		vTri[2]->vertices[0].y = h;
		vTri[2]->vertices[1].y = h;
		vTri[2]->vertices[2].y = h;
		vTri[2]->vertices[0].z = 0;
		vTri[2]->vertices[1].z = radBase* sin((2.0 * 3.14) / 3.0);
		vTri[2]->vertices[2].z = -radBase* sin((2.0 * 3.14) / 3.0);
		vTri[2]->set(2, 0);

}

PiramideTri::~PiramideTri()
{
	
}

void PiramideTri::draw(){
	
	for (int i = 0; i < 3; ++i){
		vTri[i]->draw();
	}
}


