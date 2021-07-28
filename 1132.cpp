# include<iostream>
# include<string>
using namespace std;

const long long N = 2e9 + 10;

int main()
{
	int n;
	string s;
	scanf("%d", &n);
	while(n --)
	{
		cin >> s;
		int a, b, c;
		a = stoi(s);
		b = stoi(s.substr(0, s.size()/2));
		c = stoi(s.substr(s.size()/2, s.size()/2));
		if(b*c!=0 && a%(b*c)==0)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	return 0;	
} 
