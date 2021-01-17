#pragma once
// Methods class contains the methods for calcule the longest decreasing path 
#include"InfoLongestPath.h"
#include<string>

class Methods final
{
	public:
		Methods() = default;
		~Methods() = default;
		//Print longest path into console
		void PrintLongestPath(const std::vector<int>& longestPath);
		//Read .txt file and save the information
		std::vector<std::vector<int> > ReadFile(const std::string name);
		//Main method to calculate Longesth Path
		InfoLongestPath CalculateLongestPath(const std::vector<std::vector<int> > matrix);

	private:
		//Depth First Search algorithm for a decreasing path
		int DFS(int i, int j, const std::vector<std::vector<int> >& matrix, std::vector<std::vector<int> >& length);
		//GetPathInfo - obtain depth and path of an specific initial point and maximun length
		InfoLongestPath GetPathInfo(int i, int j, const std::vector<std::vector<int>>& matrix, const std::vector<std::vector<int>>& length);

};

