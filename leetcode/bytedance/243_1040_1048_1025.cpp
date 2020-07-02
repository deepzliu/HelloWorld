#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode *fast = head, *slow = head;
		ListNode *mid = slow;
		while(fast)
		{
			if(fast->next == NULL) break;
			mid = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *right = slow;
		if(slow->next)
		{
			right = sortList(slow);
		}

		mid->next = NULL;
		ListNode *left = head;
		if(head->next)
		{
			left = sortList(head);
		}

		return mergeTwoLists(left, right);
    }

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) return NULL;
		ListNode *result = lists[0];
		for(int i = 1; i < lists.size(); i++)
		{
			result = mergeTwoLists(result, lists[i]);
		}
		return result;
    }

	ListNode *mergeTwoLists(ListNode *left, ListNode *right)
	{
		ListNode *p = left, *q = right;
		ListNode *result = NULL, *tail = NULL;
		while(p && q)
		{
			if(p->val < q->val)
			{
				if(result == NULL)
				{
					result = p;
					tail = p;
				}
				else
				{
					tail->next = p;
					tail = tail->next;
				}
				p = p->next;
			}
			else
			{
				if(result == NULL)
				{
					result = q;
					tail = q;
				}
				else
				{
					tail->next = q;
					tail = tail->next;
				}
				q = q->next;
			}
		}

		if(p)
		{
			if(result == NULL) result = p;
			else tail->next = p;
		}

		if(q)
		{
			if(result == NULL) result = q;
			else tail->next = q;
		}

		return result;
	}

	static void print(ListNode *head)
	{
		ListNode *p = head;
		//cout << "List: ";
		while(p)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	ListNode *head = NULL, *tail = NULL, *p = NULL;
	int n = argc;
	for(int i = 1; i < n; i++)
	{
		int num = atoi(argv[i]);
		p = new ListNode(num);
		if(head == NULL)
		{
			head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	
	cout << "origianl: ";
	Solution::print(head);
    p =  so.sortList(head);

	cout << "result: ";
	Solution::print(p);

	//cout << "result: " << result << endl;
}
