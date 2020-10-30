#include <iostream>
#include <string>
#include <fstream>

#include "asistencia.h"
#include "limpiar.h"

void pedirDatos()
{
	int cent = 2, _dia, _mes, _anio;
	
	std::cout << "-.-Menu Asistencia-.-" << std::endl << std::endl;
	
	std::cout << "Ingrese la fecha de hoy (numericamente)..." << std::endl;
	std::cout << "Dia: ";
	std::cin >> _dia;
	std::cout << "Mes: ";
	std::cin >> _mes;
	std::cout << "Anio: ";
	std::cin >> _anio;
	
	do
	{
		Alumno *student = new Alumno();
		student->anio = _anio;
		student->dia = _dia;
		student->mes = _mes;
		std::cout << std::endl;
		std::cin.ignore();
		std::cout << "Ingrese el nombre del alumno: ";
		getline(std::cin, student->nombre);
		std::cout << "Ingrese el apellido del alumno: ";
		getline(std::cin, student->apellido);
		do
		{
			std::cout << "Ingrese el estado del alumno [1: Presente | 2: Ausente]: ";
			std::cin >> student->estado;
			if(1 < student->estado < 0)
			{
				std::cout << "\nEstado incorrecto..." << std::endl << std::endl;
			}
		}while(1 < student->estado < 0);
		
		guardar(_anio, _mes, _dia, student->apellido, student->nombre, student->estado, cent);
		
		std::cout << "Si desea cargar otro alumno ingrese 1, de lo contrario el programa finalizara: ";
		std::cin >> cent;
		
		delete student;
		limpiar();
	}while(cent == 1);
	
	std::cout << "Hasta luego!" << std::endl;
}

void guardar(int anio, int mes, int dia, std::string apellido, std::string nombre, int est, int aux)
{
	std::ofstream archivo;
	std::string asi;
	
	if(est == 1)
	{
		asi = "Presente";
	}else
	{
		asi = "Ausente";
	}
	
	archivo.open("Asistencia clase.txt", std::ios::app);	//std::ios::app sirve para añadir contenido al final del archivo.
	if(aux == 2)
	{
		archivo << "Asistencia clase " << dia << " / " << mes << " / " << anio << std::endl << std::endl;
	}
	archivo << apellido << ", " << nombre << "\t" << asi << std::endl << "" << std::endl;
	
	archivo.close();
}
