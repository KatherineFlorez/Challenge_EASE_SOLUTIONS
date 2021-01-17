// Challenge_EASE_SOLUTIONS.cpp : main file 
#include "Methods.h"      
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
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
        cout << "Length of calculated path: " << output.maxLength << endl;
        cout << "Drop of calculated path:s " << output.maxSteep << endl;
        methods.PrintLongestPath(output.maxPath);
    }

    return 0;
}
