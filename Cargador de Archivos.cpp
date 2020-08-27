//Prácticas Profesionalizantes I
//Profesor: González Ferreira, Gabriel Nicolás
//Alumno: Nuñez Souto, A. Agustín

/*
Vamos a hacer un ejemplo completo que use arreglos (“arrays”), y estructuras (“struct”) y que además manipule strings. La idea va a ser la siguiente: Crearemos un programa que pueda almacenar datos de hasta 1000 archivos (archivos de computadora). Para cada archivo, debe guardar los  siguientes datos: Nombre del archivo (max 40 letras), Tamaño (en KB, número de 0 a 2.000.000.000). El programa mostrará un menú que permita al usuario las siguientes operaciones:

1- Añadir datos de un nuevo archivo
2- Mostrar los nombres de todos los archivos almacenados
3- Mostrar archivos que sean de más de un cierto tamaño (por ejemplo, 2000 KB).
4- Ver todos los datos de un cierto archivo (a partir de su nombre)
5- Salir de la aplicación (como todavía no sabemos almacenar los datos, éstos se perderán).

No debería resultar difícil. Vamos a ver directamente una de las formas en que se podría plantear y luego comentaremos alguna de las mejoras que se podría (incluso se debería) hacer.

Una opción que podemos a tomar para resolver este problema es la de contar el número de archivos que tenemos almacenados, y así podremos añadir de uno en uno. 

Si tenemos 0 archivos, deberemos almacenar la siguiente (la primera) en la posición 0; si tenemos dos archivos, serán la 0 y la 1, luego añadiremos en la posición 2; en general, si tenemos “n” archivos, añadiremos cada nueva ficha en la 
posición “n”. Por otra parte, para revisar todas las archivos, recorreremos desde la posición 0 hasta la n-1, haciendo algo como:
for (i=0; i<=n-1; i++) { //... más órdenes ... }

O algo como:
for (i=0; i<n; i++) { //... más órdenes ... }

El resto del programa no es difícil: sabemos leer y comparar textos y números. 
Sólo haremos dos consideraciones:
         -No se comportará correctamente si los textos (nombre del archivo, por ejemplo) contienen espacios, porque aún no sabemos leer textos con espacios.
         -Hemos limitado el número de archivos a 1000, así que, si nos piden añadir, deberíamos asegurarnos antes de que todavía tenemos hueco disponible.
*/
//--Bibliotecas--
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

//--CleanScreen-- Leí que es un comando para que limpie en linux (apple utiliza el mismo comando) y que el _WIN32 lo adapta a windows

#ifdef _WIN32
  #include<windows.h>
#endif  

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

//---Variables--
int n = 0;
std::ofstream save;
//----Struct----
struct File
{
	std::string name;
	unsigned long size;
}files[1000];
//-Declaraciones-
void howManyFiles();

void rechargeNames();

void saveNames();

void newFile();

void showNames();

void showMoreThan();

void oneFileData();

void menu();

//----Main-----
int main()
{
	howManyFiles();
	rechargeNames();
	menu();
	
	return 0;
}
//----Aux------
void howManyFiles()
{
	if(n == 0)
	{
		std::string num;
    		std::ifstream arch;
		arch.open("contador.txt");
		getline(arch, num, '\n');
		arch.close();
		n = atoi( num.c_str() );
	}
}

void rechargeNames()
{
	std::ifstream archi, fil;
	std::string auxName, auxSize, trash;
	
	archi.open("fileNames.txt");
	for(int i = 0; i < n; i++)
	{
		getline(archi, auxName);
		files[i].name = auxName;
		fil.open(files[i].name + ".txt");
		getline(fil, trash, '\n');
		getline(fil, auxSize, '\n');
		files[i].size = std::stoul(auxSize, nullptr, 0);
		fil.close();
	}
	archi.close();
}

void saveNames()
{
	save.open("fileNames.txt");
	for(int i = 0; i < n; i++)
	{
		save << files[i].name << std::endl;
	}
	save.close();
		
}
//----Menu-----
void menu()
{
	int opc;
	
	do
	{
		limpiar_pantalla();
		saveNames();
		
		std::cout << "File store app \t\t\t|By: A. Agustin, N. Souto|" << std::endl << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "1. Agregar datos de un nuevo archivo." << std::endl;
		std::cout << "2. Mostrar los nombres de todos los archivos almacenados." << std::endl;
		std::cout << "3. Mostrar archivos que sean de mas de un cierto tamaño (por ejemplo, 2000 KB)." << std::endl;
		std::cout << "4. Ver todos los datos de un cierto archivo (a partir de su nombre)." << std::endl;
		std::cout << "5. Salir de la aplicacion." << std::endl << std::endl;
		std::cout << "Opcion: ";
		std::cin >> opc;
		
		switch(opc)
		{
			case 1:
				newFile();
				break;
			case 2:
				showNames();
				break;
			case 3:
				showMoreThan();
				break;
			case 4:
				oneFileData();
				break;
			case 5:
				std::cout << "\nBye!" << std::endl;
				break;
		}
		
	}while(opc < 1 || opc > 5);
}
//----Opcs-----
void newFile()
{	
	
	std::ofstream archivo;
	
	std::cin.ignore();
	
	if(n == 1000)
	{
		std::cout << "\nNumero maximo de archivos alcanzado." << std::endl;
	}else
	{
		std::cout << "\nIngrese el nombre del archivo: ";
		getline(std::cin, files[n].name);
		std::cout << "Ingrese el tamanio del archivo (en KB): ";
		std::cin >> files[n].size;
		
		archivo.open(files[n].name + ".txt");
		archivo << files[n].name << std::endl << files[n].size;
		archivo.close();
		
		n++;
		
		archivo.open("contador.txt");
		archivo << n;
		archivo.close();
		
		std::cout << "\nCARGA COMPLETA!" << std::endl;
	}
	
	std::cin.get();
	std::cin.ignore();
	menu();
}

void showNames()
{
	std::ifstream arc;
	std::cout << "\nMostrando nombres..." << std::endl << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::cout << files[i].name << std::endl;
	}
	std::cin.get();
	std::cin.ignore();
	menu();
}

void showMoreThan()
{
	unsigned long howMuch, auxSize;
	std::string aux, aux2;
	std::ifstream arc;
	
	std::cout << "\nIngrese un tamanio en KBs: ";
	std::cin >> howMuch;
	std::cout << "\nMostrando archivos mayores a " << howMuch << " KBs..." << std::endl << std::endl;
	for(int i = 0; i < n; i++)
	{
		arc.open(files[i].name+".txt");
		getline(arc, aux);
		getline(arc, aux2);
		auxSize = std::stoul(aux2,nullptr,0);
		arc.close();
		if(auxSize >= howMuch)
		{
			std::cout << "Name: " << aux << "\nSize: " << auxSize << std::endl << std::endl;
		}
	}
	
	std::cin.get();
	std::cin.ignore();
	menu();
}

void oneFileData()
{
	std::cin.ignore();
	std::string searchName;
	bool found = false;
	
	std::cout << "\nIngrese el nombre del archivo que desea buscar: ";
	getline(std::cin, searchName);
	
	for(int i = 0; i < n; i++)
	{
		if(searchName == files[i].name)
		{
			std::cout << "\nName: " << files[i].name << "\nSize: " << files[i].size << std::endl;
			found = true;
		}
	}
	
	if(found == false)
	{
		std::cout << "\nArchivo no encontrado!";
	}
	
	std::cin.get();
	std::cin.ignore();
	menu();
}
