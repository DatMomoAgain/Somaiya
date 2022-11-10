import java.util.*;

public class Exp05 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int q=-1;
        Vector<Emp> vec = new Vector<Emp>();
        while(q!=0)
        {
            System.out.println("1-Create  2-Insert  3-DeleteByName  4-DeleteByID  5-Display  0-Exit: ");
            q = sc.nextInt();
            switch(q)
            {
             case 0:
                break;
             case 1:
                vec = create();
                break;
             case 2:
                insert(vec);
                break;
             case 3:
                deleteName(vec);
                break;
             case 4:
                deleteID(vec);
                break;
             case 5:
                disp(vec);
                break;
             default:
                System.out.println("Invalid input");
                break;
            }
        }
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
            System.out.println(v.get(i).id + "\t" + v.get(i).name + "\t" + v.get(i).sal);
        }
    }

    public static void insert(Vector<Emp> v)
    {
        Scanner sc = new Scanner(System.in);
        Emp obj = new Emp();
        obj = new Emp();
        System.out.print("Enter id: ");
        obj.id = sc.nextLong();
        System.out.print("Enter name: ");
        obj.name = sc.next();
        System.out.print("Enter salary: ");
        obj.sal = sc.nextInt();
        int p = v.size();
        for(int i=0; i<v.size(); i++)
        {
            if(obj.sal>v.get(i).sal){
                v.insertElementAt(obj, i);
                break;
            }
            if(i==p-1)
            {
                v.add(obj);
            }            
        }
    }

    public static void deleteName(Vector<Emp> v)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name of employee to be deleted: ");
        String s = sc.next();
        int p = v.size();
        for(int i=0; i<v.size(); i++)
        {
            if(s.equals(v.get(i).name))
            {
                v.remove(i);
                break;
            }

            if(i==p-1)
            {
                System.out.println("No employee by that name");
            }
        }
    }

    public static void deleteID(Vector<Emp> v)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter id of employee to be deleted: ");
        long s = sc.nextLong();
        int p = v.size();
        for(int i=0; i<v.size(); i++)
        {
            if(s == v.get(i).id)
            {
                v.remove(i);
                break;
            }
            if(i==p-1)
            {
                System.out.println("No employee by that ID");
            }
        }
    }

}

class Emp
{
    String name;
    long id;
    int sal;
}
