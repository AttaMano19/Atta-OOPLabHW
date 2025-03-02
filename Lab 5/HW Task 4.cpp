#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Blender {
public:
    void startBlending() {
        for (int i = 0; i < 4; i++) {
            cout << "Blending in progress...\n";
        }
    }
};

class Grinder {
public:
    void startGrinding() {
        cout << "Grinding in progress...\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
};

class JuiceMachine {
private:
    Blender blenderUnit;
    Grinder grinderUnit;
public:
    void prepareJuice() {
        blenderUnit.startBlending();
        grinderUnit.startGrinding();
        cout << "Your fresh juice is ready to serve!\n";
    }
};

int main() {
    JuiceMachine juiceMaker;
    juiceMaker.prepareJuice();
    return 0;
}
