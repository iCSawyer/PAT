// 1:38-2:14 19-25
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

struct node {
    int address;
    int data;
    int next;
    int flag; //1
}Node[N];
int hashT[N]; //1表示出现过了


int main() {
    int head, n;
    cin >> head >> n;
    for(int i = 0; i < n; i ++) {
        int ta, td, tn;
        cin >> ta >> td >> tn;
        Node[ta].address = ta;
        Node[ta].data = td;
        Node[ta].next = tn;
    }

    int index = head;
    vector<node> ans, ans1;
    while(index != -1) {
        if(hashT[abs(Node[index].data)] == 0) {
            hashT[abs(Node[index].data)] = 1;
            ans.push_back(Node[index]);
        }
        else
            ans1.push_back(Node[index]);
        index = Node[index].next;
    }

    for(int i = 0; i < ans.size(); i ++)
    {
        printf("%05d %d ", ans[i].address, ans[i].data);
        if(i == ans.size() - 1) cout << "-1\n";
        else printf("%05d\n", ans[i + 1].address);
    }
    for(int i = 0; i < ans1.size(); i ++)
    {
        printf("%05d %d ", ans1[i].address, ans1[i].data);
        if(i == ans1.size() - 1) cout << "-1\n";
        else printf("%05d\n", ans1[i + 1].address);
    }
    return 0;
}
