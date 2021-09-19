#include<bits/stdc++.h>
using namespace std;

int n, k, p;
int maxSum = -1;
vector<int> temp, path;

void DFS(int depth, int sum, int square) {
    if(depth == k) {
        if(sum > maxSum && square == n) {
            maxSum = sum;
            path = temp;
        }
        return;
    }

    int limit;
    if(temp.size() == 0)
        limit = sqrt(n);
    else
        limit = temp.back();

    for(int i = limit; i >= 1; i --) {
        temp.push_back(i);
        if(square + pow(i, p) <= n)
            DFS(depth + 1, sum + i, square + pow(i, p));
        temp.pop_back();
    }
}

int main() {
    cin >> n >> k >> p;
    DFS(0, 0, 0);
    if(path.size()==0) {
        cout<<"Impossible";
        return 0;
          }
    printf("%d = ", n);
    for(int i = 0;i < path.size(); i ++) {
        cout << path[i] << "^" <<p;
        if(i != k - 1)
            cout<<" + ";
    }
    return 0;
}