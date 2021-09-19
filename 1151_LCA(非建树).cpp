#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, pre[N], in[N];
unordered_map<int, bool> flag;
unordered_map<int, int> inPos;
int a, b;

int LCA(int preL, int preR, int inL, int inR) {
    if(preL > preR || !flag[a] || !flag[b]) return -1;
    int k, rootKey = pre[preL], lca = -1;
    // 如果用查找的方法查找key的位置会超时
    k = inPos[rootKey];
    if(rootKey == a || rootKey == b) lca = rootKey;
    else if((inPos[a] < k && inPos[b] > k) || (inPos[a] > k && inPos[b] < k))
        lca = rootKey;
    else if(inPos[a] < k && inPos[b] < k)
        lca = LCA(preL + 1, preL + k - inL, inL, k - 1);
    else if(inPos[a] > k && inPos[b] > k)
        lca = LCA(preL + k - inL + 1, preR, k + 1, inR);
    return lca;
}

int main() {
    int m;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i ++) { scanf("%d", &in[i]); flag[in[i]] = 1; inPos[in[i]] = i; }
    for(int i = 0; i < n; i ++) { scanf("%d", &pre[i]); flag[pre[i]] = 1; }
    for(int i = 0; i < m; i ++) {
        scanf("%d%d", &a, &b);
        int ans = LCA(0, n - 1, 0, n - 1);
        if(!flag[a] && !flag[b])
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!flag[a] || !flag[b])
            printf("ERROR: %d is not found.\n", !flag[a] ? a : b);
        else {
            if(ans == a || ans == b)
                printf("%d is an ancestor of %d.\n",ans == a ? a : b, ans == a ? b : a);
            else
                printf("LCA of %d and %d is %d.\n", a, b, ans);
        }
    }
    return 0;
}