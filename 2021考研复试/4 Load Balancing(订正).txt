#include<bits/stdc++.h>

using namespace std;

multiset<int, greater<int>> s;
int min_d = 1e9, max_count = 0;

void DFS(int max_l, int min_l, int count) {
    if (min_l * 2 <= max_l) return;
    // 掰断方法可行，更新最优解
    if (count >= max_count) {
        if (count == max_count && max_l - min_l < min_d) {
            min_d = max_l - min_l;
        } else {
            max_count = count;
            min_d = max_l - min_l;
        }
    }
    // 取出最长的木棍
    int out = *s.begin();
    s.erase(s.find(out));
    // 寻找分解方案
    for (int i = out / 3 + 1; i <= out / 2; i++) {
        int a = i, b = out - i;
        // 插入后更新最大值和最小值（因为最长的木棍被拿走了）
        s.insert(a);
        s.insert(b);
        int cur_max = max(*s.begin(), b);
        int cur_min = min(*s.rbegin(), a);
        DFS(cur_max, cur_min, count + 1);
        s.erase(s.find(a));
        s.erase(s.find(b));
    }
    s.insert(out);
}

int main() {
    int n;
    cin >> n;
    s.insert(n);
    DFS(n, n, 1);
    cout << min_d << " " << max_count;
    return 0;
}