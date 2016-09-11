/**
Description: https://leetcode.com/problems/add-two-numbers/
Date: 2016/07/14
*/

#ifndef __ADDTWONUMBERS_H__
#define __ADDTWONUMBERS_H__

#include <iostream>
#include <vector>
#include <random>

namespace AddTwoNumbers
{
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr){}
	};

	class Solution
	{
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			ListNode *head, **r = &head;

			int carry = 0;
			for (; l1 != nullptr || l2 != nullptr;)
			{
				int val = 0;
				int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + carry;
				val = sum % 10;

				carry = sum / 10;

				ListNode *node = new ListNode(val);
				*r = node;
				r = &node->next;

				l1 = l1 != nullptr ? l1->next : nullptr;
				l2 = l2 != nullptr ? l2->next : nullptr;
			}

			if (carry > 0)
			{
				ListNode *node = new ListNode(carry);
				*r = node;
			}

			return head;
		}

		static void Release(ListNode *l)
		{
			for (; l != nullptr;)
			{
				ListNode *last = l;
				l = l->next;
				delete last;
			}
		}

		static void Create(ListNode **l, std::vector<int> v)
		{
			ListNode* cur = nullptr;
			for (int i = 0; i < v.size(); ++i)
			{
				if (0 == i)
				{
					cur = new ListNode(v[i]);
					*l = cur;
				}
				else
				{
					cur->next = new ListNode(v[i]);
					cur = cur->next;
				}
			}
		}

		static void Print(ListNode *l)
		{
			for (; l != nullptr;)
			{
				std::cout << l->val << ' ';
				l = l->next;
			}
			std::cout << '\n';
		}

		static std::vector<int> GetTestCase()
		{
			std::random_device rd;
			std::vector<int> result;
			for (int i = 0; i < 10; ++i)
			{
				result.push_back(rd() % 10);
			}
			return result;
		}

		static void Run()
		{
			std::vector<int> v1 = GetTestCase();
			std::vector<int> v2 = GetTestCase();
			ListNode *l1 = nullptr;
			ListNode *l2 = nullptr;
			Create(&l1, v1);
			Create(&l2, v2);

			Solution sol;
			ListNode* r = sol.addTwoNumbers(l1, l2);

			Print(l1);
			Print(l2);
			Print(r);

			Release(l1);
			Release(l2);
			Release(r);
		};

	};
}

#endif