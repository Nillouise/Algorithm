#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<set<int> > data;



int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    data.resize(n);
    for (int i = 0; i < n; i++) 
    {
        int m;cin>>m;
        for (int j = 0; j < m; j++) 
        {
            int a;
            cin>>a;
            data[i].insert(a);
        }
    }
    // cout<<"first"<<endl;//
    
    int q;
    cin>>q;
    // cout<<q<<endl;//
    for (int i = 0; i < q; i++) 
    {
        int q1,q2;
        cin>>q1>>q2;q1--,q2--;
        int cnt =0;
        auto a=data[q1].begin();
        auto b=data[q2].begin();
        int total = 0;
        while(true)
        {
            if(a==data[q1].end()||b==data[q2].end())
            {
                //cout<<"break"<<endl;
                while(b!=data[q2].end()){b++,total++;}
                while(a!=data[q1].end())a++,total++;
                break;
            }
            if(*a==*b)
            {
                cnt++;
                total++;
                a++;
                b++;
            }else if(*a<*b)
            {
                a++;
                total++;
            }else
            {
                b++;
                total++;
            }
        }
        double ans = (double)cnt/(double)total;
        ans*=100;
        printf("%.1lf%%\n",ans);
    }


    return 0;
}
