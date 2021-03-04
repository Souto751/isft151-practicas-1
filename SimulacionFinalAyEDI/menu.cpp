#include <iostream>
#include <string>
#include "menu.h"
#include "limpiar.h"
#include "taller.h"
#include "coche.h"
#include "moto.h"

Taller taller(50, 0);	//Taller con variables inicializadas.

void menu(){
	limpiar();
	int opc = menu_opt();
	
	switch(opc){
		case 1:
			what_vehicle();
			break;
		case 2:
			taller.arreglarVehiculos();
			break;
		case 3:
			std::cout << "Hasta luego!" << std::endl;
			break;
		default:
			break;
	}
}

int menu_opt(){
	int ret_opc;
	do{
		std::cout << "--Taller de vehiculos 'AyEDI'--" << std::endl << std::endl;
		std::cout << "1. Agregar vehiculo." << std::endl;
		std::cout << "2. Arreglar vehiculos." << std::endl;
		std::cout << "3. Salir" << std::endl << std::endl;
		std::cout << "Opcion: ";
		std::cin >> ret_opc;
		if(ret_opc < 1 || ret_opc > 3){
			std::cout << "\nOpcion invalida." << std::endl;
			std::cin.get();
			std::cin.ignore();
			limpiar();
		}
	}while(ret_opc < 1 || ret_opc > 3);
}

void return_menu(){
	int ret_opc;
	std::cin.ignore();
	
	do{
		std::cout << "\nDesea regresar al menu? [Si: 1 || No: 2]: ";
		std::cin >> ret_opc;
		if(ret_opc != 1 && ret_opc != 2){
			std::cout << "Opcion incorrecta." << std::endl;
			std::cin.get();
			std::cin.ignore();
		}
	}while(ret_opc != 1 && ret_opc != 2);
	
	if(ret_opc == 1){
		menu();
	}else{
		std::cout << "Hasta pronto!" << std::endl;
		std::cin.get();
		std::cin.ignore();
	}
}


void what_vehicle()	//Selecciona entre coche y moto, depende de la eleccion se crea un objeto de un tipo u otro.
{
	int opc;
	int aux;
	std::string ma;
	std::string co;
	Vehiculo *vh = NULL;
	
	
	do
	{
		std::cout << "\n[1] Coche. \n[2] Moto." << std::endl;
		std::cout << "Opcion: ";
		std::cin >> opc;
		if(opc < 1 || opc > 2)
		{
			std::cout << "\nOpcion invalida." << std::endl;
		}
	}while(opc < 1 || opc > 2);
	
	switch(opc)
	{
		case 1:			
			limpiar();
			std::cin.ignore();
			std::cout << "-.- Ingresar coche -.-" << std::endl << std::endl;
			std::cout << "Ingrese la marca del vehiculo: ";
			getline(std::cin, ma);
			std::cout << "Ingrese el color del vehiculo: ";
			getline(std::cin, co);
			std::cout << "Ingrese el motor del vehiculo: ";
			std::cin >> aux;
			vh = new Coche(co, ma, aux);
			delete vh;
			break;
					
		
		case 2:			
			limpiar();
			std::cin.ignore();
			std::cout << "-.- Ingresar moto -.-" << std::endl << std::endl;
			std::cout << "Ingrese la marca del vehiculo: ";
			getline(std::cin, ma);
			std::cout << "Ingrese el color del vehiculo: ";
			getline(std::cin, co);
			std::cout << "Ingrese la cilindrada del vehiculo: ";
			std::cin >> aux;
			vh = new Moto(co, ma, aux);
			delete vh;
			break;
			
	}
	
	taller.meter(vh);	
	return_menu();
}
