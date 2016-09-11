/**
Description: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Date: 2016/08/20
*/

#ifndef __REMOVENTHFROMEND_H__
#define __REMOVENTHFROMEND_H__

#include <iostream>
using namespace std;

namespace RemoveNthFromEnd
{
	struct ListNode{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr){}
	};
	class Solution
	{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n)
		{
			ListNode *fast = head;
			ListNode *slow = head;
			while (n--)
			{
				fast = fast->next;
			}

			if (fast == nullptr)
			{
				return head->next;
			}

			while (fast->next != nullptr)
			{
				fast = fast->next;
				slow = slow->next;
			}

			slow->next = slow->next->next;
			return head;
		}
		
		static void Run()
		{
			Solution sol;
			ListNode *head = nullptr;
			ListNode *node = nullptr;

			for (int i = 0; i < 10; ++i)
			{
				ListNode *tmp = new ListNode(i+1);
				if (i == 0)
				{
					node = tmp;
					head = node;
				}
				else
				{
					node->next = tmp;
					node = tmp;
				}
			}

			// print
			ListNode *result = sol.removeNthFromEnd2(head, 1);
			while (result != nullptr)
			{
				cout << result->val << ends;
				result = result->next;
			}
		}
	};
}

#endif