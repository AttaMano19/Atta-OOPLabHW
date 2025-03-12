#include <iostream>
#include <string>
using namespace std;
class Vehicles
{
    protected:
    double price;
    public:
    Vehicles(double p):price(p){}
    void virtual display()
    {
        cout<<"Price: "<<price<<endl;
    }
};
class Car:public Vehicles
{
    protected:
    int seat;
    int ndoor;
    string ftype;
    public:
    Car(int s,int n,string ft,double p):seat(s),ndoor(n),ftype(ft),Vehicles(p){}
    void virtual display()override
    {
        cout<<"Seating capacity: "<<seat<<endl;
        cout<<"Number of doors: "<<ndoor<<endl;
        cout<<"Fuel Type: "<<ftype<<endl;
        Vehicles::display();
    }
};
class Audi:public Car
{
    string model;
    string type;
    public:
    Audi(int seat,int nd,string ft,double cost,string mod,string t):Car(seat,nd,ft,cost),model(mod),type(t){}
    void display()override
    {
        cout<<"Model: "<<model<<endl;
        cout<<"Type: "<<type<<endl;
        Car::display();   
    }
};
class Motorcycle:public Vehicles
{
    protected:
    int ncylinder;
    int ngear;
    int nwheels;
    public:
    Motorcycle(int nc,int ng,int nw,double p):ncylinder(nc),ngear(ng),nwheels(nw),Vehicles(p){}
    void virtual display()override
    {
        cout<<"Number of wheels: "<<nwheels<<endl;
        cout<<"Number of cylinders: "<<ncylinder<<endl;
        cout<<"Number of gears: "<<ngear<<endl;
        Vehicles::display();
    }
};
class Yamaha:public Motorcycle
{
    string make;
    string type;
    public:
    Yamaha(int nc,int ng, int nw,double cost,string mak,string t):Motorcycle(nc,ng,nw,cost),make(mak),type(t){}
    void display()override
    {
        cout<<"Make: "<<make<<endl;
        cout<<"Type: "<<type<<endl;
        Motorcycle::display();   
    }
};
int main()
{
    Audi a(5, 4, "Petrol", 60000, "A6", "Sedan");
    Yamaha y(2, 6, 2, 15000, "YZF-R1", "Sportbike");

    cout << "Audi Details:\n";
    a.display();
    cout << endl;

    cout << "Yamaha Details:\n";
    y.display();

    return 0;
}