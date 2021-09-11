// 很快AC
// 水题
#include<bits/stdc++.h>
using namespace std;

set<int> a;

int main() {
    int n, t, num = 1; 
    cin >> n;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &t);
        if(t > 0) a.insert(t);
    }
    for(auto i = a.begin(); i != a.end(); i ++) {
        if(*i != num) break;
        num ++;
    }
    cout << num;
    return 0;
}