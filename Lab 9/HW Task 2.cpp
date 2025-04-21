#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type;
    float cost;

public:
    Vehicle(string t = "", float c = 0.0f) : type(t), cost(c) {}

    string getType() const { return type; }
    float getCost() const { return cost; }

    void setType(string t) { type = t; }

    virtual void setCost(float c) = 0;

    virtual void show() const {
        cout << "Vehicle Type: " << type << " | Final Cost: $" << cost << endl;
    }

    virtual ~Vehicle() {}
};

class Paint : public Vehicle {
private:
    string tone;

public:
    Paint(string t, float c, string color) : Vehicle(t, c), tone(color) {}

    void setTone(string color) { tone = color; }
    string getTone() const { return tone; }

    void setCost(float c) override {
        cost = c + (c * 0.07f);
    }

    void show() const override {
        Vehicle::show();
        cout << "Paint Color: " << tone << endl;
    }
};

class Manufacturer : public Vehicle {
private:
    string maker;

public:
    Manufacturer(string t, float c, string m) : Vehicle(t, c), maker(m) {}

    void setMaker(string m) { maker = m; }
    string getMaker() const { return maker; }

    void setCost(float c) override {
        cost = c + 1200;
    }

    void show() const override {
        Vehicle::show();
        cout << "Maker Brand: " << maker << endl;
    }
};

int main() {
    Paint carOne("Compact", 18000, "Midnight Blue");
    carOne.setCost(18000);
    cout << "=== Paint Edition ===" << endl;
    carOne.show();

    cout << endl;

    Manufacturer carTwo("SUV", 26000, "Hyundai");
    carTwo.setCost(26000);
    cout << "=== Manufacturer Edition ===" << endl;
    carTwo.show();

    return 0;
}
