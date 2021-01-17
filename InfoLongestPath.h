#pragma once
// InfoLongestPath.h : header file contain the maximun steep, length and path

#include<vector>

struct InfoLongestPath
{
	int maxSteep = 0;
	int maxLength = 0;
	std::vector<int> maxPath;
};