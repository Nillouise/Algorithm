#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    map<string,int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        size_t pos=0;
        while((pos = s.find("u",pos))!=s.npos)
        {
            s = s.replace(pos,1,"oo");
            pos++;
        }
        pos =0;
        while((pos = s.find("kh"))!=s.npos)
        {
            s = s.replace(pos,2,"h");
            pos+=2;
        }
        
        m[s]++;
    }
    

    
    cout<<m.size()<<endl;
    
    
    return 0;
}
