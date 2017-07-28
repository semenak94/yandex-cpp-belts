#include <algorithm>
#include <string>

bool IsPalindrom(std::string input)
{
    std::string s(input);
    reverse(input.begin(), input.end());
    if (s.compare(input) == 0) {
        return true;
    }

    return false;
}
