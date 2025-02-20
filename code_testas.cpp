#include "headers_testas.h"

structureTest student;

// reik nepriimt float double char string!!
void checkGrades(int &grade) {
    while (grade < 1 || grade > 10) {
    cout << "Incorrect value entered. Make sure that the exam grade is in range 1-10. Please try again." << endl;
    cout << "Input student grade: ";
    cin >> grade;};
};

int main() {
    cout.precision(2);

    structureTest student;
    std::vector<structureTest> testukas;
    int classGradeCount;
    int interimClassGrade;
    int classGradeSum = 0;
    float averageGrade;
    student.examGrade;

    // Collect inputs
    while (student.name !=  "x") {

        // Collect student's first name
        cout << "Input student name: ";
        cin >> student.name;

        // Check if user wants to exit program
        if (student.name == "x") break;

        // Collect student's last name
        cout << "Input student surname: ";
        cin >> student.surname;

        // Collect student's exam grade
        cout << "Input student exam grade: ";
        cin >> student.examGrade;

        // Check if student's exam grade is in range
        checkGrades(student.examGrade);

        // Get class grade count
        cout << "Type the amount of marks you wish to add: " << endl;
        cin >> classGradeCount;

        // Loop for class grades
        for (int i = 1; i <= classGradeCount; i++) {
            
            // Collect class grades for the student
            cout << "Input student class grade nr. " << i << ": ";
            cin >> interimClassGrade;

            // Check if student's class grade is in range
            checkGrades(interimClassGrade);

            // Push value to vector
            student.classGrade.push_back(interimClassGrade);

            // Get sum of class grades for avg calculation
            classGradeSum += interimClassGrade;};
        
        // Calculate average of all grades for each student
        student.averageGrade = static_cast<float>(classGradeSum + student.examGrade) / (classGradeCount + 1);

        testukas.push_back({student});

        // Clear out variables
        student.classGrade.clear();
        classGradeSum = 0;
    }

    // Test if inputs are working
    /*cout << "Name   Surname   Exam grade    Class grades" << endl << "-------------------------------------------------" << endl;
    for (auto n :testukas){
	    cout << n.name << " " << n.surname << " " << n.examGrade << " ";
        for (auto v : n.classGrade)
            cout << v << " ";
        cout << endl;
    };*/

    // Print out students with their average grades
    cout << "Name       Surname   Average" << endl << "-------------------------------------------------" << endl;
    for (auto y :testukas){
	    cout << y.name << "  " << y.surname << "    " << y.averageGrade << endl;
    }
    return 0;
}