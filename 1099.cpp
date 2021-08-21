// 14:30
// 14.39 30/30

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
struct node {
    int data;
    int lchild = -1;
    int rchild = -1;
}Node[N];
int n, a[N], _index = 0;

void inOrder(int root) {
    if(root == -1) return;
    inOrder(Node[root].lchild);
    Node[root].data = a[_index ++];
    inOrder(Node[root].rchild);
}

void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        cout << Node[t].data;
        if(Node[t].lchild != -1) q.push(Node[t].lchild);
        if(Node[t].rchild != -1) q.push(Node[t].rchild);
        if(!q.empty()) cout << " ";
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n ; i ++) {
        cin >> Node[i].lchild >> Node[i].rchild;
    }
    for(int i = 0; i < n ; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    inOrder(0);
    levelOrder(0);
    return 0;
}