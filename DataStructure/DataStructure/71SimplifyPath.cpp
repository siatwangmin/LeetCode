#include <iostream>
#include <vector>;
#include <queue>

using namespace std;

//*********************Description*****************************
//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//*************************************************************


class Solution {
private:
	queue<char> s;
	
	string result;
public:
	string simplifyPath(string path) {
		if (path.size() == 0)
		{
			return result;  
		}
		for (size_t i = 0; i < path.size(); i++)
		{
			if (path[i] == '/')
			{
				result = "/";
				while (!s.empty())
				{
					result += s.front();
					s.pop();
				}
			}
			else
			{
				s.push(path[i]);
			}
		}
		return result;
	}
};