#include <bits/stdc++.h>
using namespace std;
//链表核心
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
//在链表尾部插入结点
void insert_end_node(Node *Newnode, Node *&p)
{
    // Node *Newnode = new Node(i);
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
//在链表头插入结点
void insert_head_node(Node *newnode, Node *&head)
{
    newnode->next = head;
    head = newnode;
}
//给定pos值，在这个pos下标结点前插入结点
void insert_pos_node(Node *newnode, int pos, Node *&head)
{
    if (pos == 0) {
        newnode->next = head;
        head = newnode;
        return;
    }
    Node *current = head;
    int currentposition = 0;
    while (current != nullptr && currentposition < pos - 1) {
        current = current->next;
        currentposition++;
    }
    newnode->next = current->next;
    current->next = newnode;
}

void pos_node_print(int pos, Node *&head)
{
    Node *current = head;
    for (size_t i = 0; i < pos && current->next != nullptr; i++) {
        current = current->next;
    }
    cout << current->val;
}

//遍历输出链表
void printnode(Node *head)
{
    Node *current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
}
//删除某一元素的结点
void delnode(int i, Node *&p)
{
    //链表为空
    if (p == nullptr) return;
    //头结点为目标值
    while (p != nullptr && p->val == i) {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
    //中间或尾部结点为目标
    Node *current = p;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->val == i) {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}
//删除给定pos下标的结点
void posdel(int pos, Node *&head)
{
    if (head == nullptr || pos < 0) return;
    if (pos == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    for (int i = 0; i < pos && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) return;
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}
//链表的尾删
void popdel_node(Node *&head)
{
    //链表为空
    if (head == nullptr) {
        return;
    }
    //链表只有一个元素
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    //链表有多个元素
    Node *current = head;
    while (current->next != nullptr && current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

signed main()
{
    //所有的node结点创建必须使用 Node * newnode = new Node(val) 来进行
    //lambda 构建
    auto cnewnoed = [=](int val) { return new Node(val); };
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Node *head = nullptr;
    int t = 0;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        int val;
        cin >> val;
        // Node *newnode = new Node(val);
        insert_end_node(cnewnoed(val), head);
        // insert_head_node(newnode, head);
    }
    // posdel(-1, head);
    // printnode(head);
    Node *newnode = new Node(1);
    insert_pos_node(newnode, 4, head);
    // cout << endl;
    printnode(head);
    // popdel_node(head);
    cout << endl;
    // pos_node_print(3, head);
    // printnode(head);
    // // int del = 0;
    // cin >> del;
    // delnode(del, head);
    // cout << t << endl;
    return 0;
}