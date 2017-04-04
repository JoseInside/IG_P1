//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_
#include "tipos.h"

//-------------------------------------------------------------------------

enum estados { COLLAGE = 1, RECORTAR = 2, ANIMAR = 3, DIABOLO = 4 };

//-------------------------------------------------------------------------
class Ejes {
public:
  Ejes(GLdouble l);
  ~Ejes(){};
  void draw();
public:
  PVec3 vertices[6];
  PVec3 colores[6];
};

//-------------------------------------------------------------------------

class Escena {
public:
  Escena(): ejes(200) {};
  ~Escena();
 
  void init();
  void draw();
  void drawDiabolo();
  void drawTriangulo();
  void drawCollage();
  void drawAnim();
  void updateAnim(bool simple);
  bool mouseInside(int x, int y);
  void posTri(int x, int y);
  void recortar(int winWidth, int winHeight);
  void rotatri();
public:
  Ejes ejes;
  bool copy;
  //GLdouble rotacion;
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
