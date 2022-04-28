#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <dirent.h>
#include <sstream>
#include "io.h"


using namespace std;
vector<string> csvFiles;


bool has_suffix(const string &s, const string &suffix) {
    return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
};

double totalPassed(int passed, int total) {
    double ratio = (double) passed / (double) total;
    return ratio;
}

double totalWithdrew(int w, int total) {
    double ratio = (double) w / (double) total;
    return ratio;
}

int findFiles() {
    vector<string> foundFiles;
    string extension = ".csv";

    if (auto dir = opendir("../data/")) {
        while (auto f = readdir(dir)) {
            if (!f->d_name || f->d_name[0] == '.')
                continue; // Skip everything that starts with a dot
            printf("File: %s\n", f->d_name);
//all files to vector
            foundFiles.push_back(f->d_name);
        }
        closedir(dir);
    }

//csv file filtering
    for (int i = 0; i < foundFiles.size(); i++)
        if (has_suffix(foundFiles[i], extension)) {
//std::cout << foundFiles[i] << " FOUNDLOOP" << ' ';
            csvFiles.push_back(foundFiles[i]);
        }

//csvFiles checker
    std::cout << '\n';
    for (int i = 0; i < csvFiles.size(); i++) {
        std::cout << csvFiles[i] << " CSVLOOP" << ' ';
    }
    return 0;
};

//test section csv reader
college readLoop() {
    ifstream file;
    file.open("../data/3115.csv");
    string line;
    vector<string> lines;
    college c;

    string emplId;
    string courseNo;
    string insId;
    string termId;
    string sectId;
    string grade;
    int passed = 0;
    int withdraw = 0;
    int total = 0;
    double passRatio = 0;

    getline(file, line, ',');
    while (file >> line) {
        //each line's delimited contents are streamed to appropriate var
        stringstream lineSteam(line);
        getline(lineSteam, emplId, ',');
        getline(lineSteam, courseNo, ',');
        getline(lineSteam, insId, ',');
        getline(lineSteam, termId, ',');
        getline(lineSteam, sectId, ',');
        getline(lineSteam, grade);

        string gradeString = grade;

        //test class_id string stream
        //std::cout << class_id << "\n";

        c.addStudent(emplId, courseNo, grade);
        c.addInstructor(insId, courseNo);

        //Total Pass Percentage Calc
        //Passed#
        if (gradeString.find("A+") != std::string::npos || gradeString.find("A") != std::string::npos ||
            gradeString.find("A-") != std::string::npos || gradeString.find("B+") != std::string::npos ||
            gradeString.find("B") != std::string::npos || gradeString.find("B-") != std::string::npos ||
            gradeString.find("C+") != std::string::npos || gradeString.find("C") != std::string::npos ||
            gradeString.find("CR") != std::string::npos) {
            passed++;
        }
        //Withdraw#
        if (gradeString.find("W") != std::string::npos || gradeString.find("WN") != std::string::npos ||
            gradeString.find("WD") != std::string::npos || gradeString.find("WU") != std::string::npos) {
            withdraw++;
        }
        total++;
    };

    total = total - 2;
    std::cout << '\n';
    std::cout << passed << " Passed" << '\n';
    std::cout << withdraw << " Withdrew" << '\n';
    std::cout << total << " Total" << '\n';

    passRatio = totalPassed(passed, total);
    std::cout << "Total Pass Percentage: " << passRatio << '\n';
    //c.testPrint();
    //c.insPrint();
    file.close();


    return c;
};

int insPassrate(college co) {
    ifstream file;
    ofstream outFile;
    ofstream withdrawFile;
    outFile.open ("inst passrate.txt");
    withdrawFile.open ("inst withdrawrate.txt");
    outFile << "Instructor\t" << "Pass Percentage" << '\n';
    withdrawFile << "Instructor\t" << "W Percentage" << '\n';
    string line;
    vector<string> lines;

    string emplId;
    string courseNo;
    string insId;
    string termId;
    string sectId;
    string grade;
    string courseString;

    int passed = 0;
    int withdraw = 0;
    int total = 0;
    int insTotal = 0;
    double passRatio = 0;
    double wRatio = 0;

    vector<string> insVec;
    for (const auto &s: co.instructorList) {
        insVec.push_back(s.first);
    }

    for (int i = 0; i < insVec.size(); i++) {
        //std::cout << insVec[i] << "" << ' ';
        file.open("../data/3115.csv");
        getline(file, line, ',');
        while (file >> line) {
            //each line's delimited contents are streamed to appropriate var
            stringstream lineSteam(line);
            getline(lineSteam, emplId, ',');
            getline(lineSteam, courseNo, ',');
            getline(lineSteam, insId, ',');
            getline(lineSteam, termId, ',');
            getline(lineSteam, sectId, ',');
            getline(lineSteam, grade);

            string insString = insId;
            string gradeString = grade;
            courseString = courseNo;
            if (insId == insVec[i]) {
                if (gradeString.find("A+") != std::string::npos || gradeString.find("A") != std::string::npos ||
                    gradeString.find("A-") != std::string::npos || gradeString.find("B+") != std::string::npos ||
                    gradeString.find("B") != std::string::npos || gradeString.find("B-") != std::string::npos ||
                    gradeString.find("C+") != std::string::npos || gradeString.find("C") != std::string::npos ||
                    gradeString.find("CR") != std::string::npos) {
                    passed++;
                }
                //Withdraw#
                if (gradeString.find("W") != std::string::npos || gradeString.find("WN") != std::string::npos ||
                    gradeString.find("WD") != std::string::npos || gradeString.find("WU") != std::string::npos) {
                    withdraw++;
                }
                total++;
                insTotal++;
            }
        }
        passRatio = totalPassed(passed, insTotal);
        wRatio = totalWithdrew(withdraw, insTotal);
        std::cout << insVec[i] << " " << passRatio * 100 << "%" << '\n';
        outFile << insVec[i] << "\t\t" << passRatio * 100 << "%" << '\n';
        withdrawFile << insVec[i] << "\t\t" << wRatio * 100 << "%" << '\n';

        file.close();
        passed = 0;
        withdraw = 0;
        insTotal = 0;
    }

    outFile << "Course:\t" << courseString << '\n';
    withdrawFile << "Course:\t" << courseString << '\n';
    outFile.close();
    withdrawFile.close();
    return 0;
};