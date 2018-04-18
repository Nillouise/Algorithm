#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2*100000;
int mod = 0;

long long fac[maxn],inv[maxn];//�����maxn�Ӿ������ݷ�Χ����
LL n;
long long pow(long long x,int k)//�����ݣ�Ϊ��һ����Ԫ��׼��
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans* x%mod;
        x=x*x%mod;
        k>>=1;
    } 
    return ans;
} 
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%mod;//����ɨһ����i�Ľ׳˵���Ԫ
     inv[n]=pow(fac[n],mod-2);//��n�Ľ׳˶���mod����Ԫ
     for(int i=n-1;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%mod;//������ɾ���ͨ������n�Ľ׳˵���Ԫ��������С��n�Ľ׳˵���Ԫ��Ҳ������ɨһ��  
}
long long get(int n,int m)//Ȼ��ֱ��������Ԥ��������鼴��
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main() {
    // int T;cin>>T;
    LL m,p;
    while (~scanf("%lld %lld %lld", &n, &m, &p)) {  
	cout<<n<<m<<p<<endl;//  
        n+=m;
        mod = p;
        init();
        cout<<get(n,m)<<endl;
    }
}
