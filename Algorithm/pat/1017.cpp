#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Token
{
    int beg;
    int dur;
    bool operator <(const Token&t)const
    {
        return beg<t.beg;
    }
};



int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    vector<Token> vec;
    for (int i = 0; i < n; i++) 
    {
        int h,m,se;
        char c;
        cin>>h>>c>>m>>c>>se;
        Token t;
        t.beg = h*3600+m*60+se;
        int dur;
        cin>>dur;
        dur*=60;
        if(dur>3600)dur=3600;
        t.dur = dur;
        vec.push_back(t);
    }
    sort(vec.begin(),vec.end());
    vector<int> cur(m,8*3600);
    LL total = 0;
    int cnt =0;
    
    for (int i = 0; i < vec.size(); i++) 
    {
        if(vec[i].beg>17*3600)break;
        cnt++;
        int ti=0;
        for (int j = 0; j < m; j++) 
        {
            if(cur[j]<cur[ti])ti=j;
        }
        // if(cur[ti]>)
        
        if(cur[ti]>vec[i].beg)
        {
            total += cur[ti]-vec[i].beg;
            cur[ti] += vec[i].dur;
        }else{
            cur[ti]=vec[i].beg+vec[i].dur;
        }
    }
    double ans = 1.0*total/60/cnt;
    printf("%.1lf\n",ans);
    

    return 0;
}
