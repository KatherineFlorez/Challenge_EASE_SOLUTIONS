#pragma once
// Methods class contains the methods for calcule the longest decreasing path 
#include<string>
#include<vector>

class Methods final
{
	public:
		Methods() = default;
		~Methods() = default;

		std::vector<std::vector<int> > ReadFile(const std::string name);

	private:
};

