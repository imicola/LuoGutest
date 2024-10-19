#include <bits/stdc++.h>
using namespace std;

int H1,M1,ph1,pm1,H2,M2,ph2,pm2;

void get_data()
{
    scanf("%d:%d",&H1,&M1);
    scanf("%d:%d",&H2,&M2);
    scanf("%d:%d",&ph1,&pm1);
    scanf("%d:%d",&ph2,&pm2);
}
//打表算星期
vector<string> s = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

int main()
{
    get_data();
    int pp1 = H1*60 + M1;
    int k1  = (ph1*60 + pm1);
    int pp2 = H2*60 + M2; 
    int k2  = (ph2*60 + pm2);
    int flag = 0;
    //这段for简直神来之笔
    for (size_t i = 1; i <= 10080; i++) // 一个星期最多就10080min，最小1min,如果超过10080此还没有相等说明没有可能会相等了
    {
        //当相等的时候标记flag为下面做准备
        if (pp1 == pp2)
        {
            flag++;
            break;
        }
        //如果pp1星闪的时间短于pp2，那就加间隔时间
        //无需考虑同时增加间隔时间(why?)
        //reason : 这个是在一个线性时间轴上标记所有存在点位，但实际情况却是一个循环时间轴，若线性时间轴上有点位重合，将线性时间轴裁切成若干有限时间轴其必有重合点
        else if (pp1 < pp2)
        {
            pp1 += k1;
        }
        else
        {
            pp2 += k2;
        }
    }
    
    if (!flag)
    {
        cout << "Never";
        return 0;
    }
    //简单的单位换算，分钟变时间(怎么有人这里错两次啊)
    int t = pp1/(60*24)%7;
    cout << s[t] << endl;
    int t2 = (pp1%(60*24)); 
    printf("%02d:%02d",t2/60,t2%60);
    return 0;
    
}