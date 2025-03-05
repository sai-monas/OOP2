#include "headers.h"

std::vector<structureTestVector> studentGroup;
structureTestVector student;


int main() {

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
        structureTestVector student;
        std::string fileName;

        cout << "Input file name to use for calculations: ";
        cin >> fileName; // Add exception

        // Read from the text file
        ifstream file(fileName);

        // Ignore the first line
        getline(file, firstLine);

        while (getline (file, currentLine)) {
            student = parseStudentInfo(currentLine);

            // Turning last grade to exam grade and removing it from class grades
            student.examGrade = student.classGrade[student.classGrade.size() - 1];
            student.classGrade.pop_back();
            
            // Getting the count of class grades
            student.gradeCount = student.classGrade.size();

            // Calculate average grade
            student.averageGrade = calculateAverageGrade((calculateSum(student.classGrade) + student.examGrade), student.gradeCount + 1);

            // Calculate median grade
            student.medianGrade = calculateMedianGrade(student.classGrade, student.examGrade);

            studentGroup.push_back(student);

            // Clear out class grade vector to reuse it
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

    sortOutput(studentGroup, fileOutputOption);

    outputMedianAndAverage(studentGroup);
    }
    
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

        // Check if all requested students were generated
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

        // Ask for exam grade for 1st option
        if (inputOption == 1) {
            student.examGrade = collectExamGrade();
        }
        // Generate exam grade for 2nd & 3rd options
        else {
            cout << "Exam grade is: ";
            student.examGrade = generateRandomGrade();
        };

        // Ask for class grades for 1st option
        if (inputOption == 1) {

        // Collect student's class grades
        student.classGrade = collectClassGrade();

        // Get sum of class grades for avg calculation
        //classGradeSum = calculateSum(student.classGrade);

        cout << "<< Class grade input finished for " << student.name << " >>" << endl;

        // Remove last element (0) from vector
        student.classGrade.pop_back();

        student.gradeCount = (student.classGrade.size() + 1);

        // Calculate average of all grades for each student
        student.averageGrade = calculateAverageGrade((calculateSum(student.classGrade) + student.examGrade), student.gradeCount);

        student.medianGrade = calculateMedianGrade(student.classGrade, student.examGrade);
        }
        else {
            cout << "Type the amount of grades you wish to generate: ";
            // Need to add validation
            cin >> student.gradeCount;
            for (int i = 0; i < student.gradeCount; i++) {
                cout << endl << "Grade " << i + 1 << " is: ";
                student.classGrade.push_back(generateRandomGrade());
            }

            cout << "<< Class grade input finished for " << student.name << " >>" << endl;

            student.averageGrade = calculateAverageGrade(calculateSum(student.classGrade) + student.examGrade, student.gradeCount + 1);

            student.medianGrade = calculateMedianGrade(student.classGrade, student.examGrade);
        };

        studentGroup.push_back({student});

        // Clear out variables
        student.classGrade.clear();
    }

    cout << "Would you like to receive a median or an average of the grades?" << endl << "Please type M for median, or A for average: ";
    do {
        cin >> outputOption;
     } while (validateOutputOption(outputOption) == false); // Check that chosen output option is M (m) or A (a)
    // Print chosen output
    outputMedianOrAverage(studentGroup, outputOption);
    }

    return 0;
}