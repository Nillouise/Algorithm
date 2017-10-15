#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
int cnt=0;
int buf[50][50];


//不用weight，用w比较好
int draw(int &pos,int r,int c,int w)
{
    if(s[pos]=='f')
    {
        pos++;
        for(int i=r;i<r+w;i++)
        {
            for(int j=c;j<c+w;j++)
            {
                if(buf[i][j]==0)
                {
                    buf[i][j]=1;
                    cnt++;
                }
            }
        }
        return 0;
    }else if(s[pos]=='p')
    {
        pos++;
        int half = w/2;
        draw(pos,r,c,half);
        draw(pos,r+half,c,half);
        draw(pos,r,c+half,half);
        draw(pos,r+half,c+half,half);
        return 0;
    }else{
        pos++;
        return 0;
    }
    
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int KASE;
    cin>>KASE;
    for(int kase = 1;kase<=KASE;kase++)
    {
        cnt=0;
        memset(buf, 0, sizeof(buf));
        cin>>s;
        int pos = 0;
        draw(pos,0,0,32);
        cin>>s;
        pos=0;
        draw(pos,0,0,32);
        
        printf("There are %d black pixels.\n", cnt);
    }
    
    
    return 0;
}
