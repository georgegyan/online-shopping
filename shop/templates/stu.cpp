#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student structure
struct Student {
    string name;
    float grade;
};

// Function to add a student
void addStudent(vector<Student>& students) {
    string name;
    float grade;
    
    cout << "Enter student's name: ";
    cin >> name;
    
    cout << "Enter student's grade: ";
    cin >> grade;

    students.push_back({name, grade});
}

// Function to display all students and their grades
void displayStudents(const vector<Student>& students) {
    cout << "\nStudent Grades:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }
}

// Function to calculate and display the average grade
void displayAverageGrade(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to calculate average grade.\n";
        return;
    }

    float total = 0;
    for (const auto& student : students) {
        total += student.grade;
    }
    
    float average = total / students.size();
    cout << "Average grade: " << average << endl;
}

// Function to find the student with the highest grade
void displayHighestGrade(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to find highest grade.\n";
        return;
    }

    const Student* highest = &students[0];
    for (const auto& student : students) {
        if (student.grade > highest->grade) {
            highest = &student;
        }
    }

    cout << "Highest grade: " << highest->name << " with grade " << highest->grade << endl;
}

// Function to find the student with the lowest grade
void displayLowestGrade(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to find lowest grade.\n";
        return;
    }

    const Student* lowest = &students[0];
    for (const auto& student : students) {
        if (student.grade < lowest->grade) {
            lowest = &student;
        }
    }

    cout << "Lowest grade: " << lowest->name << " with grade " << lowest->grade << endl;
}

// Function to remove a student by name
void removeStudent(vector<Student>& students) {
    string name;
    cout << "Enter the name of the student to remove: ";
    cin >> name;

    auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
        return student.name == name;
    });

    if (it != students.end()) {
        students.erase(it);
        cout << "Student " << name << " has been removed.\n";
    } else {
        cout << "Student not found.\n";
    }
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n1. Add Student\n2. Display Students\n3. Display Average Grade\n";
        cout << "4. Display Highest Grade\n5. Display Lowest Grade\n6. Remove Student\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                displayAverageGrade(students);
                break;
            case 4:
                displayHighestGrade(students);
                break;
            case 5:
                displayLowestGrade(students);
                break;
            case 6:
                removeStudent(students);
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }

    return 0;
}
