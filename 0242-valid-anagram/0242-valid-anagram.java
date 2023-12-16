class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        int n = s.length();
        int freq[] = new int[26];
        for(int i=0;i<n;i++){
            freq[s.charAt(i)-'a']++;
            freq[t.charAt(i)-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            return false;
        }
        return true;
    }
}