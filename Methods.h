#pragma once
// Methods class contains the methods for calcule the longest decreasing path 
#include"InfoLongestPath.h"
#include<string>

class Methods final
{
	public:
		Methods() = default;
		~Methods() = default;

		//Read .txt file and save the information
		std::vector<std::vector<int> > ReadFile(const std::string name);
		//Main method to calculate Longesth Path
		InfoLongestPath CalculateLongestPath(const std::vector<std::vector<int> > matrix);

	private:
		//Depth First Search algorithm for a decreasing path
		int DFS(int i, int j, const std::vector<std::vector<int> >& matrix, std::vector<std::vector<int> >& length);
		
};

