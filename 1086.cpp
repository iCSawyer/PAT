#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* lchild;
    node* rchild;
};
int n;
node* tree;
void postorder(node* root) {
    if(!root) return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data;
    if(root != tree) cout << " ";
}

void layerorder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* top = q.front();
        q.pop();
        cout << top->data;
        if(!top->lchild) q.push(top->lchild);
        if(!top->rchild) q.push(top->rchild);
        if(!q.empty()) cout << " ";
    }
}

int main() {
    scanf("%d", &n);
    stack<node*> f;
    char pp[10];
    int in, direction = 0; //0往左，1往右
    node* father = NULL;
    node* root = new node;
    tree = root;
    for(int i = 1; i <= 2*n; i ++) {
        scanf("%s", pp);
        if(i == 1) {
            scanf("%d", &in);
            root->lchild = root->rchild = NULL;
            root->data = in;
            father = root;
            f.push(father);
            direction = 0;
            continue;
        }

        if(strcmp(pp,"Push") == 0) {
            scanf("%d", &in);
            node* Node = new node;
            Node->data = in;
            Node->lchild = Node->rchild = NULL;
            if(direction == 0) father->lchild = Node;
            else father->rchild = Node;
            father = Node;
            f.push(father);
            direction = 0;
        }
        else {
            direction = 1;
            father = f.top();
            f.pop();
        }
    }
    postorder(root);
}