#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

    for(int kase = 1;;kase++)
    {
        int n;
        cin>>n;
        if(n==0)break;
        vector<LL> P(n+1);
        for(int i=1;i<=n;i++)cin>>P[i];
        int m;
        cin>>m;
        vector<int> T[2*m];
        for(int i=0;i<m;i++)
        {
            int v;
            while(cin>>v,v!=0)
            {
                if(v<0)
                {
                    T[i*2].push_back(-v);
                }else{
                    T[i*2+1].push_back(v);
                }
            }
        }
        int MAX;
        cin>>MAX;
        int flag=1;
        int ans =0;
        for(int i=0;i<MAX;i++)
        {
            int flag2 = 0;
            for(int j=0;j<m*2;j+=2)
            {
                vector<LL> clo(P);
                int flag3=1;
                for(auto a:T[j])
                {
                    if(clo[a]>0)clo[a]--;
                    else {flag3=0;break;}
                }
                if(flag3==1)
                {
                    P.clear();
                    P.assign(clo.begin(),clo.end());
                    for(auto a:T[j+1])P[a]++;
                    flag2=1;
                    break;
                }
            }
            if(flag2==0)
            {
                ans=i;
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Case "<<kase<<": dead after "<<ans<<" transitions"<<endl;
            cout<<"Places with tokens:";
            for(int i=1;i<=n;i++)
            {
                if(P[i]>0)
                cout<<" "<<i<<" ("<<P[i]<<")";
            }
            cout<<endl;
        }else{
            cout<<"Case "<<kase<<": still live after "<<MAX<<" transitions"<<endl;
            cout<<"Places with tokens:";
            for(int i=1;i<=n;i++)
            {
                if(P[i]>0)
                cout<<" "<<i<<" ("<<P[i]<<")";
            }
            cout<<endl;
        }
        cout<<endl;
    }


}
