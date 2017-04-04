#pragma once
#include <GL/freeglut.h>
#include "tipos.h"
#include "PixMap24RGB.h"

class Textura
{
public:
	
	Textura() : w(0), h(0), id(0) {};
	~Textura() { glDeleteTextures(1, &id); };
	
	void init() {
		glGenTextures(1, &id); // generar un nombre
		activar(); 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}; // establecer filtros
	
	void activar() { glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, id); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	}; 

	void desactivar() { glBindTexture(GL_TEXTURE_2D, 0); glDisable(GL_TEXTURE_2D); };
	bool load(const std::string & BMP_Name); // cargar y transferir a openGL
	bool load(const std::string & BMP_Name, GLubyte alpha);
	bool load(const std::string & BMP_Name, PixMap24RGB::rgb_color colorKey, GLubyte alpha);
	void save(const std::string & BMP_Name); // obtener de openGL y guardar
	void copyCollage();

public:
	GLuint w, h; // dimensiones de la imagen
	GLuint id; // identificador interno de la textura
	PixMap24RGB * pA; //Array de la imagen a guardar (Puntero para utilizarlo en el método glGetTexImage())
};

