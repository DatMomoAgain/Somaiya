import java.util.Scanner;

public class Complex1
{
    public static void main(String args[])
    {
	//TAKING INPUT
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter real part of 1st no.: ");
        int x1 = sc.nextInt();

        System.out.println("Enter imaginary part of 1st no.: ");
        int x2 = sc.nextInt();

	System.out.println("Enter real part of 2nd no.: ");
        int y1 = sc.nextInt();

	System.out.println("Enter imaginary part of 2nd no.: ");
        int y2 = sc.nextInt();

	System.out.println("Enter 1-addition 2-subtraction 3-multiplication 4-division: ");

	int q = sc.nextInt();
	Complex1 obj1 = new Complex1();
	Complex2 obj2 = new Complex2();
	
	//SAME CLASS STATIC
	/*switch(q)
	{
	 case 1:
		add(x1,x2,y1,y2);
		break;
	 case 2:
		subtract(x1,x2,y1,y2);
		break;
	 case 3:
		multi(x1,x2,y1,y2);
		break;
	 case 4:
		div(x1,x2,y1,y2);
		break;
	}
    */

	//SAME CLASS NON-STATIC
	/*switch(q)
	{
	 case 1:
		obj1.add(x1,x2,y1,y2);
		break;
	 case 2:
		obj1.subtract(x1,x2,y1,y2);
		break;
	 case 3:
		obj1.multi(x1,x2,y1,y2);
		break;
	 case 4:
		obj1.div(x1,x2,y1,y2);
		break;
	}*/

	//DIFFERENT CLASS STATIC
	/*switch(q)
	{
	 case 1:
		Complex2.add(x1,x2,y1,y2);
		break;
	 case 2:
		Complex2.subtract(x1,x2,y1,y2);
		break;
	 case 3:
		Complex2.multi(x1,x2,y1,y2);
		break;
	 case 4:
		Complex2.div(x1,x2,y1,y2);
		break;
	}*/

	//DIFFERENT CLASS NON-STATIC
	switch(q)
	{
	 case 1:
		obj2.add(x1,x2,y1,y2);
		break;
	 case 2:
		obj2.subtract(x1,x2,y1,y2);
		break;
	 case 3:
		obj2.multi(x1,x2,y1,y2);
		break;
	 case 4:
		obj2.div(x1,x2,y1,y2);
		break;
	}

}

	//SAME CLASS STATIC
    /*public static void add(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1+y1;
	int a2 = x2+y2; 
	System.out.println("Addition gives: " + a1 + " + (" + a2 + "i)");
    }

    public static void subtract(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1-y1;
	int a2 = x2-y2; 
	System.out.println("Subtraction gives: " + a1 + " + (" + a2 + "i)");
    }

    public static void multi(int x1, int x2, int y1, int y2)
    {
	int a1 = x1*y1 - x2*y2;
	int a2 = x1*y2 + x2*y1;
	System.out.println("Multiplication gives: " + a1 + " + (" + a2 + "i)");
    }

    public static void div(double x1, int x2, int y1, int y2)
    {
	double ad = y1*y1 + y2*y2;
	double a1 = (x1*y1 + x2*y2)/ad;
	double a2 = (x1*(-y2) + x2*(y1))/ad;
	System.out.println("Division gives: " + a1 + " + (" + a2 + "i)");
    }*/

	//SAME CLASS NON-STATIC
	public  void add(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1+y1;
	int a2 = x2+y2; 
	System.out.println("Addition gives: " + a1 + " + (" + a2 + "i)");
    }

    public  void subtract(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1-y1;
	int a2 = x2-y2; 
	System.out.println("Subtraction gives: " + a1 + " + (" + a2 + "i)");
    }

    public  void multi(int x1, int x2, int y1, int y2)
    {
	int a1 = x1*y1 - x2*y2;
	int a2 = x1*y2 + x2*y1;
	System.out.println("Multiplication gives: " + a1 + " + (" + a2 + "i)");
    }

    public  void div(double x1, int x2, int y1, int y2)
    {
	double ad = y1*y1 + y2*y2;
	double a1 = (x1*y1 + x2*y2)/ad;
	double a2 = (x1*(-y2) + x2*(y1))/ad;
	System.out.println("Division gives: " + a1 + " + (" + a2 + "i)");
    }


}

class Complex2
{
	//DIFFERENT CLASS STATIC
	/*public static void add(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1+y1;
	int a2 = x2+y2; 
	System.out.println("Addition gives: " + a1 + " + (" + a2 + "i)");
    }

    public static void subtract(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1-y1;
	int a2 = x2-y2; 
	System.out.println("Subtraction gives: " + a1 + " + (" + a2 + "i)");
    }

    public static void multi(int x1, int x2, int y1, int y2)
    {
	int a1 = x1*y1 - x2*y2;
	int a2 = x1*y2 + x2*y1;
	System.out.println("Multiplication gives: " + a1 + " + (" + a2 + "i)");
    }

    public static void div(double x1, int x2, int y1, int y2)
    {
	double ad = y1*y1 + y2*y2;
	double a1 = (x1*y1 + x2*y2)/ad;
	double a2 = (x1*(-y2) + x2*(y1))/ad;
	System.out.println("Division gives: " + a1 + " + (" + a2 + "i)");
    }*/

	//DIIFERENT CLASS NON-STATIC
	public  void add(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1+y1;
	int a2 = x2+y2; 
	System.out.println("Addition gives: " + a1 + " + (" + a2 + "i)");
    }

    public  void subtract(int x1, int x2, int y1, int y2)
    {	
	int a1 = x1-y1;
	int a2 = x2-y2; 
	System.out.println("Subtraction gives: " + a1 + " + (" + a2 + "i)");
    }

    public  void multi(int x1, int x2, int y1, int y2)
    {
	int a1 = x1*y1 - x2*y2;
	int a2 = x1*y2 + x2*y1;
	System.out.println("Multiplication gives: " + a1 + " + (" + a2 + "i)");
    }

    public  void div(double x1, int x2, int y1, int y2)
    {
	double ad = y1*y1 + y2*y2;
	double a1 = (x1*y1 + x2*y2)/ad;
	double a2 = (x1*(-y2) + x2*(y1))/ad;
	System.out.println("Division gives: " + a1 + " + (" + a2 + "i)");
    }

}
