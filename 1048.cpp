#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
	int n, sum;
	scanf("%d&d", &n, &sum);
	for(int i = 0; i < n; i ++)
	{
		int in;
		scanf("%d", &in);
		a[in] = 1;
		if(a[sum - in] == 1)
		{
			printf("%d %d\n", in <= sum - in ? in : sum - in, in <= sum - in ? sum - in : sum);		
			return 0; 
		}
	}
	printf("No Solution\n");
	return 0;
} 
