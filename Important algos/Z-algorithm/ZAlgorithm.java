import java.util.*;

class ZAlgorithm {
    private static String string, pattern;
    private static int zarray[];

    public static void main(String args[]) {
        Scanner x = new Scanner(System.in);

        System.out.print("String: ");
        string = x.next();

        System.out.print("Pattern: ");
        pattern = x.next();

        generateZ();
        ZSearch();
    }

    private static void generateZ() {
        String pattstr = pattern + "$" + string;
        int length = pattstr.length();
        int left = 0, right = 0;

        zarray = new int[length];
         
        for(int i=1;i<length;i++) {
            if(i > right) {
                left = right = i;
                while(right < length && pattstr.charAt(right) == pattstr.charAt(right - left)) {
                    right++;
                }
                zarray[i] = right - left;
                right--;
            }
            else {
                int diff = i - left;
                if(zarray[diff] < right - i + 1) {
                    zarray[i] = zarray[diff];
                }     
                else {
                    left = i;
                    while(right < length && pattstr.charAt(right) == pattstr.charAt(right - left)) {
                        right++;
                    }
                    zarray[i] = right - left;
                    right--;
                }
            }
        }
    }

    private static void ZSearch() {
        boolean notfound = true;
        int pattlength = pattern.length();
        
        System.out.print("Location: ");

        for(int i=0;i<zarray.length;i++) {
            if(zarray[i] == pattlength) {
                notfound = false;
                System.out.print((i - pattlength - 1) + " ");
            }
        }

        if(notfound) System.out.println("Pattern not found!");
    }
}