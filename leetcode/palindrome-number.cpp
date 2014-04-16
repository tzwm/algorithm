class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int xx = x;
        int y = 0;
        while(x>0) {
            y = y*10 + x%10;
            x = x / 10;
        }

        return xx==y;
    }
};

int main() {
    Solution s;
    bool ans = s.isPalindrome(10);

    return 0;
}

