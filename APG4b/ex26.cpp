#include <bits/stdc++.h>
using namespace std;

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec)
{
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << "]" << endl;
}

// int同士の加算
int add_int(int a, int b)
{
    return a + b;
}

// int同士の減算
int sub_int(int a, int b)
{
    return a - b;
}

// vector同士の加算
vector<int> add_vector(vector<int> a, vector<int> b)
{
    vector<int> c;
    for (int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i] + b[i]);
    }
    return c;
}

// vector同士の減算
vector<int> sub_vector(vector<int> a, vector<int> b)
{
    vector<int> c;
    for (int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i] - b[i]);
    }
    return c;
}

// int変数を宣言(更新)
vector<pair<char, int>> define_int(char c, int value, vector<pair<char, int>> int_variables)
{
    for (int i = 0; i < int_variables.size(); i++)
    {
        if (int_variables[i].first == c)
        {
            int_variables[i].second = value;
            return int_variables;
        }
    }
    int_variables.push_back(make_pair(c, value));
    return int_variables;
}

// int変数が宣言済みかどうか判定
int check_exist_int(char c, vector<pair<char, int>> int_variables)
{
    int value;
    for (int i = 0; i < int_variables.size(); i++)
    {
        if (int_variables[i].first == c)
        {
            return i;
        }
    }
    return -1;
}

// int変換を返す
int load_int(string c, vector<pair<char, int>> int_variables)
{
    int index = check_exist_int(c[0], int_variables);
    if (index >= 0)
    {
        return int_variables[index].second;
    }
    exit(-1);
}

// int変数なら数字に変換して返す
int return_int(string c, vector<pair<char, int>> int_variables)
{
    try
    {
        return stoi(c);
    }
    catch (const invalid_argument &e)
    {
        return load_int(c, int_variables);
    }
}

// vector変数を宣言(更新)
vector<pair<char, vector<int>>> define_vector(char c, vector<int> value, vector<pair<char, vector<int>>> vector_variables)
{
    for (int i = 0; i < vector_variables.size(); i++)
    {
        if (vector_variables[i].first == c)
        {
            vector_variables[i].second = value;
            return vector_variables;
        }
    }
    vector_variables.push_back(make_pair(c, value));
    return vector_variables;
}

// vector変数が宣言済みかどうか判定
int check_exist_vector(char c, vector<pair<char, vector<int>>> vector_variables)
{
    vector<int> value;
    for (int i = 0; i < vector_variables.size(); i++)
    {
        if (vector_variables[i].first == c)
        {
            return i;
        }
    }
    return -1;
}

// vector変換を返す
vector<int> load_vector(string c, vector<pair<char, vector<int>>> vector_variables)
{
    int index = check_exist_vector(c[0], vector_variables);
    if (index >= 0)
    {
        return vector_variables[index].second;
    }
    exit(-1);
}

int main()
{
    // 命令数を入力
    int n;
    cin >> n;

    // 命令列を入力
    vector<pair<string, vector<string>>> operations(n);
    for (int i = 0; i < n; i++)
    {
        // 命令の種類を入力
        string ope;
        cin >> ope;
        // 命令の引数を入力
        vector<string> args;
        while (true)
        {
            string arg;
            cin >> arg;
            args.push_back(arg);
            if (arg == ";")
            {
                break;
            }
        }
        operations[i] = make_pair(ope, args);
    }

    // // 各命令を実行
    vector<pair<char, int>> int_variables;
    vector<pair<char, vector<int>>> vector_variables;
    for (int i = 0; i < n; i++)
    {
        pair<string, vector<string>> operation = operations[i];
        if (operation.first == "int")
        {
            char c = operation.second[0][0];
            int value = return_int(operation.second[2], int_variables);
            for (int j = 3; j < operation.second.size() - 1; j = j + 2)
            {
                if (operation.second[j] == "+")
                {
                    value = add_int(value, return_int(operation.second[j + 1], int_variables));
                }
                else if (operation.second[j] == "-")
                {
                    value = sub_int(value, return_int(operation.second[j + 1], int_variables));
                }
            }
            int_variables = define_int(c, value, int_variables);
        }
        else if (operation.first == "print_int")
        {
            int value = return_int(operation.second[0], int_variables);
            for (int j = 1; j < operation.second.size() - 1; j = j + 2)
            {
                if (operation.second[j] == "+")
                {
                    value = add_int(value, return_int(operation.second[j + 1], int_variables));
                }
                else if (operation.second[j] == "-")
                {
                    value = sub_int(value, return_int(operation.second[j + 1], int_variables));
                }
            }
            cout << value << endl;
        }
        else if (operation.first == "vec")
        {
            char c = operation.second[0][0];
            vector<int> v1;
            vector<int> v2;
            bool in_vec = false;
            function<vector<int>(vector<int>, vector<int>)> ope;
            for (int j = 2; j < operation.second.size() - 1; j++)
            {
                if (operation.second[j] == "[")
                {
                    in_vec = true;
                }
                else if (operation.second[j] == "]")
                {
                    in_vec = false;
                    if (ope != nullptr)
                    {
                        v1 = ope(v1, v2);
                    }
                    else
                    {
                        v1 = v2;
                    }
                    v2 = {};
                }
                else if (operation.second[j] == "+")
                {
                    ope = add_vector;
                }
                else if (operation.second[j] == "-")
                {
                    ope = sub_vector;
                }
                else if (operation.second[j] == ",")
                {
                    continue;
                }
                else
                {
                    if (in_vec == true)
                    {
                        v2.push_back(return_int(operation.second[j], int_variables));
                    }
                    else
                    {
                        v2 = load_vector(operation.second[j], vector_variables);
                        if (ope != nullptr)
                        {
                            v1 = ope(v1, v2);
                        }
                        else
                        {
                            v1 = v2;
                        }
                        v2 = {};
                    }
                }
            }
            vector_variables = define_vector(c, v1, vector_variables);
        }
        else if (operation.first == "print_vec")
        {
            vector<int> v1;
            vector<int> v2;
            bool in_vec = false;
            function<vector<int>(vector<int>, vector<int>)> ope;
            for (int j = 0; j < operation.second.size() - 1; j++)
            {
                if (operation.second[j] == "[")
                {
                    in_vec = true;
                }
                else if (operation.second[j] == "]")
                {
                    in_vec = false;
                    if (ope != nullptr)
                    {
                        v1 = ope(v1, v2);
                    }
                    else
                    {
                        v1 = v2;
                    }
                    v2 = {};
                }
                else if (operation.second[j] == "+")
                {
                    ope = add_vector;
                }
                else if (operation.second[j] == "-")
                {
                    ope = sub_vector;
                }
                else if (operation.second[j] == ",")
                {
                    continue;
                }
                else
                {
                    if (in_vec == true)
                    {
                        v2.push_back(return_int(operation.second[j], int_variables));
                    }
                    else
                    {
                        v2 = load_vector(operation.second[j], vector_variables);
                        if (ope != nullptr)
                        {
                            v1 = ope(v1, v2);
                        }
                        else
                        {
                            v1 = v2;
                        }
                        v2 = {};
                    }
                }
            }
            print_vec(v1);
        }
        else
        {
            return -1;
        }
    }
}
