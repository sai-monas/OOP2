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

bool validateInputOption(int input) {
    bool inputOkay;
    if (cin.fail()) {
        // Redundant ?
        cout << "Invalid option chosen. Please try again: " << endl;
        inputOkay = false;
    }
    else if ((input != 1) && (input != 2) && (input != 3)){
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

	// Get a random number
	int randomGrade = 1 + rand() % 10;

	// Print the random number
	cout<< randomGrade <<endl;

    return randomGrade;
};

int main() {
    structureTestArray student;
    cout.precision(2);
    int classGradeSum = 0;
    std::vector<structureTestArray> studentGroup;
    std::string stringClassGrade;
    std::string stringExamGrade;

    int inputOption;

    std::string outputOption;

    // Providing a seed value
	srand(time(0));

    cout << "Welcome to student grade calculator. Choose next steps: " << endl;
    cout << "Type 1 for manual grade input" << endl << "Type 2 for grade generation" << endl << "Type 3 to exit the program" << endl;
    do {
        cout << "Waiting for your answer: ";
        cin >> inputOption;
     } while (validateInputOption(inputOption) == false);

    if (inputOption == 3) {return 0;};

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

        if (inputOption == 1) {
        // Get and check if collected grade is valid
        do {
            cout << "Input student exam grade: ";
            cin >> stringExamGrade;
            validateGrade(stringExamGrade);
         } while (testas.inputOkay == false);
         // Accept the exam grade
         student.examGrade = testas.validatedGrade;
        }
        else {
            cout << "Exam grade is: ";
            student.examGrade = generateRandomGrade();
        };

        if (inputOption == 1) {
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

        cout << "<< Class grade input finished for " << student.name << " >>" << endl;

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
        }
        else {
            cout << "Type the amount of grades you wish to generate: ";
            // Need to add validation
            cin >> student.gradeCount;
            for (int i = 0; i < student.gradeCount; i++) {
                cout << endl << "Grade " << i + 1 << " is: ";
                student.classGrade[i] = generateRandomGrade();
                classGradeSum += student.classGrade[i];
            }

            cout << "<< Class grade input finished for " << student.name << " >>" << endl;

            student.averageGrade = static_cast<float>(classGradeSum + student.examGrade) / (student.gradeCount + 1);

            int* allGrades = new int[student.gradeCount + 1];
            for (int i = 0; i < student.gradeCount; i++) {
                allGrades[i] = student.classGrade[i];
                cout << allGrades[i] << " = " << student.classGrade[i] << endl;
                }
            allGrades[student.gradeCount] = student.examGrade;
            std::sort(allGrades, allGrades + (student.gradeCount +1));
            for (int i; i < (student.gradeCount + 1); i++) {
                cout << allGrades[i] << endl;
            }
        
             // Odd number
            if ((student.gradeCount + 1) % 2 != 0) {
                student.medianGrade = (double)allGrades[(student.gradeCount + 1) / 2];
            }
            // Even number
            else {
                student.medianGrade = (double)(allGrades[student.gradeCount / 2] + allGrades[(student.gradeCount + 1) / 2]) / 2.0;
            }
        };


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