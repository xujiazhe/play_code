// http://codeforces.com/contest/272/problem/C

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

#define MAXN 100001
long long int a[MAXN];

int main()
{
    int n;
    int m;
    long long int M;
    int j;
    int h,w;
    while( cin >> n)
    {
        for(int i = 1;i<=n;i++)
            cin>> a[i];
        cin>>m;
        M = a[1],j = 1;
        for(int i = 1;i<=m;i++){
            cin>>w>>h;
            if( w > j ){
                for(int l = j+1;l<=w;l++)
                    M = max(M,a[l]);
                j = w;
            }
            cout << M << endl;
            M += h;
        }
    }
    return 0;
}