//这题让局部有序，两个局部确实无序的，就可以了
//这题有一点要注意的是，偶数分为两堆和奇数分为两堆是不同的，要注意这点
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,k;
int dat[100000+10];
void merge(int l,int r)
{
    if(k==0)
        return;
    if(r==l)return;
    k-=2;
    vector<int> tmp;
    int mid = (r+l)>>1;// 这种取中间的实现会导致 mid更远离l，也就是说前半段很更长，而这会在这题中，前半段更长会添加复杂度的。
    //这是巨蠢的交换数字的实现，因为他很难解决奇数个个数的交换
    // for (int i = (r-l+1)/2+1; i < r-l+1; i++) 
    // {
    //     tmp.push_back(dat[l+i]);
    // }
    // for (int i = 0;i<=(r-l+1)/2;i++)
    // {
    //     tmp.push_back(dat[l+i]);// 这里错了，要从上面的循环的位置开始才行
    // }
    //
    // int cut = 0;
    // if((r-l+1)%2) cut=1;
    // for (int i = mid+1-cut; i <=r; i++) //解决方法是只转换前偶数个数 所以减去tmp.size()%2;
    // {
    //     tmp.push_back(dat[i]);
    // }
    // 
    // for (int i = l; i <= mid-cut; i++) 
    // {
    //     tmp.push_back(dat[i]);
    // }
    // for (int i = 0; i < tmp.size(); i++) 
    // {
    //     dat[i+l] = tmp[i];
    // }
    for (int i = l; i <= mid; i++) 
    {
        
    }
    merge(l,mid);//这时错的，当把后面的数调到前面时，数量可能会不一样的。//解决方法是只转换前偶数个数
    merge(mid+1,r);
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n>>k;
    for (int i = 0; i < 100000+10; i++) 
    {
        dat[i] = i+1;
    }
    k--;
    if(k&1)
    {
        return cout<<-1<<endl,0;
    }
    merge(0,n-1);
    if(k==0)
    {
        for (int i = 0; i < n; i++) 
        {
            cout<<dat[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    

    return 0;
}
