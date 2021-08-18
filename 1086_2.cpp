// 16:06-16:34 28min
#include<bits/stdc++.h>

using namespace std;

vector<int> pre, mid, ans;
stack<int> ss;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* createTree(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;

    node* root= new node;
    root->data = pre[preL];

    int k;
    for(k = inL; k <= inR; k ++) {
        if(mid[k] == pre[preL])
            break;
    }
    int num = k - inL; //左子树有多少个结点

    root->lchild = createTree(preL + 1, preL + num, inL, k - 1);
    root->rchild = createTree(preL + num + 1, preR, k + 1, inR);

    return root;
}

void postorder(node* root) {
    if(root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    ans.push_back(root->data);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t * 2; i++) {
        char s[10]; int num;
        cin >> s;
        if(s[1] == 'u') {
            cin >> num;
            pre.push_back(num);
            ss.push(num);
        }
        else {
            mid.push_back(ss.top());
            ss.pop();
        }
    }

    node* tree = createTree(0, pre.size() - 1, 0, mid.size() - 1);
    postorder(tree);

    for(int i = 0; i < ans.size(); i ++ ) {
        cout << ans[i];
        if(i != ans.size() - 1)
            cout << " ";
    }

    return 0;
}
