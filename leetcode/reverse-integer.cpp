class Solution {
    public:
        int reverse(int x) {
            int lr = 1;
            int ans = 0;
            if (x < 0) {
                lr = -1;
                x = x * -1;
            }
            while(x>0) {
                ans = ans*10 + (x%10);
                x = x/10; 
            }
            
            ans = ans * lr;
        }
}
