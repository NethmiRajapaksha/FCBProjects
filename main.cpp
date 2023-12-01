/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int biology;
    int physics;
    int chemistry;
    int totalMarks;
    int rank;
};

struct Class {
    std::string stream;
    int classNumber;
    std::vector<Student> students;
};

void calculateTotalMarksAndRank(std::vector<Class>& classes) {
    for (auto& currentClass : classes) {
        // Calculate total marks for each student
        for (auto& student : currentClass.students) {
            student.totalMarks = student.biology + student.physics + student.chemistry;
        }

        // Sort students based on total marks
        std::sort(currentClass.students.begin(), currentClass.students.end(),
                  [](const Student& a, const Student& b) {
                      return a.totalMarks > b.totalMarks;
                  });

        // Assign ranks
        int currentRank = 1;
        for (auto& student : currentClass.students) {
            student.rank = currentRank++;
        }
    }
}

void printResults(const std::vector<Class>& classes) {
    std::ofstream outputFile("rank_results.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    for (const auto& currentClass : classes) {
        std::cout << "Stream: " << currentClass.stream << " Class: " << currentClass.classNumber << std::endl;
        outputFile << "Stream: " << currentClass.stream << " Class: " << currentClass.classNumber << std::endl;

        for (const auto& student : currentClass.students) {
            std::cout << "Name: " << student.name << " Total Marks: " << student.totalMarks
                      << " Rank: " << student.rank << std::endl;

            outputFile << "Name: " << student.name << " Total Marks: " << student.totalMarks
                       << " Rank: " << student.rank << std::endl;
        }

        std::cout << std::endl;
        outputFile << std::endl;
    }

    outputFile.close();
}

int main() {
    // Define classes, streams, and students
    std::vector<Class> classes = {
        {"Bioscience", 1, {/* List of students */}},
        {"Bioscience", 2, {/* List of students */}},
        {"Bioscience", 3, {/* List of students */}},
        {"Math", 1, {/* List of students */}},
        {"Math", 2, {/* List of students */}},
        {"Math", 3, {/* List of students */}},
        {"Math", 4, {/* List of students */}},
        {"Math", 5, {/* List of students */}},
    };

    return 0;
}

