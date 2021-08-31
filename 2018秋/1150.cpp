// 14.43 - 15:39 25/25
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n; // n个城市
int G[N][N];
vector<int> path;
int vis[N];

int main() {
    int t, case_n;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < t; i ++) {
        int city1, city2, dis;
        scanf("%d%d%d", &city1, &city2, &dis);
        G[city1][city2] = dis;
        G[city2][city1] = dis;
    }
    scanf("%d", &case_n);
    int min = 1e9, minindexx = 0;
    for(int indexx = 1; indexx <= case_n; indexx ++) {
        path.clear();
        fill(vis, vis + N, 0);
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
            int in;
            scanf("%d", &in);
            path.push_back(in);
        }
        // 判断path里面的内容
        int head = path[0], tail = path[path.size() - 1];
        int dis = 0; // 记录距离
        for (int i = 0; i < path.size() - 1; i++) {//每次表示从i到i+1
            int u = path[i], v = path[i + 1];
            if (G[u][v] == 0) { //如果不可达
                dis = -1;
                break;
            }
            dis += G[u][v];
            vis[u] = vis[v] = 1;
        }

        printf("Path %d: ", indexx);
        if (dis != -1) printf("%d ", dis); else printf("NA ");

        int have_visit = 1;
        for(int i = 1; i <= n; i ++) {
            if(vis[i] == 0) {
                have_visit = 0;
                break;
            }
        }
        if(!have_visit || head!=tail) printf("(Not a TS cycle)\n");
        else {
            if(dis < min) { min = dis; minindexx = indexx;}
            if(path.size() == n + 1) {
                printf("(TS simple cycle)\n");
            }
            else
                printf("(TS cycle)\n");
        }
    }
    printf("Shortest Dist(%d) = %d\n", minindexx, min);
    return 0;
}