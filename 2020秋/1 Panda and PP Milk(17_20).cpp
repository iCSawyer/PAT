// 36min 17/20
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, w[N], m[N] = {0};

void print1() {

    for(int ii = 0; ii < n; ii ++) {
        printf("%d", m[ii]);
        if(ii != n - 1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> w[i];
    }
    m[0] = 200;
    for(int i = 1; i < n; i ++) {
        if(w[i] < w[i - 1]) {
            m[i] = 200;
            if(m[i - 1] == 200) {
                int k = i; //
                for(k = i; k > 0 && w[k - 1] >= w[k]; k --);
                for(int j = k; j < i; j ++)
                    m[j] += 100;
            }
        }
        else if(w[i] == w[i - 1])
            m[i] = m[i - 1];
        else {
            m[i] = m[i - 1] + 100;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i ++)
        sum += m[i];
    cout << sum;
    return 0;
}
