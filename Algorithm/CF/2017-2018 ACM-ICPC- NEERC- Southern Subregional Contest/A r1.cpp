//这个模拟题好难写呀，door，过门
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n,m,a,d;
    cin>>n>>m>>a>>d;
    vector<LL> cus(m);
    for (int i = 0; i < m; i++) {
        cin>>cus[i];
    }
    m = unique(cus.begin(),cus.end())-cus.begin();
    LL mod = d/a+1;
    //这里emp代表已过门的员工数目，而不是代表他的位置，会比较好写
    LL i=0,emp=1;
    LL cnt=0;
    while(i<m&&emp<=n)
    {
        if(emp*a<=cus[i])
        {
            //这里也不要用位置，就用人数表示（因为这个图像是离散的，用人数表示更好）
            // LL y = min(cus[i],a*n);
            LL y = min(cus[i]/a,n);
            cnt+=( y - emp)/mod+1;
            LL z = (y-emp)/mod+1;
            emp=emp+z*mod;
            LL pos = (emp-mod)*a;
            
            //这么写pos+d>=cus[i]不好，应该倒转逻辑表达才会清楚
            // while(i<m&&pos+d>=cus[i])i++;
            while(i<m&&cus[i]<=pos+d)i++;
            // cout<<"pos"<<pos<<endl; //
        }else{
            int j=i;
            emp = (cus[i]+d)/a+1;
            while(j<m&&cus[j]-cus[i]<=d)j++;
            i=j;
            cnt++;
        }
    }
    
    
    while(i<m)
    {
        // cout<<i<<endl;//
        int j=i;
        while(j<m&&cus[j]<=cus[i]+d)j++;
        i = j;
        cnt++;
    }
    if(emp<=n)
    {
        cnt+=(n-emp)/mod+1;
    }
    cout<<cnt<<endl;
    

    return 0;
}
