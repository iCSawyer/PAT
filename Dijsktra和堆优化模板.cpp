//通用Dij：①找最近点加入集合要判断vis[]；②优化时判断G[][] != INF，要提前fill(G[0], G[0]+N*N, INF)
//堆优化：①取堆顶后判断vis[]是否为true，否则continue；②每次优化，都要push进优先队列 

#include<bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 1e9;
int G[N][N], vis[N], d[N] = {0};
int n, m, s; //顶点数，边数，起点编号

struct cmp {
    bool operator()(int a, int b) {
        return d[a] > d[b];
    }
};

void Dij(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    for(int i = 0; i < n; i ++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j ++) {
            if(!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        else vis[u] = true;
        for(int v = 0; v < n; v ++) {
            if(!vis[v] && G[u][v] != INF && d[v] > d[u] + G[u][v])
                d[v] = d[u] + G[u][v];
        }
    }
}

void Dij_heap(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    priority_queue<int, vector<int>, cmp> q;
    q.push(s);
    while(q.size()) {
        int u = q.top(); q.pop();
        if(vis[u]) continue;
        else vis[u] = 1;
        for(int v = 0; v < n; v ++) {
            if(!vis[v] && G[u][v] != INF && d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                q.push(v);
            }
        }
    }
}

int main() {
    int u, v, w;
    scanf("%d%d%d", &n, &m, &s);
    fill(G[0], G[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
    }
    Dij_heap(s);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    return 0;
}