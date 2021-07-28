# include<bits/stdc++.h>
using namespace std;

struct node{
    int x, y, z;
}Node;

int M, N, L, T;
int a[65][1290][130];
bool inq[65][1290][130] = {false};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = {1, -1, 0, 0, 0, 0};

int vol = 0;

int BFS(int x, int y, int z){
    int rtn = 0;
    queue<node> q;
    Node.x = x; Node.y = y; Node.z = z;
    q.push(Node);rtn ++;
    inq[x][y][z] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int newX = top.x + dx[i];
            int newY = top.y + dy[i];
            int newZ = top.z + dz[i];
            if(newX >= 0 && newX < L && newY >=0 && newY < M && newZ >=0 && newZ < N)
                if(inq[newX][newY][newZ] == false && a[newX][newY][newZ] == 1){
                    Node.x = newX; Node.y = newY; Node.z = newZ;
                    q.push(Node);
                    rtn ++;
                    inq[newX][newY][newZ] = true;
                }
        }
    }
    return rtn >= T ? rtn : 0;
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
            for (int k = 0; k < N; k++){
                if(a[i][j][k] == 1 && inq[i][j][k] == false){
                    ans += BFS(i, j, k);
                }
            }

    cout << ans;

    return 0;
}