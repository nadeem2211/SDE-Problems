#include <iostream>
using namespace std;

bool isPalindrom(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[(str.length()) - i - 1])
            return false;
    }
    return true;
}

int main()
{
    string arr = "abcdef";

    cout << isPalindrom(arr) << endl;

    return 0;
}