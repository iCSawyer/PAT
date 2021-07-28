#include<cstdio>
#include<cstring>
#include<set>

using namespace std;
const int N = 1e4 + 10;
char str1[N], str2[N];

int main()
{
	fgets(str1,N, stdin);
	str1[strlen(str1)-1] = '\0';
	fgets(str2, N, stdin);
	str2[strlen(str2)-1] = '\0';
	set<char> s;
	for(int i = 0; i < strlen(str2); i ++)
		s.insert(str2[i]);
	for(int i = 0; i < strlen(str1); i ++)
		if(s.count(str1[i]) == 0) printf("%c", str1[i]);
	return 0;
}
