#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    static int counter;
    int registrationNumber;
     string lastName;
     string firstName;
    int numberOfGrades;
    float* grades;
public:
    Student() : registrationNumber(++counter), numberOfGrades(0), grades(new float[20]) {
        lastName = "";
        firstName = "";
    }

    Student( string last,  string first, int numGrades)
            : registrationNumber(++counter), lastName(last), firstName(first), numberOfGrades(numGrades), grades(new float[20]) {}

    Student(const Student& student)
            : registrationNumber(student.registrationNumber), lastName(student.lastName), firstName(student.firstName), numberOfGrades(student.numberOfGrades), grades(new float[20]) {
        for (int i = 0; i < numberOfGrades; ++i) {
            grades[i] = student.grades[i];
        }
    }

    ~Student() {
        delete[] grades; 
    }

    int getRegistrationNumber() const { return registrationNumber; }
     string getLastName() const { return lastName; }
     string getFirstName() const { return firstName; }
    int getNumberOfGrades() const { return numberOfGrades; }
    void setLastName( string last) { lastName = last; }
    void setFirstName( string first) { firstName = first; }
    void setNumberOfGrades(int numGrades) { numberOfGrades = numGrades; }

    void inputGrades() {
         cout << "Enter grades for " << firstName << " " << lastName << " (" << numberOfGrades << " grades):\n";
        for (int i = 0; i < numberOfGrades; ++i) {
             cout << "Grade " << i + 1 << ": ";
             cin >> grades[i];
        }
    }

    float calculateAverage() const {
        if (numberOfGrades == 0) return 0.0f;
        float sum = 0.0f;
        for (int i = 0; i < numberOfGrades; ++i) {
            sum += grades[i];
        }
        return sum / numberOfGrades;
    }

    bool isAdmitted() const {
        return calculateAverage() >= 12.0f;
    }

    void displayData() const {
         cout << "\nStudent Information:\n";
         cout << "Registration Number: " << registrationNumber << "\n";
         cout << "Name: " << firstName << " " << lastName << "\n";
         cout << "Grades: ";
        for (int i = 0; i < numberOfGrades; ++i) {
             cout <<  fixed <<  setprecision(2) << grades[i] << " ";
        }
         cout << "\nAverage Grade: " << calculateAverage() << "\n";
         cout << "Admission Status: " << (isAdmitted() ? "Admitted" : "Not Admitted") << "\n";
    }
};

int Student::counter = 0;

int main() {
    Student student1("Doe", "John", 3);
    Student student2("Smith", "Jane", 4);

    student1.inputGrades();
    student2.inputGrades();

    student1.displayData();
    student2.displayData();

    return 0;
}
