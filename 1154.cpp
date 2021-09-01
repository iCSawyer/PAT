// 14:19-14:34 25/25
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<int> Adj[N];
set<int> colorSet;
int color[N]; //顶点的颜色

int n, m, k; //顶点数，边数，测试样例数

int main() {
    int u, v, t, flag;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        cin >> u >> v;
        Adj[u].push_back(v); //邻接表，不用加反向
    }
    cin >> k;
    while(k --) {
        // 初始化
        flag = 0;
        colorSet.clear();
        // fill(color, color + N, -1);

        for(int i = 0; i < n; i++) {
            cin >> t;
            color[i] = t;
            colorSet.insert(t);
        }

        // 对每个顶点的每条边进行遍历
        for(int i = 0; i < n && flag == 0; i ++) {
            for(int j = 0; j < Adj[i].size(); j ++) {
                if(color[i] == color[ Adj[i][j] ]) {
                    flag = 1; break;
                }
            }
        }

        if(flag == 1) { cout << "No\n"; }
        else { printf("%d-coloring\n", colorSet.size()); }
    }
    return 0;
}