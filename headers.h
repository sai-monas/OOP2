#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>

#include <iomanip>

// For file
#include <fstream>
using std::ifstream;
#include <sstream>
//using std::count;

// For regex
#include <regex>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;
using std::count;


struct structureTestVector {
    std::string name;
    std::string surname;
    std::vector<int> classGrade;
    int examGrade;
    int gradeCount;
    double averageGrade;
    double medianGrade;
};

struct structureTestArray {
    std::string name;
    std::string surname;
    //int* classGrade = new int;
    int examGrade;
    int gradeCount;
    int* classGrade = new int[gradeCount];
    double averageGrade;
    double medianGrade;
};

struct structureBoolInt {
    bool inputOkay;
    int validatedGrade;
};



// Functions
double calculateAverageGrade(int sum, int count);
double calculateMedianGrade(std::vector<int> grades, int exam);
void outputMedianOrAverage(std::vector<structureTestVector> students, std::string choice);
void outputMedianAndAverage(std::vector<structureTestVector> students);
int collectExamGrade();
std::vector<int> collectClassGrade();
int calculateSum(std::vector<int> grades);
structureBoolInt validateGrade(std::string grade);
bool validateOutputOption(std::string output);
bool validateInputOption(int input);
int generateRandomGrade();
int generateRandomNumber();
structureTestVector parseStudentInfo(std::string& line);
void sortOutput(std::vector<structureTestVector> &students, int option);
bool sortByName(structureTestVector& s1, structureTestVector& s2);
bool sortBySurname(structureTestVector& s1, structureTestVector& s2);
bool sortByAverage(structureTestVector& s1, structureTestVector& s2);
bool sortByMedian(structureTestVector& s1, structureTestVector& s2);