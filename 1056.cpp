# include<iostream>
# include<queue>
# include<vector>
using namespace std;

struct mouse{
	int id;
	int w;
	int rk;
}a[10010];

int m(vector<mouse> &v)
{
	int ans = 0,  maxw = v[0].w;
	for(int i = 1; i < v.size(); i ++)
		if(v[i].w > maxw)
		{
			ans = i;
			maxw = v[i].w;
		}
	return ans;
}

int main()
{
	int n, gnum;
	scanf("%d%d", &n, &gnum);
	
	for(int i = 0; i < n; i ++){
		int in;
		scanf("%d", &in);
		a[i].w = in;
		a[i].id = i;
		a[i].rk= -1;
	} 
	
	queue<mouse> q;
	for(int i = 0; i < n; i ++){
		int in;
		scanf("%d", &in);
		q.push(a[in]);
	}
	
	
	while(q.size() > 1)
	{
		queue<mouse> temp;
		
		// 每一个turn 
		int groupnum = (q.size() - 1) / gnum + 1;
		
		//每个turn的每个组 
		for(int i = 1; i <= groupnum; i ++)
		{
			vector<mouse> t;
			for(int j = 0; j < gnum && !q.empty(); j ++)
			{
				t.push_back(q.front());
				q.pop();
			}
			
			
			int maxi = m(t); 
			for(int j = 0; j < t.size(); j ++)
			{
				if(j != maxi)	
					a[t[j].id].rk = groupnum + 1;
				else
					temp.push(a[t[j].id]);
			}
		}
		
		q = temp;
	}
	
	a[q.front().id].rk = 1;
	
	for(int i = 0; i < n; i ++)
	{
		cout << a[i].rk;
		if(i != n - 1) cout << " ";
	}
		
		 
	return 0; 
} 
