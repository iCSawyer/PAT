# include<iostream>
# include<algorithm>
using namespace std;

const int N = 1000010;

struct node{
	int address;
	int data;
	int next;
	bool flag;
}list[N];

bool cmp(node a, node b)
{
	if(!a.flag || !b.flag) return a.flag > b.flag;
	return a.data < b.data;
} 

int main()
{
	int n, head, count = 0;
	scanf("%d%d", &n, &head);
	for(int i = 0; i < n; i ++)
	{
		int ad, da, ne;
		scanf("%d%d%d", &ad, &da, &ne);
		list[ad] = {ad, da, ne, 0};	
		//printf("%05d %d %05d\n", list[ad].address, list[ad].data, list[ad].next);
	}
	
	
	int p = head;
	while(p != -1)
	{
		list[p].flag = 1;
		p = list[p].next;
		count ++;
	}
		
	sort(list, list + N, cmp);

	if(n == 0){
		printf("0 -1\n");
		return 0;
	}
	
	printf("%d %05d\n", count, list[0].address);
	for(int i = 0; i < count; i ++)
	{
		printf("%05d %d ", list[i].address, list[i].data);
		if(i == count - 1) printf("-1\n");
		else printf("%05d\n", list[i + 1].address);
	}
		
	return 0;	
} 
