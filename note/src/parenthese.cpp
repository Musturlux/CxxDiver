#include <iostream>
#include <string>
#include <stack>

bool check_parentheses(std::string const &str)
{
    std::stack<char> parenthese_stack;
    char tmp;
    for (char const &c : str)
    {
        if (c == '(' || c == '[')
        {
            parenthese_stack.push(c);
        }
        else if (c == ')' || c == ']')
        {
            tmp = parenthese_stack.top();
            switch (tmp)
            {
            case '(':
                if (c != ')')
                {
                    return false;
                }
                break;

            case '[':
                if (c != ']')
                {
                    return false;
                }
                break;

            default:
                break;
            }
            parenthese_stack.pop();
        }
    }
    return parenthese_stack.empty();
}