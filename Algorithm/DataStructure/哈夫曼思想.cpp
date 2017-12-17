//https://www.nowcoder.com/acm/contest/18/A

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
 
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    LL S,M;
    cin>>S>>M;
 
    int be=0,en=S;
 
    for(int i=1;i<=1000;i++)
    {
        //int mid = (be+en)>>1;
        int mid =i;
        vector<int> v(mid);
        for(int i=0;i<mid;i++)
        {
            v[i] = S/mid;
        }
        for(int i=0;i< S%mid;i++)
        {
            v[i]++;
        }
        priority_queue<LL,vector<LL>,less<LL> > q;
        LL sum=0;
        for(int i=0;i<mid;i++)
        {
            q.push(v[i]);
        }
        while(q.size()>1)
        {
            LL u1 = q.top();q.pop();
            LL u2 = q.top();q.pop();
 //           cout<<"u1"<<u1<<"u2"<<u2<<"add"<<u1*u2<<endl; //
 
            sum+=u1*u2;
            q.push(u1+u2);
        }
 //       cout<<endl; //
//        if(sum>=M)
//        {
//            en = mid;
//        }else{
//            be = mid +1;
//        }
        if(sum>=M)
        {
            cout<<mid-1<<endl;
            return 0;
        }
    }
 
    cout<<-1<<endl;
 
}
