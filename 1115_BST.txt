// AC
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
struct node {
    int key, level;
    node* lchild = NULL;
    node* rchild = NULL;
};
int n, maxLevel, num1, num2;

void insert(node* &root, int x, int level) {
    if(root == NULL) {
        root = new node;
        root->key = x;
        root->level = level;
        if(level > maxLevel) maxLevel = level;
        return;
    }
    if(x <= root->key) insert(root->lchild, x, level + 1);
    else insert(root->rchild, x, level + 1);
}

void preOrder(node* root) {
    if(root == NULL) return;
    if(root->level == maxLevel) num1 ++;
    else if(root->level == maxLevel - 1) num2 ++;
    preOrder(root->lchild);
    preOrder(root->rchild);
}

int main() {
    int t; node* root = NULL;
    cin >> n;
    maxLevel = -1; num1 = num2 = 0;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &t);
        insert(root, t, 1);
    }
    preOrder(root);
    printf("%d + %d = %d", num1, num2, num1 + num2);
    return 0;
}
