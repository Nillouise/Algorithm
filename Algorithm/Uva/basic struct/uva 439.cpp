#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int chess[10][10];
const int INF=1e9;
int way[8][2] = {{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{-2,1},{-2,-1},{2,-1}};


int check(int x1,int x2)
{
    if(x1>8||x1<1)return 0;
    if(x2>8||x2<1)return 0;
    return 1;
}


int main()
{
//    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	string s1,s2;
    while(cin>>s1>>s2)
    {
        //fill(chess,&chess[9][9],INF);//二维数组好像不能用fill
        for(int i=0;i<10;i++)for(int j=0;j<10;j++)chess[i][j]=INF;
        int x1 = s1[0]-'a'+1;
        int x2 = s1[1]-'0';
        int y1 = s2[0]-'a'+1;
        int y2 = s2[1]-'0';

        queue<pair<int,int> > Q;
        Q.push({x1,x2});
        chess[x1][x2]=0;
        while(!Q.empty())
        {
            pair<int,int> node = Q.front();Q.pop();
            for(int i=0;i<8;i++)
            {
                int nx1 = node.first+way[i][0];
                int nx2 = node.second+way[i][1];
                if(check(nx1,nx2))
                {
                    if(chess[nx1][nx2]>chess[node.first][node.second]+1)
                    {
                        chess[nx1][nx2]=chess[node.first][node.second]+1;
                        Q.push({nx1,nx2});
                    }
                }
            }
            if(chess[y1][y2]<INF)
            {
                break;
            }
        }
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<chess[y1][y2]<<" knight moves."<<endl;

    }


    return 0;
}
