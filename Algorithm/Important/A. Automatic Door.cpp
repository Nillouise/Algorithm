//这题很考一个长度能覆盖多少数量之间的转换，以及找到长度最近的位置。
//还有就是要注意运算符优先级呀。
//之前抄别人的代码ac了一次，现在自己重写一遍，依然犯了所有之前犯过的错误
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    LL n,m,a,d;
    cin>>n>>m>>a>>d;
    // vector<int> data(m);//卧槽这题还要long long，我还漏看了
    vector<LL> data(m);
    for (int i = 0; i < m; i++) 
    {
        cin>>data[i];
    }
    sort(data.begin(),data.end());
    m = unique(data.begin(),data.end())-data.begin();
    
    LL e=1,c=0;//employee,client
    // int mod = d/a+((d%a)?1:0);//这么写是错的
    // LL mod = (d-1)/a+1; // 这里为什么不行？//这是错的，d是长度覆盖
    LL mod = d/a+1;
    LL cnt =0;
    while(e<=n&&c<m)
    {
        
        // cout<<"e "<<e<<" c "<<c<<" cnt "<<cnt<<endl;//
        if(e*a<data[c])
        {
            LL cpre = data[c]/a;//client前面的employee编号
            cpre = min(n,cpre);
            LL gapnum = cpre-e+1;
            // int curcnt = gapnum/mod + (gapnum%mod)?1:0;//卧槽这表达式优先级错了
            LL curcnt = gapnum/mod + (gapnum%mod?1:0);
            // cout<<"mod "<<mod<<" "<<gapnum<< " "<<"curcnt"<<curcnt<<endl;//
            cnt+=curcnt;
            LL begin = e+ (gapnum-1)/mod *mod;
            e = begin+mod;
            
            // cnt++;
            // e+=mod;
            while(c<m&&begin*a+d>=data[c])c++;
        }else{
            cnt++;
            LL j = c;
            // LL r = (d-(a-(data[c]%a)));//这里好蠢呀，只要找data[c]+d 之前的门就可以了//顺带一提这个实现也是错的
            // LL add = r/a+((r%a)?1:0);//这是错的，长度覆盖端点会产生，端点都在线段上的问题
            // LL add= (r-1)/a+1;
            // e+=add;
            e = (data[c]+d)/a+ 1;
            while(j<m&&data[j]<=data[c]+d)j++;
            // c=j+1;//这里并不需要+1，我对上面的while语句有很大误解
            c=j;
        }
    }
    
        // cout<<"e "<<e<<" c "<<c<<" cnt "<<cnt<<endl;//
        
    if(e<=n)
    {
        LL geshu = n-e+1;//个数
        // LL curcnt = (n-e)/mod +(n-e)%mod ?1:0;//这是错的，用个数才对
        // LL curcnt = geshu/mod+ geshu%mod?1:0;//这里的表达式优先级又搞错
        LL curcnt = geshu/mod+(geshu%mod?1:0);
        // cout<<"curcnt "<<curcnt<<endl;//
        cnt+=curcnt;
    }
    while(c<m)
    {
        cnt++;
        LL j =c;
        while(j<m&&data[j]<=data[c]+d)j++;
        
        // c=j+1;//这里并不需要+1，我对上面的while语句有很大误解
        c=j;
    }
    cout<<cnt<<endl;

    return 0;
}
