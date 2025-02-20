#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>

// For regex
#include <regex>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;


struct structureTest {
    std::string name;
    std::string surname;
    std::vector<int> classGrade;
    int examGrade;
    double averageGrade;
};

struct structureTestArray {
    std::string name;
    std::string surname;
    int* classGrade = new int;
    int examGrade;
    int gradeCount;
};

struct structureBoolInt {
    bool inputOkay;
    int validatedGrade;
};