package engineering;
import java.util.*;

public class Student {
    long roll;
    String sub_name;
    String stud_name;
    int tot_marks;

    /*public static void main(String args[])
    {
        Vector<Student> v = create();
        Marks obj1 = new Marks();
        obj1.display(v);        
    }*/

    public static Vector<Student> create(){
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter no. of students: ");
        n = sc.nextInt();
        Vector<Student> v = new Vector<Student>();
        for(int i=0; i<n; i++)
        {
            Student obj = new Student();
            System.out.print("Enter roll no: ");
            obj.roll = sc.nextLong();
            System.out.print("Enter student name: ");
            obj.stud_name = sc.next();
            System.out.print("Enter subject name: ");
            obj.sub_name = sc.next();
            System.out.print("Enter total marks: ");
            obj.tot_marks = sc.nextInt();
            v.add(obj);
        }
        return v;
    }
}

class Marks{
    //Vector<Student> v = Student.create();
    public static void display(Vector<Student> v)
    {
        v = sort(v);
        System.out.println("Name\troll no.\tsubject\tmarks");
        for(int i=0; i<v.size(); i++)
        {
            Student s1 = v.get(i);
            System.out.println(s1.stud_name + "\t" + s1.roll + "\t" + s1.sub_name + "\t" + s1.tot_marks);
        }
    }

    public static Vector<Student> sort(Vector<Student> v)
    {
        Student s1 = new Student();
        for(int i =0; i<v.size(); i++)
        {
            for(int j=0; j<v.size()-1; j++)
            {
                if(v.get(j).tot_marks < v.get(j+1).tot_marks)
                {
                    s1 = v.get(j);
                    v.set(j, v.get(j+1));
                    v.set(j+1, s1);
                }
            }

        }
        return v;
    }
}
