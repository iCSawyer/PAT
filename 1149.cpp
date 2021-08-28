// 14.28-14:42 AC
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int pair_n, case_n, goods[N];
vector< pair<int,int> > a;

int main() {
    int t1, t2;
    scanf("%d%d", &pair_n, &case_n);
    for(int i = 0;i < pair_n; i ++) {
        scanf("%d%d", &t1, &t2);
        a.push_back(pair<int, int>(t1, t2));
    }
    while(case_n --) {
        int n, t, flag = 0;
        scanf("%d", &n);
        fill(goods, goods + N, 0);
        for(int i = 0; i < n; i ++) {
            scanf("%d", &t);
            goods[t] = -1;
        }
        for(int i = 0; i < a.size(); i ++) {
            if(goods[a[i].first] * goods[a[i].second] == 1) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}