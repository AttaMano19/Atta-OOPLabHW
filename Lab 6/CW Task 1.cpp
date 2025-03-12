#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
public:
    Account(int accNo, double bal) : accountNumber(accNo), balance(bal) {}
    
    void addFunds(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " | Updated Balance: $" << balance << endl;
    }
    
    void removeFunds(double amount) {
        if (amount > balance) {
            cout << "Not enough balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: $" << amount << " | Updated Balance: $" << balance << endl;
    }
    
    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

class Savings : public Account {
    const double interestRate;
public:
    Savings(int accNo, double bal, double rate) : Account(accNo, bal), interestRate(rate) {}
    
    void addInterest() {
        balance += balance * interestRate;
        cout << "Interest Applied! New Balance: $" << balance << endl;
    }
};

class Checking : public Account {
    double overdraftLimit;
public:
    Checking(int accNo, double bal, double limit) : Account(accNo, bal), overdraftLimit(limit) {}
    
    void overdraft(double amount) {
        if (amount > overdraftLimit) {
            cout << "Overdraft Limit Reached!" << endl;
            return;
        }
        removeFunds(amount);
    }
    
    void adjustOverdraft(double newLimit) {
        overdraftLimit = newLimit;
    }
};

class Business : public Account {
    const double taxRate;
public:
    Business(int accNo, double bal, double tax) : Account(accNo, bal), taxRate(tax) {}
    
    void addFunds(double amount) {
        double taxAmount = amount * taxRate;
        Account::addFunds(amount - taxAmount);
        cout << "Tax Deducted: $" << taxAmount << endl;
    }
};

class Client {
    Account* account;
    string clientName;
public:
    Client(Account* acc, string name) : account(acc), clientName(name) {}
    
    void deposit(double amount) {
        account->addFunds(amount);
    }
    
    void withdraw(double amount) {
        account->removeFunds(amount);
    }
    
    void checkBalance() {
        account->showBalance();
    }
};

class Employee {
protected:
    string empName;
    int empId;
public:
    Employee(string name, int id) : empName(name), empId(id) {}
};

class Cashier : public Employee {
    Account* account;
public:
    Cashier(Account* acc, string name, int id) : account(acc), Employee(name, id) {}
    
    void deposit(double amount) {
        account->addFunds(amount);
    }
    
    void withdraw(double amount) {
        account->removeFunds(amount);
    }
    
    void checkBalance() {
        account->showBalance();
    }
    
    void freezeAccount() {
        cout << empName << "'s account has been frozen!" << endl;
    }
};

class Supervisor : public Employee {
    Account* account;
public:
    Supervisor(Account* acc, string name, int id) : account(acc), Employee(name, id) {}
    
    void deposit(double amount) {
        account->addFunds(amount);
    }
    
    void withdraw(double amount) {
        account->removeFunds(amount);
    }
    
    void checkBalance() {
        account->showBalance();
    }
    
    void freezeAccount() {
        cout << empName << "'s account has been frozen!" << endl;
    }
    
    void modifyOverdraft(Checking* chk, double limit) {
        chk->adjustOverdraft(limit);
    }
};

int main() {
    Savings savingsAcc(201, 1500, 0.04);
    Checking checkingAcc(202, 700, 250);
    Business businessAcc(203, 5000, 0.08);

    Client client(&savingsAcc, "John");
    Cashier cashier(&checkingAcc, "David", 101);
    Supervisor supervisor(&businessAcc, "Michael", 102);

    cout << "\nClient Transactions:\n";
    client.deposit(300);
    client.withdraw(200);
    client.checkBalance();
    
    cout << "\nCashier Transactions:\n";
    cashier.deposit(400);
    cashier.withdraw(180);
    cashier.checkBalance();
    cashier.freezeAccount();

    cout << "\nSupervisor Transactions:\n";
    supervisor.deposit(600);
    supervisor.withdraw(300);
    supervisor.checkBalance();
    supervisor.freezeAccount();

    cout << "\nApplying Interest for Savings Account:\n";
    savingsAcc.addInterest();
    
    return 0;
}
