#include "Methods.h"
#include <fstream>      
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::max;
using std::pair;
using std::string;
using std::vector;

const vector<pair<int, int> > DIRECTION{ {-1,0},{1,0},{0,-1},{0,1} };

void Methods::PrintLongestPath(const vector<int>& longestPath)
{
    cout << "The longest path is: " << endl;

    for (int i = 0; i < static_cast<int>(longestPath.size() - 1); ++i)
    {
        cout << longestPath[i] << "-";
    }

    cout << longestPath.back() << endl;
}
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

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int> > length(m, vector<int>(n, -1));

    int maxCol = 0;
    int maxRow = 0;
    int maxLength = 0;
    bool pathIsCalculated = false;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int currentLength = DFS(i, j, matrix, length);

            if (currentLength > maxLength)
            {
                maxRow = i;
                maxCol = j;
                maxLength = currentLength;
                pathIsCalculated = false;
            }
            else if (currentLength == maxLength)
            {
                InfoLongestPath temp = GetPathInfo(i, j, matrix, length);

                if (!pathIsCalculated)
                {
                    output = GetPathInfo(maxRow, maxCol, matrix, length);
                }

                pathIsCalculated = true;

                if (output.maxDepth < temp.maxDepth)
                {
                    maxRow = i;
                    maxCol = j;
                    maxLength = currentLength;
                    output = temp;
                }
            }
        }
    }

    if (!pathIsCalculated)
    {
        output = GetPathInfo(maxRow, maxCol, matrix, length);
    }

    output.maxLength = maxLength;
    return output;
}
int Methods::DFS(int i, int j, const vector<vector<int> >& matrix, vector<vector<int> >& length)
{
    if (length[i][j] == -1)
    {
        int maxLength = 0;

        for (auto p : DIRECTION)
        {
            int x = i + p.first;
            int y = j + p.second;

            if (x < 0 || x >= static_cast<int>(matrix.size()) || y < 0 || y >= static_cast<int>(matrix[0].size())) continue;

            if (matrix[x][y] < matrix[i][j])
            {
                maxLength = max(maxLength, DFS(x, y, matrix, length));
            }
        }

        length[i][j] = maxLength + 1;
    }

    return length[i][j];
}
InfoLongestPath Methods::GetPathInfo(int i, int j, const vector<vector<int>>& matrix, const vector<vector<int>>& length)
{
    InfoLongestPath output;
    int maxLength = length[i][j];
    int depth = 0;
    vector<int> path(maxLength, 0);

    for (int currentLength = maxLength; currentLength >= 1; --currentLength)
    {
        int index = maxLength - currentLength;

        for (auto p : DIRECTION)
        {
            path[index] = matrix[i][j];
            int x = i + p.first;
            int y = j + p.second;

            if (x < 0 || x >= static_cast<int>(matrix.size()) || y < 0 || y >= static_cast<int>(matrix[0].size())) continue;

            if (currentLength - length[x][y] == 1)
            {
                depth += matrix[i][j] - matrix[x][y];
                i = x;
                j = y;
                break;
            }
        }
    }

    output.maxPath = path;
    output.maxDepth = depth;
    return output;
}