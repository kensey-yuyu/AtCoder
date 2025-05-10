#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        sum += a.at(i);
    }

    int average = sum / n;
    for (int i = 0; i < n; i++)
    {
        int diff = a.at(i) - average;
        if (diff < 0)
        {
            diff *= -1;
        }
        cout << diff << endl;
    }
}
