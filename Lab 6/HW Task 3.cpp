#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
protected:
    string fullName;
    int studentID;
public:
    Person(int id, string name) : fullName(name), studentID(id) {}
    virtual void showDetails()
    {
        cout << "Student Name: " << fullName << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

class Grades : public Person
{
protected:
    double programming;
    double circuits;
    double databases;
    int subjectCount;
public:
    Grades(string name, int id, double prog, double circ, double db) : Person(id, name), programming(prog), circuits(circ), databases(db), subjectCount(3) {}
    virtual void showDetails() override
    {
        Person::showDetails();
        cout << "Programming Marks: " << programming << endl;
        cout << "Circuits Marks: " << circuits << endl;
        cout << "Databases Marks: " << databases << endl;
    }
};

class Report : public Grades
{
private:
    double totalMarks;
    double averageMarks;
public:
    Report(string name, int id, double prog, double circ, double db) : Grades(name, id, prog, circ, db)
    {
        totalMarks = programming + circuits + databases;
        averageMarks = totalMarks / subjectCount;
    }
    void showDetails() override
    {
        Grades::showDetails();
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }
};

int main()
{
    vector<Report> studentRecords;
    studentRecords.push_back({"Atta", 101, 85.5, 78.0, 90.0});
    studentRecords.push_back({"Naheel", 102, 92.0, 81.5, 88.5});
    studentRecords.push_back({"Zamin", 103, 76.0, 84.5, 79.0});
    
    for (Report student : studentRecords)
    {
        cout << "------------------" << endl;
        student.showDetails();
    }
    return 0;
}
