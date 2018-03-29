//这是错的
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<int> sign;
    vector<int> num;
    int t = 1;
    for(int i=1;i<n;i++)
    {
        if(vec[i]!=vec[i-1])
        {
            num.push_back(t);
            sign.push_back(vec[i-1]);
            t=1;
        }else{
            t++;
        }
    }
    num.push_back(t);
    sign.push_back(vec.back());
    if(num.size()<=3)
    {
        cout<<n<<endl;
        return 0;
    }
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    
    
    sign.push_back(0);
    sign.push_back(0);
    sign.push_back(0);
    sign.push_back(0);
    sign.push_back(0);
    sign.push_back(0);
    
    for(auto a:num)
    {
        cout<<a<<" ";
    }
    
    int MAX = 0;
    for(int i=0;i<num.size()-3;i++)
    {
        if(sign[i]==1)
        {
            MAX = max(num[i]+num[i+1]+num[i+2]+num[i+3],MAX);
        }
    }
    for(int i=0;i<num.size()-2;i++)
    {
        if(sign[i]==2)
        {
            MAX = max(num[i]+num[i+1]+num[i+2],MAX);
        }
    }
    
    for(int i=0;i<num.size()-3;i++)
    {
        if(sign[i]==1)
        {
            for(int j=i+2;j<num.size()-3;j++)
            {
                if(sign[j]==2)
                {
                    MAX = max(MAX,num[i]+num[j]);
                }else if(sign[j]==1)
                {
                    MAX = max(MAX,num[i]+num[j]+num[j-1]);
                }
            }
        }else if(sign[i]==2)
        {
            for(int j = i+2;j<num.size()-3;j++)
            {
                if(sign[j]==2)
                {
                    MAX = max(MAX,num[i]+(i==0?0:num[i-1])+num[j] );
                }
            }
        }
    }
    
    
    cout<<MAX<<endl;
    
    return 0;
}
