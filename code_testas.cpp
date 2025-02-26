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

    structureTest student;
    std::vector<structureTest> studentGroup;

    std::string stringClassGrade;
    std::string stringExamGrade;

    int classGradeSum = 0;
    float averageGrade;

    std::vector<int> allGrades;
    int allGradeCount;

    int inputOption;
    
    std::string outputOption;

    // Providing a seed value
	srand(time(0));

    cout << "Welcome to student grade calculator. Choose next steps: " << endl;
    cout << "- Type 1 for manual grade input" << endl << "- Type 2 for grade generation" << endl << "- Type 3 to exit the program" << endl;
    do {
        cout << "Waiting for your answer: ";
        cin >> inputOption;
     } while (validateInputOption(inputOption) == false);

    if (inputOption == 3) {
        cout << endl << "Have a nice day!";
        return 0;};

    // Collect inputs
    while (student.name !=  "x" || student.name != "X") {
        cout << "- Please type X for the student name if you do not have any remaining students left." << endl;

        // Collect student's first name
        cout << "Input student name: ";
        cin >> student.name;

        // Check if user wants to exit program
        if (student.name == "x" || student.name == "X") {
            cout << "<< Student input finished >>" << endl;
            break;
        };

        // Collect student's last name
        cout << "Input student surname: ";
        cin >> student.surname;

        if (inputOption == 1) {
        // Check if collected grade is valid
            do {
                cout << "Input student's exam grade: ";
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

        cout << "- Please type 0 for the grade if you do not have any remaining grades left" << endl;

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
        }
        else {
            cout << "Type the amount of grades you wish to generate: ";
            // Need to add validation
            cin >> student.gradeCount;
            for (int i = 0; i < student.gradeCount; i++) {
                cout << endl << "Grade " << i + 1 << " is: ";
                student.classGrade.push_back(generateRandomGrade());
                classGradeSum += student.classGrade[i];
            }

            cout << "<< Class grade input finished for " << student.name << " >>" << endl;

            student.averageGrade = static_cast<float>(classGradeSum + student.examGrade) / (student.gradeCount + 1);

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
        };

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