#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include "college.h"

#ifndef LAB3TEST_IO_H
#define LAB3TEST_IO_H

int findFiles();
college readLoop();
double totalPassed(int, int);
int insPassrate(college c);

#endif //LAB3TEST_IO_H
