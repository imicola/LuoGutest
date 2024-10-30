#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e3 + 5;
int n, m;
int a[N];
void binarySearch(int m)
{
    // left:序列的左端位置，right:序列的右端位置
    int left = 0, right = n - 1;
    /****** 请补充以下的while循环******/
    while (left <= right) {
        int mid = (left + right)/2;   // 序列的中间位置
        if (a[mid] == m) {
            cout << "YES";
            return;
        }
        if (a[mid] > m) right--;
        if (a[mid] < m) left++;
        //cout << mid << right << left << endl;
    }
    cout << "NO" << endl;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);   // 从小大进行排序
    cin >> m;
    binarySearch(m);
    return 0;
}