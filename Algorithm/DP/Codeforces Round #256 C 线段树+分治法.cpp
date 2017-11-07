//这题我没想到是分治法，好差劲，不需要一次性分段，只要把第一段分出来，之后的段就在之后的分治里分就可以了。
//cf好像开的栈很大，这题5000层递归调用都没有爆栈（爆栈其实就是爆内存），这题好像连尾递归都不需要（因为min好像会导致尾递归不了。。）

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
const int INF = 1e9+100;
vector<int> vec;

int tree[5000*10];//一开始这个线段树数组开小了，导致re，应该是因为线段树的最大值不只是数量的两倍，而是数量的最近2次方的两倍
//在这里就是5000的最近2次方，8000左右，两倍就是16000左右

int build(int o,int l,int r)
{
//    cout<<"l"<<l<<"r"<<r<<endl; //
    if(l==r)
    {
        tree[o]= l;
        return tree[o];
    }else{
        int mid = (l+r)>>1;
        int x1 = build(o*2,l,mid);
        int x2 = build(o*2+1,mid+1,r);
        if(vec[x2]<vec[x1])//感觉一定要x2<x1,因为是要先找左边数第一个最小数
        {
            tree[o]=x2;
        }else{
            tree[o]=x1;
        }
        return tree[o];
    }
}
int gl,gr;
int get(int o,int l,int r)
{
    //if(l<=gl&&gr<=r)
    if(gl<=l&&r<=gr)//这里错了一次
    {
        return tree[o];
    }else{
        int mid = (l+r)>>1;
        //int r=-1;//弱智了，跟参数名同名了
        int res=-1; //以后返回变量统计叫res
        if(gl<=mid)
        {
            int x1 = get(o*2,l,mid);
            if(res==-1||vec[x1]<=vec[res])
            {
                res=x1;
            }
        }
        if(gr>mid)
        {
            int x1 = get(o*2+1,mid+1,r);
            if(res==-1||vec[x1]<vec[res])//注意这里是<,因为右半段优先级比较低。
            {
                res=x1;
            }
        }
        return res;
    }

}




//这是之前写的没用线段树的版本
int dfs(int b,int e,int h)
{
    int MIN =INF;
    int vercnt = 0;
    for(int i=b;i<=e;i++)
    {
        if(vec[i]>h)vercnt++;
        if(vec[i]<MIN)MIN = vec[i];
    }
    LL total = 0;
    for(int i = b;i<=e;)
    {
        int j = i;
        while(vec[j]>MIN)j++;
        total+=dfs(i,j-1,MIN);

    }
}
//这里应该是用了尾递归优化
int cal(int l,int r,int h)
{
    //入口忘记检查了。。。
//    cout<<"l"<<l<<" r"<<r<<endl; //
    if(l>r)return 0;
    gl=l,gr=r;
    int x = get(1,0,n-1);
    return min(r-l+1,vec[x]-h+cal(l,x-1,vec[x])+cal(x+1,r,vec[x]));//这里用vec[x]可能会导致无法尾递归，待会检查一下
    //这里本来就无法尾递归优化，因为有min
}

int main()
{
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

    cin>>n;
 //   n=5000;//
    vec.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    //    vec[i]=10000;//
    }
    build(1,0,n-1);
    cout<<cal(0,n-1,0)<<endl;

    return 0;
}
