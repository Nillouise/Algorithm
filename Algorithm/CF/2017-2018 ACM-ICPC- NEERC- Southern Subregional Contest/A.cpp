#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n,m,a,d;
    cin>>n>>m>>a>>d;
    vector<LL> cus(m);
    for (int i = 0; i < m; i++) {
        cin>>cus[i];
    }
    LL emp=a;
    LL i=0;
    LL opt=-1e19;//错了才发现这个初始数据很重要
    LL cnt=0;
    for(;;)
    {
        if((i<m&&emp<=n*a))
        {
            if(emp==cus[i])
            {
                if(opt+d<emp)
                {
                    opt=emp;
                    cnt++;
                }
                emp+=a;
                int j;
                for (j = i; j<m&&cus[j]==cus[i]; j++) {
                }
                i=j;
            }else if(emp<cus[i]&&(emp<=n*a))
            {
                if(emp>opt+d)
                {
                    opt=emp;
                    cnt++;
                }
                emp+=a;
            }else if(i<m&&cus[i]<emp){
                if(cus[i]>opt+d)
                {
                    opt = cus[i];
                    cnt++;
                }
                int j;
                for (j = i; j<m&&cus[j]==cus[i]; j++) {
                }
                i=j;
            }
            
        }else if((i==m&&emp<=a*n))
        {
            if(emp>opt+d)
            {
                opt=emp;
                cnt++;
            }
            emp+=a;
        }else if((emp>n*a&&i<m)){
            if(cus[i]>opt+d)
            {
                opt = cus[i];
                cnt++;
            }
            int j;
            for (j = i; j<m&&cus[j]==cus[i]; j++) {
            }
            i=j;
        }
        
        // while(opt+d>=emp)emp+=a; //这里太慢了
        // if(opt+d>=emp)
        // {
        //     LL n =(opt+d-emp)/a;//这里的n跟上面的变量重复了，编译器也没提示
        //     emp+=a*n;
        // }
        
        LL shi =(opt+d-emp)/a;
        emp+=a*shi;
        // cout<<emp<<" ";//
        
        while(i<m&&opt+d>=cus[i])i++;
        
        if(i>=m&&emp>n*a)
        {
            break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
