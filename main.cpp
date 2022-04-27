#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include <dirent.h>
#include "io.h"
#include "college.h"
college c;

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;

int p = findFiles();
int o = readLoop();
//int b = insPassrate();
//pass rate per instructor
//w rate per instructor
//pass rate per course
//w rate per course
//pass rate per term

//output folder with timestamp for filename
//one report per file
    return 0;
}
