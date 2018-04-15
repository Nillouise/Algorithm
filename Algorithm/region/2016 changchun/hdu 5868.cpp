#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int N;
    while(cin>>N)
    {
        for (int t = 0; t < N; t++) {
            
            int x;cin>>x;
            vector<int> vec(x);
            for (int i = 0; i < x; i++) {
                cin>>vec[i];
            }
            sort(vec.begin(),vec.end());
            int allfail = 0,allwin = 0,tied = 0,exceed=0;
            int maxsum = x*(x-1);
            int total = 0;
            for(auto a:vec)
            {
                if(a==2*x-2)allwin++;
                if(a>2*x-2)exceed++;
                if(a%2)tied++;
                if(a==0)allfail++;
                total+=a;
            }
            if(allwin>1||allfail>1||tied%2==1||exceed>0||total!=maxsum){//一开始写成total>maxsum，没有考虑小于的情况
                cout<<"F"<<endl;
            }else{
                cout<<"T"<<endl;
            }
        }
        
        
    }
    
    
    
    return 0;
}