# include<iostream>
# include<vector>
# include<cmath>
using namespace std;

int n, k, p;
int maxN; //最大的n[i] 
int maxj = -1;

vector<int> ans, t;

int pow(int x, int y)
{
	int d = x, ans = 1;
	while(y){
		if(y & 1) ans *= d;
		d *= d;
		y >>= 1;
	}
	return ans;
}

void DFS(int num, int sum, int many, int judge){
	//cout << num << " " << sum << " " << many << " " << endl;
	if(many == k && sum == n){
		// for(int i = 0; i < ans.size(); i ++)
		// cout << i << ":" << ans[i] << endl;
		// cout << "A" ;
		if(judge > maxj){
			t = ans;
			maxj = judge;	
		} 
		
		return;
	}
	//cout << "2";
	if(num > maxN || sum > n || many > k) {
		// cout << "B";
		return;
	}
	//cout << "3";
	// 继续选这一个 
	for(int i = num; i >= 1; i --)
	{
		ans.push_back(i);	
		DFS(i, sum + pow(i, p), many + 1, judge + i);
		ans.pop_back();
	}	
}

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	
	
	for(int i = 1; i <= sqrt(n * 1.0) + 10; i ++){
		if((int)pow(i, p) >= n){
			maxN = i;
			break;
		}
	}
	
	DFS(maxN, 0, 0, 0);
	
	if(t.size() == 0)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	
	cout << n << " = ";
	for(int i = 0; i < t.size(); i ++)
	{
		cout << t[i] << "^" << p;
		if(i != t.size() - 1)
			cout << " + ";
	}
	
	
	return 0;	
} 
