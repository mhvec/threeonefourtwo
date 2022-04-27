#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <dirent.h>
#include <sstream>
#include "io.h"
#include "college.h"

using namespace std;

bool has_suffix(const string &s, const string &suffix) {
    return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
};

double totalPassed(int passed, int total){
    double ratio = (double)passed / (double)total;
    return ratio;
}

int findFiles() {
    vector<string> foundFiles;
    vector<string> csvFiles;
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
int readLoop() {
    ifstream file;
    file.open("../data/1115.csv");
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

        string gradeString =  grade;

        //test class_id string stream
        //std::cout << class_id << "\n";

        c.addStudent(emplId, courseNo, grade);
        c.addInstructor(insId, courseNo);

        //Total Pass Percentage Calc
        //Passed#
        if (gradeString.find("A+") != std::string::npos || gradeString.find("A") != std::string::npos || gradeString.find("A-") != std::string::npos || gradeString.find("B+") != std::string::npos || gradeString.find("B") != std::string::npos || gradeString.find("B-") != std::string::npos || gradeString.find("C+") != std::string::npos || gradeString.find("C") != std::string::npos || gradeString.find("CR") != std::string::npos) {
            passed++;
        }
        //Withdraw#
        if (gradeString.find("W") != std::string::npos || gradeString.find("WN") != std::string::npos || gradeString.find("WD") != std::string::npos || gradeString.find("WU") != std::string::npos) {
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
    c.insPrint();
    file.close();
return 0;
};

int insPassrate() {
    ifstream fin("../data/3115i.txt");
    vector<string> data;
    string element;
    while (fin >> element)
    {
        data.push_back(element);
    }
    for (int i = 0; i < data.size(); i++) {
    }
    return 0;
};