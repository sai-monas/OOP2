#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>
#include <iomanip>

// For file
#include <fstream>
#include <sstream>
using std::ifstream;
using std::ofstream;

// For regex
#include <regex>
#include <cstdlib>

// For speedtest
#include <chrono>
using namespace std::chrono;

// For list
#include <list>
using std::list;

// For deque
#include <deque>
using std::deque;

using std::cout;
using std::cin;
using std::endl;
using std::count;

#include <cstdio>

class Student {
    // realizacija
    private:
        std::string name;
        std::string surname;
        int examGrade;
        std::vector<int> classGrade;
    // interfeisas
    public:
        Student() {
            //cout << "Constructor called" << endl;
        };
        std::string getName() {
            return name;
        };
        std::string getSurname() {
            return surname;
        };
        int getExamGrade() {
            return examGrade;
        };
        std::vector<int> getClassGrade() {
            return classGrade;
        };
        int calculateSum() {
            int sum = examGrade;
            for (int i = 0; i < classGrade.size(); i++) {
                sum += classGrade[i];
            }
            return sum;
        };
        int calculateCount() {
            int count = classGrade.size() + 1;
            return count;
        };
        double calculateAverage() { 
            //double average = static_cast<double>(calculateSum())/(calculateCount());
            return static_cast<double>(calculateSum())/(calculateCount());
        };
        double calculateMedian() {
            double median;
            std::vector<int> allGrades = classGrade;
            allGrades.insert(allGrades.begin(), examGrade);
            sort(allGrades.begin(),allGrades.end());
    
            // Odd number
            if (calculateCount() % 2 != 0) {
                median = (double)allGrades[calculateCount() / 2];
            }
            // Even number
            else {
                median = (double)(allGrades[(calculateCount() - 1) / 2] + allGrades[calculateCount() / 2]) / 2.0;
            }
            allGrades.clear();
            return median;
        };
        void setFromFile(std::string& line) {
            int tempGrade;
            int whitespace = count(line.cbegin(), line.cend(), ' ');
            int lineLength = line.length();
            int actualLength = line.length() - whitespace;
            std::istringstream stream(line);
            if (whitespace >= 0) {
                stream >> name;
            }
            if (whitespace >= 1) {
                stream >> surname;
            } 
            if (whitespace >= 2) {
                for (int i = 0; i < (actualLength - name.length() - surname.length()); i++) {
                stream >> tempGrade;
                if (tempGrade == 10) {
                    actualLength -= 1;
                }
                classGrade.push_back(tempGrade);
                };
            }
            examGrade = classGrade[calculateCount() - 2];
            classGrade.pop_back();
        };
        void setName(std::string n) {
            name = n;
        };
        void setSurname(std::string s) {
            surname = s;
        };
        void setExamGrade(int ex) {
            examGrade = ex;
        };
        void setClassGrades(std::vector<int> cl) {
            classGrade = cl;
        };
    ~Student() {
        //cout << "Destructor called" << endl;
    };
};

std::vector<Student> students;

bool sortByName(Student& s1, Student& s2) {
    return s1.getName() < s2.getName();
}

bool sortBySurname(Student& s1, Student& s2) {
    return s1.getSurname() < s2.getSurname();
}

bool sortByAverage(Student& s1, Student& s2) {
    return s1.calculateAverage() < s2.calculateAverage();
}

bool sortByMedian(Student& s1, Student s2) {
    return s1.calculateMedian() < s2.calculateMedian();
}

void sortOutput(std::vector<Student> &students, int option) {
    if (option == 1) {
        std::sort(students.begin(), students.end(), sortByName);
    }
    else if (option == 2) {
        std::sort(students.begin(), students.end(), sortBySurname);
    }
    else if (option == 3) {
        std::sort(students.begin(), students.end(), sortByAverage);
    }
    else if (option == 4) {
        std::sort(students.begin(), students.end(), sortByMedian);
    }
}


    int main() {
        /*std::vector<int> grades;
        grades.push_back(10);
        grades.push_back(9);
        grades.push_back(5);
        Student student("Saimonas", "Sudintas", 10, grades);
        cout << student.getName() << endl << student.getSurname() << endl << student.getExamGrade() << endl;
        for (int i = 0; i < student.getClassGrade().size(); i++) {
            cout << student.getClassGrade()[i] << endl;
        }
        //cout << student.calculateAverage() << endl << student.calculateMedian() << endl;*/

        std::vector<Student> students;
        //students.push_back(student);

        std::string currentLine;
        std::string firstLine;
        
        std::string fileName = "studentai1000";
        bool fileRead = false;

        // Read from the text file
        ifstream file(fileName);

        // Ignore the first line (header)
        getline(file, firstLine);

        while (getline (file, currentLine)) {
            Student st;
            st.setFromFile(currentLine);
            //cout << "Constructor outside" << endl;
            //cout << st.getName() << " " << st.getSurname() << " " << st.calculateAverage() << " " << st.getExamGrade() << endl; 
            students.push_back(st);
            //cout << "While loop iteration ended" << endl;
        }

        // Close the file
        file.close();

        sortOutput(students, 3);


        cout << "Name            Surname         Average  Median" << endl << "-------------------------------------------------" << endl;
        for (auto y :students){
        cout << std::left << std::setw(15) << y.getName() << " " << std::setw(15) << y.getSurname() << " " <<
         std::setw(9) << std::setprecision(3) << y.calculateAverage() << std::setw(9) << std::setprecision(3) << y.calculateMedian() << endl;
        }


        return 0;
    }