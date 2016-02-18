//  http://codeforces.com/contest/205/problem/C

#include <iostream>
#include <climits>

using namespace std;

typedef unsigned long long ull;

ull all[22] = {0,9,9+9,90+9+9};
ull group[22] = {0,1,1,10,100};

ull trans(const char* s,int len)
{
	ull ans = 0;
	while(--len + 1){
		ans*=10,ans+=s[len];
	}return ans+1;
}

ull get(ull m)
{
	static char a[22];
	int len,i = 0;
	ull n = m,ans = 0;
	do{
		a[i++] = n%10;
	}while(n/=10);
	len = i;
	if(len==1) return m;

	ans = (a[len-1]-1)*group[len] + all[len-1];
	char another = (a[len-1] > a[0]);
	ull temp = trans(a+1,len-2);
	temp -= another;
	return ans + temp;
}

int main()
{
	ull l,r;
	ull ans;
	ull pre = 9;
	for(int i = 3;i<22;i++){
		all[i] = pre*=10;
		all[i] += all[i-1];
		group[i]=group[i-1]*10;
	}

	while( cin >> l >> r )
	{
		ans = get(r) - get(l-1);
		cout << ans << endl;
	}
	return 0;
}