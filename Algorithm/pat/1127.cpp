//直到现在，写递归，都不考虑边界条件。。。写过中序后序生成树就频频出bug。。

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Token
{
    int val=0;
    Token* l=NULL;
    Token* r=NULL;
};
int rd[100];
int cd[100];

Token * dfs(int r1,int r2,int c1,int c2)
{
//    cout<<"r "<<r1<<" "<<r2<<"c "<<c1<<" "<<c2<<endl;//

    Token *t = new Token();
    t->val = cd[c2];
    // cout<<t->val<<endl;
    if(c1==c2)return t;
    if(c2<c1)return NULL;
    // int pos = lower_bound(rd,rd+r2+1,t->val)-rd;//卧槽lower_bound要在有序的数组里查才行
    int pos = 0;
    for (int i = r1; i <= r2; i++) 
    {
        if(rd[i]==t->val){pos=i;break;}
    }
    // cout<<"pos "<<pos<<" val "<<t->val<<endl;//
    // cout<<rd<<" "<<rd+r2+1<<" "<<t->val<<" "<<pos<<endl;//
    int ln = pos - r1;
    t->l = dfs(r1,pos-1,c1,c1+ln-1);
    t->r = dfs(pos+1,r2,c1+ln,c2-1);
    return t;
}
vector<int> ans;
void cen(int dep,vector<Token*> &vec)
{
    // cout<<dep<<endl;//
    if(dep%2==0)
    {
        for(int i=vec.size()-1;i>=0;i--)
        {
            ans.push_back(vec[i]->val);
        }
    }else{
        for (int i = 0; i < vec.size(); i++) 
        {
            ans.push_back(vec[i]->val);
        }
    }
    vector<Token*> nv;
    for(auto a:vec)
    {
        if(a->l!=NULL)
            nv.push_back(a->l);
        if(a->r!=NULL)
            nv.push_back(a->r);
    }
    if(nv.size()!=0)
    cen(dep+1,nv);
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) 
    {
        cin>>rd[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin>>cd[i];
    }
    Token * head = dfs(0,n-1,0,n-1);
    vector<Token*> nv;
    nv.push_back(head);
    // cout<<"ok"<<endl;//
    
    cen(0,nv);
    for (int i = 0; i < ans.size(); i++) 
    {
        cout<<ans[i];
        if(i!=ans.size()-1)cout<<" ";
    }
    cout<<endl;

    return 0;
}
