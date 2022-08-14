#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define ll long long
ll map[515][515];
ll a[515][515];
int b[515];
int vis[515];
ll ans[515];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%lld",&map[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        int cont=0;
        for(int i=n;i>=1;i--)
        {
            int now=b[i];
            vis[now]=1;
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    map[j][k]=min(map[j][k],map[j][now]+map[now][k]);
                }
            }
            ll sum=0;
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(vis[j]==0||vis[k]==0)continue;
                    sum+=map[j][k];
                }
            }
            ans[cont++]=sum;
        }
        for(int i=cont-1;i>=0;i--)
        {
            printf("%lld ",ans[i]);
        }
        printf("\n");
    }
}
