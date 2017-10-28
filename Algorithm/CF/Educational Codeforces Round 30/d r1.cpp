#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> vec;
int remain=0;
int merge(int l,int r)
{
    if(remain==0)
    {
        return 0;
    }
    int mid = (l+r)/2;
//    if(mid==l)//这个判断好像是必要的
//        return 0;
    for(int i=l;i<mid;i++)
    {
        swap(vec[i],vec[mid+(i-l)]);
    }
//    swap(vec[mid-1],vec[mid]);

    remain-=2;
    merge(l,mid);
    merge(mid,r);
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if((k&1)==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(k>=2*n)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        vec.push_back(i);
    }
    remain=k-1;
    merge(0,n);

    for(auto a:vec)
    {
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}
