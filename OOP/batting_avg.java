import java.util.Scanner;

public class Exp03 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of players: ");
        int np = sc.nextInt();
        double arr[][] = new double[np][];
        for(int i=0; i<np; i++)
        {
            System.out.print("Enter no. of matches of player"+(i+1)+": ");
            int nm = sc.nextInt();
            arr[i] = new double[nm+2];
            double avg = 0;
            for(int j=0; j<nm; j++)
            {
                System.out.print("Enter no. of runs in match "+(j+1)+": ");
                arr[i][j] = sc.nextDouble();
                avg += arr[i][j];
            }
            avg = avg/nm;
            arr[i][nm] = avg;
            arr[i][nm+1] = i+1;
        }
        
        for(int i=0; i<arr.length; i++)
        {
            System.out.println("Player" + (i+1) + " :");
            for(int j=0; j<arr[i].length-2; j++)
            {
                System.out.print("match"+(j+1)+"  ");
            }
            System.out.println("batting avg");

            for(int j=0; j<arr[i].length-2; j++)
            {
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println(arr[i][arr[i].length-2]);
        }

        //SORTING
        System.out.println("\nStats of top 3 players: ");
        for(int i=0; i<arr.length; i++)
        {
            for(int j=0; j<arr.length-1; j++)
            {
                if(arr[j][arr[j].length-2] < arr[j+1][arr[j+1].length-2])
                {
                    double[] temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        for(int i=0; i<3; i++)
        {
            System.out.println("Player" + (int)arr[i][arr[i].length-1] + " :");
            for(int j=0; j<arr[i].length-2; j++)
            {
                System.out.print("match"+(j+1)+"  ");
            }
            System.out.println("batting avg");

            for(int j=0; j<arr[i].length-2; j++)
            {
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println(arr[i][arr[i].length-2]);
        }
    }    
}
