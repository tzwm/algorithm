#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            sort(num.begin(), num.end());
            int ans = num[0] + num[1] + num[2];

            for(int i=0; i<num.size()-2; i++) {
                int tmpTarget = target - num[i];
                int ret = twoSumClosest(num, tmpTarget, i+1);
                if(abs(ret+num[i]-target) < abs(ans-target)) {
                    ans = ret + num[i];
                }
            }

            return ans;
        }

    private:
        int twoSumClosest(vector<int> &num, int target, int start) {
            int l = start;
            int r = num.size()-1;
            int ans = num[l]+num[r];

            while(r - l > 0) {
                if(abs(num[l] + num[r] -target) < abs(ans - target)){
                    ans = num[l]+num[r];
                    if(ans - target == 0) break;
                }
                if(num[l]+num[r] > target)
                    r--;
                else
                    l++;
            }

            return ans;
        }
};


int main() {
    vector<int> tmp;
    tmp.push_back(-1);
    tmp.push_back(2);
    tmp.push_back(1);
    tmp.push_back(-4);

    Solution s;
    int ans = s.threeSumClosest(tmp, 1);

    cout<<ans<<endl;

    return 0;
}

