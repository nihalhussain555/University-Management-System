# University Management System

A comprehensive C++ application demonstrating advanced Object-Oriented Programming (OOP) principles through efficient management of student, faculty, and course data using multiple inheritance and file handling techniques.

**Developer:** Nihal Hussain  
**Reg No:** 711524BCS106  
**Department:** CSE – 'B'

## 📋 Project Overview

The University Management System automates records management and integrates multiple system modules (Students, Faculty, and Courses) into a unified platform. The system emphasizes OOP principles with special focus on multiple inheritance and implements reliable file-based storage systems.

## ✨ Key Features

### Core Functionality
- **Student Management** - Register, update, and manage student records including enrollment and grades
- **Faculty Management** - Handle instructor profiles, department assignments, and course designations
- **Course Management** - Maintain curriculum information, course codes, credits, and prerequisites
- **Student Enrollment** - Seamlessly enroll students in courses with grade tracking
- **Search Functionality** - Quick record retrieval by ID with efficient file searching
- **Data Persistence** - Automatic saving and loading ensures data integrity between sessions

### Advanced OOP Concepts
- **Multiple Inheritance** - Relationship classes (StudentCourse, FacultyCourse) for managing many-to-many relationships
- **Virtual Inheritance** - Proper handling of the diamond problem in inheritance hierarchies
- **Polymorphism** - Virtual functions for runtime polymorphic behavior
- **Encapsulation** - Protected and private members with public accessor methods
- **File I/O** - Complete CRUD (Create, Read, Update, Delete) operations

## 🎓 OOP Concepts Implemented

### 1. **Inheritance Hierarchy**
```
Person (Base Class)
├── Student (Derived Class)
├── Faculty (Derived Class)
└── Relationship classes using Multiple Inheritance
```

### 2. **Virtual Inheritance**
```cpp
class Student : public virtual Person {
    // Avoids diamond problem
    // Ensures single instance of Person members
}
```

### 3. **Polymorphism**
- Virtual functions for `getData()` and `display()` methods
- Different implementations in Student and Faculty classes
- Base class pointers/references can reference derived class objects

### 4. **Encapsulation**
- Protected attributes in base class (Person)
- Private attributes in derived classes (Student, Faculty)
- Public methods for controlled data access

### 5. **File Handling**
- Text-based file storage using C++ fstream
- Complete CRUD functionality
- Persistent data across program executions

## 📁 Class Structure

### Base Class: Person
```cpp
class Person {
protected:
    string name;      // Person's full name
    string id;        // Unique identifier
    int age;          // Age of the person
    string contact;   // Contact information

public:
    virtual void getData();    // Input method
    virtual void display();    // Display method
};
```

### Derived Class: Student
**Additional Attributes:**
- `course` - Enrolled course name
- `gpa` - Grade Point Average
- `enrollmentStatus` - Active/Inactive status

**Methods:**
- `getData()` - Override to collect student-specific data
- `display()` - Display student information
- `saveToFile()` - Persist student to students.txt
- `displayShort()` - Compact display format

### Derived Class: Faculty
**Additional Attributes:**
- `department` - Faculty department
- `designation` - Job designation/title
- `assignedCourses` - Vector of assigned courses

**Methods:**
- `getData()` - Override to collect faculty-specific data
- `display()` - Display faculty information
- `saveToFile()` - Persist faculty to faculty.txt
- `displayShort()` - Compact display format

### Course Class
```cpp
class Course {
private:
    string courseCode;      // Unique course identifier
    string courseTitle;     // Course name
    int credits;            // Credit hours
    string prerequisites;   // Prerequisite courses
    string instructor;      // Instructor ID
};
```

### Enrollment Class: StudentCourse
```cpp
class StudentCourse {
private:
    string studentID;   // Student ID
    string courseCode;  // Course code
    float grade;        // Student's grade
    string semester;    // Semester taken
};
```

## 💾 Data Storage Files

- **students.txt** - Student records (pipe-delimited)
  ```
  name|id|age|contact|course|gpa|enrollmentStatus
  ```

- **faculty.txt** - Faculty records (pipe-delimited)
  ```
  name|id|age|contact|department|designation
  ```

- **courses.txt** - Course records (pipe-delimited)
  ```
  courseCode|courseTitle|credits|prerequisites|instructor
  ```

- **enrollments.txt** - Enrollment records (pipe-delimited)
  ```
  studentID|courseCode|grade|semester
  ```

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, MinGW, or Visual Studio)
- C++11 or later
- Any operating system (Windows, Linux, macOS)

### Compilation

```bash
# Using g++ (Linux/Mac)
g++ university_system.cpp -o university

# Using MinGW (Windows)
g++ university_system.cpp -o university.exe
```

### Execution

```bash
# Linux/Mac
./university

# Windows
university.exe
```

## 📱 Menu System

```
========== MAIN MENU ==========
1. Add Student
2. Add Faculty
3. Add Course
4. Display All Students
5. Display All Faculty
6. Display All Courses
7. Search Student by ID
8. Enroll Student in Course
9. Display All Enrollments
10. Exit
================================
```

## 💻 Usage Examples

### Adding a Student
```
Option: 1
Enter Name: John Doe
Enter ID: STU001
Enter Age: 20
Enter Contact: john@email.com
Enter Course: B.Tech Computer Science
Enter GPA: 3.8
Enter Enrollment Status (Active/Inactive): Active
✓ Student record saved successfully!
```

