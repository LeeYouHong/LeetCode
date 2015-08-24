#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int missingNumber(vector<int>& nums)
	{
		sort(begin(nums), end(nums));

		int i = 0;
		for (auto num : nums)
		{
			if (i != num)
			{
				break;
			}
			i++;
		}
		return i;
	}

	int missingNumber2(vector<int>& nums)
	{
		int result = nums.size();
		int i = 0;
		for (auto num : nums)
		{
			result ^= num;
			result ^= i;

			i++;
		}
		return result;
	}
};

int main(void)
{
	Solution sol;
	
	cout << sol.missingNumber2(vector<int>({0,1,4,3,2,5,8,7})) << endl;

	return 0;
}
