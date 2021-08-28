// 13.30-14.27 AC
#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, in[N], a[N];

bool depoly() { // 返回-1表示冲突
    int pos = 0, flag = 0;
    int wrong_wolf = 0, wrong_num = 0;
    for(int i = 1; i <= n; i ++) {
        pos = abs(in[i]);
        if(a[pos] * in[i] < 0) {
            wrong_num ++;
            if(a[i] == -1)
                wrong_wolf ++;
        }
    }
    if(wrong_wolf == 1 && wrong_num == 2) return true;
    return false;
}

// i和j是狼
bool wolf(int i, int j) {
    fill(a, a + N, 1);
    a[i] = -1; a[j] = -1;
    if(depoly() == true)
        return true;
    else
        return false;
}

int main() {
    int t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &in[i]);
    }


    // 假设i和j说谎了
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            if(wolf(i, j)== true) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution\n";
    return 0;
}