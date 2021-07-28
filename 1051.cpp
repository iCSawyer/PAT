# include<iostream>
# include<stack>
# include<vector>
using namespace std;

int main()
{
	int m, n, t;
	scanf("%d%d%d", &m, &n, &t);
	while(t--)
	{
		stack<int> s;
		vector<int> v;
		for(int i = 0;i < n; i ++)
		{
			int in;
			scanf("%d", &in);
			v.push_back(in);
		}
		
		int p = 0;
		
		for(int i = 1; i <= n; i ++)
		{
			if(s.size() != m)
				s.push(i);
			while(!s.empty() && s.top() == v[p])
			{
				s.pop();
				p ++;
			}
		}
		
		if(s.empty()) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
