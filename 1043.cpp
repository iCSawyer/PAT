// 16:49
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, a[N], flag = 0; // 0表示标准BST，1表示反转BST
struct node {
    int data;
    node* lchild;
    node* rchild;
};
vector<int> pre, post;
int cnt = 0;

void insertT(node* &root, int x) {
    if(root == NULL) {
        node* Node = new node;
        Node->data = x;
        Node->lchild = Node->rchild = NULL;
        root = Node;
    }
    else if(root->data <= x) {
        insertT(root->rchild, x);
    }
    else {
        insertT(root->lchild, x);
    }
}

void print(int x) {
    cnt++;
    if(cnt == n) cout << x;
    else cout << x << " ";
}

void postOrder(node* root) {
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    print(root->data);
}

void postOrder2(node* root) {
    if(root == NULL) return;
    postOrder2(root->rchild);
    postOrder2(root->lchild);
    print(root->data);
}

void preOrder1(node* root) {
    if(root == NULL) return;
    pre.push_back(root->data);
    preOrder1(root->lchild);
    preOrder1(root->rchild);
}

void preOrder2(node* root) {
    if(root == NULL) return;
    pre.push_back(root->data);
    preOrder2(root->rchild);
    preOrder2(root->lchild);
}

bool check() {
    for(int i = 0; i < n ; i ++) {
        if(pre[i] != a[i]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        insertT(root, a[i]);
    }
    preOrder1(root);
    if(check() == true) {
        cout << "YES" << endl;
        postOrder(root);
    }
    else {
        pre.clear();
        preOrder2(root);
        if(check() == true) {
            cout << "YES" << endl;
            postOrder2(root);
        }
        else
            cout << "NO";
    }
    return 0;
}
