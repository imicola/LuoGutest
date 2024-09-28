#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 该程序用于判断输入的数字是否可以表示为两个斐波那契数的乘积。
    int T;
    cin >> T;
    vector<int> arr1(T);
    vector<long long> arr(50);
    arr[0] = 0;
    arr[1] = 1;
    // 计算前50个斐波那契数并存入数组arr中。
    for (size_t i = 2; i <= 50; i++)
    {
        arr[i] = arr[i-1] + arr[i - 2];
    }
    // 从标准输入读取T个测试用例的数字。
    for (size_t i = 0; i < T; i++)
    {
        cin >> arr1[i];
    }
    // 对每个测试用例进行处理。
    for (size_t i = 0; i < T; i++)
    {
        int flag = 0;
        // 嵌套循环检查是否存在两个斐波那契数，其乘积等于当前测试用例的数字。
        for (size_t k = 0; arr[k] <=  arr1[i] ; k++)
        {
            for (size_t j = k; arr[j] <= arr1[i] ; j++)
            {
                if (arr1[i] == arr[k] * arr[j])
                {
                    cout << "TAK";
                    flag++;
                    goto P;
                }
            }
        }
        // 如果未找到这样的两个斐波那契数，则输出"NIE"。
        if (flag == 0)
        {
            cout << "NIE";
        }
        P:
        cout << endl;
    }

    return 0;
}