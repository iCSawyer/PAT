# include<iostream>
using namespace std;

const int N = 1e5 + 10;

struct node{
	char data;
	int next;
	int flag;
}a[N]; 


int main()
{
	int add1, add2, n;
	scanf("%d%d%d", &add1, &add2, &n);
	for(int i = 0; i < n; i ++)
	{
		int in1; char in2; int in3;
		scanf("%d %c %d", &in1, &in2, &in3);
		a[in1] = {in2, in3, 0};	
	}
	
	for(int i = add1; i != -1; i = a[i].next)
		a[i].flag = 1;
	
	for(int i = add2; i != -1; i = a[i].next)
		if(a[i].flag == 1)
		{
			printf("%05d\n", i);
			return 0;
		}
	printf("-1\n");
	return 0;	
}
