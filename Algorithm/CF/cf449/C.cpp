#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL F[100000+10];
string s1 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s2 = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
string pre ="What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string suf = "\"?";
void getNum()
{
    F[0]=s1.size();
    int len = s2.size();
    for (int i = 1; i < 100000+10; i++) 
    {
        F[i] = 2*F[i-1]+len;
        if(F[i]>1e18*7LL)
        {
             // cout<<"i "<<i<<" "<<F[i]<<endl;
            break;
        }
    }
}

char query(int f,int pos)
{
    // cout<<"f "<<f<<" pos "<<pos<<endl;
    if(f==0)
    {
        if(pos>=s1.size())
            return '.';
        else
            return s1[pos];
    }
        
    if(pos<pre.size())
    {
        return pre[pos];
    }else if(pos<pre.size()+F[f-1])
    {
        return query(f-1,pos-pre.size());
    }else if(pos<pre.size()+F[f-1]+mid.size()){
        {
            // cout<<"mid"<<pos - pre.size()-F[f-1]<<endl;
            return mid[pos - pre.size()-F[f-1]];
        }
    }else if(pos<pre.size()+F[f-1]+mid.size()+F[f-1])
    {
        return query(f-1,pos - pre.size()-F[f-1]-mid.size());
    }else if(pos<pre.size()+F[f-1]+mid.size()+F[f-1]+suf.size())
    {
        return suf[pos-pre.size()-F[f-1]-mid.size()-F[f-1]];
    }else 
    {
        return '.';
    }
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    // cout<<suf.size()<<endl;//
    ios::sync_with_stdio(false);
    // cout<<pre+mid+suf<<endl;//
    int n;
    cin>>n;
    getNum();
    for (int i = 0; i < n; i++) 
    {
        LL f,pos;
        cin>>f>>pos;
        if(f>59)
        {
            pos--;
            if(pos<pre.size()*(f-59))
            {
                cout<<pre[pos%pre.size()]<<endl;
            }else{
                cout<<query(59,pos-pre.size()*(f-59))<<endl;
            }
        }else
        {
            pos--;
            cout<<query(f,pos);
        }
    }


    return 0;
}
