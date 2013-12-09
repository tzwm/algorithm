class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = i+1; j< numbers.size(); j++) {
                if(numbers[i] + numbers[j] == target) {
                    vector<int> ret;
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    
                    return ret;
                }
            }
        }
    }
};
