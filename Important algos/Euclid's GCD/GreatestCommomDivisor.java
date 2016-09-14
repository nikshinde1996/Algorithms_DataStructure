import java.util.*;

class GreatestCommonDivisor {
    public static void main(String args[]) {
        Scanner x = new Scanner(System.in);
        System.out.print("a: ");
        int a = x.nextInt();
        System.out.print("b: ");
        int b = x.nextInt();

        System.out.println("gcd: " + gcd(a,b));
    }
    
    public static int gcd(int a, int b) {
        if(b==0)
            return a;

        return gcd(b, a % b);
    }
}