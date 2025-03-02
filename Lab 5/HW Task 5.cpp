#include <iostream>

class Vehicle {
private:
    int enginePower;
    int seatCount;
    int speakerCount;

public:
    Vehicle(int power, int seats, int speakers) : enginePower(power), seatCount(seats), speakerCount(speakers) {}

    void modifyAttributes(int& powerRef, int& seatsRef, int& speakersRef, int power, int seats, int speakers) const {
        powerRef = power;
        seatsRef = seats;
        speakersRef = speakers;
    }

    int& getEnginePowerRef() { return enginePower; }
    int& getSeatCountRef() { return seatCount; }
    int& getSpeakerCountRef() { return speakerCount; }

    void showDetails() const {
        std::cout << "Engine Power: " << enginePower << " HP\n";
        std::cout << "Seat Count: " << seatCount << "\n";
        std::cout << "Speaker Count: " << speakerCount << "\n";
    }
};

int main() {
    Vehicle myVehicle(200, 5, 4);
    myVehicle.showDetails();
    
    myVehicle.modifyAttributes(myVehicle.getEnginePowerRef(), myVehicle.getSeatCountRef(), myVehicle.getSpeakerCountRef(), 250, 7, 10);
    std::cout << "\nAfter Modification\n";
    
    myVehicle.showDetails();
    
    return 0;
}
