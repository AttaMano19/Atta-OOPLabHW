#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    float WgtKg, WgtLb; 
    cout << "Enter Your Weight in Kilograms: ";
    cin >> WgtKg;
    WgtLb = WgtKg * 2.2;

    cout << fixed << setprecision(2);

    cout << WgtKg << " Kilograms Equals " << WgtLb << " Pounds" << endl;
    return 0;
}
