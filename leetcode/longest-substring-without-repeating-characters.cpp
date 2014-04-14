//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        for(int i = 0; i < s.size(); i++){
            bool a[26];
            memset(a, 0, sizeof(a));
            a[(int)s[i]-(int)'a'] = true;
            int num = 1;
            for(int j = i+1; j < s.size(); j++) {
                if(a[(int)s[j]-(int)'a'])
                    break;
                a[(int)s[j]-(int)'a'] = true;
                num++;
            }
            
            if(num > ret)
                ret = num;
        }
        
        return ret;
    }
};

