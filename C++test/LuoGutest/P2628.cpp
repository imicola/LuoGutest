#include <bits/stdc++.h>
using namespace std;

int main()
{
    string map1;
    getline(cin,map1);
    cout << map1;
    int n;
    cin >> n;
    vector<int> arr(100200);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto it = map1.begin() - 1;
    int c = 0;
    for (size_t i = 0;i < n; i++)
    {   
        it += arr[i];
        if (*it == '>')
        {
            for (auto it2 = it;*it2 == '>';it2++) //!!!
            {
                c++;
            }
            if (c > 2)
            {
                it += c;
                c = 0;
                continue;
            }
        }
        if (*it == '*')
        {
            for(auto it3 = it; *it3 == '*';it3++)
            {
                c++;
            }
            if (c > 2)
            {
                it -= c;
                c = 0;
                if (it - map1.begin() + 1 < 0)
                {
                    it = map1.begin();
                }
                continue;
            }
        }
    }
    if (map1.end() - it - 1 < 0)
    {
        cout << map1.size() <<" "<<0 << endl;
        return 0;
    }
    if (it - map1.begin() + 1 < 0)
    {
        cout << 1 <<" "<< map1.size()<< endl;
        return 0;
    }
    cout << it - map1.begin() + 1 << " ";
    cout << map1.end() - it - 1 << endl; 
    return 0;

    //不知道为什么用getline+迭代器会判错qwq
}