#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo{
	private:
		std::string m_marca;
		std::string m_color;
		
	public:
		Vehiculo(std::string marca, std::string color){
			m_marca = marca;
			m_color = color;
		};
		virtual ~Vehiculo(){};
		virtual void arrancar() = 0;
		virtual void parar() = 0;
		virtual void repostar() = 0;
};

#endif //VEHICULO_H
