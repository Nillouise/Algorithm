//放弃这题吧，用来理解的材料质量太低了

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> A;
vector<int> B;
int n;
vector<int> gen(int x)
{
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        res.push_back(B[i]^x);
        // cout<< (B[i]^x) <<" "; //
    }
    // cout<<endl; //
    return res;
}

vector<int> ans;

int check2(vector<int> &p)
{
    vector<int> nb;
    for (int i = 0; i < n; i++) {
        nb.push_back(p[0]^A[i]);
    }
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if(p[i]>=n||p[i]<0)return 0;
        vis[p[i]]++;
        if(vis[p[i]]>1)return 0;
    }
    for (int i = 0; i < n; i++) {
        if(nb[p[i]]!=i)return 0;
    }
    ans.assign(p.begin(),p.end());
    return 1;
    
}

//这个check有问题的，因为题目的inverse permutation仅仅只是一个限制条件，只要check好这个限制条件就可以了
int check(vector<int> &p)
{

    
    int b0 = p[0]^A[0];
    vector<int> vis(n);
    vector<int> nb;
    for(int i=0;i<n;i++)
    {
        if(p[i]>=n||p[i]<0)return 0;
        vis[p[i]]++;
        if(vis[p[i]]>1)return 0;
        //
        if(p[0]==6)
        {
            cout<<"ch "<<p[i]<<" "<<A[i]<<" "<<b0<<endl;
        }
        // if((p[i]^A[i])!=b0)
        //这里是错的，b0最多只能用来check上面那个permutaion是否合法，不能check下面的permutation是否合法
        if((p[i]^B[i]!=b0))
        {
            //
            // cout<<"check error: ";
            // cout<<p[i]<<" "<<A[i]<<" "<<b0<<endl;
            
            return 0;
        }
        nb.push_back(A[i]^p[0]);
    }
    
    //
    if(p[0]==6)
    {
        cout<<"check"<<endl;
        for (int i = 0; i < 10; i++) {
            cout<<nb[i]<<" ";
        }
        cout<<"nb"<<endl;
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(nb[p[i]]!=i)
        {
            return 0;
        }
    }
    
    ans.clear();
    ans.assign(p.begin(),p.end());
    return 1;
}


int main()
{
     freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    

    cin>>n;
            fflush(stdout);
    for (int i = 0; i < n; i++) {
                fflush(stdout);
        cout<<"? "<<0<<" "<<i<<endl;
                fflush(stdout);
        int a;
        cin>>a;
        A.push_back(a);
    }
    for (int i = 0; i < n; i++) {
                fflush(stdout);
        cout<<"? "<<i<<" "<<0<<endl;
        fflush(stdout);
        int a;
        cin>>a;
        B.push_back(a);
    }
    
    // cout<<"输入"<<endl; //
    // for (int i = 0; i < n; i++) {
        // cout<<A[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; i++) {
    //     cout<<B[i]<<" ";
    // }
    // cout<<endl;
    
    //iter seed
    int cnt=0;
    for (int i = 0; i < n; i++) {
        vector<int> perm = gen(i);
        
        
        if(check2(perm))
        {
            cnt++;
        }
    }
    cout<<"!"<<endl;
    cout<<cnt<<endl;
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
