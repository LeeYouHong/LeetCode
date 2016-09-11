/**
Description: https://leetcode.com/problems/two-sum/
Date: 2016/07/12
*/

#ifndef __TWOSUM_H__
#define __TWOSUM_H__

#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
namespace TwoSum
{
	class Solution
	{
		struct stNumberEx
		{
			int num;
			int index;

			//bool operator()(stNumberEx n1, stNumberEx n2)
			//{
			//	return n1.num < n2.num;
			//}

			static bool cmp(stNumberEx n1, stNumberEx n2)
			{
				return n1.num < n2.num;
			}
		};

	public:
		std::vector<int> twoSum(std::vector<int>& nums, int target)
		{
			std::vector<int> result;
			int size = nums.size();

			for (int i = 0; i < size; ++i)
			{
				for (int j = i+1; j < size; ++j)
				{
					if (nums[i] + nums[j] == target)
					{
						result.push_back(i);
						result.push_back(j);

						return result;
					}
				}
			}
			return result;
		}

		std::vector<int> twoSum2(std::vector<int>& nums, int target)
		{
			std::vector<int> result;
			int size = nums.size();

			std::vector<stNumberEx> NumberExList;
			for (int i = 0; i < size; ++i)
			{
				stNumberEx numEx = {};
				numEx.index = i;
				numEx.num = nums[i];

				NumberExList.push_back(numEx);
			}

			// 先排序
			std::sort(NumberExList.begin(), NumberExList.end(), stNumberEx::cmp);

			for (int i = 0; i < size; ++i)
			{
				// 和更小，则退出循环
				if (NumberExList[i].num > target && NumberExList[i].num > 0)
				{
					break;
				}

				// 求出第二个数
				int num2 = target - NumberExList[i].num;

				for (int j = i + 1; j < size; ++j)
				{
					// 和更小，退出循环
					if (NumberExList[j].num > target && NumberExList[i].num > 0)
					{
						break;
					}

					// 内循环的数等于第二个数，则得到了结果
					if (NumberExList[j].num == num2)
					{
						result.push_back(NumberExList[i].index);
						result.push_back(NumberExList[j].index);
						std::sort(result.begin(), result.end());
						return result;
					}
				}
			}
			return result;
		}

		std::vector<int> twoSum3(std::vector<int>& nums, int target)
		{
			std::map<int, std::vector<int>> numsMap;
			std::vector<int> result;
			int size = nums.size();

			for (int i = 0; i < size; ++i)
			{
				numsMap[nums[i]].push_back(i);
			}

			for (int i = 0; i < size; ++i)
			{
				int num2 = target - nums[i];
				auto values = numsMap.find(num2);
				if (values != numsMap.end() && values->second[0] != i)
				{
					result.push_back(i);
					result.push_back(values->second[0]);
					//std::sort(result.begin(), result.end());
					return result;
				}
			}
			return result;
		}

		std::vector<int> twoSum4(std::vector<int>& nums, int target)
		{
			std::unordered_map<int, int> numsMap;
			int size = nums.size();

			for (int i = 0; i < size; ++i)
			{
				if (numsMap.count(target-nums[i]) > 0)
				{
					return std::vector<int>() = {numsMap[target-nums[i]], i};
				}
				//numsMap[nums[i]] = i;
				numsMap.insert(std::make_pair(nums[i], i));
			}

			return std::vector<int>();
		}

		static void Run()
		{
			Solution sol;

			std::vector<int> nums = { 2, 30, 7, 11, 15, 15, 788, 92, 78, 8, 99, 11, 33};
			//std::vector<int> nums = { -1, -2, -3, -4, -5 };
			//std::vector<int> nums = { -3, 4, 3, 90};
			//std::vector<int> nums = { 3, 2, 4};
			std::vector<int> result = sol.twoSum4(nums, 44);
			if (result.size() != 2)
			{
				std::cout << "[]";
			}
			else
			{
				std::cout << "[" << result[0] << "," << result[1] << "]";
			}
		}
	};
}

#endif
