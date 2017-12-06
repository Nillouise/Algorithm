//这题需要写 AVL的插入，注意每次有影响（树高的操作，insert，rotate），都要更新一遍树高才行的！！！！！！！！
//这题用queue进行层次遍历（这才是正法），然后检查是否满二叉树（想想怎么检查）
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Token
{
    int h;
    Token* l = NULL;
    Token* r = NULL;
    int v;
};
int get(Token *t)
{
    if(t==NULL)
    {
        return 0;
    }else{
        return t->h;
    }
}
//旋转时不能选择 中间那个子结点，要选择父结点才行//卧槽，rotate完要更新高度才行
void rotL(Token *&t)
{
    Token *tmp = t->r;
    t->r = t->r->l;
    tmp->l=t;
    t = tmp;
    t->l->h = max(get(t->l->l),get(t->l->r))+1;
    t->h = max(get(t->l),get(t->r))+1;
}
void rotR(Token *&t)
{
    Token *tmp = t->l;
    t->l = t->l->r;
    tmp->r = t;
    t = tmp;
    t->r->h = max(get(t->r->l),get(t->r->r))+1;
    t->h = max(get(t->l),get(t->r))+1;
}
//这个要用引用，因为可能会改变父结点的孩子值的。
Token* add(Token* &t,int val)
{
    // cout<<"t "<<t<<" val"<<val<<endl;//
    if(t==NULL)
    {
        t=new Token();
        t->h= 1;
        t->v=val;
    }else{
        if(val<t->v)//这里比较的是值
        {
            add(t->l,val);
            if(get(t->l)==get(t->r)+2)//这里比较的是高度
            {
                // if(val< t->v)// 注意这里是t->l->v
                if(val< t->l->v)// 注意这里是t->l->v  //这里又比较值，想想为什么
                {
                    rotR(t);
                }else{
                    rotL(t->l);
                    rotR(t);
                }
            }
        }else{
            add(t->r,val);
            if(get(t->r) == get(t->l)+2)
            {
                if(val>t->r->v)
                {
                    rotL(t);
                }else{
                    rotR(t->r);
                    rotL(t);
                }
            }
        }
    }
    t->h = max(get(t->l),get(t->r))+1;
    return t;
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    Token* head=NULL;//这里要初始化才行
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin>>a;
        add(head,a);
    }
    queue<Token*> Q;
    vector<int> ans;
    // ans.push_back(head->v);
    Q.push(head);
    int complete = 1;
    int cutpoint = 0;
    while(!Q.empty())
    {
        Token* t = Q.front();Q.pop();
        ans.push_back(t->v);
        if(t->l==NULL)
        {
            cutpoint=1;
        }else{
            Q.push(t->l);
            if(cutpoint)
            {
                complete = 0;
            }
        }
        if(t->r ==NULL)
        {
            cutpoint = 1;
        }else{
            Q.push(t->r);
            if(cutpoint)
            {
                complete=0;
            }
        }
    }
    
    for (int i = 0; i < ans.size(); i++) 
    {
        cout<<ans[i];
        if(i!=ans.size()-1)cout<<" ";
    }
    cout<<endl;
    if(complete)
    {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
