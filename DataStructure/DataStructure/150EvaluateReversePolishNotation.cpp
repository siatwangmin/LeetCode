#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//*******************************Description***********************************************
//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//*****************************************************************************************


class Solution {
private:
	stack<int> sta;
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 0)
			return 0;
		for (size_t i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+")
			{
				int second = sta.top();
				sta.pop();
				int first = sta.top();
				sta.pop();
				sta.push(first + second);
			}
			else if (tokens[i] == "-")
			{
				int second = sta.top();
				sta.pop();
				int first = sta.top();
				sta.pop();
				sta.push(first - second);
			}
			else if (tokens[i] == "*")
			{
				int second = sta.top();
				sta.pop();
				int first = sta.top();
				sta.pop();
				sta.push(first * second);
			}
			else if (tokens[i] == "/")
			{
				int second = sta.top();
				sta.pop();
				int first = sta.top();
				sta.pop();
				sta.push(first / second);
			}
			else
			{
				sta.push(atoi(tokens[i].c_str()));
			}
		}
		return sta.top();
	}
};


class TestClass{
public:
	vector<string> GetTestData()
	{
		vector<string> vec;
		vec.push_back("2");
		vec.push_back("1");
		vec.push_back("+");
		vec.push_back("3");
		vec.push_back("*");
		return vec;
	}
};