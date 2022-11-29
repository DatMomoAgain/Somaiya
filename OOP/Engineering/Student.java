package Engineering;
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
