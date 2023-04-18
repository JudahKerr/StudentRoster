#pragma once
#include "student.h"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student *classRosterArray[numStudents] = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:
    Roster();

    Student **getStudents();
    void parse(string row);
    void add(string ID, string firstName, string lastName, string email, string age, int days1, int days2, int days3, DegreeProgram dp);
    void printAll();
    void printAverageDaysInCourse(string ID);
    void remove(string ID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    ~Roster(); // Destructor
};