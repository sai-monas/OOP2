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
    int validatedNumber;
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
structureBoolInt validateNumber(std::string count);
std::vector<int> generateClassGrades();
void generateFile(std::string name);
bool validateOutputOption(std::string output);
bool validateInputOption(int input);
bool validateFileMethod(int method);
int generateRandomGrade();
int generateRandomNumber();
structureTestVector parseStudentInfo(std::string& line);
void sortOutput(std::vector<structureTestVector> &students, int option);
void sortOutputList(list<structureTestVector> &students, int option);
void sortOutputDeque(deque<structureTestVector> &students, int option);
bool sortByName(structureTestVector& s1, structureTestVector& s2);
bool sortBySurname(structureTestVector& s1, structureTestVector& s2);
bool sortByAverage(structureTestVector& s1, structureTestVector& s2);
bool sortByMedian(structureTestVector& s1, structureTestVector& s2);