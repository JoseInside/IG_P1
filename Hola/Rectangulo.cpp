#include "Rectangulo.h"


Rectangulo::Rectangulo(GLdouble ancho, GLdouble alto){
	
	numDat = 4; 
	h = alto; 
	w = ancho;
	color.set(0.0, 0.0, 0.0, 1.0);

	// se ponen los vertices
	vertices[0].set(-w / 2, h / 2, 0);
	vertices[1].set(w / 2, h / 2, 0);
	vertices[2].set(-w / 2, -h / 2, 0);
	vertices[3].set(w / 2, -h / 2, 0);

	//coordenadas de la textura relacionadas con los vertices
	cordText[0].set(0, 1);
	cordText[1].set(1, 1);
	cordText[2].set(0, 0);
	cordText[3].set(1, 0);

	normales[0].set(0,0,1); // se pone solo una normal ya que todas las de los vertices son iguales
}
void Rectangulo::draw(){
	activar();
	
	glLineWidth(2);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glLineWidth(1);

	desactivar();
}
void Rectangulo::set(GLdouble ancho, GLdouble alto){

	w = ancho;
	h = alto;
}
// glDrawElements(Primitiva, NºInd, Tipo, PtrArray);
void Rectangulo::activar() {
	
	// ‐> MallaTri::activar()
	//glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_TEXTURE_2D);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);

	glColor4d(color.r, color.g, color.b, color.a);
	glNormal3d(normales[0].x, normales[0].y, normales[0].z);
	glTexCoordPointer(2, GL_DOUBLE, 0, cordText);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	
}
void Rectangulo::desactivar() {
	
	// ‐> MallaTri::desactivar()
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}
bool Rectangulo::load(char arch[]) {
	/*
	//abrir el archivo de datos
	//leer número de datos y de índices(índices = 3 * caras)
	delete[] vertices; delete[] normales;	// liberar tablas
	delete[] indices;
	malla.vertices = new PVec3[numDat]; malla.normales = new PVec3[numDat];
	malla.indices = new GLuint[numInd];
	for each i in[0 … numDat) // leer los vértices
		//leer vertices[i]	// 3 coordenadas cada vértice
		for each i in[0 … numDat) // leer las normales
		//	leer normales[i] // 3 coordenadas cada vector
			for each i in[0 … numInd)	// leer los índices de los
			//	triángulos
			//	leer indices[i]
			*/
	return true;
}