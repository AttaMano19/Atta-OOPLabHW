#include <iostream>
#include <string>
using namespace std;

int main() {
    string movie;
    int adultTkts, adultCost;
    int childTkts, childCost;
    float percentage;
    cout << "Enter Movie Name: ";
    cin >> movie;
    cout << endl << "Enter Number of Adult Tickets: ";
    cin >> adultTkts;
    cout << endl << "Enter Price of an Adult Ticket: ";
    cin >> adultCost;
    cout << endl << "Enter Number of Children's Tickets: ";
    cin >> childTkts;
    cout << endl << "Enter Price of a Children's Ticket: ";
    cin >> childCost;
    cout << endl << "Enter Percentage to Donate: ";
    cin >> percentage;
    int grossAmount = (adultTkts*adultCost) + (childCost*childTkts);
    float donation = (percentage/100) * grossAmount;
    float finalAmount = grossAmount - donation;
    cout << "Movie Name: " << movie << endl << "Number of Tickets Sold: " << adultTkts + childTkts << endl << "Gross Amount: " << grossAmount << endl << "Percentage of Amount Donated: " << percentage << "%" << endl << "Amount Donated: " << donation << endl << "Net Sale: " << finalAmount;

    return 0;
}