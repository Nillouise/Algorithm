#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Node
{
    Node * nxt1=NULL;
    Node *nxt2 =NULL;
    int val;
    int br;
};
vector<int> data;
int pos = 0;
int init(Node* &pre, int l,int r)
{
    if(pos>=data.size())return 0;
    if(abs(data[pos])>l&&abs(data[pos])<=r)
    {
        Node *c = new Node();
        c->val = abs(data[pos]);
        c->br = data[pos]>0;
        pre = c;
        pos++;
        init(c->nxt1,l,c->val);
        init(c->nxt2,c->val,r);
        return 1;
    }else{
        return 0;
    }
}
int flag=1;
//父亲的颜色，黑色的长度
int dfs(Node *node ,int fac,int len)
{
    if(node==NULL)return len;
    if(fac==0&& node->br == 0)
    {
        flag=0;
        return 0;
    }
    int cr = len + node->br;
    int ll = dfs(node->nxt1,node->br,cr);
    int lr = dfs(node->nxt2,node->br,cr);
    if(ll!=lr)
    {
        flag=0;
        return 0;
    }
    return ll;
}

void prin(Node *node)
{
    if(node==NULL)return;
    cout<<node->val<<" "<<node->br<<endl;
    prin(node->nxt1);
    prin(node->nxt2);
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        flag=1;
        pos=0;
        data.resize(n);
        for (int i = 0; i < n; i++) 
        {
            cin>>data[i];
            if(data[i]==0)
            {
                flag=0;
                break;
            }
        }
        if(data[0]<0)flag=0;
        if(flag==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        Node* head = new Node();
        // head->br = 1;
        init(head,0,1e9);
        
        // prin(head);//
        
        dfs(head,1,1);
        if(flag==0)
        {
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    


    return 0;
}
