import java.util.Scanner;

public class Exp04 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of users: ");
        int n = sc.nextInt();
        Account arr[] = new Account[20];
        for(int i=0; i<n; i++)
        {
            arr[i] = new Account();
            System.out.println("For account"+(i+1)+": ");
            System.out.print("Enter id: ");
            arr[i].id = sc.nextLong();
            System.out.print("Enter name: ");
            arr[i].name = sc.next();
            System.out.print("Enter balance: ");
            arr[i].bal = sc.nextInt();
        }
        int q=-1;
        while(q!=0){
        System.out.println("Enter 1.To add account\n2.To delete any account detail\n3.To display account details.\n0.To exit");
        q = sc.nextInt();        
        switch(q)
        {
         case 0:
            break;

         case 1:
            System.out.print("Enter id: ");
            arr[n].id = sc.nextLong();
            System.out.print("Enter name: ");
            arr[n].name = sc.nextLine();
            System.out.print("Enter balance: ");
            arr[n].bal = sc.nextInt();
            n += 1;
            break;

         case 2:
            System.out.print("Enter account you want to delete: ");
            int n2 = sc.nextInt();
            Account[] temp = arr;
            int w =0;
            for(int i=0; i<n-1; i++)
            {
                if (i != n2-1)
                {
                    arr[w] = temp[i];
                }
                w += 1;
            }
            break;

         case 3:
            System.out.print("Enter account no.: ");
            int n3 = sc.nextInt();
            break;

         default:
            System.out.println("Invalid input");
            break;

        }
    }
}
}

class Account
{
    long id;
    String name;
    int bal;
}
