/**
Description: https://leetcode.com/problems/zigzag-conversion/
Date: 2016/07/14
*/

#ifndef __ZIGZAGCONVERSION_H__
#define __ZIGZAGCONVERSION_H__

#include <string>
#include <iostream>

using namespace std;

namespace ZigZagConversion
{
	class Solution
	{
	public:
		string convert(string s, int numRows)
		{
			int newLines = 0;
			string result;
			for (auto ch : s)
			{
				if (!isblank(ch) && ch != '\n')
				{
					result += ch;
				}
				if (ch == '\n')
				{
					newLines++;
				}
				if (newLines == numRows)
				{
					break;
				}
			}

			return result;
		}

		string convert2(string s, int numRows)
		{

		}

		static void Run()
		{
			Solution sol;
			cout << sol.convert("P A   H N \n A P L S I I G\n Y     I R", 3);
		}
	};
}

#endif
