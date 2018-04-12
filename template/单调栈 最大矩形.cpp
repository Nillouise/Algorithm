#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,M;
int G[3000][3000];
int maze[3000][3000];
int top[3000][3000];
int squ,ran;


void monotoneStack()
{
    //这里是在算类似直方图的东东，即使向上最长延展多长。
    for (int j = 0; j < M; j++) {
        if(maze[0][j]==1) top[0][j]=1;
        for (int i = 1; i < N; i++) {
            if(maze[i][j]==1)
                // top[i][j] = max(top[i-1][j]+1,top[i][j]);
                    top[i][j] = top[i-1][j]+1;
            else top[i][j] = 0;
        }
    }

    //单调栈求最大子矩阵
    for (int i = 0; i < N; i++) {
        stack<pair<int,int>> stk;
        for (int j = 0; j < M+1; j++) {//注意这个M+1，因为算的是之前累积的top值
            int newj = j;
            while(!stk.empty()&&stk.top().first>=top[i][j])
            {
                pair<int,int> c= stk.top();//first是高，second是左边的起始坐标。
                // squ = max(squ, min(c.first,newj-c.second));//注意这里是newj而不是j//这是个弱智错误。
                // ran = max(ran, c.first* (newj-c.second));
                //这是在算最大正方形的边长
                squ = max(squ, min(c.first,j-c.second));//注意这里是j而不是newj,因为j是延展的最长的时候
                //这是在算最长矩形的边长。
                ran = max(ran, c.first* (j-c.second));
                newj = c.second;//这是在求当前这么高的直方图，他最左能延展到哪个位置。
                stk.pop();
            }
            stk.push({top[i][j],newj});
        }
    }
}





int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>G[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if((i+j+G[i][j])%2 ==1){//根据奇偶性，可以把黑白相间的棋盘转回纯碎的求最大矩阵。
                maze[i][j] = 1;
            }
        }
    }
    monotoneStack();
    memset(maze,0,sizeof(maze));
    memset(top,0,sizeof(top));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if((i+j+G[i][j])%2 ==0)
            {
                maze[i][j] = 1;
            }
        }
    }
    monotoneStack();
    cout<<squ*squ<<endl;
    cout<<ran<<endl;
    
    
    
    
    return 0;
}