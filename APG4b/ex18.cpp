#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<vector<char>> result(n, vector<char>(n, '-'));
    for (int i = 0; i < m; i++)
    {
        result[a[i] - 1][b[i] - 1] = 'o';
        result[b[i] - 1][a[i] - 1] = 'x';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j];

            if (j < n - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
}
