#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


/**************************** Class Student ****************************/


class Student {
	
	string firstName;
	string lastName;
	int ID;
	double grade;
	
public:
	Student(int=0, string="", string="", double=0.0);
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);

	//getter & setter
	void setFirstName(string);
	void setLastName(string);
	void setID(int);
	void setGrade(double);
	
	string getFirstName() const;
	string getLastName() const;
	int getID() const;
	double getGrade() const;
};


	Student::Student(int id, string first, string last, double score) : ID(id), firstName(first), lastName(last), grade(score)
	{
		//empty
	}



	istream& operator>>(istream& input, Student& s) {
		int id;
		string first, last;
		double score;

		input >> id >> first >> last >> score;
		s.setFirstName(first);
		s.setLastName(last);
		s.setID(id);
		s.setGrade(score);
		
		return input;
	}

	ostream& operator<<(ostream& output, const Student& s) {
		output << s.getID() << ' ' << s.getFirstName() << ' ' << s.getLastName() << ' ' << s.getGrade() << endl;
		return output;
	}





		// getter & setter
	void Student::setFirstName(string first) {firstName = first;}
	void Student::setLastName(string last)	 {lastName = last;}
	void Student::setID(int id) 			 {ID = id;}
	void Student::setGrade(double score)	 {grade = score;}

	string Student::getFirstName() const 	 {return firstName;}
	string Student::getLastName() const 	 {return lastName;}
	int Student::getID() const 				 {return ID;}
	double Student::getGrade() const 		 {return grade;}


/**************************** Class Student End ****************************/



void saveGrades(ofstream&);
void displayGrades(ifstream&);

int main() {
	
	// saving grades
	string fileName;
	cout << "Enter a name for the file: ";
	cin >> fileName;
	
	ofstream output(fileName, ios::out);
	if (!output) {              // confirm the file is available
		cerr << "File \"" << fileName << "\" could not be opened." << endl;
		exit(1);
	}
	saveGrades(output);
	output.close();
	
	
	// output grades
	cin.clear();
	cout << "Enter a file name: ";
	cin >> fileName;
	
	ifstream input(fileName, ios::in);
	if (!input) {               // confirm the file is available
		cerr << "File \"" << fileName << "\" could not be opened." << endl;
		exit(1);
	}
	displayGrades(input);
	input.close();
	
}



void saveGrades(ofstream& output) {
	Student temp;
	cout << "Enter the records of students (input Ctrl+Z to end):" << endl;
	while (cin >> temp) {
		output << temp;
	}
}

void displayGrades(ifstream& input) {
	Student temp;
	double sumOfGrades = 0.0;       // class grade summary
	unsigned numOfStudents = 0;     // class student count
	while (input >> temp) {
		sumOfGrades += temp.getGrade();
		++numOfStudents;
		cout << temp;
	}
	cout << "Class average: " << sumOfGrades / numOfStudents << endl;
}
