#include <iostream>
#include <string>
#include <fstream>
#include "files.h"
#include "alumno.h"

Alumno returnAlumnos[100];

Alumno * cargar(){
	std::ifstream archivo;
	
	Alumno alumnoAux;
	int q, dniAux;
	bool finished = false;
	std::string dniString, qAux;
	std::string nombreAux, apellidoAux, strAux;
	
	archivo.open("listaAlumnos.txt");
	
	if(archivo.is_open()){
		getline(archivo, qAux, '\n');
		q = std::stoi(qAux);
		getline(archivo, strAux, '\n');
		
		for(int i = 0; i < q; i++){
			getline(archivo, dniString, '\n');
			dniAux = std::stoi(dniString);
			alumnoAux.setDni(dniAux);
			
			getline(archivo, apellidoAux, '\n');
			alumnoAux.setApellido(apellidoAux);
			
			getline(archivo, nombreAux, '\n');
			alumnoAux.setNombre(nombreAux);
			
			getline(archivo, strAux, '\n');
			
			returnAlumnos[i] = alumnoAux;
		}
		
		archivo.close();
	}
	
	return returnAlumnos;
	
}

void guardar(Alumno a, std::string fecha, bool primerGuardado){
	std::ofstream archivo;
		
	archivo.open(fecha+".txt", std::ios::app);	//std::ios::app sirve para agregar contenido al final del archivo.
	
	if(primerGuardado == false){
		archivo << "Asistencia clase: " << fecha << std::endl << std::endl;
	}
	
	archivo << a.getDni() << "  ||  " << a.getApellido() << ", " << a.getNombre() << "  ||  " << a.getPresente(a.getPresente()) << std::endl;
	archivo.close();
}

void guardarAlumno(Alumno a[], int q){
	std::ofstream archivo;
	Alumno aux;
	int i = 0, j = 0;
	
	archivo.open("listaAlumnos.txt");
	archivo << q << std::endl << std::endl;
	
	for(int i = 0; i < sizeof(a); i++){
		if(a[i].getNombre() != ""){
			archivo << a[i].getDni() << std::endl << a[i].getApellido() << std::endl << a[i].getNombre() << std::endl << std::endl;
		}
	}
	
	archivo.close();
}
