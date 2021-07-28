# include<iostream>
# include<string>
# include<math.h>
using namespace std;

bool judge(int n)
{
    for(int i = 2; i <= sqrt(n); i ++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    int num, width;
    char s[1010];
    scanf("%d%d%s", &num, &width, s);
    
    int loc = -1;
    for(int i = 0; i <= num - width; i ++)
    {
        int value = 1, sum = 0;
        for(int j = 0; j < width; j ++)
        {
            sum += ( s[i + width - j - 1] - '0' ) * value;
            value *= 10;
        }
        if(judge(sum))
        {
            loc = i;
            break;
        }
    }
    
    if(loc == -1) printf("404\n");
    else for(int i = loc; i < loc + width; i ++) printf("%c", s[i]);
    
    return 0;
}
