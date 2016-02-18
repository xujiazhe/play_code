//  http://codeforces.com/contest/205/problem/A


#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	int a;
	int min;
	char same;
	int index,ans;
	while(scanf("%d",&n)!=EOF)
	{
		same = 1;
		min = INT_MAX;
		index = 0;
		ans = 0;
		while(n--){
			scanf("%d",&a);
			index++;
			if(a<min){
				same = 0;
				min = a;
				ans = index;
			}else if(a == min){
				same = 1;
			}
		}
		if(same)puts("Still Rozdil");
		else printf("%d\n",ans);
	}
	return 0;
}