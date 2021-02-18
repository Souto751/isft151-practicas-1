#ifndef ALUMNO_H
#define ALUMNO_H

#include <string.h>

class Alumno{
	private:
		std::string nombre = "", apellido = "";
		bool presente;
		int dni;
	public:
		Alumno();
		void setNombre(std::string);
		void setApellido(std::string);
		void setDni(int);
		void setPresente(bool);
		std::string getNombre();
		std::string getApellido();
		int getDni();
		std::string getPresente(bool);
		bool getPresente();
};

#endif	//ALUMNO_H
