#include <iostream>
#include <string>
using namespace std;

int main() {
    float array[20];
    for (int i=0; i<20; i++) {
        cout << "Enter Number " << i+1 << ": ";
        cin >> array[i];
    }
    float max = 0, highestI;
    for (int i=0; i<20; i++) {
        if (array[i] > max) {
            max = array[i];
            highestI = i;
        }
    }
    max = 0;
    for (int i=0; i<20; i++) {
        if (i != highestI) {
            if (array[i] > max) {
                max = array[i];
            }
        }
    }
    cout << endl << "Second Highest Number = " << max;
    return 0;
}