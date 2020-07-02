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
    ListNode* reverseList(ListNode* head) {

		ListNode *result = NULL;
		ListNode *p = head, *q = NULL;
		while(p)
		{
			if(result == NULL)
			{
				result = p;
				p = p->next;
				result->next = NULL;
			}
			else
			{
				q = p;
				p = p->next;
				q->next = result;
				result = q;
			}
		}
		return result;
    }

	static void print(ListNode *head)
	{
		ListNode *p = head;
		cout << "List: ";
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
	
	Solution::print(head);
    p =  so.reverseList(head);
	Solution::print(p);

	//cout << "result: " << result << endl;
}


