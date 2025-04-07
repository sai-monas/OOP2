#include "headers.h"
#include <windows.h> // For Lithuanian output (SetConsoleOutputCP(CP_UTF8))

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

structureBoolInt gradeCheckClass;

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
        void printAverageAndMedian() {
            cout << std::left << std::setw(15) << getName() << " " << std::setw(15) << getSurname() << " " <<
                std::setw(9) << std::setprecision(3) << calculateAverage() << std::setw(9) << std::setprecision(3) << calculateMedian() << endl;
        }
        void printAverage() {
            cout << std::left << std::setw(15) << getName() << " " << std::setw(15) << getSurname() << " " <<
                std::setw(9) << std::setprecision(3) << calculateAverage() << endl;
        }
        void printMedian() {
            cout << std::left << std::setw(15) << getName() << " " << std::setw(15) << getSurname() << " " <<
                std::setw(9) << std::setprecision(3) << calculateMedian() << endl;
        }
        void inputExamGrade() {
            /*std::string stringExamGrade;
            do {
                cout << "Input student's exam grade: ";
                cin >> stringExamGrade;
                validateNumber(stringExamGrade);
            } while (gradeCheckClass.inputOkay == false);

            // Accept the exam grade
            examGrade = gradeCheckClass.validatedNumber;*/
            cin >> examGrade;
        }
        void inputClassGrades() {
            cout << "- Please type 0 for the grade if you do not have any remaining grades left" << endl;
            int grade;
            int gradeCount = -1;
            while (grade != 0) {
                gradeCount++;
                cout << "Enter grade " << gradeCount + 1 << ": " << endl;
                cin >> grade;

            // Accept the class grade
            classGrade.push_back(grade);
            };
            if (getClassGrade()[gradeCount] = 0) {
                classGrade.pop_back();
            }
        }
        void clearGrades() {
            classGrade.clear();
        }
        ~Student() {
            //cout << "Destructor called" << endl;
        };
};

std::vector<Student> students;

bool isLessThanFiveClass(Student st) {
    return (st.calculateAverage() >= 5);
}

bool sortByNameClass(Student& s1, Student& s2) {
    return s1.getName() < s2.getName();
}

bool sortBySurnameClass(Student& s1, Student& s2) {
    return s1.getSurname() < s2.getSurname();
}

bool sortByAverageClass(Student& s1, Student& s2) {
    return s1.calculateAverage() < s2.calculateAverage();
}

bool sortByMedianClass(Student& s1, Student s2) {
    return s1.calculateMedian() < s2.calculateMedian();
}

