#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, pre[N];
map<int, bool> in;

int main() {
    int m;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i ++) { scanf("%d", &pre[i]); in[pre[i]] = 1; }
    for(int i = 0; i < m; i ++) {
        int a, b, j, lca;
        scanf("%d%d", &a, &b);
        
        for(j = 0; j < n; j ++)
            if((pre[j] >= a && pre[j] <= b) || (pre[j] <= a && pre[j] >= b))
                break;
        lca = pre[j];

        if(!in[a] && !in[b]) printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!in[a]) printf("ERROR: %d is not found.\n", a);
        else if(!in[b]) printf("ERROR: %d is not found.\n", b);
        else if(lca == a || lca == b)
            printf("%d is an ancestor of %d.\n", lca == a ? a : b, lca == a ? b : a);
        else
            printf("LCA of %d and %d is %d.\n", a, b, lca);
    }
    return 0;
}