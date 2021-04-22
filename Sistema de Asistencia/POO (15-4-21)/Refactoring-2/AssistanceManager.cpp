// Assistance Class App //
// Student: Nuñez Souto, A. Agustín //

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>


// -----Clear Screen----- //
#ifdef _WIN32
  #include<windows.h>
#endif  

void limpiar(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}


// -----Student----- //
class Student{
	private:
		int identifier;
		std::string name;
		std::string surname;
	public:
		Student(){};
		Student(int identifier, std::string name, std::string surname){
			setIdentifier(identifier);
			setName(name);
			setSurname(surname);	
		};
		~Student(){};
		void setIdentifier(int identifier){
			this->identifier = identifier;
		};
		void setName(std::string name){
			this->name = name;
		};
		void setSurname(std::string surname){
			this->surname = surname;
		};
		int getIdentifier(){
			return this->identifier;
		};
		std::string getName(){
			return this->name;
		};
		std::string getSurname(){
			return this->surname;
		};
};


// -----Course----- //
class Course{
	private:
		int identifier;
		std::string name;
		std::vector<int> studentsId;
	public:
		Course(){};
		Course(int identifier, std::string name){
			setIdentifier(identifier);
			setName(name);	
		};
		~Course(){};
		void setIdentifier(int identifier){
			this->identifier = identifier;
		};
		void setName(std::string name){
			this->name = name;
		};
		int getIdentifier(){
			return this->identifier;
		};
		std::string getName(){
			return this->name;
		};
		void addStudent(int id){
			this->studentsId.push_back(id);
		}
};


// -----StudentMapper----- //
class StudentMapper{
	private:
		std::vector<Student> students;
	public:
		StudentMapper(){};
		~StudentMapper(){};
		bool insert(Student student){
			this->students.push_back(student);
			return true;
		};
		bool update(int identifier){
			bool modify = false;
			std::string aux;
			for(int i = 0; i < this->students.size(); i++){
				if(this->students[i].getIdentifier() == identifier){
					std::cout << this->students[i].getIdentifier() << " || " << this->students[i].getName() << " || " << this->students[i].getSurname() << std::endl;
					std::cout << "Change Name? [If don't enter '0']: ";
					getline(std::cin, aux);
					if(aux != "0"){
						this->students[i].setName(aux);
						modify = true;
					}
					std::cout << "Change Surname? [If don't enter '0']: ";
					getline(std::cin, aux);
					if(aux != "0"){
						this->students[i].setSurname(aux);
						modify = true;
					}
				}
			}
			
			return modify;
		};
		
		bool del(int identifier){
			int aux;
			bool found = false;
			for(int i = 0; i < this->students.size(); i++){
				if(this->students[i].getIdentifier() == identifier){
					aux = i;
					found = true;
				}
			}
			if(found){
				this->students.erase(this->students.begin() + aux);
			}
			return found;
		};
		
		void show(){
			for(int i = 0; i < this->students.size(); i++){
				std::cout << this->students[i].getIdentifier() << " || " << this->students[i].getName() << " || " << this->students[i].getSurname() << std::endl;
			}
		}
		
		std::vector<Student> getStudentsList(){
			return this->students;
		}
};


// -----CourseMapper----- //
class CourseMapper{
	private:
		std::vector<Course> courses;
	public:
		CourseMapper(){};
		~CourseMapper(){};
		
		bool insert(Course course){
			this->courses.push_back(course);
			return true;
		};
		
		bool update(int identifier){
			bool modify = false;
			std::string aux;
			for(int i = 0; i < this->courses.size(); i++){
				if(this->courses[i].getIdentifier() == identifier){
					std::cout << this->courses[i].getIdentifier() << " || " << this->courses[i].getName() << std::endl;
					std::cout << "Change Name? [If don't enter '0']: ";
					getline(std::cin, aux);
					if(aux != "0"){
						this->courses[i].setName(aux);
						modify = true;
					}
				}
			}
			
			return modify;
		};
		
		bool del(int identifier){
			int aux;
			bool found = false;
			for(int i = 0; i < this->courses.size(); i++){
				if(this->courses[i].getIdentifier() == identifier){
					aux = i;
					found = true;
				}
			}
			if(found){
				this->courses.erase(this->courses.begin() + aux);
			}
			return found;
		};
		
