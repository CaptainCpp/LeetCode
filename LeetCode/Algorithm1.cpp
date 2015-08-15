//////////////////////////////////////////////////////////////////////////
/// Given an array of integers, find two numbers such that they add up to a specific target number.

/// The function twoSum should return indices of the two numbers such that they add up to the target, 
/// where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.

/// You may assume that each input would have exactly one solution.

/// Input: numbers = { 2, 7, 11, 15 }, target = 9
/// Output : index1 = 1, index2 = 2
//////////////////////////////////////////////////////////////////////////

#include<vector>
#include <algorithm>
#include <map>
using namespace std;

struct NumStruct
{
	NumStruct(int a, int b) : number(a), location(b) {}
	int number;
	int location;
};

bool isLesser(NumStruct a, NumStruct b)
{
	return a.number < b.number;
}

class Solution {
public:
	vector<int> twoSum1(vector<int>& nums, int target) 
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

	vector<int> twoSum2(vector<int>& nums, int target)
	{
		vector<int> resultVec;
		vector<NumStruct> vecStruct;
		for (int i = 0; i < nums.size(); ++i)
		{
			NumStruct numStruct(nums[i], i);
			vecStruct.push_back(numStruct);
		}

		sort(vecStruct.begin(), vecStruct.end(), isLesser);

		int front = 0;
		int back = vecStruct.size() - 1;

		while (front != back)
		{
			int addResult = (vecStruct[front]).number + (vecStruct[back]).number;
			if (addResult == target)
			{
				int iLocation1 = vecStruct[front].location + 1;
				int iLocation2 = vecStruct[back].location + 1;

				if (iLocation1 > iLocation2)
				{
					int tmp = iLocation1;
					iLocation1 = iLocation2;
					iLocation2 = tmp;
				}
				resultVec.push_back(iLocation1);
				resultVec.push_back(iLocation2);
				return resultVec;
			}
			else if (addResult < target )
			{
				++front;
			}
			else
			{
				--back;
			}
		}
		return resultVec;
	}
	
};

int main()
{
	Solution solution;
	vector<int> nums = {-1,-2,-3,-4,-5};
	int target = -8;
	vector<int> result = solution.twoSum2(nums, target);
	
	system("pause");
	return 0;
}