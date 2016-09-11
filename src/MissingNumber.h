/**
Description: https://leetcode.com/problems/two-sum/
Date: 2016/07/12
*/

#ifndef __MISSINGNUMBER_H__
#define __MISSINGNUMBER_H__

#include <vector>
#include <iostream>
#include <algorithm>


namespace MissingNumber
{
	class Solution{
	public:
		int missingNumber(std::vector<int>& nums)
		{
			std::sort(begin(nums), end(nums));

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

		int missingNumber2(std::vector<int>& nums)
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

		static void Run()
		{
			Solution sol;
			std::cout << sol.missingNumber2(std::vector<int>({ 0, 1, 4, 3, 2, 5, 8, 7 })) << std::endl;
		}
	};
}

#endif
