# include<bits/stdc++.h>

using namespace std;

struct node {
    int x, y, z;
} Node;

int M, N, L, T;
int a[65][1290][130];
bool inq[65][1290][130] = {false};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = {1, -1, 0, 0, 0, 0};

int vol = 0;

int DFS(int x, int y, int z) {
    inq[x][y][z] = 1;
    // if(!(x >=0 && x<L && y >=0 && y < M && z >= 0 && z < N)) return;
    int rtn = 1;
    for (int i = 0; i < 6; i++) {
        x += dx[i];
        y += dy[i];
        z += dz[i];
        if (x >= 0 && x < L && y >= 0 && y < M && z >= 0 && z < N) {
            if(a[x][y][z] == 1 && inq[x][y][z] == 0){
                inq[x][y][z] = 1;
                rtn += DFS(x, y, z);
            }
        }
        x -= dx[i];
        y -= dy[i];
        z -= dz[i];
    }
    return rtn;
}

int main() {
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &a[i][j][k]);

    int ans = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++) {
                if (a[i][j][k] == 1 && inq[i][j][k] == false) {
                    int p = DFS(i, j, k);
                    if(p >= T)
                        ans += p;
                }
            }

    cout << ans;
    return 0;
}