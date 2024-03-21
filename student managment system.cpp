#include <iostream>

using namespace std;

// Define a structure for holding student information
struct Student {
    int id;
    string name;
    int age;
    string grade;
};

const int MAX_STUDENTS = 100; // Maximum number of students
Student students[MAX_STUDENTS]; // Array to store students
int numStudents = 0; // Counter for the number of students

// Function to add a new student
void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    Student newStudent;
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    cout << "Enter student name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newStudent.name);
    cout << "Enter student age: ";
    cin >> newStudent.age;
    cout << "Enter student grade: ";
    cin >> newStudent.grade;

    students[numStudents++] = newStudent;
    cout << "Student added successfully!" << endl;
}

// Function to display all students
void displayStudents() {
    if (numStudents == 0) {
        cout << "No students found!" << endl;
        return;
    }

    cout << "List of students:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", Age: " << students[i].age << ", Grade: " << students[i].grade << endl;
    }
}

// Function to search for a student by ID
void searchStudent() {
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].id == searchId) {
            cout << "Student found:" << endl;
            cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", Age: " << students[i].age << ", Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found!" << endl;
    }
}

// Function to delete a student by ID
void deleteStudent() {
    int deleteId;
    cout << "Enter student ID to delete: ";
    cin >> deleteId;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].id == deleteId) {
            for (int j = i; j < numStudents - 1; ++j) {
                students[j] = students[j + 1]; // Shift elements to overwrite the deleted student
            }
            numStudents--;
            found = true;
            cout << "Student with ID " << deleteId << " deleted successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << deleteId << " not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Management System" << endl;
        cout << "Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
