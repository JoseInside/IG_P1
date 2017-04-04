#include "Triangulo.h"


Triangulo::Triangulo(GLdouble radio){

	GLdouble ang = (2.0 * 3.14) / 3.0;
	GLdouble x = radio* cos(ang);
	GLdouble y = radio* sin(ang);

	
	vertices[0].set(radio, 0, 0);
	vertices[1].set(x, y, 0);
	vertices[2].set(x, -y, 0);

	normales[0].set(0, 0, 1);
	normales[1].set(0, 0, 1);
	normales[2].set(0, 0, 1);

	//coordenadas de la textura relacionadas con los vertices
	cordText[0].set(-1, -1);
	cordText[1].set(0, 1);
	cordText[2].set(1, -1);

	color.r = 1.0;
	color.g = 0.0;
	color.b = 0.0;
	color.a = 1.0;


	centro = PVec3(0, 0);
	r = radio;
}


Triangulo::~Triangulo()
{
	delete[] vertices; 
	delete[] normales;
}
void Triangulo::set(int n, GLdouble h)//GLdouble px, GLdouble py)
{
	vertices[n].set(0, 0, h);
	
}

void Triangulo::draw() {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_2D);

	glColor4d(color.r, color.g, color.b, color.a);
	glNormal3d(normales[0].x, normales[0].y, normales[0].z);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	glTexCoordPointer(2, GL_DOUBLE, 0, cordText);

	glLineWidth(2);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glLineWidth(1);
	
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_TEXTURE_2D);
	
}

void Triangulo::drawSimple() {
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	glNormal3d(normales[0].x, normales[0].y, normales[0].z);
	glColor4d(color.r, color.g, color.b, color.a);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	
}

//Esto comprueba si está dentro de las coordenadas de los vértices
bool Triangulo::dentro(GLdouble x, GLdouble y) {
	
	if ((vertices[0].x - x) * (vertices[1].y - y) - (vertices[0].y - y) * (vertices[1].x - x) < 0)
		return false;
	else if ((vertices[1].x - x) * (vertices[2].y - y) - (vertices[1].y - y) * (vertices[2].x - x) < 0)
		return false;
	else if ((vertices[2].x - x) * (vertices[0].y - y) - (vertices[2].y - y) * (vertices[0].x - x) < 0)
		return false;
	else return true;

}

//Esto re-posiciona el triángulo con el centro
void Triangulo::posicionar(GLdouble xcentro, GLdouble ycentro) {

	centro = PVec3(xcentro, ycentro, 0);
		
	vertices[0] = { r*cos(0) + centro.x, r * sin(0) + centro.y, vertices[0].z + centro.z };
	vertices[1] = { r*cos(0 + 2 * 3.14 / 3) + centro.x, r * sin(0 + 2 * 3.14 / 3) + centro.y, vertices[1].z + centro.z };
	vertices[2] = { r*cos(0 + 4 * 3.14 / 3) + centro.x, r * sin(0 + 4 * 3.14 / 3) + centro.y, vertices[2].z + centro.z };

}

// Corta la textura y le da las coordenadas de la misma al triángulo
void Triangulo::cortar(GLdouble width, GLdouble height) {
	CTex2 a, b, c;
	a.set((vertices[0].x + width/2) / width, (vertices[0].y + height/2) / height);
	b.set((vertices[1].x + width/2) / width, (vertices[1].y + height/2) / height);
	c.set((vertices[2].x + width/2) / width, (vertices[2].y + height/2) / height);

	cordText[0] = a;
	cordText[1] = b;
	cordText[2] = c;  
}
void Triangulo::rotar() {
	rotacion += 0.1;
	vertices[0] = { r*cos(rotacion) + centro.x, r * sin(rotacion) + centro.y, 0 };
	vertices[1] = { r*cos(rotacion + 2.0 * 3.14 / 3.0) + centro.x, r * sin(rotacion + 2.0 * 3.14 / 3.0) + centro.y, 0 };
	vertices[2] = { r*cos(rotacion + 4.0 * 3.14 / 3.0) + centro.x, r * sin(rotacion + 4.0 * 3.14 / 3.0) + centro.y, 0 };


}

