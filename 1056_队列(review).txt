#include<bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, k;
int weight[N], award[N];
map<int, int> w2i; // 重量映射序号
queue<int> q, temp;

int main() {
    int t;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        w2i[weight[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        q.push(weight[t]);
    }

    while (!q.empty()) {
        int size = q.size();
        // 如果只剩一个了
        if (size == 1) {
            t = q.front();
            q.pop();
            award[w2i[t]] = 1;
            break;
        }
        // 分为groupNum组，则淘汰者的名次为groupNum + 1;
        int groupNum = size / k;
        if (size % k != 0) groupNum++;
        // 每个组
        for (int i = 0; i < size; i += k) {
            int max = -1;
            for (int j = 0; j < k; j++) {
                if (q.empty())
                    break;
                t = q.front();
                q.pop();
                award[w2i[t]] = groupNum + 1; // 因为新名次可以覆盖旧名次
                if (t > max) // 找到本组的winner
                    max = t;
            }
            temp.push(max);
        }
        // temp是下一轮的人选; q本轮已经全部pop了
        swap(temp, q);
    }

    for (int i = 0; i < n; i++) {
        cout << award[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}