//GradeBook.cpp
#include "GradeBook.h"
#include <iostream>
using namespace std;

GradeBook::GradeBook(string courseName, string instructorName) {
	setCourseName(courseName);
	setInstructorName(instructorName);
}

void GradeBook::setCourseName(string name) {
	courseName = name;
}

string GradeBook::getCourseName() {
	return courseName;
}

void GradeBook::setInstructorName(string name) {
	instructorName = name;
}

string GradeBook::getInstructorName() {
	return instructorName;
}

void GradeBook::displayMessage() {
	cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
	cout << "This course is presented by: " << getInstructorName() << "." << endl;
}
//end GradeBook.cpp