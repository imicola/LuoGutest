//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Person
{
protected:
    string name;
    int age;

public:
    // Person();
};

class student : public Person
{
public:
    int ID;
    double cpp_score, cpp_count, cpp_grade;
    student(string s, int a, int b, double c, double d)
    {
        this->name = s;
        this->ID = a;
        this->age = b;
        this->cpp_score = c;
        this->cpp_count = d;
    }
    void prints()
    {
        this->cpp_grade = this->cpp_score * 0.9 + this->cpp_count * 0.1;
        cout << this->ID << " " << this->name << " ";
        printf("%.1f\n", this->cpp_grade);
    }
};

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while (1) {
        string name;
        int a, b;
        double c, d;
        cin >> name;
        if (name == "0") break;
        cin >> a >> b >> c >> d;
        student s(name, a, b, c, d);
        s.prints();
    }

    return 0;
}