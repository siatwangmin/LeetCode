#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//****************Description*******************************************************
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, / 
//operators and empty spaces . The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples:
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//**************************************************************************************


class Solution {
public:
	int calculate(string s) {
		int res = 0;
		vector<string> output;
		stack<string> ope;
		stack<int> rpn;
		bool sNum = false;
		int start = 0;

		if (s.size() == 0)
			return res;
		//中缀式转换为逆序式
		for (size_t i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
			{
				start = i;
				while (i < s.size() && '0' <= s[i] && s[i] <= '9')
				{
					i++;
				}
				output.push_back(s.substr(start, i - start));
				if (i != s.size())
				{
					i--;
				}
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (ope.size() != 0)
				{
					output.push_back(ope.top());
					ope.pop();
				}
				ope.push(s.substr(i, 1));
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				while (ope.size() != 0 && ope.top() != "+" && ope.top() != "-")
				{
					output.push_back(ope.top());
					ope.pop();
				}
				ope.push(s.substr(i, 1));
			}
		}

		while (ope.size() != 0)
		{
			output.push_back(ope.top());
			ope.pop();
		}


		//RPN
		for (size_t j = 0; j < output.size(); j++)
		{
			if (output[j] == "+")
			{
				int second = rpn.top();
				rpn.pop();
				int first = rpn.top();
				rpn.pop();
				rpn.push(first + second);
			}
			else if (output[j] == "-")
			{
				int second = rpn.top();
				rpn.pop();
				int first = rpn.top();
				rpn.pop();
				rpn.push(first - second);
			}
			else if (output[j] == "*")
			{
				int second = rpn.top();
				rpn.pop();
				int first = rpn.top();
				rpn.pop();
				rpn.push(first * second);
			}
			else if (output[j] == "/")
			{
				int second = rpn.top();
				rpn.pop();
				int first = rpn.top();
				rpn.pop();
				rpn.push(first / second);
			}
			else
			{
				rpn.push(atoi(output[j].c_str()));
			}
		}
		res = rpn.top();
		return res;
	}
};

class TestClass{
public:
	string GetTestData()
	{
		string s = "3+ 2*2";
		return s;
	}
};