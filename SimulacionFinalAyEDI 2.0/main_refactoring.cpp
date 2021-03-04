#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**********************************VEHICULO PURE ABSTRACT CLASS************************************/
class Vehiculo
{
    public:
        virtual ~Vehiculo(){};
        virtual void arrancar() = 0;
        virtual void parar() = 0;
        virtual void repostar() = 0;
};

/**********************************TALLER CLASS************************************/
class Taller
{
    private:
        int capacidadMaximaVehiculos;
        int cantidadActualVehiculos;
        //https://www.cplusplus.com/reference/vector/vector/vector/
        vector<Vehiculo*> vehiculos; 

    public:
        Taller(int capacidad);
        virtual ~Taller();
        void meter(Vehiculo* v);
        void arreglarVehiculos();
        int getCantidadActualDeVehiculos();
};

Taller::Taller(int capacidad)
{
    capacidadMaximaVehiculos = capacidad;
    cantidadActualVehiculos = 0;
}

Taller::~Taller()
{
    //vacio
    cout << endl;
    for(int i = 0; i < vehiculos.size(); i++){
    	delete vehiculos[i];	
	}
    cout << endl << "El taller ha cerrado." << endl;
}

void Taller::meter(Vehiculo* v)
{
    vehiculos.push_back(v);
    cout << "Se ha metido el vehiculo al taller." << endl;
}

void Taller::arreglarVehiculos()
{
    //por cada vehículo de la lista invocar el método arrancar...
    for(int i = 0; i < vehiculos.size(); i++){
    	cout << endl;
    	vehiculos[i]->repostar();
    	vehiculos[i]->arrancar();
    	vehiculos[i]->parar();
	}
}

int Taller::getCantidadActualDeVehiculos()
{
    return cantidadActualVehiculos;
}

/**********************************COCHE CLASS************************************/
class Coche : public Vehiculo
{
    private:
        string m_color;
        string m_marca;
        int m_motor;
    public:
        Coche(string color, string marca, int motor);
        virtual ~Coche();
        void arrancar();
        void parar();
        void repostar();
};

Coche::Coche(string color, string marca, int motor)
{
    //cosas que deban nacer con un coche
    m_color = color;
    m_marca = marca;
    m_motor = motor;
}

Coche::~Coche()
{
    //cosas que deban morir con un coche
    cout << "El coche " << m_marca << " " << m_color << " ha salido del taller." << endl;
}

void Coche::arrancar()
{
    //algo para arrancar, cout << "estoy en marcha" << endl;
    cout << "El coche " << m_marca << " " << m_color << " ha arrancado." << endl;
}

void Coche::parar()
{
    //algo para arrancar, cout << "estoy detenide" << endl;
    cout << "El coche " << m_marca << " " << m_color << " ha parado." << endl;
}

void Coche::repostar()
{
    //algo para arrancar, cout << "me detuve a repostar combustible" << endl;
    cout << "Se ha llenado el tanque de combustible del coche " << m_marca << " " << m_color << "." << endl;
}
/**********************************MOTO CLASS************************************/
class Moto : public Vehiculo
{
    private:
        string m_color;
        string m_marca;
        int m_cilindrada;
    public:
        Moto(string color, string marca, int cilindrada);
        virtual ~Moto();
        void arrancar();
        void parar();
        void repostar();
};

Moto::Moto(string color, string marca, int cilindrada)
{
    //cosas que deban nacer con un coche
    m_color = color;
    m_marca = marca;
    m_cilindrada = cilindrada;
}

Moto::~Moto()
{
    //cosas que deban morir con un coche
    cout << "La moto " << m_marca << " " << m_color << " ha salido del taller." << endl;
}

void Moto::arrancar()
{
    //algo para arrancar, cout << "estoy en marcha" << endl;
    cout << "La moto " << m_marca << " " << m_color << " ha arrancado." << endl;
}

void Moto::parar()
{
    //algo para arrancar, cout << "estoy detenide" << endl;
    cout << "La moto " << m_marca << " " << m_color << " ha parado." << endl;
}

void Moto::repostar()
{
    //algo para arrancar, cout << "me detuve a repostar combustible" << endl;
    cout << "Se ha llenado el tanque de combustible de la moto " << m_marca << " " << m_color << "." << endl;
}

int main()
{
    Taller* taller1 = new Taller(256);
    
	//-----Agregar Vehiculos-----
    Vehiculo* coche1 = new Coche("azul", "Ford", 4); 
    taller1->meter(coche1);
    Vehiculo* moto1 = new Moto("roja", "Honda", 4); 
    taller1->meter(moto1);
    
    taller1->arreglarVehiculos();
    //-----Fin Agregar Vehiculos-----
    
    //-----Eliminar taller antes de finalizar la ejecucion-----
    taller1->~Taller();
    
    return 0;
}
