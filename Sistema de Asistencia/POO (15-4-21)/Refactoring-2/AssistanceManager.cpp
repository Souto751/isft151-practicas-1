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

void clearScreen(){
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
		
		~StudentMapper(){
			std::ofstream saveStudents;
			saveStudents.open("students.txt");
			for(int i = 0; i < students.size(); i++){
				saveStudents << students[i].getIdentifier() << std::endl;
				saveStudents << students[i].getSurname() << std::endl;
				saveStudents << students[i].getName() << std::endl;
				if(i == students.size() - 1){
					saveStudents << "-end-";
				}else{
					saveStudents << std::endl;
				}
			}
			saveStudents.close();
		};
		
		bool insert(Student student){
			this->students.push_back(student);
			return true;
		};
		
		bool update(int identifier){
			bool modify = false;
			std::string aux;
			for(int i = 0; i < this->students.size(); i++){
				if(this->students[i].getIdentifier() == identifier){
					std::cout << "\n " << this->students[i].getIdentifier() << " || " << this->students[i].getName() << " || " << this->students[i].getSurname() << std::endl;
					std::cout << " Nombre [Para no cambiar: 0]: ";
					getline(std::cin, aux);
					if(aux != "0"){
						this->students[i].setName(aux);
						modify = true;
					}
					std::cout << " Apellido [Para no cambiar: 0]: ";
					getline(std::cin, aux);
					if(aux != "0"){
						this->students[i].setSurname(aux);
						modify = true;
					}
					
					std::cout << " Datos del alumno modificados" << std::endl;
					std::cin.get();
					std::cin.ignore();
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
		
		~CourseMapper(){
			std::ofstream saveCourses;
			saveCourses.open("courses.txt");
			for(int i = 0; i < courses.size(); i++){
				saveCourses << courses[i].getIdentifier() << std::endl;
				saveCourses << courses[i].getName() << std::endl;
				for(int j = 0; j < courses[i].getStudentsId().size(); j++){
					saveCourses << courses[i].getStudentsId()[j] << std::endl;
				}
				if(i == courses.size() - 1){
					saveCourses << "-end-";
				}else{
					saveCourses << std::endl;
				}
			}
			saveCourses.close();
		};
		
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
		clearScreen();
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
				std::ofstream saveAssistance;
				do{
					clearScreen();
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
					saveAssistance.open("assistance.txt", std::ios::app);
					if(cmppr->getCoursesList()[selectCourse].getStudentsId().size() > 0){
						int present;
						clearScreen();
						std::cout << " " << cmppr->getCoursesList()[selectCourse].getName() << std::endl << std::endl;
						saveAssistance << "[" << day << " / " << month << " / " << year << "] || " << cmppr->getCoursesList()[selectCourse].getName() << std::endl;
						for(int i = 0; i < cmppr->getCoursesList()[selectCourse].getStudentsId().size(); i++){
							std::cout << "   " << i+1 << ". " << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getSurname() << ", " << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getName() << " | Presente [Si: 1 | No: 0]: ";
							std::cin >> present;
							std::cout << std::endl;
							saveAssistance << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getIdentifier() << " || "
										   << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getSurname() << ", "
										   << smppr->getStudentsList()[cmppr->getCoursesList()[selectCourse].getStudentsId()[i]-1].getName() << " || ";
							if(present == 1){
								saveAssistance << "Presente" << std::endl;
							}else if(present == 0){
								saveAssistance << "Ausente" << std::endl;
							}else{
								saveAssistance << "Error" << std::endl;
							}
						}
						
						saveAssistance << std::endl;
						
					}else{
						std::cout << " No hay alumnos en este curso" << std::endl;
						std::cin.get();
						std::cin.ignore();
					}
					saveAssistance.close();
				}
				AssistanceManager();
			}else{
				clearScreen();
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 2:
			if(smppr->getStudentsList().size() > 0){
				clearScreen();
				std::cout << " Mostrar Lista de Alumnos" << std::endl << std::endl;
				for(int i = 0; i < smppr->getStudentsList().size(); i++){
					std::cout << "   " << smppr->getStudentsList()[i].getIdentifier() << ". " << smppr->getStudentsList()[i].getSurname() << ", " << smppr->getStudentsList()[i].getName() << std::endl;
				}
				
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}else{
				clearScreen();
				std::cout << " No hay alumnos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 3:
			{
				Student newStudent;
				std::string inputAux;
				if(smppr->getStudentsList().size() > 0){
					newStudent.setIdentifier(smppr->getStudentsList()[smppr->getStudentsList().size() - 1].getIdentifier() + 1);
				}else{
					newStudent.setIdentifier(1);
				}
				
				clearScreen();
				
				std::cout << " Agregar nuevo alumno" << std::endl << std::endl
						  << "   . Nombre: ";
				getline(std::cin, inputAux);
				newStudent.setName(inputAux);
				std::cout << "   . Apellido: ";
				getline(std::cin, inputAux);
				newStudent.setSurname(inputAux);
				smppr->insert(newStudent);
				
				std::cout << " Alumno agregado" << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 4:
			clearScreen();
			if(smppr->getStudentsList().size() > 0){
				bool studentExists = false;
				int idToUpdate;
				std::string confirmUpdate;
				std::cout << " Modificar datos de Alumno" << std::endl << std::endl;
				for(int i = 0; i < smppr->getStudentsList().size(); i++){
					std::cout << " " << smppr->getStudentsList()[i].getIdentifier() << ". " << smppr->getStudentsList()[i].getSurname() << ", " << smppr->getStudentsList()[i].getName() << std::endl;
				}
				
				std::cout << "\n Ingrese el ID del alumno a modificar: ";
				std::cin >> idToUpdate;
				
				for(int i = 0; i < smppr->getStudentsList().size(); i++){
					if(idToUpdate == smppr->getStudentsList()[i].getIdentifier()){
						std::cin.ignore();
						studentExists = true;
						idToUpdate = i;
					}
				}
				
				if(studentExists == true){
					std::cout << "\n   " << smppr->getStudentsList()[idToUpdate].getIdentifier() << ". " << smppr->getStudentsList()[idToUpdate].getSurname() << ", " << smppr->getStudentsList()[idToUpdate].getName() << std::endl << std::endl;
					std::cout << " Ingrese 1 para modificar el alumno, de lo contrario se retornara al menu: ";
					getline(std::cin, confirmUpdate);
					if(confirmUpdate == "1"){
						smppr->update(smppr->getStudentsList()[idToUpdate].getIdentifier());
						AssistanceManager();
					}else{
						AssistanceManager();
					}
				}else{
					std::cout << "\n El ID no corresponde a ningun alumno, se retornara al menu." << std::endl;
					std::cin.get();
					std::cin.ignore();
				}
			}else{
				std::cout << " No hay alumnos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 5:
			clearScreen();
			if(smppr->getStudentsList().size() > 0){
				bool studentExists = false;
				int idToDelete;
				std::string confirmDelete;
				std::cout << " Eliminar Alumno" << std::endl << std::endl;
				for(int i = 0; i < smppr->getStudentsList().size(); i++){
					std::cout << " " << smppr->getStudentsList()[i].getIdentifier() << ". " << smppr->getStudentsList()[i].getSurname() << ", " << smppr->getStudentsList()[i].getName() << std::endl;
				}
				
				std::cout << "\n Ingrese el ID del alumno a eliminar: ";
				std::cin >> idToDelete;
				
				for(int i = 0; i < smppr->getStudentsList().size(); i++){
					if(idToDelete == smppr->getStudentsList()[i].getIdentifier()){
						std::cin.ignore();
						studentExists = true;
						idToDelete = i;
					}
				}
				
				if(studentExists == true){
					std::cout << "\n   " << smppr->getStudentsList()[idToDelete].getIdentifier() << ". " << smppr->getStudentsList()[idToDelete].getSurname() << ", " << smppr->getStudentsList()[idToDelete].getName() << std::endl << std::endl;
					std::cout << " Ingrese 1 para eliminar el alumno, de lo contrario se retornara al menu: ";
					getline(std::cin, confirmDelete);
					if(confirmDelete == "1"){
						smppr->del(smppr->getStudentsList()[idToDelete].getIdentifier());
						AssistanceManager();
					}else{
						AssistanceManager();
					}
				}else{
					std::cout << "\n El ID no corresponde a ningun alumno, se retornara al menu." << std::endl;
					std::cin.get();
					std::cin.ignore();
				}
				
			}else{
				std::cout << " No hay alumnos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 6:
			if(cmppr->getCoursesList().size() > 0){
				clearScreen();
				std::cout << " Mostrar Lista de Cursos" << std::endl << std::endl;
				for(int i = 0; i < cmppr->getCoursesList().size(); i++){
					std::cout << "   . " << cmppr->getCoursesList()[i].getName() << std::endl;
				}
				
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}else{
				clearScreen();
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 7:
			{
				Course newCourse;
				std::string inputAux;
				if(cmppr->getCoursesList().size() > 0){
					newCourse.setIdentifier(cmppr->getCoursesList()[cmppr->getCoursesList().size() - 1].getIdentifier() + 1);
				}else{
					newCourse.setIdentifier(1);
				}
				
				clearScreen();
				std::cin.ignore();
				std::cout << " Agregar nuevo curso" << std::endl << std::endl
						  << "   . Nombre: ";
				getline(std::cin, inputAux);
				newCourse.setName(inputAux);
				cmppr->insert(newCourse);
				
				std::cout << " Curso agregado" << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 8:
			clearScreen();
			if(cmppr->getCoursesList().size() > 0){
				bool courseExists = false;
				int idToUpdate;
				std::string confirmUpdate;
				std::cout << " Modificar datos de Curso" << std::endl << std::endl;
				for(int i = 0; i < cmppr->getCoursesList().size(); i++){
					std::cout << " " << cmppr->getCoursesList()[i].getIdentifier() << ". " << cmppr->getCoursesList()[i].getName() << std::endl;
				}
				
				std::cout << "\n Ingrese el ID del curso a modificar: ";
				std::cin >> idToUpdate;
				
				for(int i = 0; i < cmppr->getCoursesList().size(); i++){
					if(idToUpdate == cmppr->getCoursesList()[i].getIdentifier()){
						std::cin.ignore();
						courseExists = true;
						idToUpdate = i;
					}
				}
				
				if(courseExists == true){
					std::cout << "\n   " << cmppr->getCoursesList()[idToUpdate].getIdentifier() << ". " << cmppr->getCoursesList()[idToUpdate].getName() << std::endl << std::endl;
					std::cout << " Ingrese 1 para modificar el curso, de lo contrario se retornara al menu: ";
					getline(std::cin, confirmUpdate);
					if(confirmUpdate == "1"){
						cmppr->update(cmppr->getCoursesList()[idToUpdate].getIdentifier());
						AssistanceManager();
					}else{
						AssistanceManager();
					}
				}else{
					std::cout << "\n El ID no corresponde a ningun curso, se retornara al menu." << std::endl;
					std::cin.get();
					std::cin.ignore();
				}
			}else{
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 9:
			clearScreen();
			if(cmppr->getCoursesList().size() > 0){
				bool courseExists = false;
				int idToDelete;
				std::string confirmDelete;
				std::cout << " Eliminar Curso" << std::endl << std::endl;
				for(int i = 0; i < cmppr->getCoursesList().size(); i++){
					std::cout << " " << cmppr->getCoursesList()[i].getIdentifier() << ". " << cmppr->getCoursesList()[i].getName() << std::endl;
				}
				
				std::cout << "\n Ingrese el ID del curso a eliminar: ";
				std::cin >> idToDelete;
				
				for(int i = 0; i < cmppr->getCoursesList().size(); i++){
					if(idToDelete == cmppr->getCoursesList()[i].getIdentifier()){
						std::cin.ignore();
						courseExists = true;
						idToDelete = i;
					}
				}
				
				if(courseExists == true){
					std::cout << "\n   " << cmppr->getCoursesList()[idToDelete].getIdentifier() << ". " << cmppr->getCoursesList()[idToDelete].getName() << std::endl << std::endl;
					std::cout << " Ingrese 1 para eliminar el curso, de lo contrario se retornara al menu: ";
					getline(std::cin, confirmDelete);
					if(confirmDelete == "1"){
						cmppr->del(cmppr->getCoursesList()[idToDelete].getIdentifier());
						AssistanceManager();
					}else{
						AssistanceManager();
					}
				}else{
					std::cout << "\n El ID no corresponde a ningun curso, se retornara al menu." << std::endl;
					std::cin.get();
					std::cin.ignore();
				}
			}else{
				std::cout << " No hay cursos cargados." << std::endl;
				std::cin.get();
				std::cin.ignore();
				AssistanceManager();
			}
			break;
		case 10:
			clearScreen();
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
	
	delete smppr;
	delete cmppr;
	return 0;
}
