#include <iostream>
#include <iomanip>
#include "degree.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;

class Student
{
public:
    const static int daysArraySize = 3;

private: // Init variables
    string ID;
    string firstName;
    string lastName;
    string email;
    string age;
    int daysArray[daysArraySize];
    DegreeProgram degreeProgram;

public:        
    Student(); // default constructor

    Student(string ID, string firstName, string lastName, string email, string age, int daysArray[], DegreeProgram degreeProgram); // parameterized constructor

    // getters
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    string getAge();
    const int *getDaysArray();
    DegreeProgram getDegreeProgram();

    // setters
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(string age);
    void setDaysArray(const int daysArray[]);
    void setDegreeProgram(DegreeProgram degree);
    void print();
};