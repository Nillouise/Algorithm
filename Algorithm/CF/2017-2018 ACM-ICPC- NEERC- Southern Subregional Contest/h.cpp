#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> m;
    for(auto a:s)
    {
        m[a]++;
    }
    vector<char> vec;
    for(auto &a:m) //这里一定要改引用&，不然修改不了变量的
    {
        if(a.second&1)
        {
            vec.push_back(a.first);
            a.second--;
        }
    }
    
    
    if(vec.size()==0)
    {
        cout<<1<<endl;
        string rs;
        for(auto a:m)
        {
            for(int i=0;i<a.second/2;i++)
            {
                rs+=a.first;
            }
        }
        cout<<rs;
        reverse(rs.begin(),rs.end());
        cout<<rs<<endl;
    }else{
        int rm = s.size()-vec.size();

            
        while((rm/2)%vec.size()!=0)
        {
            rm-=2;
            for(auto &a:m)//这里要加& ，才能改m里面的变量，不然只是个复制而已
            {
                if(a.second>=2)
                {
                    a.second-=2;
                    
                    vec.push_back(a.first);
                    vec.push_back(a.first);
                    break;
                }
            }

        }
        cout<<vec.size()<<endl;
        int len=rm/vec.size();

        
        for(auto a:vec)
        {
            string cs;
            int ct=0;
            for(auto iter = m.begin();iter!=m.end();)
            {
                auto &b = *iter;
                int MIN = min(b.second,len-ct);
                b.second-=MIN;
                for(int i=0;i<MIN/2;i++)cs+=b.first;
                ct+=MIN;
                
                if(iter->second==0)iter=m.erase(iter);
                else iter++;
                
                if(ct==len)break;
            }
            cout<<cs<<a;
            reverse(cs.begin(),cs.end());
            cout<<cs<<" ";
        }
            cout<<endl;
    }

    
    return 0;
}
