#include "headers_testas.h"
#include <fstream>
using std::ifstream;
#include <sstream>
using std::count;

struct tempStudentInfo {
    std::string name;
    std::string surname;
    std::vector<int> grades;
    int exam;
    int count;
};

std::vector<tempStudentInfo> studentGroup;
tempStudentInfo student;

tempStudentInfo parseStudentInfo(std::string& myLine) {
    student.count = 0;
    int hi, hii;
    int arg = count(myLine.cbegin(), myLine.cend(), ' ');
    int lineLength = myLine.length();
    int actualLength = lineLength - arg;
    std::istringstream stream(myLine);
    if (arg >= 0) {
        stream >> student.name;
    }
    if (arg >= 1) {
        stream >> student.surname;
    } 
    if (arg >= 2) {
        for (int i = 0; i < (actualLength - student.name.length() - student.surname.length()); i++) {
        stream >> hi;
        if (hi == 10) {
            actualLength -= 1;
        }
        student.grades.push_back(hi);};
    };
    return student;
}


int main() {
    
    // Create a text string, which is used to output the text file
    std::string myLine;
    std::string junkText;
    tempStudentInfo studentReal;


    // Read from the text file
    ifstream MyReadFile("kursiokai.txt");

    int lineCount = 2;

    getline(MyReadFile, junkText);

     while (getline (MyReadFile, myLine)) {
        //const auto args = parseArgs(myLine);
        studentReal = parseStudentInfo(myLine);
        cout << "Number of class grades: " << studentReal.grades.size() << "    16th grade: " << studentReal.grades[studentReal.grades.size() - 1] <<endl;
        studentReal.exam = studentReal.grades[studentReal.grades.size() - 1];
        studentReal.grades.pop_back();
        cout << "Number of class grades: " << studentReal.grades.size() << "    16th grade: " << studentReal.grades[studentReal.grades.size() - 1] <<endl;
        cout << "Exam grade: " << studentReal.exam << endl << endl;
        studentGroup.push_back(studentReal);
        student.grades.clear();
        studentReal.grades.clear();
     }

     cout << "Name   Surname   Class grades                 Exam grade" << endl << "------------------------------------------------------------" << endl;
     for (auto n :studentGroup){
         cout << n.name << " " << n.surname << " ";
         for (auto v : n.grades)
             cout << v << " ";
        cout << "   " << n.exam;
        cout << endl;
     }

    // Close the file
    MyReadFile.close();

}