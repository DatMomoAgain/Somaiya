import java.util.Scanner;
public class Exp02 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1:e^x  2:(1+x)^n: ");
        int q = sc.nextInt();
        switch(q)
        {
        case 1:
            System.out.println("Enter x: ");
            double x1 = sc.nextDouble();
            System.out.println("Enter n (no. of terms): ");
            double n1 = sc.nextDouble();
            System.out.println("e^"+(int)x1+" upto "+(int)n1 + " terms is: " + exp(x1,n1));
            break;
       
        case 2:
            System.out.println("Enter x: ");
            double x2 = sc.nextDouble();
            System.out.println("Enter n: ");
            double n2 = sc.nextDouble();
            System.out.println("(1 + " + x2 + ")^" + (int)n2 + " = " + xplus1(x2,n2));
            break;

        default:
            System.out.println("Incorrect input");
            break;
        }
    }
    
    public static double exp(double x, double n)
    {
        double e =1;
        for(double i=0; i<n; i++)
        {
            e += (myMath.pow(x,i+1))/(myMath.fact(i+1));
        }
        return e;
    }
    public static double xplus1(double x, double n)
    {
        double ans =1;
        double multi =1;
        for(double i=0; i<n; i++)

        {
            for(double j=0; j<i+1; j++)
            {
                multi *= (n-j);
            }
            ans += (multi*myMath.pow(x,i+1))/myMath.fact(i+1);
        }
        return ans;
    }
}

class myMath
{
    public static double pow(double x, double y)
    {
        double ans = 1;
        for(int i=0; i<y; i++)
        {
            ans *= x;
        }
        return ans;
    }
    public static double fact(double x)
    {
        double ans = 1;
        for(int i=(int)x; i>0; i--)
        {
            ans *= i;
        }
        return ans;
    }
}
