//
// Created by wangmin on 7/19/18.
//

class Solution {
public:
    bool validate_bracket(const char * code)
    {
        stack<char> s;
        char c = code[0];
        int i = 0;
        while(c != '\0')
        {
            switch (c){
                case '[':
                case '{':
                case '(':
                    s.push(c);
                    break;
                case ']':{
                    if(s.top() != '[') {
                        return false;
                    }
                    s.pop();
                    break;
                }
                case '}':{
                    if(s.top() != '{') {
                        return false;
                    }
                    s.pop();
                    break;
                }
                case ')':{
                    if(s.top() != '(') {
                        return false;
                    }
                    s.pop();
                    break;
                }
                default:
                    break;
            }
            c = code[++i];
        }
        return s.empty();
    }
};

void test1()
{
    char* code = "int bar () {{ }}";
    Solution s;
    std::cout << s.validate_bracket(code) << std::endl;

}
void test2()
{
    char* code = "int bar () {{ }";
    Solution s;
    std::cout << s.validate_bracket(code) << std::endl;

}

void test3()
{
    char* code = "int bar ({}) {{ }}";
    Solution s;
    std::cout << s.validate_bracket(code) << std::endl;

}

