package Engineering;
import java.util.*;

public class Marks{
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
