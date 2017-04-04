#include "escena.h"
#include <GL/freeglut.h>
#include "PiramideTri.h"
#include "Triangulo.h"
#include "TriAnimado.h"
#include "Textura.h"
#include "Rectangulo.h"
#include <string>
//-------------------------------------------------------------------------

Textura textura1, textura2, textura3;
string imagen1 = "..\\bmps\\ray.bmp";
string imagen2 = "..\\bmps\\earth24.bmp";
string imagen3 = "..\\bmps\\pelota.bmp";
string collage = "..\\bmps\\collage.bmp";

Rectangulo rect(800.0, 600.0);
Rectangulo rect2(200.0, 150.0);
Rectangulo rect3(200.0, 150.0);

Triangulo tri(60.0f);

TriAnimado triAnim;

PiramideTri tria(50.0f, 100.0f);
PiramideTri tria2(-50.0f, 100.0f);
PiramideTri tria3(50.0f, -100.0f);
PiramideTri tria4(-50.0f, -100.0f);

//-------------------------------------------------------------------------

void Escena::init(){
  
	glEnable(GL_TEXTURE_2D);
	textura1.init();
	textura1.load(imagen1);
	textura2.init();
	textura2.load(imagen2, 150.0f);
	textura3.init();
	textura3.load(imagen3, { 0,0,0 }, 150.0f);

	copy = true;
}

//-------------------------------------------------------------------------

Escena::~Escena(){
   // liberar memoria y recursos 
}

//-------------------------------------------------------------------------

//ESTADO RECORTAR

void Escena::draw(){
	bool simple = true;
	if (copy) {
		textura1.copyCollage();
		textura1.save(collage);
		copy = false;
	}

	glDisable(GL_DEPTH_TEST);

	textura1.activar();
	
	rect.draw();
	
	drawTriangulo();
	textura1.desactivar();
	
}

//-------------------------------------------------------------------------

Ejes::Ejes(GLdouble l) {
  vertices[0].set(0, 0, 0);
  vertices[1].set(l, 0, 0);
  vertices[2].set(0, 0, 0);
  vertices[3].set(0, l, 0);
  vertices[4].set(0, 0, 0);
  vertices[5].set(0, 0, l);

  colores[0].set(1, 0, 0);
  colores[1].set(1, 0, 0);
  colores[2].set(0, 1, 0);
  colores[3].set(0, 1, 0);
  colores[4].set(0, 0, 1);
  colores[5].set(0, 0, 1);
}

//-------------------------------------------------------------------------

void Ejes::draw(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertices);
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3, GL_DOUBLE, 0, colores);

  glLineWidth(2);
  glDrawArrays(GL_LINES, 0, 6); 
  glLineWidth(1);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

}

//-------------------------------------------------------------------------
//ESTADO DIABOLO
void Escena::drawDiabolo() {


	textura1.activar();
	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			tria.vTri[i]->cordText[j].set(tri.cordText[j].s, tri.cordText[j].t);
			tria2.vTri[i]->cordText[j].set(tri.cordText[j].s, tri.cordText[j].t);
			tria3.vTri[i]->cordText[j].set(tri.cordText[j].s, tri.cordText[j].t);
			tria4.vTri[i]->cordText[j].set(tri.cordText[j].s, tri.cordText[j].t);
		}
	}
	
	tria.draw();
	tria2.draw();
	tria3.draw();
	tria4.draw();

	textura1.desactivar();

	ejes.draw();
}

//-------------------------------------------------------------------------

void Escena::drawTriangulo() {	
	tri.drawSimple();
}

//ESTADO COLLAGE
void Escena::drawCollage() {
	
	textura1.activar();
	rect.draw();
	textura1.desactivar();

	textura2.activar();
	glTranslated(-250, -150, 0);
	glRotated(315, 0, 0, 1);
	rect2.draw();
	glRotated(-315, 0, 0, 1);
	glTranslated(250, 200, 0);
	textura2.desactivar();

	glTranslated(150, 150, 0);
	textura3.activar();
	rect3.draw();
	textura3.desactivar();
	glTranslated(-150, -150, 0);

	ejes.draw();
}

//ESTADO ANIMAR
void Escena::drawAnim() {
	
	tri.posicionar(0, 0);
	textura1.activar();
	
	glPushMatrix();
	
	triAnim.draw();	
	tri.draw();	
	
	glPopMatrix();

	textura1.desactivar();	
	ejes.draw();
}

void Escena::updateAnim(bool simple) { triAnim.update(simple); };

bool Escena::mouseInside(int x, int y) {
	return tri.dentro(x, y);
}

void Escena::posTri(int x, int y) {
	tri.posicionar(x, y);
}

void Escena::recortar(int winWidth, int winHeight) { tri.cortar(winWidth, winHeight); };

void Escena::rotatri() { tri.rotar();}