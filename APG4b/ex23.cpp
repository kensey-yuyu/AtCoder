#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int max_start = 0;
    int max_end = 0;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1 && a[index] == a[i])
        {
            if (i - index + 1 > max_end - max_start + 1)
            {
                max_start = index;
                max_end = i;
            }
        }
        else if (a[index] != a[i])
        {
            if (i - index > max_end - max_start + 1)
            {
                max_start = index;
                max_end = i - 1;
            }
            index = i;
        }
    }

    int number = a[max_start];
    int count = max_end - max_start + 1;
    cout << number << " " << count << endl;
}
