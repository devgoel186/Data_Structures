#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket
{
    Bracket(char type, int position) : type(type),
                                       position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);
    int error_code = 0;

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            Bracket b = {
                next,
                position + 1};
            opening_brackets_stack.push(b);
        }
        if (next == ')' || next == ']' || next == '}')
        {
            if (opening_brackets_stack.empty())
            {
                error_code = position + 1;
                break;
            }
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!top.Matchc(next))
            {
                error_code = position + 1;
                break;
            }
        }
    }

    if (error_code == 0 && opening_brackets_stack.empty())
        cout << "Success" << endl;
    else if (error_code == 0)
        cout << opening_brackets_stack.top().position << endl;
    else
        cout << error_code << endl;
    return 0;
}
