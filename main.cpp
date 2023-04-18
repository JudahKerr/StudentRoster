#include "roster.h"

int main()
{

    const int numStudents = 5;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    cout << "Class Roster Program for WGU C867" << std::endl;
    cout << "Language used: C++" << std::endl;
    cout << "Student ID: 010608610" << std::endl;
    cout << "By Judah Kerr" << std::endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    Roster classRoster;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    cout << "Invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    cout << "Average number of days in 3 courses:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.getStudents()[i]->getID());
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    cout << "Filtering by Degree Program: SOFTWARE" << std::endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    cout << "Removing Student with ID: A3" << std::endl;
    classRoster.remove("A3");
    classRoster.remove("A3");

    return 0;
}