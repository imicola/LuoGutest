#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 11; // 最大大小
int n;
array<array<char, MAX_N>, MAX_N> end0; // 用 std::array 替换原始数组
array<array<char, MAX_N>, MAX_N> temp1;
array<array<char, MAX_N>, MAX_N> temp0;

void get_n() {
    cin >> n;
    
}

void get_block() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp0[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> end0[i][j];
        }
    }
}

void fanzhuan() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(temp1[i][j], temp1[i][n - j - 1]);
        }
    }
}

void fan90() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp1[j][i] = temp0[n - i - 1][j]; // 直接旋转90度
        }
    }
}

void fanshe() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp1[i][j] = temp0[i][j];
        }
    }
    fanzhuan();
}

void trans(int x) {
    switch (x) {
        case 0:
            fan90();
            break;
        case 1:
            fan90();
            temp0 = temp1; // 直接赋值
            fan90();
            break;
        case 2:
            for (int i = 0; i < 3; i++) {
                fan90();
            }
            break;
        case 3:
            fanshe();
            break;
        case 4:
            fanshe();
            fan90();
            break;
        case 5:
            fanshe();
            fan90();
            temp0 = temp1; // 直接赋值
            fan90();
            break;
        case 6:
            for (int i = 0; i < 3; i++) {
                fanshe();
                fan90();
            }
            break;
        case 7:
            temp1 = temp0; // 直接赋值
            break;
        case 8:
            temp1 = end0; // 直接赋值
            break;
    }
}

int main() {
    get_n();
    get_block();
    
    int x = 0;
    while (x < 9) {   
        trans(x);
        
        if (temp1 == end0) {
            break; // 找到匹配
        }
        x++;
    }
    
    if (x < 4) {
        cout << x + 1;
    } else if (x >= 4 && x <= 6) {
        cout << 5;
    } else {
        cout << x - 1;
    }
    
    return 0;
}
