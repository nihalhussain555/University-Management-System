#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

class Person {
protected:
    string name;
    string id;
    int age;
    string contact;

public:
    Person() : name(""), id(""), age(0), contact("") {}

    virtual void getData() {
        cout << "\n--- Enter Person Information ---" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter ID: ";
        getline(cin, id);
        
        cout << "Enter Age: ";
        cin >> age;
        
        cout << "Enter Contact: ";
        cin.ignore();
        getline(cin, contact);
    }

    virtual void display() const {
        cout << "Name: " << name << " | ID: " << id 
             << " | Age: " << age << " | Contact: " << contact << endl;
    }

    string getID() const { return id; }
    string getName() const { return name; }

    virtual ~Person() {}
};

// ========================= Derived Classes =========================

class Student : public virtual Person {
private:
    string course;
    float gpa;
    string enrollmentStatus;

public:
    Student() : course(""), gpa(0.0), enrollmentStatus("Active") {}

    void getData() override {
        Person::getData();
        
        cout << "\n--- Enter Student Information ---" << endl;
        cout << "Enter Course: ";
        cin.ignore();
        getline(cin, course);
        
        cout << "Enter GPA: ";
        cin >> gpa;
        
        cout << "Enter Enrollment Status (Active/Inactive): ";
        cin.ignore();
        getline(cin, enrollmentStatus);
    }

    void display() const override {
        cout << "\n========== STUDENT DETAILS ==========" << endl;
        Person::display();
        cout << "Course: " << course << " | GPA: " << fixed << setprecision(2) << gpa 
             << " | Status: " << enrollmentStatus << endl;
        cout << "=====================================" << endl;
    }

    void saveToFile() {
        ofstream file("students.txt", ios::app);
        if (file.is_open()) {
            file << name << "|" << id << "|" << age << "|" << contact << "|" 
                 << course << "|" << gpa << "|" << enrollmentStatus << "\n";
            file.close();
            cout << "✓ Student record saved successfully!" << endl;
        } else {
            cout << "✗ Error opening file!" << endl;
        }
    }

    void displayShort() const {
        cout << "ID: " << id << " | Name: " << name << " | Course: " << course 
             << " | GPA: " << fixed << setprecision(2) << gpa << endl;
    }

    virtual ~Student() {}
};

class Faculty : public virtual Person {
private:
    string department;
    string designation;
    vector<string> assignedCourses;

public:
    Faculty() : department(""), designation("") {}

    void getData() override {
        Person::getData();
        
        cout << "\n--- Enter Faculty Information ---" << endl;
        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, department);
        
        cout << "Enter Designation: ";
        getline(cin, designation);
    }

    void display() const override {
        cout << "\n========== FACULTY DETAILS ==========" << endl;
        Person::display();
        cout << "Department: " << department << " | Designation: " << designation << endl;
        cout << "=====================================" << endl;
    }

    void saveToFile() {
        ofstream file("faculty.txt", ios::app);
        if (file.is_open()) {
            file << name << "|" << id << "|" << age << "|" << contact << "|" 
                 << department << "|" << designation << "\n";
            file.close();
            cout << "✓ Faculty record saved successfully!" << endl;
        } else {
            cout << "✗ Error opening file!" << endl;
        }
    }

    void displayShort() const {
        cout << "ID: " << id << " | Name: " << name << " | Department: " << department 
             << " | Designation: " << designation << endl;
    }

    virtual ~Faculty() {}
};

// ========================= Course Class =========================

class Course {
private:
    string courseCode;
    string courseTitle;
    int credits;
    string prerequisites;
    string instructor;

public:
    Course() : courseCode(""), courseTitle(""), credits(0), prerequisites("None"), instructor("") {}

