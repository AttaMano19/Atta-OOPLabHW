#include <iostream>
#include <string>
using namespace std;

int main() {
    int elements; 
    cout << "Enter Number of Elements: ";
    cin >> elements;
    int array[elements];
    int sum = 0;
    for (int i=0; i<elements; i++) {
        cout << "Enter Element " << i+1 << ": ";
        cin >> array[i];
        sum += array[i];
    }
    cout << endl << "Sum of Elements: " << sum;
    return 0;
}