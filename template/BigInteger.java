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