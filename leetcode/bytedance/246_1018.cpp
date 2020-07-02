#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <algorithm>
struct st_max_cont
{
    int x;
    int y;
    st_max_cont():x(0),y(0){}
    st_max_cont(int x0, int y0):x(x0),y(y0){}
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int imax = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                matrix[i][j] = matrix[i][j] - '0';
                //cout << "i: " << i << ", j: " << j << ", retset val: " << (int)matrix[i][j] << endl;
            }
        }
        
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[i].size(); j++)
            {
                cout << "i: " << i << ", j: " << j << ", val: " << (int)matrix[i][j] 
                     << ", left: " << (int)matrix[i-1][j] << ", top: " << (int)matrix[i][j-1] << endl;
                if(matrix[i][j] == 0) continue;
                matrix[i][j] = matrix[i-1][j] < matrix[i][j-1] ? matrix[i-1][j] : matrix[i][j-1];
                matrix[i][j] = matrix[i][j] > 1 ? matrix[i][j] : 1;
                imax = imax > matrix[i][j] ? imax : matrix[i][j];
                cout << "imax: " << imax << ", val: " << (int)matrix[i][j] << endl;

                //matrix[i][j] = std::min(matrix[i-1][j], matrix[i][j-1]);
                //matrix[i][j] = std::max((int)matrix[i][j], move(1));
                //imax = std::max(imax, (int)matrix[i][j]);
            }
        }
        return imax*imax;
    }

    int maximalSquare2(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        // if size == 1
        
        int imax = 0, result_max = 0;
        vector<vector<st_max_cont>> dp(matrix.size());

        // init
        for(int i = 0; i < matrix.size(); i++)
        {
            dp[i].resize(matrix[i].size());
            dp[i][0].x = matrix[i][0] - '0';
            dp[i][0].y = dp[i][0].x;
            if(dp[i][0].y == 1 && i > 0)
            {
                dp[i][0].y += dp[i-1][0].y; 
            }
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            dp[0][j].x = matrix[0][j] - '0';
            dp[0][j].y = dp[0][j].x;
            if(dp[0][j].x == 1 && j > 0)
            {
                dp[0][j].x += dp[0][j-1].x; 
            }
        }
        
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[i].size(); j++)
            {
                cout << "i: " << i << ", j: " << j << ", val: " << matrix[i][j] 
                     << ", left: " << matrix[i-1][j] << ", top: " << matrix[i][j-1] << endl;
                if(matrix[i][j] == '0') continue;
                
                dp[i][j].x = dp[i][j-1].x+1;
                dp[i][j].y = dp[i-1][j].y+1;
                imax = min(dp[i][j].x, dp[i][j].y);
                if(imax > result_max)
                {
                    result_max = imax;
                    cout << "i: " << i << ", j: " << j 
                         << ", x: " << dp[i][j].x << ", y: " << dp[i][j].y
                         << ", max: " << result_max << endl;
                }
                else
                {
                    cout << "i: " << i << ", j: " << j 
                         << ", x: " << dp[i][j].x << ", y: " << dp[i][j].y
                         << endl;
                }
            }
        }
        return result_max*result_max;
    }
};

int main(int argc, char *argv[])
{
	Solution so;
}
