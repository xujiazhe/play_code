// http://acm.hdu.edu.cn/showproblem.php?pid=4442


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=100010;
const int MOD=365*24*60*60;
struct Node
{
    int a,b;
}node[MAXN];

bool cmp(Node a,Node b)
{
    return (long long)a.a*b.b<(long long)b.a*a.b;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
          scanf("%d%d",&node[i].a,&node[i].b);
        sort(node,node+n,cmp);
        long long ans=0;
        long long t=0;
        for(int i=0;i<n;i++)
        {
            ans+=(node[i].a+t*node[i].b)%MOD;
            ans%=MOD;
            t+=(node[i].a+t*node[i].b)%MOD;
            t%=MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}