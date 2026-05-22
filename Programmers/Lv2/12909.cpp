#include <string>
#include <iostream>

bool solution(std::string s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            ++count;
        }
        else
        {
            --count;
        }

        if (count < 0)
        {
            return false;
        }
    }

    return (count == 0);
}

#ifdef LOCAL
int main()
{
    bool answer1 = solution("()()"); // true
    bool answer2 = solution("(())()"); // true
    bool answer3 = solution(")()("); // false
    bool answer4 = solution("(()("); // false

    return 0;
}
#endif