class Solution {
public:
    string longestPalindrome(string s1) {
        if(s1.size() < 2)
            return s1;
        int k = 0, j = 0, i = 0, longest = 1, st = 0;
        while(k < s1.size() - longest/2){
            j = k;
            while(s1[k] == s1[k+1])
                ++k;
            i = k;
            while(k < s1.size() && j >0 && s1[k+1] == s1[j-1]){
                ++k;
                --j;
            }
            if(k-j+1 > longest){
                longest = k-j+1;
                st = j;
            }
            k = i + 1;
        }
        return s1.substr(st,longest);
    }
};