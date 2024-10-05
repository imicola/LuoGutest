#include <bits\stdc++.h>
using namespace std;

vector<int> brr;
int san(int temp);
int i = 0;

int main(void){
    int arr[3]={0,0,46};
    int d;
    for(i = 0  ;i <= 2;i++)
    {
        d = arr[2-i] ;       
        arr[i] = san(d);
        cout << "1"  << (char)(arr[i]);
    }
    return 0;
}
int san(int temp)
{
    brr.push_back(temp);
    return brr.back();
}