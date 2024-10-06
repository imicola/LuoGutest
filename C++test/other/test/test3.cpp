#include <iostream> 
using namespace std;
int main()
{
	long long t;
	cin>>t;
	long long a=t/3600,b=(t/60)%60,c=t%60;
	if(a<10&&b<10&&c<10)
	{
		cout<<0<<a<<":"<<0<<b<<":"<<0<<c<<endl;
	}
	else if(b<10&&c<10)
	{
		cout<<a<<":"<<0<<b<<":"<<0<<c<<endl;
	}
	else if (a<10&&c<10)
    {
        cout<<0<<a<<":"<<b<<":"<<0<<c<<endl;
    }
    else if (a<10)
    {
        cout<<0<<a<<":"<<b<<":"<<c<<endl;
    }
    else if (b<10)
    {
        cout<<a<<":"<<0<<b<<":"<<c<<endl;
    }
    else if (c<10)
    {
        cout<<a<<":"<<b<<":"<<0<<c<<endl;
    }
    else
    {
        cout<<a<<":"<<b<<":"<<c<<endl;
    }
	return 0;
}