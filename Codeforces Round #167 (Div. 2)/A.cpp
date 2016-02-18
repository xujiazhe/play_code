//  http://codeforces.com/contest/272/problem/A

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,a,sa;
    while( cin>> n )
    {
        for(int i = sa = 0;i<n;i++){
            cin>>a;
            sa += a;
        }
        int s = 0;
        for(int i = 1;i<=5 ;i++){
            if( (sa+i)%(n+1) != 1 )s++;
        }
        cout << s << endl;
    }
    return 0;
}