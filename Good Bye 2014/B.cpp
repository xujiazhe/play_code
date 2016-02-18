// http://codeforces.com/contest/500/problem/B

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int cg[301];
int map_flag = 1;
bool visited[311];
char map[311][311];
int A[301];
int n;

void DFS(int s){
    if(visited[s])
        return ;

    visited[s] = true;
    cg[s] = map_flag;

    for(size_t i = 1;i<=n;i++){
        if(map[s][i] == '1'){
            DFS(i);
        }
    }
}

int  sort_array(){
    for(size_t i = 1;i<n;i++)
    {
        size_t min_index = i;
        for(size_t j = i+1;j<=n;j++){
            if(cg[j] != cg[i])
                continue;

            if(A[j] < A[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            int t = A[i];
            A[i] = A[min_index];
            A[min_index] = t;
        }
    }
}


int  main()
{
    scanf("%d",&n);

    memset(cg,0,sizeof(cg));
    memset(visited, 0, sizeof(visited));
    map_flag = 1;

    for(size_t i = 1;i<=n;i++){
        scanf("%d",A+i);
    }
    for(size_t i = 1;i<=n;i++){
        scanf("%s",map[i]+1);
    }

    for(size_t i = 1;i<=n;i++)
    {
        if(visited[i])
            continue;

        DFS(i);

        map_flag++;
    }

    sort_array();

    for(size_t i = 1;i<=n;i++){
        printf("%d%c",A[i], i==n?'\n':' ');
    }

    return 0;
}