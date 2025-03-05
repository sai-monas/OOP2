#include "headers.h"
#include <iostream>

structureBoolInt gradeCheck;
structureBoolInt countCheck;
structureTestVector tempStudent;

double calculateAverageGrade(int sum, int count) {
    double average = static_cast<double>(sum)/(count);
    return average;
}

double calculateMedianGrade(std::vector<int> grades, int exam) {
    double medianGrade;
    std::vector<int> allGrades = grades;
    allGrades.insert(allGrades.begin(), exam);
    sort(allGrades.begin(),allGrades.end());
    int allGradeCount = allGrades.size();

    // Odd number
    if (allGradeCount % 2 != 0) {
        medianGrade = (double)allGrades[allGradeCount / 2];
    }
    // Even number
    else {
        medianGrade = (double)(allGrades[(allGradeCount - 1) / 2] + allGrades[allGradeCount / 2]) / 2.0;
    }
    allGrades.clear();
    return medianGrade;
}

void outputMedianOrAverage(std::vector<structureTestVector> students, std::string choice) {
    // Median output
    if (choice == "M" || choice == "m") {
        cout << "Name            Surname         Median" << endl << "-------------------------------------------------" << endl;
        for (auto y :students) {
        cout << std::left << std::setw(15) << y.name << " " << std::setw(15) << y.surname << " " <<
         std::setw(9) << std::setprecision(3) << y.medianGrade<< endl;
        }
    }
    // Average output
    else if (choice == "A" || choice == "a") {
        cout << "Name            Surname         Average" << endl << "-------------------------------------------------" << endl;
        for (auto y :students){
        cout << std::left << std::setw(15) << y.name << " " << std::setw(15) << y.surname << " " <<
         std::setprecision(3) << y.averageGrade<< endl;
        }
    }
}

void outputMedianAndAverage(std::vector<structureTestVector> students) {
    cout << "Name            Surname         Average  Median" << endl << "-------------------------------------------------" << endl;
        for (auto y :students){
        cout << std::left << std::setw(15) << y.name << " " << std::setw(15) << y.surname << " " <<
         std::setw(9) << std::setprecision(3) << y.averageGrade << std::setw(9) << std::setprecision(3) << y.medianGrade<< endl;
        }
}

int collectExamGrade() {
    std::string stringExamGrade;
    do {
        cout << "Input student's exam grade: ";
        cin >> stringExamGrade;
        validateGrade(stringExamGrade);
    } while (gradeCheck.inputOkay == false);

    // Accept the exam grade
    return gradeCheck.validatedNumber;
}

std::vector<int> collectClassGrade() {
    cout << "- Please type 0 for the grade if you do not have any remaining grades left" << endl;
    std::string stringClassGrade;
    std::vector<int> grades;
    int gradeCount = -1;
    while (gradeCheck.validatedNumber != 0) {
        gradeCount++;
        cout << "Enter grade " << gradeCount + 1 << ": " << endl;
        // Check if collected grade is valid
         do {
            cin >> stringClassGrade;
            validateGrade(stringClassGrade);
         } while (gradeCheck.inputOkay == false);

         // Accept the class grade
         grades.push_back(gradeCheck.validatedNumber);
    };
    return grades;
}


int calculateSum(std::vector<int> grades) {
    int count = grades.size();
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum;
}

structureBoolInt validateGrade(std::string grade) {
    std::regex checkIfNumber("^\\d+$");

    if (cin.fail()) {
        // Redundant ?
        cout << "Grade is not a valid number. Please try again: " << endl;
        gradeCheck.inputOkay = false;
    }
    else if (std::regex_match(grade, checkIfNumber) == false) {
        cout << "Grade is not a valid number. Please try again: " << endl;
        gradeCheck.inputOkay = false;
    }
    else {
        gradeCheck.validatedNumber = std::stoi(grade);
        gradeCheck.inputOkay = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return gradeCheck;
};

structureBoolInt validateGradeCount(std::string count) {
    std::regex checkIfNumber("^\\d+$");

    if (cin.fail()) {
        // Redundant ?
        cout << "Amount is not a valid number. Please try again: " << endl;
        countCheck.inputOkay = false;
    }
    else if (std::regex_match(count, checkIfNumber) == false) {
        cout << "Amount is not a valid number. Please try again: " << endl;
        countCheck.inputOkay = false;
    }
    else {
        countCheck.validatedNumber = std::stoi(count);
        countCheck.inputOkay = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return countCheck;
};

std::vector<int> generateClassGrades() {
    std::vector<int> grades;
    std::string gradeCount;
    cout << "Type the amount of grades you wish to generate: ";
    do {
        cin >> gradeCount;
        validateGradeCount(gradeCount);
    } while (countCheck.inputOkay == false);
    for (int i = 0; i < countCheck.validatedNumber; i++) {
            cout << endl << "Grade " << i + 1 << " is: ";
            grades.push_back(generateRandomGrade());
        }
    return grades;
}

bool validateOutputOption(std::string output) {
    bool outputOkay;
    if (cin.fail()) {
        // Redundant ?
        cout << "Invalid output option chosen. Please try again: " << endl;
        outputOkay = false;
    }
    else if ((output != "M") && (output != "m") && (output != "A") && (output != "a")){
        cout << "Invalid output option chosen. Please try again: " << endl;
        outputOkay = false;
    }
    else {
        outputOkay = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return outputOkay;
};

bool validateInputOption(int input) {
    bool inputOkay;
    if (cin.fail()) {
        // Redundant ?
        cout << "Invalid option chosen. Please try again: " << endl;
        inputOkay = false;
    }
    else if ((input != 1) && (input != 2) && (input != 3) && (input != 4) && (input != 5)){
        cout << "Invalid option chosen. Please try again: " << endl;
        inputOkay = false;
    }
    else {
        inputOkay = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return inputOkay;
};

int generateRandomGrade() {

	// Get a random grade from 1 to 10
	int randomGrade = 1 + rand() % 10;

    // Print to show user in terminal
	cout<< randomGrade <<endl;

    return randomGrade;
};

int generateRandomNumber() {

	// Get a random number from 0 to 9
	int randomNumber = rand() % 10;

    return randomNumber;
};

structureTestVector parseStudentInfo(std::string& line) {
    tempStudent.classGrade.clear();
    tempStudent.gradeCount = 0;
    int tempGrade;
    int whitespace = count(line.cbegin(), line.cend(), ' ');
    int lineLength = line.length();
    int actualLength = line.length() - whitespace;
    std::istringstream stream(line);
    if (whitespace >= 0) {
        stream >> tempStudent.name;
    }
    if (whitespace >= 1) {
        stream >> tempStudent.surname;
    } 
    if (whitespace >= 2) {
        for (int i = 0; i < (actualLength - tempStudent.name.length() - tempStudent.surname.length()); i++) {
        stream >> tempGrade;
        if (tempGrade == 10) {
            actualLength -= 1;
        }
        tempStudent.classGrade.push_back(tempGrade);};
    };
    return tempStudent;
}

void sortOutput(std::vector<structureTestVector> &students, int option) {
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

bool sortByName(structureTestVector& s1, structureTestVector& s2) {
    return s1.name < s2.name;
}

bool sortBySurname(structureTestVector& s1, structureTestVector& s2) {
    return s1.surname < s2.surname;
}

bool sortByAverage(structureTestVector& s1, structureTestVector& s2) {
    return s1.averageGrade < s2.averageGrade;
}

bool sortByMedian(structureTestVector& s1, structureTestVector& s2) {
    return s1.medianGrade < s2.medianGrade;
}