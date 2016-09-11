#ifndef __LONGESTPALINDROME_H__
#define __LONGESTPALINDROME_H__

/**
Description: https://leetcode.com/problems/longest-palindromic-substring/
Date: 2016/08/08
**/

#include <string>

using namespace std;

namespace LongestPalindrome
{
	class Solution
	{
	public:
		string longestPalindrome(string s) {
			int size = s.size();
			int maxLen = 0;
			int maxStart = 0;
			int maxEnd = 0;
			int tempStr[256] = { 0, };

			for (int i = 0; i < size; ++i)
			{
				int end = size - 1;
				int pos;
				if ((end - i + 1) < maxLen)
				{
					break;
				}

				while ((pos = s.find_last_of(s[i], end)) != string::npos)
				{
					// 先判断后面的比较是否有意义
					if ((pos - i + 1) < maxLen)
					{
						break;
					}

					int j = 0;
					int flag = true;
					while ((i + j) <= (pos - j))
					{
						if (s[i + j] != s[pos - j])
						{
							flag = false;
							break;
						}
						j++;
					}

					if (flag)
					{
						if ((pos - i + 1) > maxLen)
						{
							maxLen = pos - i + 1;
							maxStart = i;
							maxEnd = pos;
						}

						break;
					}

					end = pos - 1;
				}
			}

			return s.substr(maxStart, maxEnd - maxStart + 1);
		}

		string longestPalindrome2(string s) {
			int left, right;
			int maxleft = 0, maxlen = 0;
			int start = 0;
			int size = s.size();

			if (size < 2)
				return s;

			while (start < size)
			{
				left = right = start;

				// 处理重复数
				while (right < size-1 && s[right] == s[right+1])
				{
					right++;
				}

				start = right + 1;

				while (left > 0 && right < size-1 && s[left-1] == s[right+1])
				{
					left--;
					right++;
				}

				while (maxlen < (right - left + 1))
				{
					maxleft = left;
					maxlen = right - left + 1;
				}

			}

			return s.substr(maxleft, maxlen);
		}

		static void Run()
		{
			Solution sol;
			//cout << sol.longestPalindrome2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			cout << sol.longestPalindrome2("bananas");
		}
	};
}

#endif
