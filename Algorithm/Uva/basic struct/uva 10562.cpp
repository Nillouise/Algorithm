#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn= 1000;
char buf[100][1000];
int n;

int dfs(int r,int c)
{
    cout<<buf[r][c]<<"(";
    if(r+1<n&&buf[r+1][c]=='|')
    {
        int i=c;
        //注意这里i-1的形式
        while(i>0&&buf[r+2][i-1]=='-')i--;
        //这里考虑一下buf[r+3][i]!='\0'比较好？
        //for(int j=i;buf[r+2][j]=='-';j++)
        for(int j=i;buf[r+2][j]=='-'&&buf[r+3][j]!='\0';j++)
        {
            if(!isspace(buf[r+3][j])&&buf[r+3][j]!='#')
   //         if(!isspace(buf[r+3][j]))

            {
 //               cout<<"spa"<<buf[r+3][j]; //
                dfs(r+3,j);
            }
        }

    }
    cout<<")";
    return 0;
}



void solve()
{
    n=0;
    for(;;)
    {
        fgets(buf[n],maxn,stdin);
        if(buf[n][0]=='#')break;else n++;
    }

    //for(int i=0;i<n;i++)  //
    //{
     //   printf("%s",buf[i]);
    //}

cout<<"(";
    if(n)
    {
//        cout<<'(';//假如没输入的话，应该也要输出空树
  //      cout<<strlen(buf[0])<<endl<<buf[0];//
        for(int i=0;i<9;i++)
        {
   //         cout<<'a'<<buf[0][i];//
            if(buf[0][i]!=' ')//这里我曾写成i!=' '，导致恒定判断是跳过
            {
 //               cout<<"init"<<buf[n][i]<<i<<endl; //
                dfs(0,i);
                break;
            }
            //break;//我居然把break写了出来
        }
 //       cout<<')';
    }
    cout<<")"<<endl;
}



int main()
{
    freopen("input.txt","r",stdin); //
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    //或许需要这样去消除行尾的空格。
    fgets(buf[0],maxn,stdin);
    sscanf(buf[0],"%d",&T);
    while(T--)solve();



    return 0;
}
