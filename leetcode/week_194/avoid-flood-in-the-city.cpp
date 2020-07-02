class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> fulls;
        vector<int> ans(rains.size(), -1);
        for(int i = 0; i < rains.size(); i++)
        {
            //cout << "i: " << i << ", rain: " << rains[i] << endl;
            if(rains[i] > 0)
            {
                if(fulls.find(rains[i]) != fulls.end())
                {
                    //cout << "no solution" << endl;
                    ans.clear(); // no solution
                    break;
                }
                fulls.insert(rains[i]);
            }
            else
            {
                int flag = 0;
                // finding nearest rain lake to clear.
                for(int j = i+1; j < rains.size(); j++)
                {
                    //cout << "to clear j: " << j << ", rain: " << rains[j] << endl;
                    if(rains[j] <= 0) continue;
                    
                    if(fulls.find(rains[j]) != fulls.end())
                    {
                        //cout << "clear j: " << j << ", rain: " << rains[j] << endl;
                        fulls.erase(rains[j]);
                        ans[i] = rains[j];
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    if(!fulls.empty())
                    {
                        ans[i] = *fulls.begin();
                        fulls.erase(fulls.begin());
                        //cout << "rand clear, " << ans[i] << endl;
                    }
                    else
                    {
                        ans[i] = 1;
                    }
                }
                if(i == rains.size() - 1)
                {
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};
