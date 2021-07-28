# include<iostream>
# include<map>
# include<vector>
# include<algorithm> 
using namespace std;

bool cmp(pair<double, double>a, pair<double, double> b)
{
	if(a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main()
{
	double V, D, P; int n;
	scanf("%lf%lf%lf%d", &V, &D, &P, &n);
	
	vector<pair<double, double>> gas;
	for(int i = 0; i < n; i ++)
	{
		double a, b;
		scanf("%lf%lf", &a, &b);
		gas.push_back(pair<double, double>(a, b));
	}
	
	sort(gas.begin(), gas.end(), cmp);
	gas.push_back(pair<double, double>(0.0, D));
	
	if(gas[0].second != 0.0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	else
	{
		double left_dis = 0, money = 0;
		int cur_index = 0; double cur_price = gas[0].first;
		int min_index = 0; double min_price = 1e9;
		double limit_dis = V * P;
		int flag = 0;
		
		while(cur_index != n)
		{
			// cout << cur_index << " " << money << endl;
			
			min_index = 0; min_price = 1e9;
			flag = 0;
			
			for(int i = cur_index + 1; i <= n && gas[cur_index].second + limit_dis >= gas[i].second; i ++)
			{
				// cout << "j";
				if(gas[i].first < gas[cur_index].first)
				{
					// cout << money << endl;
					money += (gas[i].second - gas[cur_index].second - left_dis) / P * gas[cur_index].first;
					left_dis = 0;
					cur_index = i; cur_price = gas[i].first;
					flag = 1;
					break;
				}
				
				if(gas[i].first < min_price)
				{
					min_index = i;
					min_price = gas[i].first;
				}
			}
			
			if(!flag)
			{
				if(min_price == 1e9)
				{
					double dis = gas[cur_index].second + limit_dis;
					printf("The maximum travel distance = %.2f\n", dis);
					return 0;	
				}
				else
				{
					money += (limit_dis - left_dis) / P * gas[cur_index].first;
					left_dis = limit_dis - gas[min_index].second + gas[cur_index].second;
					cur_index = min_index; cur_price = gas[min_index].first;
				}
			}
		}
		printf("%.2f\n", money);
	}
	return 0;
}
