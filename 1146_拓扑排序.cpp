#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n;
int seq[N];
vector<int> inDegree, inDegree1;
vector<int> Adj[N];

bool check() {
    // 循环n次更直接
    for(int i = 0; i < n; i ++) {
        int a = seq[i];
        if(inDegree[a] != 0) return false;
        for(int j = 0; j < Adj[a].size(); j ++) {
            int v = Adj[a][j];
            inDegree[v] --;
        }
    }
    return true;
}

int main() {
    vector<int> ans;
    int m, a, b;
    cin >> n >> m;
    inDegree.resize(n + 1); inDegree1.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        scanf("%d%d", &a, &b);
        Adj[a].push_back(b);
        inDegree1[b] ++;
    }
    cin >> m;
    for(int i = 0; i < m; i ++) {
        inDegree = inDegree1;
        for(int i = 0;i < n; i ++) scanf("%d", &seq[i]);
        if(!check()) ans.push_back(i);
    }
    for(int i = 0; i < ans.size(); i ++) {
        printf("%d", ans[i]);
        if(i != ans.size() - 1) printf(" ");
    }
    return 0;
}