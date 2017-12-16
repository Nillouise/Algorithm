#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
   freopen("input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin>>vec[i];
    }
    set<int> but;
    vector<int> vis(n+1);
    // vector<int> vis(n);// 真是弱智错误，以后多多考虑这种数据的表示

范围
    for (int i = 0; i < n; i++) {
        if(i==0)
        {
            vis[vec[0]]--;
        }else{
            auto it = but.end();

            if(it== but.begin())
            {
                vis[vec[i]]--;
            }else{
                it--;
                // cout<<"it "<< *it<<" ";
                auto it2 = it;
                if(*it> vec[i])
                {
                    // it--;
                    // cout<<"vec[i]"<<vec[i]<<" "<<*it<<" 

"<<*it2<<endl;//
                    if(it2==but.begin()||*(--it)<vec[i])
                    {
                        // vis[vec[*it]]++; // 这里减错数了
                        // vis[vec[*it2]]++;//弱智
                        vis[*it2]++;
                    }
                    
                }else{
                    vis[vec[i]]--;
                }
            }
        }
        but.insert(vec[i]);
    }
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        cout<<vis[i]<<" ";
        if(vis[pos]<vis[i])pos=i;
    }
    cout<<pos<<endl;
    
    
    return 0;
}