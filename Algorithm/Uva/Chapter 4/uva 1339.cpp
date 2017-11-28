#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    string s1,s2;
    while(cin>>s1)
    {
        cin>>s2;
        vector<int> vec1(26);
        vector<int> vec2(26);
        for(auto a:s1)
        {
            vec1[a-'A']++;
        }
        for(auto a:s2)
        {
            vec2[a-'A']++;
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        int flag=0;
        for (int i = 0; i < 26; i++) 
        {
            if(vec1[i]!=vec2[i]){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES"<<endl;
        }
        
    }


    return 0;
}
