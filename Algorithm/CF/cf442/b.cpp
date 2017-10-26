#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    vector<int> prea;
    vector<int> preb;
    prea.push_back(0);
    preb.push_back(0);

    for(auto a:s)
    {
        if(a=='a')
        {
            prea.push_back(prea.back()+1);
        }else{
            prea.push_back(prea.back());
        }
    }
    for(auto a:s)
    {
        if(a=='b')
            preb.push_back(preb.back()+1);
        else
            preb.push_back(preb.back());
    }
    int MAX=0;
    for(int i=0;i<=s.size();i++)
    {
        for(int j=i;j<=s.size();j++)
        {
            //重要
            //这里的b段部包括i位置，第一个a段也有可能是0，第三个a段不包括j位置
            int cur = prea[i]+preb[j]-preb[i]+prea.back()-prea[j];
            if(cur>MAX)MAX=cur;
        }
    }
    cout<<MAX<<endl;

    return 0;
}
