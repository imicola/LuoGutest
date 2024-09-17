#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int p = 10;
    // vector<int> dp0(10,0);
    // cin >> dp0[0];
    // cin >> dp0[15];
    // cout <<"t1,0:size:"<<dp0.size()<<endl;
    // cout <<"t1,0:" <<dp0[0]<<endl;
    // cout <<"t2,0:size:"<<dp0.size()<<endl;
    // cout <<"t1,15:" <<dp0[15]<<endl;
    // cout <<"t3,15:size:"<<dp0.size()<<endl;
    // p = 15;
    // cout <<"t4,p=15:size:"<< dp0.size() <<endl;

    // vector <vector<int> >array;
    // vector<int> v;
    // for (int i = 0; i <3; i++){
    //     for (int j = 0; j <3; j++){
    //         int value;
    //         cin >> value;
    //         v.push_back(value);
    //     }
    //     array.push_back(v); //保存array的每个元素
    //     v.clear();
    // }

    // for (int i = 0; i <array.size(); i++)
    // {
    //     for (int j = 0; j <3; j++)
    //         cout <<array[i][j];
    //     cout<<endl;
    // }
    // return 0;
    // vector<vector<int>> dp(3,vector<int> (3,0)); 
    // for (int i = 0; i <3; i++){
    //     for (int j = 0; j <3; j++){
    //         cin >> dp[i][j];
    //     }
    // }

    // for (int i = 0; i <dp.size(); i++)
    // {
    //     for (int j = 0; j <3; j++)
    //         cout << dp[i][j];
    //     cout<<endl;
    // }
    // return 0;

    // vector<int> dp(0,0);
    // for (size_t i = 0; i < 15; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     dp.push_back(temp);
    //     cout <<"size:"<<dp.size() <<"第"<< i <<"个数"<<endl;
    // }
    
    // for (size_t i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i] <<" ";
    // }
    
    // return 0;


    vector<pair<int,int>> dp1(10);
    pair<int,int> p1;
    for (size_t i = 0; i < 5; i++)
    {
        cin >> p1.first >> p1.second;
        dp1[i] = p1;
    }
    int k;
    cin >> k;
    for (size_t i = 0; i < dp1.size(); i++)
    {
        if (k == dp1[i].first)
        {
            cout << dp1[i].second;
        }
    }
    

}
    // vector<vector<int>> dp(5,vector<int> (6,0)); 
    // vector<vector<vector<int>>> dp3(5,vector<vector<int>>(6,vector<int> (4,0)));
    // int mat[5][6][4];