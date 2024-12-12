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

int t = 0;

struct Node
{
    int val;
    Node *next = nullptr;
    Node(int value)
    : val(value)
    , next(nullptr)
    {
    }
};

void insert_end_node(int i, Node *&p)
{
    Node *Newnode = new Node(i);
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
        cout << current->val << " ";
        current = current->next;
    }
}

void delnode(int i, Node *&p)
{
    //链表为空
    if (p == nullptr) return;
    //头结点为目标值
    while (p != nullptr && p->val == i) {
        Node *temp = p;
        p = p->next;
        delete temp;
        t--;
    }
    //中间或尾部结点为目标
    Node *current = p;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->val == i) {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            t--;
        }
        else {
            current = current->next;
        }
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Node *head = nullptr;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        int val;
        cin >> val;
        insert_end_node(val, head);
    }
    int del = 0;
    cin >> del;
    delnode(del, head);
    cout << t << endl;
    printnode(head);
    return 0;
}