 15min 2525
#includebitsstdc++.h
using namespace std;

const int INF = 1e9;
const int N = 10010;
int n, m, k; 测试数、前置关系数、样例数
int G[N][N], D[N][N];
int vis[N];
不可能情况的变量
int isOK = 1, isNotDirect[N] = {0};
vectorint path;
迪杰斯特拉
int dvis[N], d[N];
int pre[N];

void Dij(int s) {
    pre[s] = s;
    fill(d, d + N, INF);
    d[s] = 0;
    for(int i = 0; i  n; i ++) {
        int u = -1, MIN = INF;
        for(int j = 0; j  n; j ++) {
            if(d[j]  MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        dvis[u] = 1;
        for(int v = 0; v  n; v ++) {
            if(!dvis[v] && G[u][v] != INF && d[v]  d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    }
}

void setDirect() {
    for(int i = 0; i  path.size(); i ++)
        isNotDirect[path[i]] = 1;
}

void printPath() {
    for(int i = 0; i  path.size(); i ++)
        cout  path[i];
    cout  endl;
}

void DFS(int s) {
     printPath();
    vis[s] = 1;
    for(int i = 0; i  n; i ++) {
        if(G[s][i] != INF) {
            path.push_back(i);
            if(path[0] == i) {  如果有环路
                isOK = 0;
                setDirect();
            }
            if(!vis[i]) {
                DFS(i);
            }
            path.pop_back();
        }
    }
}

int main() {
    int t;
    cin  n  m;
    fill(G[0], G[0] + N  N, INF);
    for(int i = 0; i  m; i ++) {
        int t1, t2, s, d;
        scanf(%d%d%d%d, &t1, &t2, &s, &d);
        G[t1][t2] = s; s是通过t1，获取上t2的最小分数
        D[t1][t2] = d; 如果通过t1，打算上t2，就可以抵扣t2的钱
    }
     DFSTravel
    for(int i = 0; i  n; i ++) {
        if(vis[i] == false) {
            path.push_back(i);
            DFS(i);
            path.pop_back();
        }
    }

    if(isOK) {
        cout  Okay.;
        cin  k;
        Dij(0);
        for(int i = 0; i  k; i ++) {
            cin  t;
            int x = t;
            while(x != 0) {
                cout  pre[x]   ;
                x = pre[x];
            }
        }
    }
    else {
        cout  Impossible.n;
        cin  k;
        for(int i = 0; i  k; i ++) {
            cin  t;
            if(isNotDirect[t] == 1) cout  Error.n;
            else printf(You may take test %d directly.n, t);
        }
    }
    return 0;
}