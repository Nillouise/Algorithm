import java.math.BigInteger;
import java.util.*;
import java.lang.String;
import java.io.*;

public class Main
{
    //这玩意会爆栈，在长度一万位的数据下。
    static BigInteger gcd(BigInteger a,BigInteger b)
    {
        if(b.equals(BigInteger.valueOf(0)))return a;
        return gcd(b,a.mod(b));
    }
    
    public static void main(String args[])throws Exception
    {
        Scanner scan = new Scanner(System.in);  
        String name = sb.nextLine(); 
        int age = sb.nextInt(); 
         
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String str = stdin.readLine();
        while(str.trim().length()==0)str = stdin.readLine();
        BigInteger a = new BigInteger(str.trim());
        str = stdin.readLine();
        while(str.trim().length()==0)str = stdin.readLine();
        BigInteger b = new BigInteger(str.trim());
        System.out.println(a.gcd(b));
    }
}
//这里可以定义数据类
class Token
{
    public long mul;
    public int ind;
}
public class Main
{
    public static void main(String args[])throws Exception
    {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int a = scan.nextInt(),b=scan.nextInt();
        int dat1[] = new int[n],dat2[] = new int[n];
        for (int i=0;i<n;i++) {
            dat1[i] = scan.nextInt();
            dat2[i] = scan.nextInt();
        }
        Token t[] = new Token[n]; 
        for (int i=0;i<n;i++ ) {
        	t[i] = new Token();//新创建的数组没有元素
            t[i].mul = dat1[i]*dat2[i];
            t[i].ind = i;
        }
        Arrays.sort(t,(t1,t2)-> {
            //comparator返回 -1,0,1;
        	if(t1.mul==t2.mul)return 0;
        	return t1.mul<t2.mul?-1:1;
        });
        BigInteger total = BigInteger.valueOf(a);
        BigInteger ans = BigInteger.valueOf(0);
        for(int i=0;i<n;i++)
        {
            int ind = t[i].ind;
            BigInteger cur = total.divide(BigInteger.valueOf(dat2[ind]));
            if(ans.compareTo(cur)==-1){
                ans = cur;
            }
            total=total.multiply(BigInteger.valueOf(dat1[ind]));
        }
        System.out.println(ans);

    }
}



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,w,maxk;
int a[515][515][205],res[205];
void mysum(int* x,int* y,int* z)  //传入数组这个参数 
{
    Tips:1、手写高精度，可将a[0]记为这个数的位数，并向函数中传入数组！

2、此时要注意倒序输出

3、如果预处理数组从1开始记录，C(m,n)实际上为a[m+1][n+1]!!!
    
    int jw=0,cur=0;
    z[0]=max(x[0],y[0]);  //用A[0]代表位数 
    for(int i=1;i<=z[0];i++)
    {
        int t=x[i]+y[i]+jw;
        cur=t%10;jw=t/10;
        z[i]=cur;
    }
    if(jw) 
    {
        z[0]++;
        z[z[0]]=jw; 
    } 
}
int main()
{
    cin >> k >> w;
    int maxk=pow(2,k);
    for(int i=1;i<=maxk;i++)
        for(int j=1;j<=i;j++)
        {    
            if(j==1 || j==i) a[i][j][0]=1,a[i][j][1]=1;
            else mysum(a[i-1][j],a[i-1][j-1],a[i][j]);
        }
    int p=w/k,q=w-p*k;
    int maxq=pow(2,q);
    //注意这里的i不仅要小于w/k，还要小于maxk
    for(int i=2;i<=p&&i<maxk;i++) mysum(a[maxk][i+1],res,res);    
    //注意这里的i不仅要小于maxq，还要保证需要的数字数不能大于剩下可选的数字数 
    for(int i=1;i<=maxq-1&&p+i<maxk;i++) mysum(a[maxk-i][p+1],res,res);
    for(int i=res[0];i>=1;i--) cout << res[i];  //注意倒序输出 
    return 0;
}