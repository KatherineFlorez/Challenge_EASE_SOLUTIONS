#pragma once
// Methods class contains the methods for calcule the longest decreasing path 
#include"InfoLongestPath.h"
#include<string>

class Methods final
{
	public:
		Methods() = default;
		~Methods() = default;

		std::vector<std::vector<int> > ReadFile(const std::string name);
		InfoLongestPath CalculateLongestPath(const std::vector<std::vector<int> > matrix);

	private:
		int DFS(int i, int j, const std::vector<std::vector<int> >& matrix, std::vector<std::vector<int> >& length);
		InfoLongestPath GetPathInfo(int i, int j, const std::vector<std::vector<int>>& matrix, const std::vector<std::vector<int>>& length);

};

