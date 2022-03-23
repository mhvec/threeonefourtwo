//A user-defined calculator struct type with an Operator enum within the same scope
//End-user input into program through mathematical expression
//Operations include addition, subtraction, multiply, division, square root

#include <iostream>
#include <cmath>
using namespace std;
using std::cin;
using std::cout;
using std::string;
using std::endl;

//Structure as per guidelines
struct Calc {
    int opSelect;
    double x;
    double y;

    //enum selector for calculator operations
    enum operations {add = 1, subtract = 2, multiply = 3, divide = 4, square = 5};

    //converting into local variables within the structure
    Calc(int opInput, double firstInput, double secondInput){
        opSelect = opInput;
        x = firstInput;
        y = secondInput;
    }

    //section where backend calculations are done
    int calculator(int opSelect) {
        switch(opSelect){
            case operations::add:
                return x + y;
                break;
            case operations::subtract:
                return x - y;
                break;
            case operations::multiply:
                return x * y;
                break;
            case operations::divide:
                return x / y;
                break;
            case operations::square:
                return sqrt(x);
                break;
            default:
                return -1;
                break;
        }
    }
};

int main() {
    double firstInput;
    double secondInput;
    int opInput;
    int loop;
    int exit;
    int valid;

    cout << "Welcome to the Calculator\n";

//loop for multiple uses of the calculator
do {
    exit = 0;
//validation loop for operation selection (the two cases not accounted for is numbers that are 0 and negative numbers, anything higher than 6 will result in termination)   
    do {
        valid = 0;
        cout << "Please input a number and hit enter for the following operations:\n\n";
        cout << "\t1 - Addition \n\t2 - Subtraction \n\t3 - Multiplication \n\t4 - Division \n\t5 - Square Root \n\t6 - Quit Program \n";
        cin >> opInput; 
        
            if (cin.fail()) {
                cout << "\nInvalid input" << endl;
                valid = 1;
                cin.clear();
                cin.ignore();
            }else{
                break;
            }
    } while (valid = 1);

//checking for a "quit" selection before accepting inputs, breaks if selected
if(opInput <= 6) {
//validation loop for first input
    do {valid = 0;
        cout << "\nPlease input the first number\n";
        cin >> firstInput;
        if (cin.fail()) {
            cout << "\nInvalid input" << endl;
            valid = 1;
            cin.clear();
            cin.ignore();
        }else{
            break;
        }
    } while (valid = 1);

//validation loop for second input
    if(opInput != 5) {
        do {
            valid = 0;
            cout << "\nPlease input the second number\n";
            cin >> secondInput;
            if (cin.fail()) {
                cout << "\nInvalid input" << endl;
                valid = 1;
                cin.clear();
                cin.ignore();
            }else{
                break;
            }
        } while (valid = 1);
    }

    //sending inputs to structure for calculation
    Calc answer = Calc(opInput, firstInput, secondInput);
    cout <<"\nThe answer is: " <<answer.calculator(opInput);
    cout <<"\n\n";
    } else {
        break;
    }

} while (exit = 1);
return 0;
}