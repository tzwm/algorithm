class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int min = 2147483647;
            int ans;

            for(int i = 0; i < num.size(); i++) {
                for(int j = i+1; j < num.size(); j++) {
                    for(int z = j+1; z < num.size(); z++) {
                        int sum = num[i] + num[j] + num[z];
                        if(abs(sum) < min) {
                            min = abs(sum);
                            ans = sum;
                        }
                    }
                }
            }

            return ans;
        }
};

