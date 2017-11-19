#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
vector<int> stk;


int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n;
    map<int,int> backet;//这东西一开始还放到里里面导致出bug，没有考虑每个变量合适的位置
    for (int i = 0; i < n; i++) 
    {
        string cmd;
        cin>>cmd;
        if(cmd=="Pop")
        {
            if(stk.size()==0)
            {
                cout<<"Invalid"<<endl;
            }else{
                cout<<stk.back()<<endl;
                map<int,int>::iterator it = backet.find(stk.back());
                it->second--;
                if(it->second==0)
                    backet.erase(it);
                
                stk.pop_back();
            }
        }else if(cmd=="PeekMedian")
        {
            //cout<<"PeekMedian";//
            if(stk.size()==0)
            {
                cout<<"Invalid"<<endl;                
            }else{
                int pos = stk.size();
                pos = (pos%2==0)?pos/2:(pos+1)/2;
                int cnt = 0;
            //    for(auto a:backet)cout<<"fdfd"<<a.first<<" ";//
                
                for(auto &a:backet)
                {
                    cnt+=a.second;
                    if(cnt>=pos)
                    {
                        cout<<a.first<<endl;
                        break;
                    }
                }
            }
        }else if(cmd=="Push")
        {
            int a;
            cin>>a;
            stk.push_back(a);
            backet[a]++;
        }
    }


    return 0;
}
