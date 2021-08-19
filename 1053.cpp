// 0:56 - 1:32 almost “ª±ÈAC
#include<bits/stdc++.h>
using namespace std;

const int N = 200;
struct node {
    int weight;
    vector<int> child;
}Node[N];
int n1, n2, sum_w;
vector<int> path;

void print() {
    for(int i = 0; i < n1; i ++) {
        cout << "No " << i << " Sun ";
        for(int j = 0; j < Node[i].child.size(); j ++) {
            cout << Node[i].child[j] << " ";
        }
        cout << endl;
    }
}

void dfs(int cur_node, int cur_w) {
    if(cur_w == sum_w && Node[cur_node].child.empty()) {
        for(int i = 0; i < path.size(); i ++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < Node[cur_node].child.size(); i ++) {
        int t = Node[cur_node].child[i];
        path.push_back(Node[t].weight);
        if(cur_w + Node[t].weight <= sum_w) //ºÙ÷¶
            dfs(t, cur_w + Node[t].weight);
        path.pop_back();
    }
}

bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}

int main() {
    cin >> n1 >> n2 >> sum_w;
    for(int i = 0; i < n1; i ++) {
        int t;
        cin >> t;
        Node[i].weight = t;
    }
    for(int i = 0; i < n2; i ++) {
        int no, nchild;
        cin >> no >> nchild;
        for(int j = 0; j < nchild; j ++) {
            int t;
            cin >> t;
            Node[no].child.push_back(t);
        }
        vector<int>::iterator s = Node[no].child.begin();
        vector<int>::iterator e = Node[no].child.end();
        sort(s, e, cmp);
    }
    // print();
    path.push_back(Node[0].weight);
    dfs(0, Node[0].weight);
    return 0;
}
