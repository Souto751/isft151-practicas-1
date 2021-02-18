#include <iostream>
#include <string.h>
#include "menu.h"
#include "limpiar.h"
#include "asistencia.h"

int menuOpc(){
	int opc;
	do{
		limpiar();
		std::cout << "--Menu Asistencia | By: Agustin Souto--" << std::endl << std::endl;
		std::cout << "1. Tomar asistencia" << std::endl;
		std::cout << "2. Ver lista de alumnos presentes" << std::endl;
		std::cout << "3. Ver lista de alumnos ausentes" << std::endl;
		std::cout << "4. Ver lista de alumnos completa" << std::endl;
		std::cout << "5. Agregar nuevo alumno" << std::endl;
		std::cout << "6. Eliminar alumno" << std::endl;
		std::cout << "7. Salir" << std::endl << std::endl;
		std::cout << "Ingrese la funcion que desea realizar: ";
		std::cin >> opc;
		if(opc < 1 || opc > 7){
			std::cout << "Opcion invalida" << std::endl;
			std::cin.get();
			std::cin.ignore();
		}
	}while(opc < 1 || opc > 7);

	return opc;
}

void menu(){
	int opc = menuOpc();
	
	switch(opc){
		case 1:
			tomarAsistencia();
			break;
		case 2:
			verPresentes();
			break;
		case 3:
			verAusentes();
			break;
		case 4:
			verAlumnos();
			break;
		case 5:
			nuevoAlumno();
			break;
		case 6:
			eliminarAlumno();
			break;
		case 7:
			std::cout << "Hasta pronto!" << std::endl;
			break;
	}
}

void returnMenu(){
	int retAux;
	
	do{
		std::cout << "\nDesea regresar al menu? [Si: 1 || No: 2]: ";
		std::cin >> retAux;
		
		if(retAux != 1 && retAux != 2){
			std::cout << "Opcion invalida." << std::endl << std::endl;
		}
	}while(retAux != 1 && retAux != 2);
	
	if(retAux == 1){
		menu();
	}else{
		std::cout << "\nHasta pronto!" << std::endl;
	}
}


