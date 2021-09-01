// 13:31-13:39 AC
#include<bits/stdc++.h>
using namespace std;

bool judge(int n) {
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i ++)
        if(n % i == 0) return false;
    return true;
}

int main() {
    int n, l;
    string s, t;
    cin >> n >> l >> s;
    for(int i = 0; i < n - l + 1; i ++) {
        t = s.substr(i, l);
        if(judge(stoi(t))) {
            cout << t;
            return 0;
        }
    }
    cout << "404";
    return 0;
}