    void inputData() {
        cout << "\n--- Enter Course Information ---" << endl;
        cout << "Enter Course Code: ";
        cin.ignore();
        getline(cin, courseCode);
        
        cout << "Enter Course Title: ";
        getline(cin, courseTitle);
        
        cout << "Enter Credits: ";
        cin >> credits;
        
        cout << "Enter Prerequisites (or 'None'): ";
        cin.ignore();
        getline(cin, prerequisites);
        
        cout << "Enter Instructor ID: ";
        getline(cin, instructor);
    }

    void display() const {
        cout << "Code: " << courseCode << " | Title: " << courseTitle 
             << " | Credits: " << credits << " | Prerequisites: " << prerequisites 
             << " | Instructor: " << instructor << endl;
    }

    void saveToFile() {
        ofstream file("courses.txt", ios::app);
        if (file.is_open()) {
            file << courseCode << "|" << courseTitle << "|" << credits << "|" 
                 << prerequisites << "|" << instructor << "\n";
            file.close();
            cout << "✓ Course record saved successfully!" << endl;
        } else {
            cout << "✗ Error opening file!" << endl;
        }
    }

    string getCourseCode() const { return courseCode; }
    string getTitle() const { return courseTitle; }
    string getInstructor() const { return instructor; }

    ~Course() {}
};

// ========================= Enrollment Class =========================

class StudentCourse {
private:
    string studentID;
    string courseCode;
    float grade;
    string semester;

public:
    StudentCourse() : studentID(""), courseCode(""), grade(0.0), semester("") {}

    void inputData() {
        cout << "\n--- Enroll Student in Course ---" << endl;
        cout << "Enter Student ID: ";
        cin.ignore();
        getline(cin, studentID);
        
        cout << "Enter Course Code: ";
        getline(cin, courseCode);
        
        cout << "Enter Semester: ";
        getline(cin, semester);
        
        cout << "Enter Grade (if available, else enter 0): ";
        cin >> grade;
    }

    void saveToFile() {
        ofstream file("enrollments.txt", ios::app);
        if (file.is_open()) {
            file << studentID << "|" << courseCode << "|" << grade << "|" << semester << "\n";
            file.close();
            cout << "✓ Enrollment record saved successfully!" << endl;
        } else {
            cout << "✗ Error opening file!" << endl;
        }
    }

    void display() const {
        cout << "Student ID: " << studentID << " | Course: " << courseCode 
             << " | Grade: " << fixed << setprecision(2) << grade 
             << " | Semester: " << semester << endl;
    }

    ~StudentCourse() {}
};

// ========================= University Management System =========================

class UniversityManagementSystem {
private:
    vector<Student> students;
    vector<Faculty> faculty;
    vector<Course> courses;

    void loadStudents() {
        ifstream file("students.txt");
        if (file.is_open()) {
            students.clear();
            string line, name, id, age_str, contact, course, gpa_str, status;
            
            while (getline(file, line)) {
                size_t pos = 0;
                
                pos = line.find('|');
                name = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                pos = line.find('|');
                id = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                pos = line.find('|');
                age_str = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                pos = line.find('|');
                contact = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                pos = line.find('|');
                course = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                pos = line.find('|');
                gpa_str = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                status = line;
                
                Student s;
                cout << "Loaded student: " << name << endl;
            }
            file.close();
        }
    }

    void loadFaculty() {
        ifstream file("faculty.txt");
        if (file.is_open()) {
            faculty.clear();
            string line;
            while (getline(file, line)) {
                // Parse and load faculty data
            }
            file.close();
        }
    }

    void loadCourses() {
        ifstream file("courses.txt");
        if (file.is_open()) {
            courses.clear();
            string line;
            while (getline(file, line)) {
                // Parse and load course data
            }
            file.close();
        }
    }

public:
    UniversityManagementSystem() {
        loadStudents();
        loadFaculty();
        loadCourses();
    }

    void addStudent() {
        Student s;
        s.getData();
        students.push_back(s);
        s.saveToFile();
    }

    void addFaculty() {
        Faculty f;
        f.getData();
        faculty.push_back(f);
        f.saveToFile();
    }

