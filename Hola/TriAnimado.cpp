#include "TriAnimado.h"
#include "PiramideTri.h"


#include <GL/freeglut.h>

TriAnimado::TriAnimado()
{
	angGir = 170;
	angRot = 3;
	angRot2 = 1;
}


TriAnimado::~TriAnimado()
{
}


void TriAnimado::update(bool simple) {

	if (simple) {
		angGir = 170;
		angRot += 3;
	}
	else {
		angRot2++;	
		angGir = 170;
		angRot += 3;
	}
	

	
}

void TriAnimado::draw(){

	glRotated(angRot2, 0, 0, 1);
	glTranslated(angGir, angGir, 0.0);	
	glRotated(angRot, 0, 0, 1);

}
