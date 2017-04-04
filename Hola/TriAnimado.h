#pragma once

class TriAnimado
{
public:
	TriAnimado();
	~TriAnimado();
	void draw();

	
	int angRot;
	int angGir;
	int angRot2;


	void update(bool simple);
};