    void addCourse() {
        Course c;
        c.inputData();
        courses.push_back(c);
        c.saveToFile();
    }

    void displayAllStudents() {
        cout << "\n========== ALL STUDENTS ==========" << endl;
        ifstream file("students.txt");
        if (file.is_open()) {
            string line;
            int count = 0;
            while (getline(file, line)) {
                cout << ++count << ". " << line << endl;
            }
            file.close();
        } else {
            cout << "No student records found!" << endl;
        }
    }

    void displayAllFaculty() {
        cout << "\n========== ALL FACULTY ==========" << endl;
        ifstream file("faculty.txt");
        if (file.is_open()) {
            string line;
            int count = 0;
            while (getline(file, line)) {
                cout << ++count << ". " << line << endl;
            }
            file.close();
        } else {
            cout << "No faculty records found!" << endl;
        }
    }

    void displayAllCourses() {
        cout << "\n========== ALL COURSES ==========" << endl;
        ifstream file("courses.txt");
        if (file.is_open()) {
            string line;
            int count = 0;
            while (getline(file, line)) {
                cout << ++count << ". " << line << endl;
            }
            file.close();
        } else {
            cout << "No course records found!" << endl;
        }
    }

    void searchStudent(string sid) {
        cout << "\n========== SEARCH STUDENT ==========" << endl;
        ifstream file("students.txt");
        if (file.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                if (line.find(sid) != string::npos) {
                    cout << "Found: " << line << endl;
                    found = true;
                    break;
                }
            }
            file.close();
            if (!found) cout << "Student not found!" << endl;
        }
    }

    void enrollStudentInCourse() {
        StudentCourse enrollment;
        enrollment.inputData();
        enrollment.saveToFile();
    }

    void displayEnrollments() {
        cout << "\n========== ALL ENROLLMENTS ==========" << endl;
        ifstream file("enrollments.txt");
        if (file.is_open()) {
            string line;
            int count = 0;
            while (getline(file, line)) {
                cout << ++count << ". " << line << endl;
            }
            file.close();
        } else {
            cout << "No enrollment records found!" << endl;
        }
    }

    ~UniversityManagementSystem() {}
};

// ========================= Main Function =========================

int main() {
    UniversityManagementSystem ums;
    int choice;

    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║   UNIVERSITY MANAGEMENT SYSTEM              ║" << endl;
    cout << "║   Using Multiple Inheritance in C++         ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;

    do {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Faculty" << endl;
        cout << "3. Add Course" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Display All Faculty" << endl;
        cout << "6. Display All Courses" << endl;
        cout << "7. Search Student by ID" << endl;
        cout << "8. Enroll Student in Course" << endl;
        cout << "9. Display All Enrollments" << endl;
        cout << "10. Exit" << endl;
        cout << "================================" << endl;
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1:
                ums.addStudent();
                break;
            case 2:
                ums.addFaculty();
                break;
            case 3:
                ums.addCourse();
                break;
            case 4:
                ums.displayAllStudents();
                break;
            case 5:
                ums.displayAllFaculty();
                break;
            case 6:
                ums.displayAllCourses();
                break;
            case 7: {
                string sid;
                cout << "Enter Student ID to search: ";
                cin.ignore();
                getline(cin, sid);
                ums.searchStudent(sid);
                break;
            }
            case 8:
                ums.enrollStudentInCourse();
                break;
            case 9:
                ums.displayEnrollments();
                break;
            case 10: {
                cout << "\n╔════════════════════════════════════════════╗" << endl;
                cout << "║  Thank you for using University Management  ║" << endl;
                cout << "║            System. Goodbye!                 ║" << endl;
                cout << "╚════════════════════════════════════════════╝" << endl;
                break;
            }
            default:
                cout << "\n✗ Invalid choice! Please enter a number between 1 and 10." << endl;
        }
    } while (choice != 10);

    return 0;
}
