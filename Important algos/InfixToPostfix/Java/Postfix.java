
import java.io.*;
import java.util.*;

public class Postfix {
    
    static char c[];
    static char[] ans;
    static ArrayList<Character> al;
    static ArrayList<Character> pfix;
   
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //System.out.println("Enter the number of test cases: ");
        int t = Integer.parseInt(br.readLine());
 
        for(int k=0;k<t;k++) {
            //System.out.print("Enter the expression: ");
            String exp = br.readLine();
            c = new char[exp.length()];
            c = exp.toCharArray();
            al = new ArrayList<Character>();
            pfix = new ArrayList<Character>();
            postfix();
        
            for(int i=al.size()-1;i>=0;i--) {
                pfix.add(al.get(i));
                al.remove(al.get(i));
            }
            //System.out.print("Postfix: ");
            for(int i=0;i<pfix.size();i++) {
                System.out.print(pfix.get(i));
            }
            System.out.println();
        }
    }
    
    private static void postfix() {
        for(int i=0;i<c.length;i++) {
            if((int)c[i] >=97 && (int) c[i] <=122) { pfix.add(c[i]); } 
            else evaluate(c[i]);
        }
    }
    
    private static void evaluate(char c) {
        if(al.isEmpty()) {
            al.add(c);
        }
        else if(c == ')') {
            while(al.get(al.size()-1)!='(') {
                pfix.add(al.get(al.size()-1));
                al.remove(al.get(al.size()-1));
            }
            al.remove(al.get(al.size()-1));
        }
        else {
            if(precedence(al.get(al.size()-1), c)) {
                al.add(c);
            }
            else {
                while(!precedence(al.get(al.size()-1), c)) {
                    pfix.add(al.get(al.size()-1));
                    al.remove(al.size()-1);
                    if(al.isEmpty()) {
                        break;
                    }
                }
                al.add(c);
            }
        }
    }
    
    private static boolean precedence(char a, char b) {
        
        if(a=='(') {
            switch(b) {
                case '^':
                    return true;
                 
                case '/':
                    return true;
                
                case '*':
                    return true;
                
                case '-':
                    return true;
                
                case '+':
                    return true;
                    
                case '(':
                    return true;
            }
        }
        
        else if(a=='^') {
            switch(b) {
                case '^':
                    return true;
                 
                case '/':
                    return false;
                
                case '*':
                    return false;
                
                case '-':
                    return false;
                
                case '+':
                    return false;
                    
                case '(':
                    return true;
            }
        } 
        else if(a=='/') {
            switch(b) {
                case '^':
                    return true;
                 
                case '/':
                    return false;
                
                case '*':
                    return false;
                
                case '-':
                    return false;
                
                case '+':
                    return false;
                    
                case '(':
                    return true;
            }
        }
        else if(a=='*') {
            switch(b) {
                case '^':
                    return true;
                 
                case '/':
                    return true;
                
                case '*':
                    return false;
                
                case '-':
                    return false;
                
                case '+':
                    return false;
                    
                case '(':
                    return true;
            }
        } 
        else if(a=='-') {
            switch(b) {
                case '^':
                    return true;
                 
                case '/':
                    return true;
                
                case '*':
                    return true;
                
                case '-':
                    return false;
                
                case '+':
                    return false;
                    
                case '(':
                    return true;
            }
        }
        else if(a=='+') {
            switch(b) {
                case '^':
                    return true;
                 
                case '/':
                    return true;
                
                case '*':
                    return true;
                
                case '-':
                    return false;
                
                case '+':
                    return false;
                    
                case '(':
                    return true;
            }
        }
        
        else {
            switch(b) {
                case '^':
                    return false;
                 
                case '/':
                    return false;
                
                case '*':
                    return false;
                
                case '-':
                    return false;
                
                case '+':
                    return false;
            }
        }
        return false;
    }
}
