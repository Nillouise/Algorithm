#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Token
{
    int val;
    int len=0;
    Token * l=NULL;
    Token *r = NULL;
    Token *h = NULL;
};
Token * head = NULL;

Token* leftRotate(Token* mid)
{
    Token* p = mid->h;
    p->r = mid->l;
    mid->l = p;
    mid->h = p->h;
    p->h = mid;
    return mid;
}
Token* rightRotate(Token* mid)
{
    Token *p = mid->h;
    p->l = mid->r;
    mid->r = p;
    mid->h = p->h;
    p->h = mid;
    return mid;
}

int get(Token* t)
{
    if(t==NULL)return 0;
    else return t->len;
}

int check(Token* t)
{
    int lc=get(t->l);
    int rc = get(t->r);
    
    if(lc>rc+1)
    {
        int nl = get(t->l->l);
        int nr = get(t->l->r);
        if(nl>nr)
        {
            rightRotate(t->l);
        }else{
            Token *mid = t->l->r;
            leftRotate(mid);
            rightRotate(mid);
        }
    }else{
        int nl = get(t->r->l);
        int nr = get(t->r->r);
        if(nl>nr)
        {
            Token *mid = t->r->l;
            rightRotate(mid);
            leftRotate(mid);
        }else{
            leftRotate(t->r);
        }
    }
    return 0;
}

Token* add(Token* &t , int a)
{
    if(t==NULL)
    {
        t = new Token();
        t->val = a;
        t->len = 1;
        return t;
    }else{
        if(t->val>a)
        {
            add(t->r,a);
        }else{
            add(t->l,a);
        }
        check(t);
        t->len = max(get(t->r),get(t->l));
    }
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
        int v;
        cin>>v;
        // add(a);s
    }
    


    return 0;
}
