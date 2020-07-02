// 未完成: https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        vector<int> result;
        result.push_back(numerator / denominator);
        numerator = (numerator % denominator) * 10;
        int loopx = 1, loopy = 1;
        bool has_loop = false;
        while(numerator % denominator)
        {
            result.push_back(numerator / denominator);
            numerator = (numerator % denominator) * 10;
            has_loop = check_loop(result, loopx, loopy);
            if(has_loop) break;
        }
        
        string res = result[0] + '0';
        if(result.size() > 1)  res += ".";
        for(int i = 1; i < result.size(); i++)
        {
            if(has_loop)
            {
                if(i < loopx || (loopx < i && i < loopy))
                {
                    res += result[i] + '0';
                }
                else if(loopx == i && i == loopy)
                {
                    res += '(' + (result[i] + '0') + ')';
                    break;
                }
                else if(loopx == i)
                {
                    res += '(' + (result[i] + '0');
                }
                else if(loopy == i)
                {
                    res += (result[i] + '0') + ')';
                }
                else
                {
                    break;
                }
            }
            else
            {
                res += result[i] + '0';
            }
        }
        
        return res;
    }
    
    bool check_loop(vector<int> &result, int &loopx, int &loopy)
    {
        int len = result.size();
        if(len > 5) return false; // 足够多？
        bool has_loop = false;
        for(int n = 1; n < (len-1)/2; n++)
        {
            has_loop = true;
            for(int i = 0; i < n; i++)
            {
                if(result[len-i] != result[len-n-i])
                {
                    has_loop = false;
                    break;
                }
            }
            if(has_loop)
            {
                loopx = 
                break;
            }
        }
    }

};
