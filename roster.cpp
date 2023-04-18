#include "roster.h"

const string studentData[] = {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Judah,Kerr,mrjkerr87@gmail.com,25,12,20,10,SOFTWARE"};
const int numStudents = 5;

Roster::Roster()
{

    for (int i = 0; i < numStudents; i++)
    {
        parse(studentData[i]);
    }
}

Student **Roster::getStudents()
{
    return Roster::classRosterArray;
}

void Roster::parse(string studentData)
{
    DegreeProgram dp = DegreeProgram::NETWORK;
    if (studentData.back() == 'Y')
        dp = DegreeProgram::SECURITY;
    else if (studentData.back() == 'E')
        dp = DegreeProgram::SOFTWARE;
    int rhs = studentData.find(",");
    string ID = studentData.substr(0, rhs);
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string age = studentData.substr(lhs, rhs - lhs);

    int d[3];
    for (int i = 0; i < 3; i++)
    {
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        d[i] = stoi(studentData.substr(lhs, rhs - lhs));
    }

    add(ID, firstName, lastName, email, age, d[0], d[1], d[2], dp);
}

void Roster::add(string ID, string firstName, string lastName, string email, string age, int d1, int d2, int d3, DegreeProgram dp)
{
    int daysArray[3] = {d1, d2, d3};
    classRosterArray[++lastIndex] = new Student(ID, firstName, lastName, email, age, daysArray, dp);
    cout << "Student added to roster at row " << lastIndex + 1 << endl;
}

void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        Roster::classRosterArray[i]->print();
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp)
            classRosterArray[i]->print();
    }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string id = Roster::getStudents()[i]->getEmail();
        if (id.find(' ') != string::npos)
        {
            cout << id << " is invalid!" << endl;
        }
        else if (id.find('@') == string::npos || id.find('.') == string::npos)
        {
            cout << id << " is invalid!" << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string ID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == ID)
        {
            cout << ID << ": ";
            int total = classRosterArray[i]->getDaysArray()[0] + classRosterArray[i]->getDaysArray()[1] + classRosterArray[i]->getDaysArray()[2];
            cout << total / 3.0 << endl;
        }
    }
}

void Roster::remove(string ID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == ID)
        {
            success = true;
            Student *temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << ID << " removed." << endl;
        printAll();
    }
    else
    {
        cout << "Student " << ID << " was not found." << endl;
    }
}

Roster::~Roster()
{

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Removed memory for: " << classRosterArray[i]->getID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
