#include <cstdio>
int f[101][101],a[101][101];
int inf=999999999;
int min(int x,int y)
{
    return x<y?x:y; 
}
int max(int x,int y)
{
    return x>y?x:y;
}
void print(int x,int y)
{
    if(x>0)
    {
        int n=x;
        while(f[n][x]!=y)
        {
            n++;
        }
        print(x-1,y-a[x][n]);
        printf("%d ",n);
    }
}
int main()
{
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            f[j][i]=-inf;
        }
    }
    for(int i=1;i<=m;i++)
    {
        f[0][i]=-inf;
    }
    f[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=min(n,i);j++)
        {
            f[i][j]=max(f[i-1][j],f[i-1][j-1]+a[j][i]);
        }
    }
    printf("%d\n",f[m][n]);
    print(n,f[m][n]);
    return 0;
}
