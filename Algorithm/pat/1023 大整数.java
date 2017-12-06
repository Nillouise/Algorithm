import java.io.*;
import java.math.*;
import java.util.Arrays;

public class Main
{
    static public void main(String []args)throws IOException
    {
        String s1=null;

        // must "throw IOException", too
        BufferedReader br = new BufferedReader(new InputStreamReader( System.in ) );
        //this works only if line contains just 1 value
        //double x = Double.parseDouble( br.readLine() );
        // BigInteger i = BigInteger.valueOf(br.readLine());
        BigInteger a = new BigInteger(br.readLine());
        s1 = a.toString();
        BigInteger b = a.add(a);
        String s2 = b.toString();
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        int flag=1;
        if(c1.length!=c2.length)
        {
            flag=0;
        }
        for (int i =0; i<c1.length; i++)
        {
            if(c1[i]!=c2[i])
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        System.out.println(b);
        
        
    }
}
