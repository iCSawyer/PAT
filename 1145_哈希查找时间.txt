// 20.15
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int msize, n, m;
int hashTable[N];

bool isPrime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i ++)
        if(x % i == 0) return false;
    return true;
}


int main() {
    int t, cnt = 0;
    cin >> msize >> n >> m;
    // 检查msize是否为素数
    while(!isPrime(msize))
        msize ++;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &t);
        int square = 1, fx = t % msize;
        while(hashTable[fx] != 0 && square < msize) {
            fx = (t + square * square) % msize;
            square ++;
        }
        if(square == msize)
            printf("%d cannot be inserted.\n", t);
        else
            hashTable[fx] = t;
    }

    for(int i = 0; i < m; i ++) {
        scanf("%d", &t);
        int square = 1, fx = t % msize;
        cnt ++;
        while(hashTable[fx] != t && hashTable[fx] != 0 && square <= msize) {
            fx = (t + square * square) % msize;
            square ++;
            cnt ++;
        }
    }
    printf("%.1f", cnt * 1.0 / m);
    return 0;
}