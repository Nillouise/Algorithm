#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    
    priority_queue<double,vector<double>,greater<double> >pq;
    for (int i = 0; i < n; i++) 
    {
        double a;
        cin>>a;
        pq.push(a);
    }
    while(pq.size()>1)
    {
        double a=pq.top();pq.pop();
        double b=pq.top();pq.pop();
        pq.push(a/2+b/2);
    }
    double ans = pq.top();
    int a = ans;
    cout<<a<<endl;
    

    return 0;
}
