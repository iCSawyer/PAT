# PAT Code Template



### ch05 数学问题

#### 素数和素数表

```C++
bool isPrime(int n) { // 注意i的范围
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; i ++)
        if(n % i == 0) return false;
    return true;
}
```

```C++
bool isprime[50010]; // 初始标记为1, 然后把i的j倍标记为0; i的范围和判断素数一样
fill(isprime, isprime + N, true); 
for(int i = 2; i * i <= 50000; i ++)  // 一个i*i, 一个j*i
    for(int j = 2; j * i < 50000; j ++)
        isprime[j * i] = 0;
```

#### 最大公约数和最小公倍数

```C++
int gcd(int a, int b) { //最大公约数; 最小公倍数为ab/d (a/d*b: 避免溢出)
    return !b : a ? gcd(b, a % b);
}
```

### ch09 树

#### 并查集 (i:1-N)

1. 初始化

   ```C++
   // 根据需要初始化【需要并、查的】元素即可
   for(int i = 1; i <= N; i ++) // 模板的i为1-N
       father[i] = i;
   ```

2. 查找 (路径压缩)

   ```C++
   // 路径压缩的主要不同：1) 保存当前结点 2) 当前节点的父亲更改为x
   int findFather(int x) {
       int a = x;
       while(x != father[x]) 
           x = father[x];
       // 此时x是根结点了
       while(a != father[a]) {
           int z = a;
           a = father[a];
           father[z] = x;
       }
       return x;
   }
   ```

3. 合并

   ```C++
   // 有时需要根据需要决定合并时【根结点是谁】
   int Union(int a, int b) {
       int fa = findFather(a);
       int fb = findFather(b);
       if(fa != fb) {
           father[fa] = fb;
       }
   }
   ```

4. 其他

   ```C++
   // 输出
   for(int i = 1; i <= n; i ++)
       ans[findFather(i)].push_back(i);
   // 用isRoot[]判断是否是根
   for(int i = 1; i <= n; i ++)
       isRoot[findFather(i)] = true;
   ```

#### 堆 (i:1-N)

1. 向下调整

   ```C++
   void downAdjust(int low, int high) { //low = 被调整元素下标, high = 尾元素下标
   	int i = low, j = i * 2;
       while(j <= high) {
           if(j + 1 <= high && heap[j + 1] > heap[j]) { //!!!如果右儿子存在
               j = j + 1;
           }
           if(heap[i] < heap[j]) {
               swap(heap[i], heap[j]);
               i = j;
               j = 2 * i;
           } else {
               break;
           }
       }
   }
   ```

2. 向上调整

   ```C++
   void upAdjust(int low, int high) {
       int i = high, j = i / 2;
       while(j >= low) {
           if(heap[i] > heap[j]) {
               swap(heap[i], heap[j]);
               i = j;
               j = i / 2;
           } else {
               break;
           }
       }
   }
   ```

3. 建堆、删除堆顶、添加元素

   ```C++
   // 建堆：在已经有元素的1~N上建堆
   for(int i = n / 2; i >= 1; i --)
       downAdjust(i, n);
   
   // 删除堆顶元素
   heap[1] = heap[n --];
   downAdjust(1, n);
   
   // 添加元素
   heap[++ n] = x;
   upAdjust(1, n);
   ```

   

### ch10 图

#### 一、最短路径 (Dijkstra)

1. 通用方法

```C++
void Dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    for(int i = 0; i < n; i ++) { // 最终添加所有点到集合中，故循环n次
		int u = -1, MIN = INF;
        for(int j = 0; j < n;j ++) {
            if(!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        else vis[u] = true;
        for(int v = 0; v < n; v ++) {
            if(!vis[v] && G[u][v] != INF && d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
            }
        }
}
```
2. 堆优化
```C++
void Dij_heap(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    priority_queue<int, vector<int>, cmp> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.top(); q.pop();
        if(vis[u]) continue; // 主要不同
        else vis[u] = 1;
        for(int v = 0; v < n; v ++) {
            if(!vis[u] && G[u][v] != INF && d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                q.push(v); //遗忘点
            }
        }
    }
}   
struct cmp {
    bool operator () (int a, int b) {
        return d[a] > d[b]; // 对于优先队列是反着的 
    }
}
```

#### 二、DFS + Dijkstra

``` C++
void Dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    for(int i = 0; i < n; i ++) {
        int u = -1, MIN = INF;
        for(int j = 0;j < n; j ++) {
            if(!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        else vis[u] = true;
        for(int v = 0; v < n; v ++) {
            if(!vis[v] && G[u][v] != INF) {
                if(d[v] > d[u] + G[u][v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear; //【】【】【】【】】【】【】【【】
                    pre[v].push_back(u);
                    num[v] = num[u];
                }
                else if(d[v] == d[u] + G[u][v]) {
                    pre[v].push_back(u);
                    num[v] += num[u]; 
                }
            }
        }
    }
}

void DFS(int st, int v) {
	if(v == nd) {
		path.push_back(v);
		count...
		path.pop_back;
		return;
	}
	path.push_back(v);
	for(int i = 0; i < pre[v].size(); i ++) {
		DFS(st, pre[v][i]); 
	}
	path.pop_back();
}
```



#### 三、拓扑排序 (判断图是否有环)

```c++
int inDegree[N]; // 需要记录入度
bool topSort( ) {
    int num;
    queue<int> q;
    for(int i = 0; i < n; i ++) {
        if(inDegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int t = q.top(); q.pop();
        for(int i = 0; i < Adj[t].size(); i ++) {
            int u = Adj[t][i];
            inDegree[u]--;
            if(inDegree[u] == 0)
                q.push(u );
        }
        num ++;
    }
    if(num == n) return true;
    return false;
}
```

#### 最短路径（B-F）

```C++
// 循环n-1次，每次对每条边u-v进行检查：通过u使d[v]松弛
// 最后做第n次，如果仍然可以松弛说明有负环
// 最短路径个数：需要保存vector<> pre计算条数，小于则直接赋值为num[u]，等于则需要重新算每一个前驱的num[]
bool BF(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    for(int i = 0; i < n - 1; i ++) {
        for(int u = 0; u < n; u ++) {
            for(int j = 0; j < Adj[u].size(); j ++) {
                int v = Adj[u][j].v;
                int dis = Adj[u][j].size.
                if(d[v] > d[u] + dis) {
                    d[v] = d[u] + dis;
                }
            }
        }
    }
    for(int u = 0; u < n; u ++) {
        for(int j = 0; j < Adj[u].size(); j ++) {
            int v = Adj[u][j].v;
            int dis = Adj[u][j].size.
                if(d[v] > d[u] + dis) {
                    return false;
                }
        }
    }
    return true;
}
```







