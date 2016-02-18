// http://acm.hdu.edu.cn/showproblem.php?pid=1022

#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    char Op[21];//存储的是in or out
    int p;

    char In[11]={0};//进入火车站的火车序列
    int in;

    char Come[11];//火车来的顺序
    int come,i;

    char Out[11];//对比的结果
    char a[][10]={"out","in"};
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s%s",Come,Out);
        come = in = p = 0;

        for(i=0;i<n;)
        {
            if(In[in] == Out[i]){
                in--;
                Op[p++] = 0;
                i++;
            }
            else
            {
                Op[p++] = 1;
                In[++in] = Come[come++];
                if(come>n)break;
                if(in>9)break;
            }
        }
        if(i==n){
            puts("Yes.");
            for(int j=0;j<p;j++)
                puts(a[Op[j]]);
        }else puts("No.");
        puts("FINISH");
    }
}