void sortOutputClass(std::vector<Student> &students, int option) {
    if (option == 1) {
        std::sort(students.begin(), students.end(), sortByNameClass);
    }
    else if (option == 2) {
        std::sort(students.begin(), students.end(), sortBySurnameClass);
    }
    else if (option == 3) {
        std::sort(students.begin(), students.end(), sortByAverageClass);
    }
    else if (option == 4) {
        std::sort(students.begin(), students.end(), sortByMedianClass);
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
        //students.push_back(student);

       /*
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

        sortOutputClass(students, 4);


        cout << "Name            Surname         Average  Median" << endl << "-------------------------------------------------" << endl;
        for (auto y :students){
            y.printAverageAndMedian();
        }
    */

    // From main_vector.cpp

    // Variable for user choice of input
    int inputOption;
    
    // Variables for user choice of output 
    std::string outputOption;
    int fileOutputOption;

    // For random student generation
    std::string randomNames[10] = {"Konstantinas", "Danielius", "Vardenis", "Aleksandras", "Kazimieras", "Fridrichas", "Deimantas", "Tautvydas", "Edgaras", "Marijonas"};
    std::string randomSurnames[10] = {"Muilinas", "Pavardenis", "Kavinukas", "Arbataitis", "Antinas", "Mogila", "Sudimtas", "Jonelaitis", "Regesas", "Mamontovas"};
    int studentCount;
    int keepingStudentCount = 0;
    bool generationFinished = false;
    // Providing a seed value for random numbers/grades
	srand(time(0));

    // Start menu with 5 options
    cout << "Welcome to student grade calculator. Choose next steps: " << endl;
    cout << "- Type 1 for manual grade input" << endl << "- Type 2 for grade generation" << endl
    << "- Type 3 to generate students and their grades" << endl  << "- Type 4 to calculate from file" << endl
    << "- Type 5 to exit the program" << endl;

    // Check which option to use
    do {
        cout << "Waiting for your answer: ";
        cin >> inputOption;
     } while (validateInputOption(inputOption) == false);

        // Exit program if 5th option is chosen
        if (inputOption == 5) {
            cout << endl << "Have a nice day!";
            return 0;};
    
        // File option chosen
        if (inputOption == 4) {
            std::string currentLine;
            std::string firstLine;
            std::string fileName;
            bool fileRead = false;

            int fileOption;

            cout << "File option chosen for the calculations!" << "Choose a method: " << endl;
            cout << "- Type 1 to use an existing file" << endl << "- Type 2 to generate a file" << endl;
            do {
                cout << "Waiting for your answer: ";
                cin >> fileOption;
             } while (validateFileMethod(fileOption) == false);

            if (fileOption == 1) {

                cout << "Input file name to use for calculations: ";
                while (fileRead == false) {
                    try {
                        cin >> fileName;

                        // Read from the text file
                        ifstream file(fileName);

                        // Get first line from the file
                        getline(file, firstLine);

                        // Check if first line is empty
                        if (firstLine.empty() == false) {
                            cout << "File '" << fileName << "' opened successfully!" << endl;
                            fileRead = true;
                        }
                        else {
                            throw fileName;
                        }
                    }
                    catch (std::string input) {
                        setlocale(LC_ALL, ".UTF8");
                        SetConsoleOutputCP(CP_UTF8);
                        std::wcout << L"Klaida: pateiktas failas pavadinimu '";
                        std::cout << input;
                        std::wcout << L"' yra tuščias arba neegzistuoja. Bandykite iš naujo: ";
                    }
                }
            }

            if (fileOption == 2) {

                // Name the file to generate
                cout << "Name the file that will be generated: ";
                cin >> fileName;

                // Generate the file
                generateFile(fileName);
            }

                // Get starting timepoint for file reading
                auto startReadingFile = high_resolution_clock::now();
            
            // Read from the text file
            ifstream file(fileName);

            // Ignore the first line (header)
            getline(file, firstLine);

            while (getline (file, currentLine)) {
                Student st;
                st.setFromFile(currentLine);
                students.push_back(st);
            }

            // Close the file
            file.close();

                // Get ending timepoint for file reading
                auto stopReadingFile = high_resolution_clock::now();

            // Sorting option menu
            cout << "Would you like to sort the results by name, surname, average grade or median grade?" << endl;
            cout << "- Type 1 to sort by name" << endl << "- Type 2 to sort by surname" << endl
                << "- Type 3 to sort by average grade" << endl  << "- Type 4 to sort by median grade" << endl
                << "- Type 5 to skip sorting" << endl;

            // Check the sorting option chosen
            do {
                cout << "Waiting for your answer: ";
                cin >> fileOutputOption;
            } while (validateInputOption(fileOutputOption) == false);

            //fileOutputOption = 3; // Sorting by average for testing

                // Get starting timepoint for sorting
                auto startSortingStudents = high_resolution_clock::now();

            // Sort the structure
            sortOutputClass(students, fileOutputOption);

                // Get ending timepoint for sorting
                auto stopSortingStudents = high_resolution_clock::now();

            // outputMedianAndAverage(studentGroup); Commenting out for testing

                // Get starting timepoint for separating students
                auto startSeparatingStudents = high_resolution_clock::now();

            // "Bad" student group creation
            //std::vector<structureTestVector> badStudent; // average < 5

            // "Good" student group creation
            //std::vector<structureTestVector> goodStudent; // average >= 5 // <- Commenting out for further tests

            // 1st strategy - creating two new containers for "good" and "bad" students
            /*for (auto i: studentGroup) {
                if (i.averageGrade < 5) {
                    badStudent.push_back(i);
                }
                else {
                    goodStudent.push_back(i);
                }
            }*/

            // 2nd strategy - leaving "good" students in default student group (studentGroup), and moving the "bad" students to a separate container
            /*int keepingCountForSeparating = 0;
            for (auto i: studentGroup) {
                if (i.averageGrade < 5.0) {
                    badStudent.push_back(i);
                    keepingCountForSeparating++;
                }
            }
            studentGroup.erase(studentGroup.begin(), studentGroup.begin() + keepingCountForSeparating);*/


            auto it = std::stable_partition(students.begin(), students.end(), isLessThanFiveClass); // !!!!!
            std::vector<Student> badStudent(std::make_move_iterator(it), std::make_move_iterator(students.end()));
            students.erase(it, students.end());

                // Get ending timepoint for separating students
                auto stopSeparatingStudents = high_resolution_clock::now();

            // Create file for "bad" students
            ofstream fileBad("bad_students");
            fileBad << firstLine << endl;
            for (auto n: badStudent) {
                fileBad << std::left << std::setw(15) << n.getName() << std::setw(15) << n.getSurname();
                for (int x = 0; x < n.calculateCount(); x++) {
                    fileBad << std::setw(6) << n.getClassGrade()[x];
                }
                fileBad << std::setw(6) << n.getExamGrade() << endl;
            }

            cout << "File 'bad_students' created successfully. 'bad_students' contains students which failed the course (average grade less than 5)." << endl;

            fileBad.close();


            // Create file for "good" students - 1st strategy
            /*ofstream fileGood("good_students");
            fileGood << firstLine << endl;
            for (auto n: goodStudent) {
                fileGood << std::left << std::setw(15) << n.name << std::setw(15) << n.surname;
                for (int x = 0; x < n.gradeCount; x++) {
                    fileGood << std::setw(6) << n.classGrade[x];
                }
                fileGood << std::setw(6) << n.examGrade << endl;
            }*/

            // Create file for "good" students - 2nd strategy
            ofstream fileGood("good_students");
            fileGood << firstLine << endl;
            for (auto n: students) {
                fileGood << std::left << std::setw(15) << n.getName() << std::setw(15) << n.getSurname();
                for (int x = 0; x < (n.calculateCount() - 1); x++) {
                    fileGood << std::setw(6) << n.getClassGrade()[x];
                }
                fileGood << std::setw(6) << n.getExamGrade() << endl;
            }

            cout << "File 'good_students' created successfully. 'good_students' contains students which passed the course (average grade more than or equal to 5)." << endl;

            fileGood.close();

            auto durationReadingFile = duration_cast<microseconds>(stopReadingFile - startReadingFile);
            double secondsReadingFile = durationReadingFile.count() / 1000000.0;

            auto durationSortingStudents = duration_cast<microseconds>(stopSortingStudents - startSortingStudents);
            double secondsSortingStudents = durationSortingStudents.count() / 1000000.0;

            auto durationSeparatingStudents = duration_cast<microseconds>(stopSeparatingStudents - startSeparatingStudents);
            double secondsSeparatingStudents = durationSeparatingStudents.count() / 1000000.0;


            cout << "SPEED TEST RESULTS" << endl;
            cout << "Variables from file read in " << durationReadingFile.count() << " microseconds." << "  Converted to seconds: " << secondsReadingFile << endl;
            cout << "Students sorted in: " << durationSortingStudents.count() << " microseconds." << "  Converted to seconds: " << secondsSortingStudents << endl;
            cout << "Students separated to two groups in: " << durationSeparatingStudents.count() << " microseconds." << "  Converted to seconds: " << secondsSeparatingStudents << endl;

            } // 4th option finished

        // 1st, 2nd and 3rd options
        if ((inputOption == 1) || (inputOption == 2) || (inputOption == 3)) {

            Student st;
            std::string nm;
            std::string srn;

            if (inputOption == 3) {
                // Check amount of students to generate for full generation option
                cout << "Type the amount of students you wish to generate: ";
                cin >> studentCount; 
            }

            // Collect inputs
            // While clause only relevant for 1st and 2nd options
            while (st.getName() !=  "x" || st.getName() != "X") {
        
        
            // Get student's first name for 1st and 2nd options
            if ((inputOption == 1) || (inputOption == 2)) {
                cout << "- Please type X for the student name if you do not have any remaining students left." << endl;
                cout << "Input student name: ";
                cin >> nm;
                st.setName(nm);
            }
            else {
                // Track number of students (and their grades) already generated
                keepingStudentCount += 1;
                if (keepingStudentCount <= studentCount) {
                    st.setName(randomNames[generateRandomNumber()]);
                }
                else {
                    generationFinished = true;
                }
            }

            // Check if user wants to exit program for 1st & 2nd options
            if (st.getName() == "x" || st.getName() == "X") {
                cout << "<< Student input finished >>" << endl;
                break;
            }

            // Check if all requested students were generated for 3rd option
            if (generationFinished == true) {
            break;
            }


            // Get student's last name
            if ((inputOption == 1) || (inputOption == 2)) {
                cout << "Input student surname: ";
                cin >> srn;
                st.setSurname(srn);
            }
            else {
                st.setSurname(randomSurnames[generateRandomNumber()]);
                cout << "Student " << keepingStudentCount << " is: " << st.getName() << " " << st.getSurname() << endl;
            }

            // Ask for exam grade for 1st option
            if (inputOption == 1) {
                cout << "Input student exam grade: ";
                st.inputExamGrade();
            }
            // Generate exam grade for 2nd & 3rd options
            else {
                cout << "Exam grade is: ";
                st.setExamGrade(generateRandomGrade());
                cout << st.getExamGrade() << endl;
            }

            // Ask for class grades for 1st option
            if (inputOption == 1) {

                // Collect student's class grades
                st.inputClassGrades();

                // Remove last element (0) from vector
                //student.classGrade.pop_back();
            }
            else {
                st.setClassGrades(generateClassGrades());
            }

            cout << "<< Class grade input finished for " << st.getName() << " >>" << endl;

            students.push_back(st);

            st.clearGrades();

        } // While loop finished

        cout << "<< Student data collection finished >>" << endl;

        cout << "Would you like to receive a median or an average of the grades?" << endl << "Please type M for median, or A for average: ";
        do {
            cin >> outputOption;
        } while (validateOutputOption(outputOption) == false); // Check that chosen output option is M (m) or A (a)
        // Print chosen output
        cout << "Name            Surname         Average " << endl << "-------------------------------------------------" << endl;
        if (outputOption == "M" || outputOption == "m") {
            for (auto y :students){
                y.printMedian();
            }
            }
        // Average output
        else if (outputOption == "A" || outputOption == "a") {
            for (auto y :students){
                y.printAverage();
            }
            }

        } // 1st, 2nd and 3rd options finished

    return 0;
    }