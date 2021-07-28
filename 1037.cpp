# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main()
{
	int n, m; long long ans = 0;
	vector<int> cou, pro; //1为正，2为负
	
	scanf("%d", &n); 
	for(int i = 0; i < n; i ++ ){
		int in;
		scanf("%d", &in);
		cou.push_back(in);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i ++ ){
		int in;
		scanf("%d", &in);
		pro.push_back(in);
	}
	
	sort(cou.begin(), cou.end(), cmp);
	sort(pro.begin(), pro.end(), cmp);
	
	int it = 0, it1 = 0, it2 = pro.size() - 1;
	while(cou[it] > 0 && pro[it1] > 0){
			ans += cou[it] * pro[it1];
			it ++; it1 ++;
	}
	it = cou.size() - 1;
	while(cou[it] < 0 && pro[it2] < 0){
			ans += cou[it] * pro[it2];
			it --; it2 --;
			
			printf("%d\n", it);
	}
	
	printf("%d\n", ans);
	return 0;		
} 
