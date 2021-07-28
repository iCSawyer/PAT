# include<iostream>
# include<string.h>
# include<vector>
using namespace std;

const int N = 1e5 + 10;
int hash[N];

int main()
{
    int n, unik = -1;
    scanf("%d", &n);
    memset(hash, 0, sizeof(hash[0]));
    
    vector<int> in;
    // vector<int>::iterator it;
	for(int i = 0; i < n; i ++)
    {
    	int t; scanf("%d", &t);
    	hash[t] ++;
    	in.push_back(t);
    }
    
    for(int i = in.size(); i >= 0; i --)
    {
    	if(hash[in[i]] == 1)
    		unik = in[i];
	}
	
    if(unik == -1)
        printf("None\n");
    else
        printf("%d\n", unik);
    return 0;
}
