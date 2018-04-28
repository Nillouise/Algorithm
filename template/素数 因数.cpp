bool is_primer(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return n!=1;
}

//约数枚举，其中会包含哪些非素数的因子
vector<int> divisor(int n)
{
    vector<int> res;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i)res.push_back(n/i);
        }
    }
}

//这个是在算哪些质因数的数量的。
map<int,int> prime_factor(int n)
{
    map<int,int> res;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0){
            ++res[i];
            n/=i;
        }
    }
    if(n!=1)res[n]=1;
    return res;
}