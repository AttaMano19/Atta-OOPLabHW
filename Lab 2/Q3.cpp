#include <iostream>
#include <stdexcept>
using namespace std;

void resize (int*& array, int *sizeofArray) {
    int newSize = (*sizeofArray) * 2;
    int* newArray = new int[newSize];

    for (int i = 0; i < (*sizeofArray); i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray; // new location
    (*sizeofArray) = newSize;
}

void resizeArray (int*& array, int* size, int count) {
    int* newArray = new int[count];
    for (int i = 0; i < count; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray; // new location
    (*size) = count;
}

int main() {
    int sizeofArray = 5;
    int count = 0;
    int *array = new int[sizeofArray];

    while (1) {
        int value;
        cout << "Enter an Integer (-1 to stop): ";
        cin >> value;

        if (value == -1) {
            break;
        }

        if (count >= sizeofArray) {
            resize(array, &sizeofArray);
        }

        array[count] = value;
        count++;
    }

    resizeArray(array, &sizeofArray, count); // at end so sizeofArray become = count

    for (int i=0; i < count; i++) {
        cout << "Element " << i+1 << ": " << array[i] << endl;
    }

    delete[] array;

    return 0;
}