/**
Description: https://leetcode.com/problems/median-of-two-sorted-arrays/
Date: 2016/08/04
*/

#ifndef __FINDMEDIANOFTWOSORTEDARRAYS_H__
#define __FINDMEDIANOFTWOSORTEDARRAYS_H__

#include <vector>
#include <iostream>
using namespace std;

namespace FindMedianTwoSortedArrays
{
	class Solution
	{
	public:
		
		double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
		{
			int size1 = nums1.size();
			int size2 = nums2.size();
			if (size1 == 0 && size2 == 0)
			{
				return 0.0;
			}

			vector<int> nums3;
			vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
			bool isOver1, isOver2;
			while (true)
			{
				isOver1 = iter1 == nums1.end();
				isOver2 = iter2 == nums2.end();

				if (isOver1 || isOver2)
				{
					break;
				}
				else
				{
					if (*iter1 < *iter2)
					{
						nums3.push_back(*iter1);
						iter1++;
					}
					else
					{
						nums3.push_back(*iter2);
						iter2++;
					}
				}
			}

			if (isOver1)
			{
				nums3.insert(nums3.end(), iter2, nums2.end());
			}
			else
			{
				nums3.insert(nums3.end(), iter1, nums1.end());
			}

			int index = nums3.size() / 2;
			if (nums3.size() % 2 == 0)   // 偶数个
			{
				return (nums3[index - 1] + nums3[index]) / 2.0f;
			}
			else
			{
				return nums3[index];
			}
		}

		double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
		{
			int size1 = nums1.size();
			int size2 = nums2.size();

			if (size1 == 0 && size2 == 0)
			{
				return 0.0;
			}

			int count = (size1 + size2) / 2;
			if (0 == (size1 + size2) % 2)
			{
				count -= 1;
			}

			int start1 = 0, start2 = 0;
			int last1 = size1 - 1;
			int last2 = size2 - 1;

			while (count > 0)
			{
				if (start1 < last1 && start2 > last2)    // 第二个列表已经为空
				{
					start1++;
					last1--;
				}
				else if (start2 < last2 && start1 > last1)   // 第一个列表为空
				{
					start2++;
					last2--;
				}
				else
				{
					// 最大值
					int max1 = nums1[last1];
					int max2 = nums2[last2];

					// 最小值
					int min1 = nums1[start1];
					int min2 = nums2[start2];

					max1 > max2 ? last1-- : last2--;
					min1 < min2 ? start1++ : start2++;
				}

				count--;
			}

			int sum = 0;
			while (start1 <= last1)
			{
				sum += nums1[start1];
				start1++;
			}

			while (start2 <= last2)
			{
				sum += nums2[start2];
				start2++;
			}
			if (0 == (size1 + size2) % 2)
			{
				return sum / 2.0f;
			}
			else
			{
				return sum;
			}
		}

		static void Run()
		{
			Solution sol;
			vector<int> nums1 = { 5, 7 };
			vector<int> nums2 = { 6, 8, 11, 12 };
			cout << sol.findMedianSortedArrays2(nums1, nums2);
		}
	};
}

#endif
