// http://codeforces.com/contest/272/problem/D

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAXN 100001
struct node{
    long long x,y;
};

node a[MAXN*2];
int cmp(const node& a,const node& b)
{
    if( a.x != b.x ) return a.x > b.x;
    else return a.y > b.y;
}
long long getres(long long num,long long samepair,long long M)
{
    long long res = 1;
    for(int i = 1;i<=num;i++){
        int j = i;
        while( samepair && j%2==0){
            j /= 2;
            samepair--;
        }
        res *= j;
        res %= M;
    }
    return res;
}
int main()
{
    int n;
    while( cin >> n )
    {
        long long M;
        for(int i = 0;i<n;i++){
            cin>> a[i].x;
            a[i].y = i;
        }
        for(int i = n;i< 2*n;i++){
            cin>> a[i].x;
            a[i].y = i-n;
        }
        cin >> M;
        sort(a,a+2*n,cmp);
        long long sum = 1;
        long long pre = 1;
        long long samepair = 0;
        for(int i = 1;i<n*2;i++)
            if(a[i].x == a[i-1].x ){
                pre ++;
                if(a[i].y == a[i-1].y )samepair ++;
            }else {
                sum *= getres(pre,samepair,M);
                sum %= M;
                pre = 1;
                samepair = 0;
            }
        sum *= getres(pre,samepair,M);
        cout << sum%M << endl;
    }


    return 0;
}