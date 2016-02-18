//  http://codeforces.com/contest/205/problem/B

#include <iostream>

using namespace std;

int main()
{
	long long  num;
	int n;
	long long  ans;
	long long a;
	long long left,m;

	while( cin>>n )
	{
		cin>> num;
		ans = 0;
		left = 0;
		while(--n){
			cin>>a;
			if(a >= num){
				num = a;
				left = 0;
			}
			else{
				m = num - a;
				if(m > left)
					a=m,m -= left,left = a;
				else
					left = m, m = 0;
				ans += m;
			}
		}
		cout << ans << endl;
	}
	return 0;
}