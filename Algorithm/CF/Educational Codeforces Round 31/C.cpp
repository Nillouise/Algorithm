//这里所有点都在某个圈，那个题目的定义要一眼看出这点才行
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int G[100000+10];
int vis[100000+10];
int quan[100000+10];

int main()
{
//    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>G[i+1];
    }

    int ans = 0;
    vector<int> vec;
    for(int i=1;i<=n;i++)
    {
        //这里所有点都在某个圈，那个题目的定义要一眼看出才行
        if(vis[i]==0)
        {
            int x = G[i];
            int cnt = 1;
            while(x!=i)
            {
                cnt++;
                x=G[x];
            }

            quan[i] = cnt;
            vis[i]=1;
            x = G[i];
            while(x!=i)
            {
                quan[x] = cnt;
                vis[x] = 1;
                x=G[x];
            }
            vec.push_back(cnt);
        }
    }
    sort(vec.begin(),vec.end());
    if(vec.size()==1)
    {
        LL ans =1LL* vec[0]*vec[0];//这里最好防止溢出
        cout<<ans<<endl;
    }else{
         int x1 = vec.back();vec.pop_back();
         int x2 = vec.back();vec.pop_back();
         vec.push_back(x1+x2);
         LL sum=0;
         for(auto a:vec)
         {
             sum+=1LL*a*a;//这里也防止溢出
         }
         cout<<sum<<endl;
    }


    return 0;
}
