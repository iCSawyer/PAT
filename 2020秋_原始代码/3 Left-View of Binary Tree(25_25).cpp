// 15min 25/25
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* lchild;
    node* rchild;
    int layer = 0;
};

const int N = 100;
int n, in[N], pre[N];
vector<int> ans;

node* crtTree(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
    node* root = new node;
    int key = pre[preL];
    root->data = key;
    int k, num;
    for(k = inL; k <= inR; k ++)
        if(in[k] == key) break;
    num = k - inL;
    root->lchild = crtTree(preL + 1, preL + num, inL, k - 1);
    root->rchild = crtTree(preL + num + 1, preR, k + 1, inR);
    return root;
}

void layer(node* root) {
    queue<node*> q;
    q.push(root);
    int layer = 0;
    while(!q.empty()) {
        node* t = q.front();
        q.pop();
        if(t->layer != layer) {
            ans.push_back(t->data);
            layer = t->layer;
        }
        if(t->lchild != NULL) q.push(t->lchild);
        if(t->rchild != NULL) q.push(t->rchild);
    }
}

void preOrder(node* root, int layer) {
    if(root == NULL) return;
    root->layer = layer;
    preOrder(root->lchild, layer + 1);
    preOrder(root->rchild, layer + 1);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> in[i];
    for(int i = 0; i < n; i ++) cin >> pre[i];
    node* root = NULL;
    root = crtTree(0, n - 1, 0, n - 1);
    preOrder(root, 1);
    layer(root);
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i];
        if(i != ans.size() - 1)
            cout << " ";
    }
    return 0;
}