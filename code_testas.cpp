#include "headers_testas.h"

structureBoolInt testas;
structureTestVector tempStudent;
std::vector<structureTestVector> studentGroup;

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

	// Get a random number
	int randomGrade = 1 + rand() % 10;

	// Print the random number
	cout<< randomGrade <<endl;

    return randomGrade;
};

int generateRandomNumber() {

	// Get a random number
	int randomNumber = rand() % 10;

	// Print the random number
	//cout<< randomGrade <<endl;

    return randomNumber;
};

structureTestVector parseStudentInfo(std::string& line) {
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

int main() {

    structureTestVector student;
    std::vector<structureTestVector> studentGroup;

    std::string stringClassGrade;
    std::string stringExamGrade;

    int classGradeSum = 0;
    float averageGrade;

    std::vector<int> allGrades;
    int allGradeCount;

    int inputOption;
    
    std::string outputOption;
    int fileOutputOption;

    // For random student generation
    std::string randomNames[10] = {"Konstantinas", "Danielius", "Vardenis", "Aleksandras", "Kazimieras", "Fridrichas", "Deimantas", "Tautvydas", "Edgaras", "Marijonas"};
    std::string randomSurnames[10] = {"Muilinas", "Pavardenis", "Kavinukas", "Arbataitis", "Antinas", "Mogila", "Sudimtas", "Jonelaitis", "Regesas", "Mamontovas"};
    int studentCount;
    int keepingStudentCount = 0;
    bool generationFinished = false;

    // Providing a seed value
	srand(time(0));

    cout << "Welcome to student grade calculator. Choose next steps: " << endl;
    cout << "- Type 1 for manual grade input" << endl << "- Type 2 for grade generation" << endl
    << "- Type 3 to generate students and their grades" << endl  << "- Type 4 to calculate from file" << endl
    << "- Type 5 to exit the program" << endl;
    do {
        cout << "Waiting for your answer: ";
        cin >> inputOption;
     } while (validateInputOption(inputOption) == false);

    if (inputOption == 5) {
        cout << endl << "Have a nice day!";
        return 0;};
    
    
    if (inputOption == 4) {
        std::string currentLine;
        std::string firstLine;
        structureTestVector student;
        std::string fileName;

        cout << "Input file name to use for calculations: ";

        cin >> fileName;

        // Read from the text file
        ifstream file(fileName);

        getline(file, firstLine); // Ignore the first line

        while (getline (file, currentLine)) {
            student = parseStudentInfo(currentLine);

            // Turning last grade to exam grade
            // cout << "Number of class grades: " << student.classGrade.size() << "    16th grade: " << student.classGrade[student.classGrade.size() - 1] <<endl;
            student.examGrade = student.classGrade[student.classGrade.size() - 1];
            student.classGrade.pop_back();
            // cout << "Number of class grades: " << student.classGrade.size() << endl;
            // cout << "Exam grade: " << student.examGrade << endl << endl;
            
            student.gradeCount = student.classGrade.size();

            int sum = 0;
            for (int i = 0; i < student.classGrade.size(); i++) {
                sum += student.classGrade[i];
            }
            sum += student.examGrade;

            student.averageGrade = static_cast<double>(sum) / (student.gradeCount +1);

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

            studentGroup.push_back(student);
            tempStudent.classGrade.clear();
            student.classGrade.clear();
     }

    // Close the file
    file.close();

    cout << "File read successfully!" << endl;
    cout << "Would you like to sort the results by name, surname, average grade or median grade?" << endl;
    cout << "- Type 1 to sort by name" << endl << "- Type 2 to sort by surname" << endl
    << "- Type 3 to sort by average grade" << endl  << "- Type 4 to sort by median grade" << endl
    << "- Type 5 to skip sorting" << endl;

    do {
        cout << "Waiting for your answer: ";
        cin >> fileOutputOption;
     } while (validateInputOption(fileOutputOption) == false);

    if (fileOutputOption == 1) {
        std::sort(studentGroup.begin(), studentGroup.end(), sortByName);
    }
    else if (fileOutputOption == 2) {
        std::sort(studentGroup.begin(), studentGroup.end(), sortBySurname);
    }
    else if (fileOutputOption == 3) {
        std::sort(studentGroup.begin(), studentGroup.end(), sortByAverage);
    }
    else if (fileOutputOption == 4) {
        std::sort(studentGroup.begin(), studentGroup.end(), sortByMedian);
    }

    /*cout << "Name   Surname   Class grades                 Exam grade" << endl << "------------------------------------------------------------" << endl;
     for (auto n :studentGroup){
         cout << n.name << " " << n.surname << " ";
         for (auto v : n.classGrade)
             cout << v << " ";
        cout << "   " << n.examGrade;
        cout << endl;
     }*/

    cout << "Name            Surname         Average  Median" << endl << "-------------------------------------------------" << endl;
        for (auto y :studentGroup){
        cout << std::left << std::setw(15) << y.name << " " << std::setw(15) << y.surname << " " <<
         std::setw(9) << std::setprecision(3) << y.averageGrade << std::setw(9) << std::setprecision(3) << y.medianGrade<< endl;
        }
    };
    
    
    if ((inputOption == 1) || (inputOption == 2) || (inputOption == 3)) {

    if (inputOption == 3) {
        cout << "Type the amount of students you wish to generate: ";
        cin >> studentCount;
    }

    // Collect inputs
    while (student.name !=  "x" || student.name != "X") {
        
        
        if ((inputOption == 1) || (inputOption == 2)) {
            cout << "- Please type X for the student name if you do not have any remaining students left." << endl;

            // Collect student's first name
            cout << "Input student name: ";
            cin >> student.name;
        }
        else {
            keepingStudentCount += 1;
            if (keepingStudentCount <= studentCount) {
                student.name = randomNames[generateRandomNumber()];
            }
            else {generationFinished = true;};
        }

        // Check if user wants to exit program
        if (student.name == "x" || student.name == "X") {
            cout << "<< Student input finished >>" << endl;
            break;
        };

        if (generationFinished == true) {
            break;
        };


        // Collect student's last name
        if ((inputOption == 1) || (inputOption == 2)) {
            cout << "Input student surname: ";
            cin >> student.surname;
        }
        else {
            student.surname = randomSurnames[generateRandomNumber()];
            cout << "Student " << keepingStudentCount << " is: " << student.name << " " << student.surname << endl;
        }


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
    }

    return 0;
}