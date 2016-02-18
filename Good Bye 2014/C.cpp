// http://codeforces.com/contest/500/problem/C

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;
    int t;
    int cost = 0;
    int weights[555];
    int stack[555];
    int len = 0;

    cin >> n >> m;

    for(size_t i = 1;i<=n;i++){
        cin>>weights[i];
    }
    int number;
    for(size_t i = 0;i<m;i++){
        cin>>number;

        int index = -1;
        int sum = 0;
        while(++index < len){
            if(stack[index] == number)
                break;
            sum += weights[ stack[index] ];
        }

        memmove(stack+1, stack, sizeof(int)*index);
        cost += sum;
        stack[0] = number;
        if(index == len){
            len++;
        }
    }

    cout << cost << endl;

    return 0;
}