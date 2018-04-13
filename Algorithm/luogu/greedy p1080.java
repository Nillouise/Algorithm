//这题要先认识到，两个之间的交换是不会影响其他人的，然后推式子（一定要推式子才能出来的

import java.math.BigInteger;
import java.util.*;
import java.lang.String;
import java.io.*;

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
        	t[i] = new Token();
            t[i].mul = dat1[i]*dat2[i];
            t[i].ind = i;
        }
        Arrays.sort(t,(t1,t2)-> {
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


