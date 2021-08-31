// 38min 19/25
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, money = 0;
int a[N] = {0};

bool check(int l, int r) {
    int sum = 0;
    for(int i = l; i <= r; i ++)
        sum += a[i];
    if(sum <= money) return true;
    return false;
}

int main() {
    int l, r, cnt = 0;
    cin >> n >> money;
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    int i, j = 0;
    while(i < n && j < n) {
        while(j < n && check(i, j)) {
            cnt ++;
            if(j != n - 1) j++;
            else break;
        }
        while(1) {
            i++;
            if(i == n) break;
            if(check(i, j)) {
                cnt = cnt + j - i;
                i = j;
            }
        }
    }
    cout << cnt;
    return 0;
}