### Adding Faculty
```
Option: 2
Enter Name: Dr. Jane Smith
Enter ID: FAC001
Enter Age: 45
Enter Contact: jane@university.edu
Enter Department: Computer Science
Enter Designation: Associate Professor
✓ Faculty record saved successfully!
```

### Enrolling Student in Course
```
Option: 8
Enter Student ID: STU001
Enter Course Code: CS101
Enter Semester: Fall 2024
Enter Grade (if available, else enter 0): 0
✓ Enrollment record saved successfully!
```

## 📊 Technical Specifications

- **Language:** C++ (C++11 standard)
- **Paradigm:** Object-Oriented Programming
- **Storage:** Text files (pipe-delimited format)
- **Main Classes:** 5 (Person, Student, Faculty, Course, StudentCourse)
- **Inheritance Pattern:** Single and Multiple (Virtual)
- **File Operations:** Binary-safe text I/O

## 🔧 Code Structure

### Inheritance Diagram
```
            Person (Base)
           /           \
          /             \
      Student         Faculty
       (virtual)       (virtual)
           \             /
            \           /
         StudentCourse
         FacultyCourse
    (Multiple Inheritance)
```

### Key Implementation Features

**Virtual Function Polymorphism:**
```cpp
Person* ptr;  // Base class pointer
Student s;    // Derived class object
ptr = &s;     // Polymorphic assignment

ptr->getData();    // Calls Student::getData()
ptr->display();    // Calls Student::display()
```

**File CRUD Operations:**
- **Create:** `saveToFile()` - Append records to files
- **Read:** `display*()` - Read and display from files
- **Update:** Search and recreate files with modified data
- **Delete:** Search and recreate files excluding deleted records

## 📈 Enhancement Opportunities

### Phase 1: Immediate Improvements
- Input validation and error handling
- Edit/update existing records functionality
- Delete record operations with file management
- Duplicate record checking

### Phase 2: Short-term Goals
- Database integration (SQLite/MySQL/PostgreSQL)
- Graphical User Interface (Qt, wxWidgets, or SFML)
- Advanced search filters (by department, course, etc.)
- Reporting and export functionality (CSV/PDF)

### Phase 3: Medium-term Goals
- Web interface with REST API
- Multi-user authentication system
- Role-based access control (Admin, Faculty, Student)
- Real-time notifications and alerts

### Phase 4: Long-term Vision
- Mobile application (Android/iOS)
- Cloud storage integration
- Advanced analytics and dashboards
- Integration with external systems (payment, scheduling)
- Automated attendance and grade tracking

## 🏫 Real-World Applications

This system can be deployed in:
- Educational institutions (colleges, universities)
- Online learning platforms
- Skill development centers
- Training institutes
- Corporate training departments
- Government educational bodies

## 📚 OOP Learning Outcomes

This project effectively demonstrates:
- ✅ Class design and object creation
- ✅ Single and multiple inheritance
- ✅ Virtual inheritance for diamond problem resolution
- ✅ Polymorphism through virtual functions
- ✅ Encapsulation and data protection
- ✅ File I/O operations in C++
- ✅ Vector and dynamic data structures
- ✅ String manipulation and file parsing
- ✅ Software architecture and modularity
- ✅ Real-world system design

## 🔍 Code Quality Highlights

- **Modular Design:** Each class has a single, well-defined responsibility
- **Maintainable:** Clean code with clear method names and documentation
- **Scalable:** Easy to extend with new classes and features
- **Robust:** Error handling for file operations
- **Efficient:** Optimized file I/O with minimal redundancy
- **Type-Safe:** Proper use of C++ type system

## 📝 Sample Data Format

### students.txt
```
John Doe|STU001|20|john@email.com|B.Tech CS|3.8|Active
Jane Smith|STU002|21|jane@email.com|B.Tech CS|3.9|Active
```

### faculty.txt
```
Dr. Robert Brown|FAC001|45|robert@university.edu|Computer Science|Professor
Dr. Sarah Lee|FAC002|42|sarah@university.edu|Mathematics|Associate Professor
```

### courses.txt
```
CS101|Introduction to Programming|4|None|FAC001
CS201|Data Structures|4|CS101|FAC001
```

### enrollments.txt
```
STU001|CS101|0|Fall 2024
STU001|CS201|0|Spring 2025
STU002|CS101|0|Fall 2024
```

## 👨‍💼 Author & Credits

**Developer:** Nihal Hussain  
**Registration Number:** 711524BCS106  
**Department:** Computer Science and Engineering – Section B

Developed as a comprehensive mini-project for Object-Oriented Programming course to demonstrate advanced C++ concepts and real-world system design.

## 🙏 Acknowledgments

- Based on OOP principles and design patterns
- Inspired by real-world university management systems
- Educational resource for computer science students
- Reference for multiple inheritance implementation

## 📞 Support & Contribution

- Report issues on GitHub Issues
- Submit pull requests for improvements
- Suggest enhancements via GitHub Discussions
- Fork and customize for your institution

## 🎓 Educational Value

This project is ideal for:
- Computer Science students learning OOP
- Teaching inheritance and polymorphism
- Understanding file-based database design
- Learning C++ best practices
- Portfolio development for employment

---

**Happy Learning! 💻**

*Transform educational management with robust C++ architecture!*
