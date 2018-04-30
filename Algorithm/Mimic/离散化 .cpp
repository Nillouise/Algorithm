#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX_N = 100;
int W,H,N;
int X1[MAX_N],X2[MAX_N],Y1[MAX_N],Y2[MAX_N];
bool fld[MAX_N*6][MAX_N*6];


int compress(int *x1,int *x2,int w)
{
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] +d,tx2 = x2[i] +d;
            //注意这里的边界条件
            if(tx1>=1&&tx1<=w)
                vec.push_back(tx1);
            if(tx2>=1&&tx2<=w)
                vec.push_back(tx2);
        }
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    
    for (int i = 0; i < N; i++) {
        x1[i] = find(x1,x1+N,x1[i]) - x1;
        x2[i] = find(x2,x2+N,x2[i]) - x1;
    }
    return xs.size();
}

void solve()
{
    int w = compress(X1,X2,W);
    int h = compress(Y1,Y2,H);
    for (int i = 0; i < N; i++) {
        for (int y = Y1[i]; y <= Y2[i]; y++) {
            for (int x = X1[i]; x < X2[i]; x++) {
                fld[x][y] = true;
            }
        }
    }
    int cnt = 0;
    queue<int>
    
    
    
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}