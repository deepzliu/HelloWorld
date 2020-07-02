class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        cout << "first: " << first << ", len: " << len << endl;

        if (first == len) {
            cout << "result: "; print(output);
            res.push_back(output);
            return;
        }
        vector<int> used;
        for (int i = first; i < len; ++i) {
            if(find(used.begin(), used.end(), output[i]) != used.end()){
                cout << "cut: "; print(output);
                continue;
            } 
            swap(output[i], output[first]);
            used.push_back(output[i]);
            backtrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }

    void print(vector<int> &v)
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ",";
        }
        cout << endl;
    }
};

class Solution {
    vector<int> nums;//记录每一次选择后数组状态，包括最终答案
    vector<vector<int>> ans;//选择完每一个数组后并入答案集
    int len;//输入数组元素数量
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len=nums.size();//更新len
        this->nums=nums;//更新nums
        dfs(0);//开始回溯
        return ans;
    }
    void dfs(int n){
        if(n==len){
            ans.push_back(nums);//已经排列到len位置，即超出数组范围，这意味着已经完成了排列，将此排列并入答案集合
            return;
        }
        vector<int> temp={};//记录该位选择过的元素值，已经选择过的值不再选择
        for(int i=n;i<len;++i){//n为当前正在选择的位，i为准备要作为n位元素目前的位置
            if(find(temp.begin(),temp.end(),nums[i])!=temp.end())continue;//已经选择过的值不再选择
            swap(nums[n],nums[i]);//将第i位数字移动到n位，完成该位选择
            temp.push_back(nums[n]);//记录选择，防止选择相等数字产生多余的解
            dfs(n+1);//选择下一位数字
            swap(nums[n],nums[i]);//变为选择之前的状态，重新选择下一位数字
        }
    }
};
