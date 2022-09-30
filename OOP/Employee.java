import java.util.*;

public class Exp05 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        Vector<Emp> vec = create();
        disp(vec);

    }
    
    public static Vector<Emp> create()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of users: ");
        int n = sc.nextInt();
        Vector<Emp> v = new Vector<>();
        Emp obj = new Emp();
        for(int i=0; i<n; i++)
        {
            obj = new Emp();
            System.out.println("For account"+(i+1)+": ");
            System.out.print("Enter id: ");
            obj.id = sc.nextLong();
            System.out.print("Enter name: ");
            obj.name = sc.next();
            System.out.print("Enter salary: ");
            obj.sal = sc.nextInt();
            v.add(obj);
        }
        
        //sorting
        Emp obj1 = new Emp();
        Emp obj2 = new Emp();
        for(int i=0; i<v.size()-1; i++)
        {
            for(int j=0; j<v.size()-1; j++)
            {
                obj1 = v.get(j);
                obj2 = v.get(j+1);
                if (obj1.sal < obj2.sal)
                {
                    v.set(j,obj2);
                    v.set(j+1,obj1);
                }
            }
        }

        return v;
    }

    public static void disp(Vector<Emp> v)
    {
        System.out.println("id\tname\tsal: ");
        for(int i=0; i<v.size(); i++)
        {
            System.out.print(v.get(i).id + "\t" + v.get(i).name + "\t" + v.get(i).sal);
        }
    }
}

class Emp
{
    String name;
    long id;
    int sal;

    /*Emp(Emp emp)
    {
        this.name = emp.name;
        this.id = emp.id;
        this.sal = emp.sal;
    }*/
}
