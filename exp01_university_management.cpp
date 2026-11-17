#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
public:
    Student(int r, string n) : rollNo(r), name(n) {
        cout << "Student object created\n";
    }
    void display() const {
        cout << "Roll Number: " << rollNo << '\n';
        cout << "Name: " << name << '\n';
    }
    ~Student() { cout << "Student object destroyed\n"; }
};

int main() {
    Student s1(101, "Arun");
    s1.display();
    return 0;
}
