import java.util.*;

class TowersOfHanoi {
    public static void main(String args[]) {
        Scanner x = new Scanner(System.in);
        System.out.print("No of discs: ");
        int discs = x.nextInt();
        System.out.print("Start Pole [1, 2, 3]: ");
        int start = x.nextInt();
        System.out.print("End Pole [1, 2, 3]: ");
        int end = x.nextInt();

        if(start!=end)
            move(6,1,3);
        else
            System.out.println("Same start and end pole. Need to solve ?");
    }

    public static void move(int n, int start, int end) {
        if(n==0)
            return;
        
        int aux = 6 - start - end;
        move(n-1,start,aux);
        System.out.println("Move " + n + " from " + start + " to " + end);
        move(n-1,aux,end);
    }
}