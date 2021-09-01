// 14:35 - 15:13 24/30
#include<bits/stdc++.h>

#define LL int
using namespace std;

const int N = 10010;
LL n, tree[N];
vector<LL> path;

void printPath() {
    for (LL i = 0; i < path.size(); i++) {
        printf("%d", path[i]);
        if (i != path.size() - 1)
            printf(" ");
    }
    printf("\n");
}


void DFS(int s) {
    if (s * 2 > n) {
        printPath();
        return;
    } else if (s * 2 + 1 <= n) {
        path.push_back(tree[s * 2 + 1]);
        DFS(2 * s + 1);
        path.pop_back();
        path.push_back(tree[s * 2]);
        DFS(2 * s);
        path.pop_back();
    } else if (s * 2 <= n) {
        path.push_back(tree[s * 2]);
        DFS(2 * s);
        path.pop_back();
    }
}

int main() {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> tree[i];
    }
    path.push_back(tree[1]);
    DFS(1);
    int minheap = 0, maxheap = 0;
    for (int i = 2; i <= n; i++) { //²»ÅÐ¶ÏµÈÓÚ
        if (tree[i / 2] > tree[i]) maxheap = 1;
        if (tree[i / 2] < tree[i]) minheap = 1;
    }
    if (maxheap && minheap) cout << "Not Heap\n";
    else if (maxheap) cout << "Max Heap\n";
    else cout << "Min Heap\n";
    return 0;
}
