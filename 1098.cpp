// 13:25
// 13:55 21/25
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, in[N], mid[N];

int main() {
    int t;
    scanf("%d", &n);
    for(int i = 0; i < n ; i ++)
        scanf("%d", &in[i]);
    for(int i = 0; i < n ; i ++)
        scanf("%d", &mid[i]);

    int p;
    for(p = 0; p < n - 1 ; p++)
        if(mid[p] > mid[p + 1]) break;
    p ++;
    for(; p < n; p ++)
    if(mid[p] != in[p]) break;

    if(p == n) { // 插入排序
        cout << "Insertion Sort\n";
        int k = 0; // 下一个处理的数字
        for(k = 1; k < n; k ++) {
            if(mid[k] < mid[k - 1])
                break;
        }
        for(int i = k - 1; i >= 0; i --) {
            if(mid[i] > mid[i + 1])
                swap(mid[i], mid[i + 1]);
        }
        for(int i = 0; i < n ; i ++) {
            cout << mid[i];
            if(i != n - 1)
                cout << " ";
        }
    }
    else { // 堆排序
        cout << "Heap Sort\n";
        // 整体后移mid数组
        for(int i = n - 1; i >= 0; i --)
            mid[i + 1] = mid[i];
        mid[0] = 0;

        int k = 0; // 下一个处理的数字
        for(k = n; k >= 1; k --)
            if(mid[k] < mid[1]) break;
        swap(mid[1], mid[k]);
        k-- ;

        int a = 1, b = 2 * a;
        while(b <= k) {
            if(b + 1 <= k && mid[b + 1] > mid[b])
                b ++;
            if(mid[a] < mid[b]) {
                swap(mid[a], mid[b]);
                a = b;
                b = 2 * a;
            }
            else {
                break;
            }
        }

        for(int i = 1; i <= n ; i ++) {
            cout << mid[i];
            if(i != n)
                cout << " ";
        }
    }
    return 0;
}