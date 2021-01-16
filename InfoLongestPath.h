#pragma once
// InfoLongestPath.h : header file contain the maximun depth, length and path

#include<vector>

struct InfoLongestPath
{
	int maxDepth = 0;
	int maxLength = 0;
	std::vector<int> maxPath;
};