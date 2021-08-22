#include<bits/stdc++.h>
using namespace std;


const int MAXV = 1010;
int n, nv, G[MAXV][MAXV];
int w[MAXV], vis[MAXV], thre;

map<string, int>s2i;
map<int, string>i2s;
map<string, int>gang;

int index_ = 0;

int fun(string name) {
    if(s2i.find(name) == s2i.end()) { //如果还没有这个名字
        s2i.insert(pair<string, int>(name, index_));
        i2s.insert(pair<int, string>(index_, name));
        index_ ++;
        return index_ - 1;
    }
    else
        return s2i[name];
}

void DFS(int u, int& head, int& personNum, int& totalValue) {
    personNum ++;
    vis[u] = true;
    if(w[u] > w[head]) head = u;
    for(int v = 0; v < n; v ++) {
        if(G[u][v] > 0) {
            totalValue += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false) {
                DFS(v, head, personNum, totalValue);
        }
        }
    }

}

int main() {
    int v1, v2, t;
    string s1, s2;
    cin >> n >> thre;
    for(int i = 0; i < n; i ++) {
        cin >> s1 >> s2 >> t;
        v1 = fun(s1);
        v2 = fun(s2);
        G[v1][v2] += t;
        G[v2][v1] += t;
        w[v1] += t;
        w[v2] += t;
    }
    n = s2i.size(); //n更新为结点数

    //DFSTravel
    int head, personNum = 0, totalValue = 0;
    for(int i = 0; i < n; i ++) {
        if(vis[i] == false) {
            head = i; personNum = 0; totalValue = 0;
            DFS(i, head, personNum, totalValue);
            if(personNum > 2 && totalValue > thre) {
                gang.insert(pair<string, int>(i2s[head], personNum));
            }
        }
    }

    //print
    cout << gang.size() << endl;
    for(map<string, int>::iterator i = gang.begin(); i != gang.end(); i ++)
        cout << i->first << " " << i->second << endl;

    return 0;
}