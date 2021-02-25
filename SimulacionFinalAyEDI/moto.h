#ifndef MOTO_h
#define MOTO_H

#include <string>
#include "vehiculo.h"

class Moto : public Vehiculo{
	private:
		int m_cilindrada;
		
	public:
		Moto(std::string color, std::string marca, int cilindrada);
		virtual ~Moto();
		void arrancar();
		void parar();
		void repostar();
};

#endif //MOTO_H
