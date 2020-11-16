#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

using std::cin;
using std::cout;
using std::max_element;
using std::string;
using std::vector;

class StackWithMax
{
    vector<int> stack;
    vector<int> stack2;
    int max = 0;

public:
    void Push(int value)
    {
        stack.push_back(value);
        if (max <= value)
        {
            max = value;
        }
        stack2.push_back(max);
        // for (int i = 0; i < stack2.size(); i++)
        //     cout << stack2[i] << "\n";
    }

    void Pop()
    {
        assert(stack.size());
        if (max == stack2.back())
        {
            max = stack2[stack2.size() - 2];
        }
        // for (int i = 0; i < stack2.size(); i++)
        //     cout << stack2[i] << "\n";
        stack2.pop_back();
        stack.pop_back();
    }

    int Max() const
    {
        assert(stack.size());
        return max;
    }
};

int main()
{
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i)
    {
        cin >> query;
        if (query == "push")
        {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop")
        {
            stack.Pop();
        }
        else if (query == "max")
        {
            cout << stack.Max() << "\n";
        }
        else
        {
            assert(0);
        }
    }
    return 0;
}