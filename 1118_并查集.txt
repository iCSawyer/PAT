// 13:15 - 13:29 Accepted
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int father[N];
set<int> birds;

int findFather(int x) {
    int a = x;
    while(x != father[x]) x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa == fb) return;
    father[fa] = fb;
}

int main() {
    int m, t, bird, rootNum = 0; cin >> m;
    for(int i = 0; i < m; i ++) {
        scanf("%d", &t); int firstBird;
        for(int j = 0; j < t; j ++) {
            scanf("%d", &bird);
            if(father[bird] == 0) { // 把自己初始化为一个集合
                father[bird] = bird;
                birds.insert(bird);
            }
            if(j == 0) { //如果是图片中的第一支鸟
                firstBird = bird;
            }
            Union(firstBird, bird);
        }
    }
    for(int i = 1; i <= birds.size(); i ++)
        if(findFather(i) == i)
            rootNum ++;
    cout << rootNum << " " << birds.size() << endl;

    cin >> m;
    for(int i = 0; i < m; i ++) {
        int pa, pb;
        scanf("%d%d", &pa, &pb);
        if(findFather(pa) == findFather(pb))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}