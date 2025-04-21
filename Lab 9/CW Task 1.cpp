#include <iostream>
using namespace std;

class Account {
    private:
        double funds;
        double dailyDeposit, dailyWithdrawal;
        static const double maxDeposit;
        static const double maxWithdrawal;
    
    public: 
        Account(double f) : funds(f), dailyDeposit(0), dailyWithdrawal(0) {}
        Account() : funds(0) {}

        void addFunds(double amount) {
            if (dailyDeposit + amount > maxDeposit) {
                cout << "Amount exceeding daily deposit limit" << endl;
                return;
            } else {
                funds += amount;
                dailyDeposit += amount;
                cout << "Successfully deposited Rs. " << amount << endl;
            }
        }

        void removeFunds(double amount) {
            if (dailyWithdrawal + amount > maxWithdrawal) {
                cout << "Amount exceeding daily withdrawal limit" << endl;
                return;
            } else if (amount > funds) {
                cout << "Not enough funds in account" << endl;
                return;
            } else {
                funds -= amount;
                dailyWithdrawal += amount;
                cout << "Successfully withdrawn Rs. " << amount << endl;
            }
        }

        void resetLimits() {
            dailyDeposit = 0;
            dailyWithdrawal = 0;
        }

        double getFunds() { return funds; }
};

const double Account::maxDeposit = 35000;
const double Account::maxWithdrawal = 20000;

class Customer {
    private:
        string customerName;
        int customerAge;
        int customerID;
        static int totalCustomers;
        Account account;

    public:
        Customer(string name, int age, Account acc) 
            : customerName(name), customerAge(age), customerID(totalCustomers++), account(acc) {}

        void makeDeposit() {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.addFunds(amount);
        }

        void makeWithdrawal() {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.removeFunds(amount);
        }

        void showBalance() {
            cout << "Your balance is Rs. " << account.getFunds() << endl;
        }
};

int Customer::totalCustomers = 0;

int main() {
    Account acc1(10000);
    Customer cust1("Alice", 30, acc1);

    Account acc2(5000); 
    Customer cust2("Bob", 25, acc2);

    cust1.showBalance();
    cust1.makeDeposit();   
    cust1.makeWithdrawal(); 
    cust1.showBalance();

    cout << "------" << endl;

    cust2.showBalance();
    cust2.makeDeposit();  
    cust2.makeWithdrawal(); 
    cust2.showBalance();

    return 0;
}
