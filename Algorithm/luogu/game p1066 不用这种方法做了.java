import java.math.BigInteger;
import java.util.*;
import java.lang.String;
import java.io.*;




public class Main
{

    
    public static void main(String args[])throws Exception
    {
        int k,w;
        
        Scanner scan = new Scanner(System.in);  
        k = scan.nextInt();
        w = scan.nextInt();
        
        BigInteger dp[][] = new BigInteger[10][1300];
        
        for(int i=0;i<(1<<k);i++)
        {
            dp[0][i] = BigInteger.valueOf((1<<k)-i);
        }
        // for (int i=1;i<w/k+2;i++ ) {
        //     dp[i][(1<<k)-1] = BigInteger.valueOf(0);
        //     for (int j = (1<<k) - 2;j>=0 ;j-- ) {
        //         dp[i][j] = BigInteger.valueOf(0);
        //         dp[i][j] = dp[i][j].add(dp[i][j+1]);
        //         dp[i][j] = dp[i][j].add(dp[i-1][j+1]);
        // 
        //     }
        // }
        BigInteger ans = new BigInteger("0");
        int b = (w-1)/k+1;
        for (int i=1;i<b;i++ ) {
            dp[1][(1<<k)] = BigInteger.valueOf(0);
            dp[1][(1<<k)-1] = BigInteger.valueOf(0);
            for (int j = (1<<k) - 2;j>=0 ;j-- ) {
                dp[1][j] = BigInteger.valueOf(0);
                dp[1][j] = dp[1][j].add(dp[1][j+1]);
                dp[1][j] = dp[1][j].add(dp[0][j+1]);
            }
            ans = ans.add(dp[1][1]);
            for (int j = (1<<k) - 1;j>=0 ;j-- ) {
                dp[0][j] = dp[1][j];
            }
        }
        
        
        // for(int i=1;i< b;i++)
        // {
        //     ans = ans.add(dp[i][1]);
        // }
        int rest =  w- k*(b-1);
        ans = ans.subtract(dp[1][1<<rest]);
        System.out.println(ans);
        // System.out.println(dp[b][0].subtract(dp[b][m]));
        
        
        // BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        // String str = stdin.readLine();
        // while(str.trim().length()==0)str = stdin.readLine();
        // 
        // BigInteger a = new BigInteger(str.trim());
        // str = stdin.readLine();
        // while(str.trim().length()==0)str = stdin.readLine();
        // 
        // BigInteger b = new BigInteger(str.trim());
        // System.out.println(a.gcd(b));
    }
}



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,w,maxk;
int a[515][515][205],res[205];
void mysum(int* x,int* y,int* z)  //传入数组这个参数 
{
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

