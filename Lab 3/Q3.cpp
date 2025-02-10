#include <iostream>
using namespace std;
#include <windows.h>

class Glass
{
public:
    int LiquidLevel;

    int Drink(int millimeters)
    {
        LiquidLevel -= millimeters;
    };

    void Refill()
    {
        LiquidLevel = 200;
    }
};


int main(){
    Glass glass;
    int temp = 0;

    glass.Refill();

    while (temp != -1){
        
        cout << "Enter drank water level (-1 for exit) : " << endl;
        cin >> temp;

        if (glass.LiquidLevel < 100 || (glass.LiquidLevel - temp) < 100){
            cout << "Glass refilling...!" << endl;
            Sleep(1000);
            glass.Refill();
        }

        glass.Drink(temp);

        cout << "Current Glass Level is : " << glass.LiquidLevel << endl;
    }

}