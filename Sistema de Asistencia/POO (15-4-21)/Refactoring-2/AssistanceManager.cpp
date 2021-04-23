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
		std::vector<int> getStudentsId(){
			return this->studentsId;
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

// -----Global Variable----- //
bool firstLoad = true;
int day, month, year;
CourseMapper *cmppr = new CourseMapper();
StudentMapper *smppr = new StudentMapper();

// -----Menu----- //
int menu(){
	int opc = 0;
	do{
		limpiar();
		std::cout << " Manager de Asistencia" << std::endl
				  << " ---------------------" << std::endl << std::endl 
				  << "[ " << day << " / " << month << " / " << year << " ]" << std::endl << std::endl
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

// --------------------------- //
// -----AssistanceManager----- //
// --------------------------- //
void AssistanceManager(){
	
	int action;
	
	if(firstLoad == true){
	
		// ... Load Data ... //
		std::ifstream loadStudents;
		std::ifstream loadCourses;
		
		loadStudents.open("students.txt");
		if(loadStudents.is_open()){
			std::string loadAux;
			do{
				Student student;
				std::getline(loadStudents, loadAux);
				student.setIdentifier(std::stoi(loadAux));
				std::getline(loadStudents, loadAux);
				student.setName(loadAux);
				std::getline(loadStudents, loadAux);
				student.setSurname(loadAux);
				std::getline(loadStudents, loadAux);
				smppr->insert(student);
			}while(loadAux != "-end-");
			
			loadStudents.close();
		}
		
		loadCourses.open("courses.txt");
		if(loadCourses.is_open()){
			std::string loadAux;
			do{
				Course course;
				std::getline(loadCourses, loadAux);
				course.setIdentifier(std::stoi(loadAux));
				std::getline(loadCourses, loadAux);
				course.setName(loadAux);
				std::getline(loadCourses, loadAux);
				if(loadAux != "" && loadAux != "-end-"){
					do{
						course.addStudent(std::stoi(loadAux));
						std::getline(loadCourses, loadAux);
					}while(loadAux != "" && loadAux != "-end-");
				}
				cmppr->insert(course);
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
			firstLoad = false;
	}
	
	action = menu();
	
	switch(action){
		case 1:
			if(cmppr->getCoursesList().size() > 0){
				int selectCourse;
				do{
					limpiar();
					std::cout << " Selecciona el curso al cual tomar asistencia:" << std::endl << std::endl;
					for(int i = 0 ; i < cmppr->getCoursesList().size() ; i++){
						std::cout << "   " << i+1 << ". " << cmppr->getCoursesList()[i].getName() << std::endl;
					}
					std::cout << "\n " << cmppr->getCoursesList().size()+1 << ". Volver al menu" << std::endl << std::endl;
					std::cout << "\n Opcion: ";
					std::cin >> selectCourse;
					if(selectCourse < 1 || selectCourse > cmppr->getCoursesList().size() +1){
						std::cout << "\n Opcion Invalida."<< std::endl;
						std::cin.get();
						std::cin.ignore();
					}
				}while(selectCourse < 1 || selectCourse > cmppr->getCoursesList().size() +1);
				
				selectCourse--;
				
				if(selectCourse == cmppr->getCoursesList().size()){
					AssistanceManager();
				}else{
					int present;
					limpiar();
					std::cout << " " << cmppr->getCoursesList()[selectCourse].getName() << std::endl << std::endl;
					for(int i = 0; i < cmppr->getCoursesList()[selectCourse].getStudentsId().size(); i++){
						std::cout << "   " << i+1 << ". " << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getSurname() << ", " << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getName() << " | Presente: ";
						std::cin >> present;
						std::cout << std::endl;
					}
				}
				AssistanceManager();
			}else{
				limpiar();
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
		case 2:
			if(smppr->getStudentsList().size() > 0){
				limpiar();
				std::cout << " Mostrar Lista de Alumnos" << std::endl << std::endl;
				for(int i = 0; i < smppr->getStudentsList().size(); i++){
					std::cout << "   " << smppr->getStudentsList()[i].getIdentifier() << ". " << smppr->getStudentsList()[i].getSurname() << ", " << smppr->getStudentsList()[i].getName() << std::endl;
				}
				
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}else{
				limpiar();
				std::cout << " No hay alumnos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 3:
			break;
		case 4:
			if(smppr->getStudentsList().size() > 0){
			}else{
				limpiar();
				std::cout << " No hay alumnos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 5:
			break;
		case 6:
			if(cmppr->getCoursesList().size() > 0){
				limpiar();
				std::cout << " Mostrar Lista de Cursos" << std::endl << std::endl;
				for(int i = 0; i < cmppr->getCoursesList().size(); i++){
					std::cout << "   . " << cmppr->getCoursesList()[i].getName() << std::endl;
				}
				
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}else{
				limpiar();
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 7:
			break;
		case 8:
			if(cmppr->getCoursesList().size() > 0){
			}else{
				limpiar();
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 9:
			break;
		case 10:
			limpiar();
			std::cout << " Cambiar Fecha" << std::endl << std::endl
					  << "   Anio: ";
			std::cin >> year;
			std::cout << "   Mes: ";
			std::cin >> month;
			std::cout << "   Dia: ";
			std::cin >> day;
			AssistanceManager();
			break;
		case 11:
			std::cout << "\n Hasta pronto!" << std::endl;
			std::cin.get();
			std::cin.ignore();
			break;
	}
}

// -------------- //
// -----Main----- //
// -------------- //
int main(){
	AssistanceManager();
	return 0;
}
