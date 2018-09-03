#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


//***********************Description************************************
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), 
//the plus + or minus sign -, non-negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples:
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//*********************************************************************


class Solution {
public:
	int calculate(string s) {
		int res = 0;
		vector<string> output;
		stack<string> ope;
		stack<int> rpn;
		bool sNum = false;
		int start = 0;
		int count = 0;

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
			else if (s[i] == ')')
			{
				while (ope.top() != "(")
				{
					output.push_back(ope.top());
					ope.pop();
				}
				ope.pop();
			}
			else if (s[i] == '(')
			{
				ope.push(s.substr(i,1));
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (ope.size() != 0 && (ope.top() == "+" || ope.top() == "-"))
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
		string s = "2147483647";
		return s;
	}
};