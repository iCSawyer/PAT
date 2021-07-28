//题解答案




 
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

long long convert(string a, long long radix)
{
	long long ans = 0, k = 1;
    reverse(a.begin(), a.end());
	for(long long i = 0; i < a.size(); i ++ )
	{
		if(a[i] >= '0' && a[i] <= '9') ans += k * (a[i] - '0');
		else ans += k * (a[i] - 'a' + 10);
		k *= radix;
	}
	return ans;
}

long long min(string &a)
{
	long long ans = -1;
	for(long long i = 0; i < a.size(); i ++ )
	{
		if(a[i] >= '0' && a[i] <= '9')
			if(a[i] - '0' > ans)
				ans = a[i] - '0' + 1;
		else
			if(a[i] - 'a' + 10 > ans)
				ans = a[i] - 'a' + 11;
	}
	return ans;
}

long long find_radix(string n, long long num) {
    // char it = *max_element(n.begin(), n.end());
    // long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1; //进制的下限
    long long low = min(n);
    
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}
