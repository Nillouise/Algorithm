//很明显，只要控制数的延展方向就可以让数组永远有序，但当一个数相同的时候，是向左延展还是向右延展？
//就是可以把数分为大于c/2 和小于c/2 ,来控制方向，这样某个位置就会变得越来越好（而且绝对不会冲突），某个位置的数只会不断增加或者不断减少（不可能会又增加然后减少，想想为什么）


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int dat[2000];


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n,m,c;
    cin>>n>>m>>c;
    //下面这种初始化是错的
    // for (int i = 0; i <= n/2; i++) 
    // {
    //     dat[i] = 1e9;
    // }
    // for (int i = n/2+1; i < n; i++) 
    // {
    //     dat[i] = -100;
    // }
    memset(dat,-1,sizeof(dat));
    
    for (int i = 0; i < m; i++) 
    {
        int a;
        cin>>a;
        // if(a<c/2)//这里好像不能这//好像可以这样，只是我初始化的问题
        if(a<=c/2)
        {
            for (int i = 0; i < n; i++) 
            {
                // cout<<"i "<<i<<" "<<dat[i]<<endl;//
                if(dat[i]>a||dat[i]==-1)
                {
                    dat[i]=a;
                    cout<<i+1<<endl;
                    fflush(stdout);
                    break;
                }
            }
        }else
        {
            for (int i = n-1; i >= 0; i--) 
            {
                if(dat[i]<a||dat[i]==-1)
                {
                    dat[i]=a;
                    cout<<i+1<<endl;
                    fflush(stdout);
                    break;
                }
            }
        }
        int finish=1;
        for (int i = 1; i < n; i++) 
        {
            if(dat[i]<dat[i-1]||dat[i]==-1||dat[i-1]==-1)
            {
                finish=0;
                break;
            }
        }
        if(finish)break;
        
    }
    
    


    return 0;
}
