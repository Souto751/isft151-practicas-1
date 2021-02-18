#include <iostream>
#include <string.h>
#include "alumno.h"

Alumno::Alumno(){}

void Alumno::setNombre(std::string nombre){
	this->nombre = nombre;
}

void Alumno::setApellido(std::string apellido){
	this->apellido = apellido;
}

void Alumno::setDni(int dni){
	this->dni = dni;
}

void Alumno::setPresente(bool presente){
	this->presente = presente;
}

std::string Alumno::getNombre(){
	return this->nombre;
}

std::string Alumno::getApellido(){
	return this->apellido;
}

int Alumno::getDni(){
	return this->dni;
}

std::string Alumno::getPresente(bool presente){
	if(presente == true){
		return "Presente";
	}else{
		return "Ausente";
	}
}

bool Alumno::getPresente(){
	return this->presente;
}
