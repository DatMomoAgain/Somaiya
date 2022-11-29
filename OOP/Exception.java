import java.io.*;
import java.util.*;

class TimeException extends Exception
{
    public String toString()
    {
        return "TimeException: Seconds cant be more than 59";
    }
}
class Exp07
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int min1=0, min2=0, sec1=0, sec2=0;
        System.out.print("Enter time 1: ");
        try{
            min1 = sc.nextInt();
            sec1 = sc.nextInt();
            if(sec1>59)
            {
                throw new TimeException();
            }
        }
        catch(TimeException e)
        {
            System.out.println(e);
            return;
        }

        System.out.print("Enter time 2: ");
        try{
            min2 = sc.nextInt();
            sec2 = sc.nextInt();
            if(sec2>59)
            {
                throw new TimeException();
            }
        }
        catch(TimeException e)
        {
            System.out.println(e);
            return;
        }

        int minf = min1+min2;
        int secf = sec1+sec2;
        if(secf>59)
        {
            secf -= 60;
            minf +=1;
        }
        String sec = Integer.toString(secf);
        if(secf<10){
            sec = '0' + sec;
        }
        System.out.println("Addition of 2 times is: "+ minf+":"+sec);
    }
}
