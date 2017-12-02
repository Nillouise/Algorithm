//这题运用了 根据种类分离物品的思想，以及处理剩余物品的思路
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,s;

struct Node
{
    LL s,a,b;
    bool operator<(const Node& t)const 
    {
        return abs(a-b)<abs(t.a-t.b);
    }
};


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n>>s;
    vector<Node> v1;
    vector<Node> v2;
    LL total = 0;
    for (LL i = 0; i < n; i++) 
    {
        Node node;
        cin>>node.s>>node.a>>node.b;
        if(node.a>node.b)
        {
            v1.push_back(node);
        }else{
            v2.push_back(node);
        }
        total += node.s*max(node.a,node.b);
    }
    // cout<<total<<"total"<<endl;
    // sort(v1.begin(),v1.begin());//卧槽这里还能把end打成 begin
    sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.begin());//
    sort(v2.begin(),v2.end());
    LL num1=0,num2 = 0;
    for(auto a:v1)
    {
        num1+=a.s;
    }
    for(auto a:v2)
    {
        num2+=a.s;
    }
    LL re1 = num1%s,re2 = num2%s;
    // cout<<"re1 "<<re1<<" re2 "<<re2<<endl;//
    if(re1+re2>s)//代表必须要吃两块
    {
        cout<<total<<endl;
    }else{
        LL cuta=0,cutb=0;
        // LL cnta = 0,cntb=0;
        for(auto a:v1)//把该吃a pizza的改吃b pizza
        {
            if(re1==0)break;
            LL cut = min(re1,a.s);
            cuta += cut*(a.a-a.b);
            re1-=cut;
        }
        
        for(auto b:v2)//把该吃b pizza的改吃a pizza
        {
            if(re2==0)break;
            LL cut = min(re2,b.s);
            cutb +=cut*(b.b-b.a);
            re2-=cut;
        }
        
        LL finalchoice = min(cuta,cutb);
        cout<<total-finalchoice<<endl;
    }
    

    return 0;
}
