// Challenge_EASE_SOLUTIONS.cpp : main file 
#include "Methods.h"      
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    string fileName;
    cout << "Enter file location: ";
    cin >> fileName;

    Methods methods;
    vector< vector<int> > matrix = methods.ReadFile(fileName);

    if (!matrix.empty())
    {
        InfoLongestPath output = methods.CalculateLongestPath(matrix);
    }
    return 0;
}
