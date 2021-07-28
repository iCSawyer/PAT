#include<bits/stdc++.h>

#define N 50
using namespace std;

struct node {
    int data;
    node *lchild;
    node *rchild;
};

int postorder[N], inorder[N];
int n;

node *createTree(int postl, int postr, int inl, int inr) {
    if (postl > postr)
        return NULL;
    int i;
    for (i = inl; i <= inr; i++) {
        if (inorder[i] == postorder[postr])
            break;
    }

    node *Node = new node;
    Node->data = postorder[postr];

    int num = i - inl;

    Node->lchild = createTree(postl, postl + num - 1, inl, i - 1);
    Node->rchild = createTree(postl + num, postr - 1, i + 1, inr);

    return Node;
}

void layerOrder(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *top = q.front();
        q.pop();
        if (top->lchild != NULL) q.push(top->lchild);
        if (top->rchild != NULL) q.push(top->rchild);
        printf("%d", top->data);
        if(!q.empty()) printf(" ");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    node *root = createTree(0, n - 1, 0, n - 1);
    layerOrder(root);

    return 0;
}