#include "headers.h"
#include <iostream>

structureBoolInt gradeCheck;
structureBoolInt check;
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
        validateNumber(stringExamGrade);
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
            validateNumber(stringClassGrade);
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

structureBoolInt validateNumber(std::string count) {
    std::regex checkIfNumber("^\\d+$");

    if (cin.fail()) {
        // Redundant ?
        cout << "Amount is not a valid number. Please try again: " << endl;
        check.inputOkay = false;
    }
    else if (std::regex_match(count, checkIfNumber) == false) {
        cout << "Amount is not a valid number. Please try again: " << endl;
        check.inputOkay = false;
    }
    else {
        check.validatedNumber = std::stoi(count);
        check.inputOkay = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return check;
};

std::vector<int> generateClassGrades() {
    std::vector<int> grades;
    std::string gradeCount;
    cout << "Type the amount of grades you wish to generate: ";
    do {
        cin >> gradeCount;
        validateNumber(gradeCount);
    } while (check.inputOkay == false);
    for (int i = 0; i < check.validatedNumber; i++) {
            cout << endl << "Grade " << i + 1 << " is: ";
            grades.push_back(generateRandomGrade());
            cout << grades[i] << endl;
        }
    return grades;
}

void generateFile(std::string name) {
    ofstream file(name);

    std::string studentAmount;
    std::string gradeAmount;

    cout << "Type the amount of students you wish to generate: ";
    do {
        cin >> studentAmount;
        validateNumber(studentAmount);
    } while (check.inputOkay == false);
    
    cout << "Type the amount of class grades you wish to generate for each student: ";
    do {
        cin >> gradeAmount;
        validateNumber(gradeAmount);
    } while (check.inputOkay == false);

    // Get starting timepoint for speedtest
    // auto startFileGeneration = high_resolution_clock::now(); // <- Uncomment for testing

    file << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 1; i <= std::stoi(gradeAmount); i++) {
        file << std::setw(6) << "ND" + std::to_string(i); 
    }
    file << std::setw(6) << "Egz." << std::endl;

    for (int i = 1; i <= std::stoi(studentAmount); i++) {
        file << std::left << std::setw(15) << "Vardas" + std::to_string(i) << std::setw(15) << "Pavarde" + std::to_string(i);
        for (int y = 1; y <= std::stoi(gradeAmount); y++) {
            file << std::setw(6) << generateRandomGrade();
        }
        file << std::setw(6) << generateRandomGrade() << std::endl;
    }

    file.close();

    //Uncomment for testing
    // Get ending timepoint for speedtest
    /*auto stopFileGeneration = high_resolution_clock::now();

    // Get time taken for file generation in seconds
    auto durationFileGeneration = duration_cast<microseconds>(stopFileGeneration - startFileGeneration);

    cout << "SPEED TEST RESULTS" << endl;
    cout << "Students (lines) in file: " << std::stoi(studentAmount) << endl;
    cout << "Amount of class grades for each student: " << std::stoi(gradeAmount) << endl;
    cout << "File generated in " << durationFileGeneration.count() << " microseconds." << endl;
    double secondsFileGeneration = durationFileGeneration.count() / 1000000.0;
    cout << "Converted to seconds: " << secondsFileGeneration << endl;*/
};

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

bool validateFileMethod(int method) {
    bool methodOkay;
    if (cin.fail()) {
        // Redundant ?
        cout << "Invalid option chosen. Please try again: " << endl;
        methodOkay = false;
    }
    else if ((method != 1) && (method != 2)){
        cout << "Invalid option chosen. Please try again: " << endl;
        methodOkay = false;
    }
    else {
        method = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return method;
};

int generateRandomGrade() {

	// Get a random grade from 1 to 10
	int randomGrade = 1 + rand() % 10;

    return randomGrade;
};

int generateRandomNumber() {

	// Get a random number from 0 to 9
	int randomNumber = rand() % 10;

    return randomNumber;
};

// Parse information from given file
// Format of file: NAME SURNAME CLASS_GRADES(n) EXAM_GRADE
structureTestVector parseStudentInfo(std::string& line) {
    tempStudent.classGrade.clear();
    tempStudent.gradeCount = 0;
    int tempGrade;
    int whitespace = count(line.cbegin(), line.cend(), ' ');
    int lineLength = line.length();
    int actualLength = line.length() - whitespace;
    std::istringstream stream(line);
    // Fix logic!!
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

// For list version
void sortOutputList(list<structureTestVector> &students, int option) {
    if (option == 1) {
        students.sort(sortByName);
    }
    else if (option == 2) {
        students.sort(sortBySurname);
    }
    else if (option == 3) {
        students.sort(sortByAverage);
    }
    else if (option == 4) {
        students.sort(sortByMedian);
    }
}

// For deque version
void sortOutputDeque(deque<structureTestVector> &students, int option) {
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
