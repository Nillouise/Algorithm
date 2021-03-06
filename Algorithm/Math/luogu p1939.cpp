#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007;

struct Mat
{
    vector< vector<LL> > dat;
    Mat operator*(const Mat &rhs){
        Mat res;
        res.dat.resize(dat.size());
        for(int i=0;i<res.dat.size();i++){
            res.dat[i].resize(rhs.dat[0].size());
        }
        for(int i=0;i<dat.size();i++){
            for(int j=0;j<rhs.dat[0].size();j++){
                //注意k这个循环，一开始我还漏了（说明我不熟悉矩阵乘法）
                for(int k=0;k<dat[i].size();k++)
                {                
                    res.dat[i][j] = (res.dat[i][j]%mod  + dat[i][k]*rhs.dat[k][j])%mod;
                }
            }
        }
        return res;
    }
    
    //矩阵代表的值
    LL dot(){
        return 0;
    }
};


 Mat pow(Mat a,LL p)
 {
    Mat res;
    //注意这里只把对角线初始化为1
    res.dat.resize(a.dat.size());
    for(int i=0;i<a.dat.size();i++){
        res.dat[i].resize(a.dat.size());
    }
    for(int i=0;i<res.dat.size();i++){
        res.dat[i][i]=1;
    }
    while(p){
        if(p&1){
            res = res*a;
        }
        a=a*a;
        p/=2;
    }
    return res;
 }
 
 

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<vector<LL> > v={
        {1,0,1},
        {1,0,0},
        {0,1,0}    
    };

    int T;cin>>T;
    while(T--){
        LL x;cin>>x;
        if(x<=3){
            cout<<1<<endl;
            continue;
        }
        Mat m;
        m.dat=v;
        Mat res = pow(m,x-3);
        cout<<(res.dat[0][0]+res.dat[0][1]+res.dat[0][2])%mod<<endl;
    }
    
    
    
    return 0;
}