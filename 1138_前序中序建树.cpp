#include<bits/stdc++.h>
using namespace std;

const int N = 50010;
struct node {
    int key;
    node* lchild;
    node* rchild;
};
int n, pre[N], in[N];
int ans = -1;

node* createTree(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
    node* root = new node;
    int key = pre[preL], num = 0, k;
    root->key = key;
    for(k = inL; k <= inR; k ++)
        if(in[k] == key) break;
    num = k - inL;
    root->lchild = createTree(preL + 1, preL + num, inL, k - 1);
    root->rchild = createTree(preL + num + 1, preR, k + 1, inR);
    return root;
}

void postOrder(node* root) {
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    if(ans == -1) ans = root->key;
}

int main() {
    node* root = NULL;
    cin >> n;
    for(int i = 0; i < n; i ++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i ++) scanf("%d", &in[i]);
    root = createTree(0, n - 1, 0, n - 1);
    postOrder(root);
    cout << ans << endl;
    return 0;
}