#ifndef COCHE_H
#define COCHE_H

#include <string>
#include "vehiculo.h"

class Coche : public Vehiculo{
	private:
		int m_motor;
		
	public:
		Coche(std::string color, std::string marca, int motor);
		virtual ~Coche();
		void arrancar();
		void parar();
		void repostar();
};

#endif //COCHE_H
