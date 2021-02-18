#include <iostream>
#include <string.h>
#include <time.h>
#include "asistencia.h"
#include "alumno.h"
#include "menu.h"
#include "limpiar.h"
#include "files.h"

Alumno *alumnos = cargar();

void tomarAsistencia(){
	bool primerGuardado = false;
	std::string fechaAux = "";
	limpiar();
	if(alumnos[0].getNombre() == ""){
		std::cout << "--Tomar Asistencia--" << std::endl; 
		std::cout << "No hay ningun alumno cargado." << std::endl << std::endl;
		returnMenu(); 
	}else{
		
		//Para mostrar la fecha actual por pantalla
		char fecha[25];
		time_t current_time;
		current_time=time(NULL);
		ctime(&current_time);
		strcpy(fecha, ctime(&current_time));
		
		//Para guardar en un archivo que tenga el nombre de la fecha
		for(int i = 0; i < 10; i++){
			fechaAux += fecha[i];
		}
		//
	    
		int i = 0;
		int aux;
		
		std::cout << "--Tomar Asistencia--" << std::endl; 
	    std::cout << fecha << std::endl;
	    std::cout << "[Presente: 1 || Ausente: 2]" << std::endl;
	    
	    while(alumnos[i].getApellido() != ""){
	    	do{
	    		std::cout << i+1 << ". " << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() << ": ";
	    		std::cin >> aux;
	    		if(aux != 1 && aux != 2){
	    			std::cout << "Opcion invalida." << std::endl << std::endl;
				}
			}while(aux != 1 && aux != 2);
	    	
	    	aux == 1 ? alumnos[i].setPresente(true) : alumnos[i].setPresente(false);
	    	guardar(alumnos[i], fechaAux, primerGuardado);
	    	primerGuardado = true;
	    	i++;
		}
	    
	    returnMenu();
	}
}

void verPresentes(){
	int i = 0;
	limpiar();
	
	std::cout << "--Ver Alumnos Presentes--" << std::endl << std::endl; 
	
	while(alumnos[i].getNombre() != ""){
		if(alumnos[i].getPresente() == true){
			std::cout << i+1 << ". " << alumnos[i].getDni() << "  |  " << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() << std::endl;
		}
		i++;
	}
	    returnMenu();
}

void verAusentes(){
	int i = 0;
	limpiar();
	
	std::cout << "--Ver Alumnos Ausentes--" << std::endl << std::endl; 
	
	while(alumnos[i].getNombre() != ""){
		if(alumnos[i].getPresente() == false){
			std::cout << i+1 << ". " << alumnos[i].getDni() << "  |  " << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() << std::endl;
		}
		i++;
	}
	    returnMenu();
}

void verAlumnos(){
	int i = 0;
	limpiar();
	
	std::cout << "--Ver Alumnos--" << std::endl << std::endl; 
	
	while(alumnos[i].getNombre() != ""){
		std::cout << i+1 << ". " << alumnos[i].getDni() << "  |  " << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() << std::endl;
		i++;
	}
	returnMenu();
}

void nuevoAlumno(){
	int i = 0;
	int aux;
	limpiar();
	std::cin.ignore();
	
	std::cout << "--Ingresar nuevo alumno--" << std::endl << std::endl; 
	
	while(alumnos[i].getNombre() != "" && i < 100){
		i++;
	}
	
	if(i == 99){
		std::cout << "Se ha alcanzado la cantidad maxima de alumnos." << std::endl;
	}else{
		std::string nombre, apellido;
		int dni;
		
		std::cout << "Complete los datos del alumno:" << std::endl;
		std::cout << "  .Nombre: ";
		getline(std::cin, nombre);
		std::cout << "  .Apellido: ";
		getline(std::cin, apellido);
		std::cout << "  .DNI (Sin puntos): ";
		std::cin >> dni;
		
		alumnos[i].setNombre(nombre);
		alumnos[i].setApellido(apellido);
		alumnos[i].setDni(dni);
	}
	
	do{
		std::cout << "Desea agregar otro alumno? [Si: 1 || No: 2]: ";
		std::cin >> aux;
		if(aux != 1 && aux != 2){
			std::cout << "Opcion invalida." << std::endl << std::endl;
		}
	}while(aux != 1 && aux != 2);
	
	guardarAlumno(alumnos, cantidadAlumnos());
	
	aux == 1 ? nuevoAlumno() : returnMenu();
}

void eliminarAlumno(){
	int i = 0;
	int dni;
	bool found = false;
	int aux;
	limpiar();
	
	std::cout << "--Eliminar alumno--" << std::endl << std::endl;
	
	if(alumnos[0].getNombre() == ""){
		std::cout << "No hay alumnos cargados." << std::endl << std::endl;
		returnMenu();
	}else{
		std::cout << "Ingrese el DNI del alumno a eliminar: ";
		std::cin >> dni;
	
		while(alumnos[i].getNombre() != ""){
			if(alumnos[i].getDni() == dni){
				std::cout << i+1 << ". " << alumnos[i].getDni() << "  |  " << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() << std::endl;
				found = true;
				break;
			}
			i++;
		}
		
		if(found == false){
			std::cout << "No hay alumnos con el DNI ingresado." << std::endl << std::endl;
		}else{
			do{
				std::cout << "Desea eliminar al alumno? [Si: 1 || No: 2]: ";
				std::cin >> aux;
				if(aux != 1 && aux != 2){
					std::cout << "Opcion invalida." << std::endl << std::endl;
				}
			}while(aux != 1 && aux != 2);
		
			if(aux == 1 && found == true){
				for(int x = i; i < 100 && alumnos[x].getNombre() != ""; x++){
					alumnos[i] = alumnos[i+1];
					if(alumnos[i+1].getNombre() == ""){
						alumnos[i].setNombre("");
						alumnos[i].setApellido("");
					}
				}
			}
		}
		
		
		do{
			std::cout << "Desea eliminar otro alumno? [Si: 1 || No: 2]: ";
			std::cin >> aux;
			if(aux != 1 && aux != 2){
				std::cout << "Opcion invalida." << std::endl << std::endl;
			}
		}while(aux != 1 && aux != 2);
		
		guardarAlumno(alumnos, cantidadAlumnos());
		
		aux == 1 ? eliminarAlumno() : returnMenu();
	}
}

int cantidadAlumnos(){
	int q = 0;
	for(int i = 0; i < 100; i++){
		if(alumnos[i].getNombre() != ""){
			q++;
		}
	}
	return q;
}
