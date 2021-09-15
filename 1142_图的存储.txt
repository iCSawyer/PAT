//33

#include<bits/stdc++.h>
using namespace std;

const int N = 500;
int n;
int G[N][N];
vector<int> input;
bool in[N];

int main() {
    int m, a, b, k, t;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    cin >> m;
    while(m --) {
        int flag = 1;
        input.clear();
        fill(in, in + N, 0);

        cin >> k;
        for(int i = 0; i < k; i ++) {
            scanf("%d", &t);
            input.push_back(t);
            in[t] = 1;
        }

        for(int i = 0; i < input.size() - 1; i ++)
            for(int j = i + 1; j < input.size(); j ++) {
                int u = input[i], v = input[j];
                if(G[u][v] == 0) {
                    flag = 0;
                    i = input.size(); // 提前退出来
                    break;
                }
            }

        if(!flag) printf("Not a Clique\n");
        else {
            int tag = -1;
            for(int i = 1; i <= n; i ++) {
                if(in[i] == 1) continue;
                tag = 1;
                for(int j = 0; j < input.size(); j ++) {
                    int u = i, v = input[j];
                    if(G[u][v] == 0) {
                        tag = 0;
                        break;
                    }
                }
                if(tag == 1)
                    break;
            }
            if(tag == 0 || tag == -1) printf("Yes\n");
            else printf("Not Maximal\n");
        }
    }
    return 0;
}