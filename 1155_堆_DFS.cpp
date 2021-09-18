#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, heap[N], in[N];
int seq = 0;
vector<int> path;


void preOrder(int root) {
    if(root * 2 > n) {
        path.push_back(heap[root]);
        for (int i = 0; i < path.size(); i++)
            printf("%d%s", path[i], i == path.size() - 1 ? "\n" : " ");
        path.pop_back();
        return;
    }
    path.push_back(heap[root]);
    if(root * 2 + 1 <= n) preOrder(root * 2 + 1);
    if(root * 2 <= n) preOrder(root * 2);
    path.pop_back();
}

int main() {
    int maxH = 0, minH = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) scanf("%d", &heap[i]);
    // sort(in, in + n);
    // leverOrder(1);
    preOrder(1);
    for(int i = 1; i <= n / 2; i ++) {
        if(heap[i] > heap[i * 2]) maxH = 1;
        if(heap[i] < heap[i * 2]) minH = 1;
    }
    if(maxH + minH == 0 || maxH + minH == 2) cout << "Not Heap";
    else if(maxH == 1) cout << "Max Heap";
    else cout << "Min Heap";
    return 0;
}
