#ifndef FILES_H
#define FILES_H

#include <string>
#include "alumno.h"

Alumno * cargar();
void guardar(Alumno, std::string, bool);
void guardarAlumno(Alumno a[], int);

#endif	//FILES_H
