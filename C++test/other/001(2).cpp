#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    for(int i=0;i< 8;i++)
    {
        for(int j=0;j< 8;j++)
        {
            for(int k=0;k< 8;k++)
            {
                for(int l=0;l< 8;l++)
                {
                    for(int m=0;m< 8;m++)
                    {
                        for(int n=0;n< 8;n++)
                        {
                            for(int o=0;o< 8;o++)
                            {
                                for(int p=0;p< 8;p++)
                                {
                                    if (i !=j&& i != k && i != l && i != m && i != n && i != o && i != p && j != k && j != l && j != m && j != n && j != o && j != p && k != l && k != m && k != n && k != o && k != p && l != m && l != n && l != o && l != p && m != n && m != o && m != p && n != o && n != p && o != p)
                                    {
                                        cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << " " << arr[m] << " " << arr[n] << " " << arr[o] << " " << arr[p] << endl;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }    
    return 0;
}