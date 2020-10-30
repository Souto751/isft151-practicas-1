#include <string>

#ifndef ASISTENCIA_H
#define ASISTENCIA_H

typedef struct
{
	int dia, mes, anio, estado;
	std::string nombre, apellido;
}Alumno;

void pedirDatos();
void guardar(int, int, int, std::string, std::string, int, int);

#endif	//ASISTENCIA_H
