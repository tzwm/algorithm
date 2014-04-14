// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
//
// The solution use [Manacher](http://blog.csdn.net/ggggiqnypgjg/article/details/6645824).
//

class Solution {
public:
    string longestPalindrome(string s) {
        int id, max = 0;
        int p[2004];
        
        string ss = "";
        for(int i = 0; i < s.size(); i++){
            ss += "`";
            ss += s[i];
        }
        ss += "`";
        ss = "$" + ss;
        
        for(int i = 1; i < ss.size(); i++) {
            if(max > i) {
                if(p[2*id-i] < max-i) 
                    p[i] = p[2*id-i];
                else
                    p[i] = max - i;
            } else {
                p[i] = 1;
            }
            
            for(;ss[i+p[i]]==ss[i-p[i]]; p[i]++)
                ;
            
            if(p[i] + i > max){
                max = p[i] + i;
                id = i;
            }
        }
        
        id = 1;
        max = 0;
        for(int i = 1; i < ss.size(); i++) {
            if (p[i] > max){
                max = p[i];
                id = i;
            }
        }

        string ret = "";
        for(int i = id-p[id]+1; i<id+p[id]; i++) {
            if(ss[i] != '`')
                ret += ss[i];
        }
        
        return ret;
    }
};

