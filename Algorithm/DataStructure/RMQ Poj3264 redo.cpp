#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int but1[50000+10][20];
int but2[50000+10][20];
struct RMQ
{
    void init(vector<int>& vec)
    {
        for (int i = 0; i < vec.size(); i++) 
        {
            but1[i][0] = vec[i];
            but2[i][0] = vec[i];
        }
        
        for (int k = 1; k < 20; k++) 
        {
            for (int i = 0; i+(1<<k) <= vec.size(); i++) 
            {
                int j = i+(1<<(k-1));
                but1[i][k] = min(but1[i][k-1],but1[j][k-1]);
                but2[i][k] = max(but2[i][k-1],but2[j][k-1]);
            }
        }
        
    }
    int query(int l,int r)
    {
        int k = 0;
        while((1<<k)<=r-l+1)k++;
        k--;
        return max(but2[l][k],but2[r+1-(1<<k)][k])-min(but1[l][k],but1[r+1-(1<<k)][k]);
        
    }
};



int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n,q;
    cin>>n>>q;
    vector<int> dat(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>dat[i];
    }
    RMQ rmq;
    rmq.init(dat);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<rmq.query(l,r)<<endl;
        
    }


    return 0;
}
