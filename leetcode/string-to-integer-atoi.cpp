#include<iostream>
#include<climits>

using namespace std;


class Solution {
    public: 
        int atoi(const char *str) {
            int i = 0;
            int ans = 0;
            int lr = 1;
            char* newStr = clearFirstWhite(str);
            while(true) {
                const char *ch = newStr + i;
                if(*ch == '\0') break;
                int ret = char2int(ch);
                if(ret == -1) {
                    if(i == 0) {
                        if(*ch == '+') {
                            i++;
                            continue;
                        }
                        if(*ch == '-') {
                            lr = -1;
                            i++;
                            continue;
                        }
                    } else return ans * lr;
                    break;
                }
                if( ans > INT_MAX / 10 || ans*10 > INT_MAX-ret) 
                    if(lr == 1) return INT_MAX;
                    else return INT_MIN;
                ans = ans*10 + ret;
                i++;
            } 

            return ans * lr;
        }

    private:
        int char2int(const char *ch) {
            if (*ch >= '0' && *ch <= '9') {
                return (int)(*ch-'0');
            }

            return -1;
        }

        char* clearFirstWhite(const char *str) {
            int i = 0;
            char ans[24];
            bool ok = false;
            int j = 0;
            while(true) {
                char ch = *(str+i++);
                if(ch == '\0') break;
                if(ch == ' ') {
                    if(ok) break;
                    continue;
                }
                ok = true;
                ans[j++] = ch;
            }

            ans[j] = '\0';
            return ans;
        }
};

int main() {
    Solution s;
    cout<<s.atoi("+1")<<endl;

    return 0;
}

