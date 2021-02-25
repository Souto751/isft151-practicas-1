#include <iostream>
#include <string>
#include "coche.h"

Coche::Coche(std::string color, std::string marca, int motor) : Vehiculo(marca, color){
	//cosas que deban nacer con un coche
	m_motor = motor;
}

Coche::~Coche(){
	//cosas que deben morir con un coche
}

void Coche::arrancar(){
	//algo para arrancar, std::cout << "estoy en marcha" << endl;
	std::cout << "El coche ha arrancado." << std::endl;
}

void Coche::parar(){
	//algo para parar, std::cout << "estoy detenido" << endl;
	std::cout << "El coche se ha detenido." << std::endl;
}

void Coche::repostar(){
	//algo para repostar, std::cout << "me detuve a repostar combustible" << endl;
	std::cout << "Se ha llenado el tanque de combustible del coche." << std::endl;
}
