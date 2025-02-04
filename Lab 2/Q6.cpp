#include <iostream>
#include <vector>
#include <string>

struct Subject {
    std::string name;
    int credits;
};

struct Student {
    int id;
    std::vector<Subject> subjects;
};

int main() {
    int numberOfStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numberOfStudents;

    std::vector<Student> students(numberOfStudents);

    for (int i = 0; i < numberOfStudents; ++i) {
        students[i].id = i + 1;
        int numberOfSubjects;
        std::cout << "Enter the number of subjects for student " << students[i].id << ": ";
        std::cin >> numberOfSubjects;

        for (int j = 0; j < numberOfSubjects; ++j) {
            Subject subject;
            std::cout << "Enter subject name: ";
            std::cin >> subject.name;
            std::cout << "Enter credits for " << subject.name << ": ";
            std::cin >> subject.credits;
            students[i].subjects.push_back(subject);
        }
    }

    for (const auto& student : students) {
        std::cout << "Student ID: " << student.id << "\nSubjects:\n";
        for (const auto& subject : student.subjects) {
            std::cout << " - " << subject.name << " (" << subject.credits << " credits)\n";
        }
    }

    return 0;
}