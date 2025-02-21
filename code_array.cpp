#include "headers_testas.h"

structureBoolInt testas;

structureBoolInt validateGrade(std::string grade) {
    std::regex checkIfNumber("^\\d+$");

    if (cin.fail()) {
        // Redundant ?
        cout << "Grade is not a valid number" << endl;
        testas.inputOkay = false;
    }
    else if (std::regex_match(grade, checkIfNumber) == false) {
        cout << "Grade is not a valid number ((regex))" << endl;
        testas.inputOkay = false;
    }
    else if (std::stof(grade) > 10 || std::stof(grade) < 0 ) {
        cout << "Incorrect value entered. Make sure that the exam grade is in range 1-10. Please try again." << endl;
        testas.inputOkay = false;
    }
    else {
        testas.validatedGrade = std::stoi(grade);
        testas.inputOkay = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
    return testas;
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

int main() {
    structureTestArray student;
    cout.precision(2);
    int classGradeSum = 0;
    std::vector<structureTestArray> studentGroup;
    std::string stringClassGrade;
    std::string stringExamGrade;

    std::string outputOption;

    while (student.name !=  "x") {

        // Collect student's first name
        cout << "Input student name: ";
        cin >> student.name;

        // Check if user wants to exit program
        if (student.name == "x") break;

        // Collect student's last name
        cout << "Input student surname: ";
        cin >> student.surname;

        // Check if collected grade is valid
        do {
            cout << "Input student exam grade: ";
            cin >> stringExamGrade;
            validateGrade(stringExamGrade);
         } while (testas.inputOkay == false);

        // Accept the exam grade
         student.examGrade = testas.validatedGrade;

        //student.classGrade = new int[student.gradeCount];

        student.gradeCount = -1;

        // Collect student's class grades
        while (student.classGrade[student.gradeCount] != 0) {
            student.gradeCount++;
            cout << "Enter grade " << student.gradeCount + 1 << endl;
            // Check if collected grade is valid
             do {
                cin >> stringClassGrade;
                validateGrade(stringClassGrade);
             } while (testas.inputOkay == false);

             // Accept the class grade
             student.classGrade[student.gradeCount] = testas.validatedGrade;

             // Get sum of class grades for avg calculation
             classGradeSum += testas.validatedGrade;
        };

        // Calculate average of all grades for each student
        student.averageGrade = static_cast<float>(classGradeSum + student.examGrade) / (student.gradeCount + 1);

        int* allGrades = new int[student.gradeCount + 1];
        for (int i = 0; i < student.gradeCount; i++) {
            allGrades[i] = student.classGrade[i];
            //cout << allGrades[i] << " = " << student.classGrade[i] << endl;
        }
        allGrades[student.gradeCount] = student.examGrade;
        std::sort(allGrades, allGrades + (student.gradeCount +1));
        
        // Odd number
        if ((student.gradeCount + 1) % 2 != 0) {
            student.medianGrade = (double)allGrades[(student.gradeCount + 1) / 2];
        }
        // Even number
        else {
            student.medianGrade = (double)(allGrades[student.gradeCount / 2] + allGrades[(student.gradeCount + 1) / 2]) / 2.0;
        }


        studentGroup.push_back({student});

        // Clear out variables
        classGradeSum = 0;
        
    };

    /*cout << "Name   Surname   Exam grade    Class grades" << endl << "-------------------------------------------------" << endl;
    for (auto n :testukas){
	    cout << n.name << " " << n.surname << " " << n.examGrade << " ";
        for (int x = 0; x < n.gradeCount; x++) {
            cout << n.classGrade[x] << " ";
        };
        cout << endl;
    };*/

    cout << "Would you like to receive a median or an average of the grades?" << endl << "Please type M for median, or A for average: ";
    do {
        cin >> outputOption;
     } while (validateOutputOption(outputOption) == false);
    if (outputOption == "M" || outputOption == "m") {
        // Print out students with their median grades
        cout << "Name       Surname   Median" << endl << "-------------------------------------------------" << endl;
        for (auto y :studentGroup){
	        cout << y.name << "  " << y.surname << "    " << std::setprecision(3) << y.medianGrade << endl;
        }
    }
    else if (outputOption == "A" || outputOption == "a") {
        // Print out students with their average grades
        cout << "Name       Surname   Average" << endl << "-------------------------------------------------" << endl;
            for (auto y :studentGroup){
	    cout << y.name << "  " << y.surname << "    " << std::setprecision(3) << y.averageGrade << endl;
        }
    };

    /*
    // Print out students with their average grades
    cout << "Name       Surname   Average" << endl << "-------------------------------------------------" << endl;
    for (auto y :studentGroup){
	    cout << y.name << "  " << y.surname << "    " << std::setprecision(3) << y.averageGrade << endl;
    }

    // Print out students with their median grades
    cout << "Name       Surname   Median" << endl << "-------------------------------------------------" << endl;
    for (auto y :studentGroup){
	    cout << y.name << "  " << y.surname << "    " << std::setprecision(3) << y.medianGrade << endl;
    }*/

    delete[] student.classGrade;
}