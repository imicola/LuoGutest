#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(10010);
    string a;
    string b1;
    int k = 0; 
    for (size_t i = 0; i < n; i++)
    {
        //输入处理比较有趣，可以看看
        int b = 0,c = 0;
        cin >> a;
        if (a != "a" && a != "b" && a!= "c")
        {
            b = stoi(a);
            a = b1;
            cin >> c;
        }
        else
        {
            cin >> b >> c;
        }
        if (a == "a")
        {
            b1 = a;
            int temp = b+c;
            s[k++] = to_string(b) + "+" + to_string(c) + "=" + to_string(b+c);
        }
        else if (a == "b")
        {
            b1 = a;
            int temp = b+c;
            s[k++] = to_string(b) + "-" + to_string(c) + "=" + to_string(b-c);
        }
        else if (a == "c")
        {
            b1 = a;
            int temp = b+c;
            s[k++] = to_string(b) + "*" + to_string(c) + "=" + to_string(b*c);
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << s[i] << endl << s[i].size()<<endl;
    }
    return 0;
}