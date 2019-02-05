public class Solution {
    public int lengthOfLongestSubstring(String A) {
        HashMap<Character, Integer> hs = new HashMap<>();
        int max = 0;
        
        for(int i = 0; i < A.length(); i++) {
            if(hs.containsKey(A.charAt(i))) {
                i = hs.get(A.charAt(i));
                hs.clear();
            }
            else {
                hs.put(A.charAt(i), i);
                if(hs.size() > max) {
                    max = hs.size();
                }
            }
        }
        return max;
    }
}