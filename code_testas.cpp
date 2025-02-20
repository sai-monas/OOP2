#include "headers_testas.h"

structureBoolInt testas;

structureBoolInt validateGrade(std::string grade) {
    std::regex checkIfNumber("^\\d+$");

    if (cin.fail()) {
        // Redundant ?
        cout << "Grade is not a valid number. Please try again: " << endl;
        testas.inputOkay = false;
    }
    else if (std::regex_match(grade, checkIfNumber) == false) {
        cout << "Grade is not a valid number. Please try again: " << endl;
        testas.inputOkay = false;
    }
    else if (std::stof(grade) > 10 || std::stof(grade) < 0 ) {
        cout << "Incorrect value entered. Make sure that the exam grade is in range 1-10. Please try again: " << endl;
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

    structureTest student;
    std::vector<structureTest> studentGroup;

    std::string stringClassGrade;
    std::string stringExamGrade;

    int classGradeSum = 0;
    float averageGrade;

    std::vector<int> allGrades;
    int allGradeCount;
    
    std::string outputOption;


    // Collect inputs
    while (student.name !=  "x") {

        // Collect student's first name
        cout << "Input student name: ";
        cin >> student.name;

        // Check if user wants to exit program
        if (student.name == "x") {
            cout << "<< Student input finished >>" << endl;
            break;
        };

        // Collect student's last name
        cout << "Input student surname: ";
        cin >> student.surname;

        // Check if collected grade is valid
        do {
            cout << "Input student's exam grade: ";
            cin >> stringExamGrade;
            validateGrade(stringExamGrade);
         } while (testas.inputOkay == false);

        // Accept the exam grade
         student.examGrade = testas.validatedGrade;

        student.gradeCount = -1;

        // Collect student's class grades
        while (testas.validatedGrade != 0) {
            student.gradeCount++;
            cout << "Enter grade " << student.gradeCount + 1 << ": " << endl;
            // Check if collected grade is valid
             do {
                cin >> stringClassGrade;
                validateGrade(stringClassGrade);
             } while (testas.inputOkay == false);

             // Accept the class grade
             student.classGrade.push_back(testas.validatedGrade);

             // Get sum of class grades for avg calculation
             classGradeSum += testas.validatedGrade;
        };

        cout << "<< Class grade input finished for " << student.name << " >>" << endl;

        // Remove last element (0) from vector
        student.classGrade.pop_back();

        // Calculate average of all grades for each student
        student.averageGrade = static_cast<double>(classGradeSum + student.examGrade) / (student.gradeCount + 1);

        // Create vector for all grades
        allGrades = student.classGrade;
        allGrades.insert(allGrades.begin(), student.examGrade);
        
        // Sort the vector in ascending order
        sort(allGrades.begin(),allGrades.end());

        // Get number of grades in vector
        allGradeCount = allGrades.size();
        
        // Odd number
        if (allGradeCount % 2 != 0) {
            student.medianGrade = (double)allGrades[allGradeCount / 2];
        }
        // Even number
        else {
            student.medianGrade = (double)(allGrades[(allGradeCount - 1) / 2] + allGrades[allGradeCount / 2]) / 2.0;
        }

        studentGroup.push_back({student});

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

    return 0;
}