#include <iostream>
#include <stack>

using namespace std;

//************************************************Description***********************************************************
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//**********************************************************************************************************************

class Solution {
private:
	stack<char> sta;
public:
	bool isValid(string s) {
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				sta.push(s[i]);
			else
			{
				if (sta.size() == 0)
					return false;
				char temp = sta.top();
				sta.pop();
				switch (temp)
				{
				case '(':
					if (s[i] != ')')
						return false;
					break;
				case '[':
					if (s[i] != ']')
						return false;
					break;
				case '{':
					if (s[i] != '}')
						return false;
					break;
				default:
					return false;
					break;
				}
			}
		}
		if (sta.size() != 0)
			return false;

		return true;
	}
};