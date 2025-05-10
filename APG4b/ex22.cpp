#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pairs[index].second > pairs[j].second)
            {
                index = j;
            }
        }
        swap(pairs[i], pairs[index]);
    }

    for (pair<int, int> p : pairs)
    {
        cout << p.first << " " << p.second << endl;
    }
}
