import java.lang.*;
public class Solution {
    public int isPalindrome(String A) {
        A = A.toLowerCase();
        int n = A.length()-1;
        for(int i=0,j= n;i<j;i++,j--){
            while(!Character.isLetterOrDigit(A.charAt(i)) && i<n)i++;
            while(!Character.isLetterOrDigit(A.charAt(j)) && j>0)j--;
            if(i<j && A.charAt(i) != A.charAt(j)) return 0;
        }
        return 1;
    }
}
