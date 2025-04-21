#include <iostream>
using namespace std;

class Learner {
    public:
        virtual int calculateFee(string level, int credits) = 0;
        virtual ~Learner() {}
};

class PostgradStudent : public Learner {
    private:
        string thesisField;

    public:
        void setThesis(string field) { thesisField = field; }
        string getThesis() { return thesisField; }

        int calculateFee(string level, int credits) override {
            int total = 0;
            if (level == "Undergraduate") {
                total = 200 * credits;
            } else if (level == "Graduate") {
                total = 300 * credits;
            } else if (level == "Doctoral") {
                total = 400 * credits;
            }
            return total;
        }
};

int main() {
    PostgradStudent student;
    student.setThesis("AI in Healthcare");
    cout << "Thesis Topic: " << student.getThesis() << endl;

    string programLevel;
    int creditHours;

    cout << "Enter academic level (Undergraduate / Graduate / Doctoral): ";
    cin >> programLevel;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    double fee = student.calculateFee(programLevel, creditHours);
    cout << "Tuition Fee: $" << fee << endl;

    return 0;
}
