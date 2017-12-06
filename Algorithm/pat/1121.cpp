//这题要注意格式，可能是一行，也可能是两行
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int dat[100000+10];
int vis[100000+10];

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    memset(dat,-1,sizeof(dat));
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) 
    {
        int a,b;
        scanf("%d%d",&a,&b);
        dat[a]=b;
        dat[b]=a;
    }
    int m;
    scanf("%d",&m);
    vector<int> vec;
    for (int i = 0; i < m; i++) 
    {
        int a;
        scanf("%d",&a);
        vec.push_back(a);
        vis[a]=1;
    }
    set<int> ans;
    for(auto a:vec)
    {
        if(dat[a]==-1||vis[dat[a]]==0)
        {
            ans.insert(a);
        }
    }
    int i= 0;
    cout<<ans.size()<<endl;
    for(auto a:ans)
    {
        printf("%05d",a);
        if(i!=ans.size()-1)
            printf(" ");
        i++;
    }
    if(ans.size()!=0)//这题要注意格式
    printf("\n");
    

    return 0;
}
