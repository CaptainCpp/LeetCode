#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> resultVec;
		size_t lengthVec = nums.size();
		for (size_t i = 0; i < lengthVec; ++i)
		{
			for (size_t j = i + 1; j < lengthVec; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					resultVec.push_back(i + 1);
					resultVec.push_back(j + 1);
				}
			}
		}
		return resultVec;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = {2, 7, 11, 5};
	int target = 9;
	vector<int> result = solution.twoSum(nums, target);
	
	system("pause");
	return 0;
}