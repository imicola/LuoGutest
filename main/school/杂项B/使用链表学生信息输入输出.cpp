//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Node
{
    string name;
    int snum, i;
    Node *next;
    Node(int num, string str, int ki)
    : i(num)
    , name(str)
    , snum(ki)
    , next(nullptr)
    {
    }
};

void insert_end_node(int i, string str, int ki, Node *&p)
{
    Node *Newnode = new Node(i, str, ki);
    bool flag = 0;
    if (p == nullptr) {
        p = Newnode;
        return;
    }
    Node *current = p;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = Newnode;
}


void printnode(Node *head)
{
    Node *current = head;
    while (current != nullptr) {
        cout << current->i << " " << current->name << " " << current->snum << endl;
        current = current->next;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Node *head = nullptr;

    while (1) {
        string str;
        int i;
        int fen;
        cin >> i;
        if (i == 0) break;
        cin >> str >> fen;
        insert_end_node(i, str, fen, head);
    }
    printnode(head);
    return 0;
}