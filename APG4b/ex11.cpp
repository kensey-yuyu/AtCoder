#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    string op;

    cin >> n >> a;

    for (int i = 0; i < n; i++)
    {
        cin >> op >> b;

        if (op == "+")
        {
            a += b;
            cout << i + 1 << ":" << a << endl;
        }
        else if (op == "-")
        {
            a -= b;
            cout << i + 1 << ":" << a << endl;
        }
        else if (op == "*")
        {
            a *= b;
            cout << i + 1 << ":" << a << endl;
        }
        else if (op == "/")
        {
            if (b == 0)
            {
                cout << "error" << endl;
                break;
            }
            else
            {
                a /= b;
                cout << i + 1 << ":" << a << endl;
            }
        }
        else
        {
            cout << "error" << endl;
            break;
        }
    }
}
