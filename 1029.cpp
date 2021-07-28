# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

int main()
{
    int n1, n2;
    vector<int> s;
    scanf("%d", &n1);
    for(int i = 0; i < n1; i ++ ){
        int in; scanf("%d", &in);
        s.push_back(in);
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i ++ ){
        int in; scanf("%d", &in);
        s.push_back(in);
    } 
    sort(s.begin(), s.end());
    printf("%d\n", s[(n1+n2-1)/2]);
    return 0;
}
