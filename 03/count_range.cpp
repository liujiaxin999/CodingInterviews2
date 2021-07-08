#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define P -1

class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        //�����������
        if (nums.size()==0)//��ֹ����Ϊ��
            return -1;
        //��������Ƿ���Խ��
        int i=0;
        for(i=0;i<nums.size();i++)
            if(nums[i]<0 || nums[i]>=nums.size())
                return -1;

        int start_=1,end_=nums.size()-1;//���ַ�Χ
        while(end_>=start_)
        {
            int middle_=((end_-start_)>>1)+start_;//����λ�������
            int count_ = countRange(nums,start_,middle_);//O(n)
            cout<<"start "<<start_<<" end "<<end_<<" count "<<count_<<endl;
            if(end_==start_)
            {
                if(count_>1)
                    return start_;
                else
                    break;//û�ҵ�
            }
            if(count_>(middle_-start_+1))//˵����ǰ��
                end_ = middle_;
            else
                start_ = middle_+1;//˵���ظ��ں���
        }
        return -1;
    }

    // ���㷶Χ���ִ���
    int countRange(vector<int>& nums,int start_,int end_)
    {
        int count_=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>=start_ && nums[i]<=end_)
                count_++;
        return count_;
    }
};

int main()
{
    Solution my_solution = Solution();
    int b[8]={2,3,5,4,3,2,6,7};
    vector<int> c(b,b+8);
    cout<<my_solution.findRepeatNumber(c)<<endl;
    return 0;
}
