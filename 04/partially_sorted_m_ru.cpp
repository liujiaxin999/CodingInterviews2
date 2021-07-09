#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    //从右上出发
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        bool is_found=false;
        if(matrix.empty() || matrix[0].empty())//判断是否为空
            return is_found;
        if(target>matrix[matrix.size()-1][matrix[0].size()-1] || target<matrix[0][0])
            return is_found;
        int row=0,col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0)
        {
            if(matrix[row][col]==target)
            {
                is_found=true;
                break;
            }
            else if (matrix[row][col]>target)//向左走
                col--;
            else//小于 向下走
                row++;
        }
        return is_found;
    }

    // 遍历检查输入是否符合题意递增
    bool checkMatrix(vector<vector<int>>& m)
    {
        int i,j;
        for(i=0;i<m.size();i++)
            for(j=1;j<m[0].size();j++)
                if(m[i][j]<m[i][j-1])
                    return false;
        return true;
    }
};

int main()
{
    Solution my_solution = Solution();
    vector<vector<int>> b={
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int t = 20;
    if(my_solution.checkMatrix(b))
        //boolalpha使得输出为bool类型变量
        cout<<boolalpha<<my_solution.findNumberIn2DArray(b,t)<<endl;
    return 0;
}
