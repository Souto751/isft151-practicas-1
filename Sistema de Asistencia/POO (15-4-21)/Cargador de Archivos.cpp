// Assistance Class App //
// Student: Nuñez Souto, A. Agustín //

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>

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



// -----AssistanceManager----- //
void AssistanceManager(){
	
	int day = 20, month = 4, year = 2021;
	StudentMapper* sMapper = new StudentMapper();
	CourseMapper* cMapper = new CourseMapper();
	std::ofstream studentsFile;
	std::ofstream coursesFile;
	std::ofstream assistanceFile;
	
	srand((unsigned int) time (NULL));
	
	Student* st1 = new Student(1, "Agustin", "Souto");
	Student* st2 = new Student(2, "Melissa", "Ali");
	Student* st3 = new Student(3, "Aaron", "Nuñez");
	Course* c1 = new Course(1, "Analisis Matematico");
	Course* c2 = new Course(2, "Algebra");
	Course* c3 = new Course(3, "Practicas Profesionalizantes I");
	
	sMapper->insert(*st1);
	sMapper->insert(*st2);
	sMapper->insert(*st3);
	cMapper->insert(*c1);
	cMapper->insert(*c2);
	cMapper->insert(*c3);
	
	std::vector<Student> students = sMapper->getStudentsList();
	std::vector<Course> courses = cMapper->getCoursesList();
	
	
	// ----- Students File ----- //
	studentsFile.open("students.txt");
	
	studentsFile << "Students" << std::endl << std::endl;
	studentsFile << "||------------------------------------------------------||" << std::endl;
	studentsFile << "||"<< std::setw(5) << "ID" << " || " << std::setw(20) << "Name" << " || " << std::setw(20) << "Surname" << " ||" << std::endl;
	studentsFile << "||------------------------------------------------------||" << std::endl;
	for(int i = 0; i < students.size(); i++){
		studentsFile << "||" << std::setw(5) << students[i].getIdentifier() << " || " << std::setw(20) << students[i].getName() << " || " << std::setw(20) << students[i].getSurname() << " ||" << std::endl;
	}
	studentsFile << "||------------------------------------------------------||" << std::endl;
	
	studentsFile.close();
	
	// ----- Courses File ----- //
	coursesFile.open("courses.txt");
	
	coursesFile << "Courses" << std::endl << std::endl;
	coursesFile << "||-------------------------------------------||" << std::endl;
	coursesFile << "||"<< std::setw(3) << "ID" << " || " << std::setw(35) << "Course" << " ||" << std::endl;
	coursesFile << "||-------------------------------------------||" << std::endl;
	for(int i = 0; i < courses.size(); i++){
		coursesFile << "||" << std::setw(3) << courses[i].getIdentifier() << " || " << std::setw(35) << courses[i].getName() << " ||" << std::endl;
	}
	coursesFile << "||-------------------------------------------||" << std::endl;
	
	coursesFile.close();
	
	// ----- Assistance File ----- //
	assistanceFile.open("assistance.txt");
	
	assistanceFile << "Assistance" << std::endl << std::endl;
	for(int i = 0; i < courses.size(); i++){
		assistanceFile << "||------------------------------------------------------------------||" << std::endl;
		assistanceFile << "||" << std::setw(35) << courses[i].getName() << " || " << std::setw(16) << "Date: " << std::setw(2) << day << "/" << std::setw(2) << month << "/" << std::setw(4) << year << std::setw(4) << " || " << std::endl;
		assistanceFile << "||------------------------------------------------------------------||" << std::endl;
		assistanceFile << "||" << std::setw(5) << "ID" << std::setw(4) << " || " << std::setw(20) << "Name" << std::setw(4) << " || " << std::setw(20) << "Surname" << std::setw(4) << " || " << std::setw(8) << "Present" << std::setw(4) << " || " << std::endl;
		assistanceFile << "||------------------------------------------------------------------||" << std::endl;
		for(int j = 0; j < students.size(); j++){
			int random = rand()%2;
			bool present;
			std::string presentString;
			
			random == 0 ? present = true : present = false;
			present == true ? presentString = "Yes" : presentString = "No";
			
			assistanceFile << "||" << std::setw(5) << students[j].getIdentifier() << std::setw(4) << " || " << std::setw(20) << students[j].getName() << std::setw(4) << " || " << std::setw(20) << students[j].getSurname() << std::setw(4) << " || " << std::setw(8) << presentString << std::setw(4) << " || " << std::endl;
		}
		assistanceFile << "||------------------------------------------------------------------||" << std::endl;
		assistanceFile << std::endl << std::endl;
	}
	
	assistanceFile.close();
	
	
	delete c1, c2, c3;
	delete cMapper;
	
	delete st1, st2, st3;
	delete sMapper;
	
}

// -----Main----- //
int main(){
	AssistanceManager();
	return 0;
}
