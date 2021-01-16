#include "Methods.h"
#include <fstream>      
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

vector<vector<int> > Methods::ReadFile(const string name)
{
    vector< vector<int> > matrix;
    ifstream infile(name);

    if (!infile)
    {
        cout << "Unable to open file " << name << endl;
    }
    else
    {
        int m;
        int n;
        infile >> m >> n;

        if (m > 0 && n > 0)
        {
            cout << "Matrix dimensions " << m << "x" << n << endl;
            int data;

            for (int i = 0; i < m; ++i)
            {
                vector<int> row;

                for (int j = 0; j < n; ++j)
                {
                    infile >> data;
                    row.push_back(data);
                }

                matrix.push_back(row);
            }
        }
        else
        {
            cout << "At least one of the dimensions is zero  " << m << "x" << n << endl;
        }
    }

    return matrix;
}
InfoLongestPath Methods::CalculateLongestPath(const vector<vector<int> > matrix)
{
    InfoLongestPath output;

    return output;
}