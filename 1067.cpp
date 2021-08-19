// 14:01 24:19/25
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N]= {0};
int n;

void print() {
    for(int i = 0; i < n; i ++) {
        cout << a[i];
        if(i != n - 1)
            cout << " ";
    }
    cout << endl;
}

bool check() {
    for(int i = 0; i < n ; i ++)
        if(a[i] != i) return false;
    return true;
}

int main() {
    cin >> n;
    int wrong = 0;
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        a[t] = i; // 数字t的位置是a[t]
        if(t != i && t != 0) wrong ++;
    }


    int ans = 0;
    int k = 1;
    while(wrong > 0) {
        while(a[0] != 0) {
            swap(a[0], a[a[0]]);
            ans ++;
            wrong --;
        }

        while(a[k] == k) k ++;
        if(k < n) {
            swap(a[0], a[k]);
            ans ++;
        }
    }

    cout << ans;

    return 0;
}