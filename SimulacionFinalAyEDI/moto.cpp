#include <iostream>
#include <string>
#include "moto.h"

Moto::Moto(std::string color, std::string marca, int cilindrada) : Vehiculo(marca, color){
	//cosas que deban nacer con un coche
	m_cilindrada = cilindrada;
}

Moto::~Moto(){
	//cosas que deben morir con un coche
}

void Moto::arrancar(){
	//algo para arrancar, std::cout << "estoy en marcha" << endl;
	std::cout << "La moto ha arrancado." << std::endl;
}

void Moto::parar(){
	//algo para parar, std::cout << "estoy detenida" << endl;
	std::cout << "La moto ha parado." << std::endl;
}

void Moto::repostar(){
	//algo para repostar, std::cout << "me detuve a repostar combustible" << endl;
	std::cout << "Se ha llenado el tanque de combustible de la moto." << std::endl;
}
