#include <iostream>
#include "menu.h"
#include "taller.h"
#include "vehiculo.h"

Taller::Taller(){}

Taller::Taller(int maxVehiculos, int numVehiculos){
	this->max_vehiculos = maxVehiculos;
	this->num_vehiculos = numVehiculos;
}

Taller::~Taller(){
	//por cada componente vehiculo invocar el operador delete...
	delete [] vehiculos;
}

void Taller::meter(Vehiculo* v){
	//lista_de_vehiculos.add(v);
	vehiculos[num_vehiculos] = v;
	num_vehiculos++;
}

int Taller::getCantVehiculos(){
	return this->num_vehiculos;
}

void Taller::arreglarVehiculos(){
	if(num_vehiculos == 0)
	{
		std::cout << "No hay vehiculos para reparar." << std::endl;
	}
	else
	{
		int aux;
		
		std::cout << "\nIngrese 1 si desea cargar combustible a los vehiculos: ";
		std::cin >> aux;
		
		if(aux == 1)
		{
			for(int i = 0; i < num_vehiculos; i++)
			{
				vehiculos[i]->repostar();
			}
		}
		
		for(int i = 0; i < num_vehiculos; i++)
		{
			vehiculos[i]->arrancar();
			vehiculos[i]->parar();
		}
		
		for(int i = 0; i < this->num_vehiculos; i++){
			delete vehiculos[i];
		}
		
		this->num_vehiculos = 0;
	}
	return_menu();	
}


