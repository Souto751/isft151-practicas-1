// Trabajo Práctico 1
// Práctica Profecional I
// Profesor: González Ferreira, Gabriel Nicolás
// Alumno: Nuñez Souto, Agustín

// Bibliotecas
#include <iostream>
#include <cstdlib>
#include <conio.h>

// Namespace
using namespace std;

// Estructuras
struct MP3{
	string artist;
	string title;
	int len;
	int mp3_size;
};

// Declaraciones de Funciones
void req_data();

// Función Main
int main(){
	req_data();
	
	cout << "\nEnter to continue...";
	getch();
	return 0;
}

// Funciones
void req_data(){
	int n, i = 0;
	
	cout << "> Welcome to the MP3 files program <" << "\t || Made by: Agustin N. Souto ||" << endl << endl;
	cout << "How many mp3 files do you want to enter?: ";
	cin >> n;
	
	MP3 list[n];
	
	do{
		if(system("cls"))system("clean");
		fflush(stdin);
		cout << ".MP3 Title: ";
		getline(cin, list[i].title);
		cout << ".Artist: ";
		getline(cin, list[i].artist);
		cout << ".Duration (in seconds): ";
		cin >> list[i].len;
		cout << ".Size (in kbs): ";
		cin >> list[i].mp3_size;
		cout << "\nEnter to continue...";
		getch();
		i++;
	}while(i < n);
	
	if(system("cls"))system("clean");
	cout << "|Title" << "\t\t\t\t|Artist" << "\t\t\t\t|Duration (sec)" << "\t\t\t|Size (kbs)" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < n; i++){
		cout << "|" << list[i].title << "\t\t\t\t|" << list[i].artist << "\t\t\t\t|" << list[i].len << "\t\t\t\t|" << list[i].mp3_size << endl;
	}
}
	
