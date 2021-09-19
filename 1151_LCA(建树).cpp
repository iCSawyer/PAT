//not finished
#include<bits/stdc++.h>
using namespace std;

const int N = 20000;
int n, case_n;
int in[N], pre[N];

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* createTree(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
    int key = pre[preL];
    node* root = new node; // ！！！！！
    root->data = key; root->lchild = root->rchild = NULL;

    int num = 0, pos = inL;
    for(int i = inL; i <= inR; i ++) {
        if(in[i] == key) {
            pos = i;
            break;
        }
    }
    num = pos - inL;

    root->lchild = createTree(preL + 1, preL + num, inL, pos - 1);
    root->rchild = createTree(preL + num + 1, preR, pos + 1, inR);

    return root;
}

bool findNode(int u) {
    for(int i = 0; i < n; i ++)
        if(u == pre[i])
            return true;
    return false;
}


node* LCA(node* root, int a, int b) {
//    思路分析：该题大致会出现四种情况：
//    p，q节点均在左子树
//    p，q节点均在右子树
//    p，q不同时在一颗子树，直接返回root
//    p或q节点等于root节点，此时直接返回root节点
    if(root == NULL)
        return NULL;
    if(root->data == a || root->data == b)
        return root;

    node* left = LCA(root->lchild, a, b);
    node* right = LCA(root->rchild, a, b);

    if(left && right)
        return root;
    else
        return left == NULL ? right : left;
}

int main() {
    node* root = NULL;
    scanf("%d%d", &case_n, &n);
    for(int i = 0; i < n; i ++)
        scanf("%d", &in[i]);
    for(int i = 0; i < n; i ++)
        scanf("%d", &pre[i]);
    root = createTree(0, n - 1, 0, n - 1);

    while(case_n --) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(!findNode(a) && !findNode(b))
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!findNode(a) || !findNode(b))
            printf("ERROR: %d is not found.\n", findNode(a) == false ? a : b);
        else {
            node *f = LCA(root, a, b);
            if(f->data == a || f->data == b)
                printf("%d is an ancestor of %d.\n",f->data==a ? a : b, f->data == a ? b : a);
            else
                printf("LCA of %d and %d is %d.\n", a, b, f->data);
        }
    }

    return 0;
}