		void show(){
			for(int i = 0; i < this->courses.size(); i++){
				std::cout << this->courses[i].getIdentifier() << " || " << this->courses[i].getName() << std::endl;
			}
		}
		
		std::vector<Course> getCoursesList(){
			return this->courses;
		}
};


// ----------------------- //
// -----Menu Section------ //
// ----------------------- //

// -----Menu----- //
int menu(){
	int opc = 0;
	do{
		limpiar();
		std::cout << " Manager de Asistencia" << std::endl
				  << " ---------------------" << std::endl << std::endl 
				  << " Asistencia" << std::endl 
				  << "   1. Tomar Asistencia" << std::endl << std::endl 
				  << " Alumnos" << std::endl
				  << "   2. Ver lista de alumnos" << std::endl
				  << "   3. Agregar alumno" << std::endl
				  << "   4. Modificar alumno" << std::endl
				  << "   5. Eliminar alumno" << std::endl << std::endl
				  << " Cursos" << std::endl
				  << "   6. Ver lista de cursos" << std::endl
				  << "   7. Agregar curso" << std::endl
				  << "   8. Modificar curso" << std::endl
				  << "   9. Eliminar curso" << std::endl << std::endl
				  << " Otras opciones" << std::endl
				  << "   10. Cambiar fecha" << std::endl
				  << "   11. Salir" << std::endl << std::endl
				  << " Opcion: ";
		std::cin >> opc;
		if(opc < 1 || opc > 11){
			std::cout << " Opcion invalida." << std::endl;
			std::cin.get();
			std::cin.ignore();
		}
	}while(opc < 1 || opc > 11);
	return opc;
}

// -----Return To Menu----- //
void returnMenu(){
	std::string opc;
	std::cout << " Regresar al menu? [Si : 1 | No : Cualquier tecla]: ";
	getline(std::cin, opc);
	if(opc == "1"){
		menu();	
	}else{
		std::cout << "\n Hasta pronto!" << std::endl;
	}
}


// --------------------------- //
// -----AssistanceManager----- //
// --------------------------- //
void AssistanceManager(){
	
	int day, month, year;
	int action;
	
	std::vector<Student> *studentList = new std::vector<Student>();
	std::vector<Course> *courseList = new std::vector<Course>();
	
	// ... Load Data ... //
	std::ifstream loadStudents;
	std::ifstream loadCourses;
	
	loadStudents.open("students.txt");
	if(loadStudents.is_open()){
		std::string loadAux;
		do{
			Student *student = new Student();
			std::getline(loadStudents, loadAux);
			student->setIdentifier(std::stoi(loadAux));
			std::getline(loadStudents, loadAux);
			student->setName(loadAux);
			std::getline(loadStudents, loadAux);
			student->setSurname(loadAux);
			std::getline(loadStudents, loadAux);
			studentList->push_back(*student);
			delete student;
		}while(loadAux != "-end-");
		
		loadStudents.close();
	}
	
	loadCourses.open("courses.txt");
	if(loadCourses.is_open()){
		std::string loadAux;
		do{
			Course *course = new Course();
			std::getline(loadCourses, loadAux);
			course->setIdentifier(std::stoi(loadAux));
			std::getline(loadCourses, loadAux);
			course->setName(loadAux);
			std::getline(loadCourses, loadAux);
			if(loadAux != "" && loadAux != "-end-"){
				do{
					course->addStudent(std::stoi(loadAux));
					std::getline(loadCourses, loadAux);
				}while(loadAux != "" && loadAux != "-end-");
			}
			delete course;
			
		}while(loadAux != "-end-");
		loadCourses.close();
	}
	
	std::cout << " Bienvenido al Manager de Asistencia" << std::endl << std::endl
	 		  << " A continuacion se le pedira que ingrese la fecha que desee utilizar para la asistencia." << std::endl
			  << " Esta se podra modificar luego." << std::endl << std::endl
			  << " Anio: ";
	std::cin >> year;
	std::cout << " Mes: ";
	std::cin >> month;
	std::cout << " Dia: ";
	std::cin >> day;
	
	
	action = menu();
	
	switch(action){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
	}
	
	delete [] studentList;
	delete [] courseList;
	
	std::cin.get();
	std::cin.ignore();
}

// -------------- //
// -----Main----- //
// -------------- //
int main(){
	AssistanceManager();
	return 0;
}
