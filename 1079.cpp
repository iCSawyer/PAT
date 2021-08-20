//15:33 16:03 22/25 16:16 25/25
#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 100010;
double p, r, sum = 0;
struct node {
    int layer = 0; // 表示其层次
    int num = -1; //非叶子节点默认为-1， 否则为实际个数
    vector<int> child;
}Node[N];
double price[N];

void kprice() {
    price[0] = p;
    double d = (1 + r / 100);
    for(int i = 1; i < n ; i ++)
        price[i] = price[i - 1] * d;
}

void preOrder(int no, int layer) {
    Node[no].layer = layer;
    if(Node[no].child.empty()) {
        sum += Node[no].num * price[layer - 1];
        return;
    }
    else{
        for(int i = 0; i < Node[no].child.size(); i ++)
            preOrder(Node[no].child[i], layer + 1);
    }
}

int main() {
    cin >> n >> p >> r;
    for(int i = 0;  i < n ; i ++) {
        int t;
        cin >> t;
        if(t == 0) {
            int m;
            cin >> m;
            Node[i].num = m;
        }
        else {
            for(int j = 0; j < t ; j ++) {
                int c;
                cin >> c;
                Node[i].child.push_back(c);
            }
        }
    }
    kprice();
    preOrder(0, 1);
    printf("%.1f", sum);
    return 0;
}
