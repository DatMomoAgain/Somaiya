import java.util.Scanner;
public class Exp02 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println(&quot;Enter 1:e^x  2:(1+x)^n: &quot;);
        int q = sc.nextInt();
        switch(q)
        {
        case 1:
            System.out.println(&quot;Enter x: &quot;);
            double x1 = sc.nextDouble();
            System.out.println(&quot;Enter n (no. of terms): &quot;);
            double n1 = sc.nextDouble();
            System.out.println(&quot;e^&quot;+(int)x1+&quot; upto &quot;+(int)n1+&quot; terms is: &quot;+
exp(x1,n1));
            break;
       
        case 2:
            System.out.println(&quot;Enter x: &quot;);
            double x2 = sc.nextDouble();
            System.out.println(&quot;Enter n: &quot;);
            double n2 = sc.nextDouble();
            System.out.println(&quot;(1 + &quot; + x2 + &quot;)^&quot; + (int)n2 + &quot; = &quot; +
xplus1(x2,n2));
            break;

        default:
            System.out.println(&quot;Incorrect input&quot;);
            break;
        }
    }
    public static double pow(double x, double y)
    {
        double ans = 1;
        for(int i=0; i&lt;y; i++)
        {
            ans *= x;
        }
        return ans;
    }
    public static double fact(double x)
    {
        double ans = 1;
        for(int i=(int)x; i&gt;0; i--)
        {
            ans *= i;
        }
        return ans;
    }
    public static double exp(double x, double n)
    {
        double e =1;
        for(double i=0; i&lt;n; i++)
        {
            e += (pow(x,i+1))/(fact(i+1));
        }
        return e;
    }
    public static double xplus1(double x, double n)
    {
        double ans =1;
        double multi =1;
        for(double i=0; i&lt;n; i++)

        {
            for(double j=0; j&lt;i+1; j++)
            {
                multi *= (n-j);
            }
            ans += (multi*pow(x,i+1))/fact(i+1);
        }
        return ans;
    }
}
