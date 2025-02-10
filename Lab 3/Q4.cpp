#include <iostream>
using namespace std;

class Employee{
    public :
    string firstName;
    string lastName;
    double salary;
};

int main(){
    Employee emp1, emp2;

    cout << "Enter firstName, lastName and monthly salary for 1st employee : " << endl;
    cin >> emp1.firstName >> emp1.lastName >> emp1.salary;

    cout << "Enter firstName, lastName and monthly salary for 2nd employee : " << endl;
    cin >> emp2.firstName >> emp2.lastName >> emp2.salary;

    if (emp1.salary < 0){
        emp1.salary = 0;
    }
    if ( emp2.salary < 0){
        emp2.salary = 0;
    }

    cout << "Yearly salary for 1st employee is : " << emp1.salary * 12 << endl << "After 10% raise : " << (emp1.salary  + (emp1.salary * 0.1)) * 12 << endl;
    cout << "Yearly salary for 2nd employee is : " << emp2.salary * 12 << endl << "After 10% raise : " << (emp2.salary + (emp2.salary * 0.1)) * 12 << endl;
}