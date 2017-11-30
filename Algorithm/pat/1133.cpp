//卧槽这题这种定长（指定5位长）输出的要用printf才行
//这测试可能数据是有问题的，就是没有对应的数（就是需要你鲁棒才行）
//这里输出答案时我默认是n个长度，但其实不是，应该是因为他输出的可能不是一条合法的链条（有游离的元素）
//所以这里要按ans的长度为准
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int but[100000];
int val[100000];


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    // cout<<"begin"<<endl;//
    int head,n,k;
    cin>>head>>n>>k;

    for (int i = 0; i < n; i++) 
    {
        int pre,v,nxt;
        cin>>pre>>v>>nxt;
        but[pre]=nxt;
        val[pre]=v;
    }
    // cout<<"mid"<<endl;//
    
    int u=head;
    vector<int> neg;
    while(u!=-1)
    {
        if(val[u]<0)
        {
            neg.push_back(u);
        }
        u=but[u];
    }
        // cout<<"mid2"<<endl;//
    vector<int> mk;
    u=head;
    while(u!=-1)
    {
        if(val[u]>=0&&val[u]<=k)
        {
            mk.push_back(u);
        }
        u=but[u];
    }
    vector<int> vr;
    u=head;
    while(u!=-1)
    {
        if(val[u]>k)
        {
            vr.push_back(u);
        }
        u=but[u];
    }
    vector<int> ans;
    //这里的assign会覆盖之前写的内容的，用insert才行
    // ans.assign(neg.begin(),neg.end());
    // ans.assign(mk.begin(),neg.end());
    // ans.assign(vr.begin(),vr.end());
    ans.insert(ans.end(),neg.begin(),neg.end());
    ans.insert(ans.end(),mk.begin(),mk.end());
    ans.insert(ans.end(),vr.begin(),vr.end());
    //注意这里的ans.size()不能用n代替，因为可能有有利的元素
    for (int i = 0; i < ans.size(); i++) 
    {
        // cout<<ans[i]<<" "<<val[ans[i]]<<" ";
        printf("%05d %d ",ans[i],val[ans[i]]);
        if(i!=ans.size()-1)
        {
            // cout<<ans[i+1]<<endl;
            printf("%05d\n",ans[i+1]);
        }else{
            // cout<<-1<<endl;
            printf("-1\n");
        }
    }
    
    return 0;
}
