#include "student.h"
#include <iomanip>

// default constructor
Student::Student()
{
    this->ID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = "";
    this->daysArray[0] = 0;
    this->daysArray[1] = 0;
    this->daysArray[2] = 0;
    this->degreeProgram = DegreeProgram::NETWORK;
}

// parameterized constructor
Student::Student(string ID, string firstName, string lastName, string email, string age, int daysArray[], DegreeProgram degreeProgram)
{
    this->ID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < 3; i++)
    {
        this->daysArray[i] = daysArray[i];
    };
    this->degreeProgram = degreeProgram;
}

// getters
string Student::getID()
{
    return this->ID;
}
string Student::getFirstName()
{
    return this->firstName;
}
string Student::getLastName()
{
    return this->lastName;
}

string Student::getEmail()
{
    return this->email;
}

string Student::getAge()
{
    return this->age;
}

const int *Student::getDaysArray()
{
    return this->daysArray;
}

DegreeProgram Student::getDegreeProgram()
{
    return this->degreeProgram;
}

// setters
void Student::setID(string ID)
{
    this->ID = ID;
}
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Student::setEmail(string email)
{
    this->email = email;
}
void Student::setAge(string age)
{
    this->age = age;
}
void Student::setDaysArray(const int daysArray[])
{
    for (int i = 0; i < 3; i++)
    {
        this->daysArray[i] = daysArray[i];
    };
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}

// Print Method
void Student::print()
{
    cout << setw(6) << this->ID;
    cout << setw(15) << "First Name: " << setw(12) << this->firstName;
    cout << setw(15) << "Last Name: " << setw(12) << this->lastName;
    cout << setw(15) << "Email: " << setw(25) << this->email;
    cout << setw(7) << "Age: " << setw(3) << this->age;
    cout << setw(17) << "daysInCourse: {";
    for (int i = 0; i < 3; i++)
    {
        cout << this->daysArray[i];
        if (i < 2) 
        {
            cout << ",";
        }
    }
    cout << "}" << setw(18) << "Degree Program: " << degreeProgramStrings[(int)this->degreeProgram];
    cout << endl;
}
