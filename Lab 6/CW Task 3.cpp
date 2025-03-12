#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StaffMember 
{
protected:
    int employeeID;
    string fullName;
public:
    StaffMember(int id, string name) : employeeID(id), fullName(name) {}
    virtual ~StaffMember() {}
};

class OrderHandler 
{
public:
    virtual void processOrder(string order) = 0;
    virtual ~OrderHandler() {}
};

class OrderMaker 
{
public:
    virtual void createOrder(string order) = 0;
    virtual ~OrderMaker() {}
};

class BillingClerk 
{
public:
    virtual void produceBill(double amount) = 0;
    virtual ~BillingClerk() {}
};

class Server : public StaffMember, public OrderHandler 
{
public:
    Server(int id, string name) : StaffMember(id, name) {}
    void processOrder(string order) override 
    {
        cout << "Server " << fullName << " is processing order: " << order << endl;
    }
};

class Cook : public StaffMember, public OrderMaker 
{
public:
    Cook(int id, string name) : StaffMember(id, name) {}
    void createOrder(string order) override 
    {
        cout << "Cook " << fullName << " is making: " << order << endl;
    }
};

class Accountant : public StaffMember, public BillingClerk 
{
public:
    Accountant(int id, string name) : StaffMember(id, name) {}
    void produceBill(double amount) override 
    {
        cout << "Accountant " << fullName << " generated bill: $" << amount << endl;
    }
};

class Supervisor : public StaffMember, public OrderHandler, public BillingClerk 
{
public:
    Supervisor(int id, string name) : StaffMember(id, name) {}
    void processOrder(string order) override 
    {
        cout << "Supervisor " << fullName << " is processing order: " << order << endl;
    }
    void produceBill(double amount) override 
    {
        cout << "Supervisor " << fullName << " generated bill: $" << amount << endl;
    }
};

class MenuCatalog 
{
protected:
    vector<pair<string, double>> menuItems;
public:
    virtual double computeTotal() = 0;
    virtual ~MenuCatalog() {}
};

class FoodSelection : public MenuCatalog 
{
public:
    void addDish(string name, double price) 
    {
        menuItems.push_back({name, price});
    }
    double computeTotal() override 
    {
        double sum = 0;
        for (auto& item : menuItems) sum += item.second;
        return sum;
    }
};

class DrinkSelection : public MenuCatalog 
{
public:
    void addDrink(string name, double price) 
    {
        menuItems.push_back({name, price});
    }
    double computeTotal() override 
    {
        double sum = 0;
        for (auto& item : menuItems) sum += item.second * 1.1;
        return sum;
    }
};

int main() 
{
    vector<OrderHandler*> orderProcessors;
    vector<OrderMaker*> orderCreators;
    vector<BillingClerk*> billGenerators;

    Server server1(101, "Ali");
    Cook cook1(102, "Sara");
    Accountant accountant1(103, "Ahmed");
    Supervisor supervisor1(104, "Zain");

    orderProcessors.push_back(&server1);
    orderProcessors.push_back(&supervisor1);
    orderCreators.push_back(&cook1);
    billGenerators.push_back(&accountant1);
    billGenerators.push_back(&supervisor1);

    orderProcessors[0]->processOrder("Pizza");
    orderCreators[0]->createOrder("Pizza");
    double total = 15.99;
    billGenerators[0]->produceBill(total);

    return 0;
}
