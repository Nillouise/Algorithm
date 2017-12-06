#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


struct Token
{
    int val;
    Token *l=NULL;
    Token *r=NULL;
    int len=0;
};
int get(Token*t)
{
    if(t==NULL)
    {
        return 0;
    }else{
        return t->len;
    }
}

Token* rol(Token *t)
{
    
}
Token *ror(Token *t)
{
    
}

Token* add(Token* t,int a)
{
    if(t==NULL)
    {
        Token *nt = new Token();
        nt->len = 1;
        nt->val = a;
        return nt; 
    }else{
        if(t->val>a)
        {
            Token *nt = add(t->l,a);
            t->l = nt;
            if(get(t->l)>get(t->r)+1)
            {
                if(nt->val>a)
                {
                    t = ror(t->l);
                }else{
                    t = ror(rol(t->l->r));
                }
            }
        }else{
            Token *nt = add(t->r,a);
            t->r = nt;
            if(get(t->r)>get(t->l)+1)
            {
                if(nt->val<a)
                {
                    t = rol(t->r);
                }else{
                    t = rol(ror(t->l->r));
                }
            }
        }
    }
    t->len = max(get(t->l),get(t->r))+1;
    return t;
}





int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    


    return 0;
}
