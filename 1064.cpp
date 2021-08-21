// too tired not finished 

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N] = {0}, n;
vector<int> input;
int _index = 0;

void inOrder(int i) {
    if(i > n) return;
    inOrder(2 * i);
    a[i] = input[_index ++];
    inOrder(2 * i + 1);
}

int main() {
    scanf("%d", &n);
    input.clear();
    for(int i = 0; i < n; i ++) {
        int t; scanf("%d", &t);
        input.push_back(t);
    }
    sort(input.begin(), input.end());
    inOrder(1);
    for(int i = 1; i <= n ; i ++) {
        cout << a[i];
        if(i != n) cout << " ";
    }

    return 0;
}
