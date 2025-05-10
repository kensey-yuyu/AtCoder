#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int result = 1;
    for (int i = 1; i < s.size(); i = i + 2)
    {
        if (s.at(i) == '+')
        {
            result++;
        }
        else if (s.at(i) == '-')
        {
            result--;
        }
    }
    cout << result << endl;
}
