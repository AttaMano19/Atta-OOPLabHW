#include <iostream>
using namespace std;


class User {
    public :
    int Age;
    string Name;

};


int main(){
    User user;

    user.Name = "Teo";
    user.Age = 24;

    cout << "My Name is " << user.Name << " and I'm " << user.Age << " years old";
}