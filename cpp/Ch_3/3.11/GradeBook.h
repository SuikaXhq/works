//GradeBook.h
#include <string>
using namespace std;

class GradeBook
{
public:
	GradeBook(string, string);
	void setCourseName(string);
	string getCourseName();
	void setInstructorName(string);
	string getInstructorName();
	void displayMessage();
private:
	string courseName;
	string instructorName;
};
//end GradeBook.h