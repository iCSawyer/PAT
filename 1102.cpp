// 17:09 - 17:30
#include<bits/stdc++.h>
using namespace std;

const int N = 20;
struct node {
    int lchild;
    int rchild;
}Node[N];
int hashtable[N] = {0};
vector<int> ans;

void level(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        if(Node[t].lchild != -1) q.push(Node[t].lchild);
        if(Node[t].rchild != -1) q.push(Node[t].rchild);
    }
}

void in(int root) {
    if(root == -1) return;
    in(Node[root].lchild);
    ans.push_back(root);
    in(Node[root].rchild);
}

int main() {
    int t, root;
    cin >> t;
    for(int i = 0; i < t; i ++) {
        char a, b;
        cin >> a >> b;
        if(a != '-') {
            hashtable[a - '0'] = 1;
        }
        if(b != '-') {
            hashtable[b - '0'] = 1;
        }
        Node[i].rchild = a == '-' ? -1 : a - '0';
        Node[i].lchild = b == '-' ? -1 : b - '0';
    }

    for(int i = 0; i < t; i ++) {
        if(hashtable[i] == 0) {
            root = i;
            break;
        }
    }

    level(root);
    for(int i = 0; i <ans.size(); i ++){
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    ans.clear();
    cout << endl;
    in(root);
    for(int i = 0; i <ans.size(); i ++){
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    return 0;
}
