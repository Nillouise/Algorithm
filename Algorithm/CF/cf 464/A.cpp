#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int> vec={0};
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        int b = vec[i];
        cout<<b<<endl;//
        for(int j=0;j<2;j++)
        {
            cout<<b<<endl;//
            b = vec[b];
        }
        if(b==i)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    
    return 0;
}
