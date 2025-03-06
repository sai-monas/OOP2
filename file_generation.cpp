#include "headers.h"

int main() {
    ofstream file("students.txt");

    int studentAmount = 10;
    int gradeAmount = 10;

    file << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 1; i <= gradeAmount; i++) {
        file << std::setw(6) << "ND" + std::to_string(i); 
    }
    file << std::setw(6) << "Egz." << std::endl;

    for (int i = 1; i <= studentAmount; i++) {
        file << std::left << std::setw(15) << "Vardas" + std::to_string(i) << std::setw(15) << "Pavarde" + std::to_string(i);
        for (int y = 1; y <= gradeAmount; y++) {
            file << std::setw(6) << generateRandomGrade();
        }
        file << std::setw(6) << generateRandomGrade() << std::endl;
    }

    //file << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(5) << "ND1" << std::setw(5) << "Exam" << std::endl;
    //file << std::left << std::setw(15) << "Saimonas" << std::setw(15) << "Sudintas" << std::setw(5) << 8 << std::setw(5) << 8 << std::endl;

    file.close();
    
    return 0;

}