// http://codeforces.com/contest/272/problem/B


#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;
long long int getbit(long long a)
{
    int s = 0;
    while( a ){
        a -= (a&-a);
        s++;
    }
    return s;
}

long long int getnum(long long a)
{
    return a*(a-1)/2;
}

int main()
{
    int n;
    long long int b[33],a;
    while(cin>>n)
    {
        long long sum = 0;
        for(int i = 0;i<33;i++)b[i] = 0;
        while(n--){
            cin>>a;
            b[getbit(a)]++;
        }
        for(int i = 0;i<33;i++){
            sum += getnum(b[i]);

        }cout << sum << endl;
    }

    return 0;
}