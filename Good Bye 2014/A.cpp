// http://codeforces.com/contest/500/problem/A

#include <cstdio>

using namespace std;
int a[30010];

int main()
{
    int n, t;

    while( scanf("%d%d",&n,&t) != EOF )
    {
        for(size_t i = 1;i<n;i++)
            scanf("%d",a+i);

        size_t i = 1;
        while(i<t){
            i += a[i];
        }
        if( i == t )puts("YES");
        else  puts("NO");
    }
    return 0;
}