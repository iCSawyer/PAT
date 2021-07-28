# include<iostream>
# include<algorithm>
using namespace std;
const int N = 100010;
struct node
{
	int pos; //pos从0到n-1 
	int address;
	int data;
	int next;	
}list[N];

bool cmp1(node a, node b)
{
	if(a.pos == 0 || b.pos == 0) return a.pos > b.pos;
	return a.pos < b.pos;
}

int main()
{
	int head, n, k;
	scanf("%d%d%d", &head, &n, &k);
	int temp;
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", &temp); list[temp].address = temp;
		scanf("%d%d", &list[temp].data, &list[temp].next);
	}
		
	int p = head, cnt = 0; //pos从1到n 
	while(p != -1)
	{ 
		cnt ++;
		list[p].pos = cnt;
		p = list[p].next;

	}
	
	sort(list, list + N, cmp1); // 现在结点都存储在0~cnt-1中 
	int retime = cnt / k; //反转的次数
	for(int i = 0; i < retime; i ++ )
		reverse(list + k*i, list + k*i+k); 
	
	
	if(cnt == 0)
	{
		printf("0 -1\n");
		return 0; 
	}
	for(int i = 0;i < cnt; i ++)
	{
		printf("%05d %d", list[i].address, list[i].data);
		if(i == cnt - 1) printf(" -1\n");
		else printf(" %05d\n", list[i + 1].address);
	}
		
	return 0;
} 
