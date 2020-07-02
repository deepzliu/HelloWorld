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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *result = NULL;
    	int cntA = coutList(headA);
    	int cntB = coutList(headB);

		ListNode *pA = headA;
		ListNode *pB = headB;
		while(cntA > cntB)
		{
			cntA--;
			pA = pA->next;
		}
		while(cntB > cntA)
		{
			cntB--;
			pB = pB->next;
		}

		while(pA && pB)
		{
			if(pA == pB)
			{
				result = pA;
				break;
			}
			else
			{
				pA = pA->next;
				pB = pB->next;
			}
		}

		return result;
    }

	int coutList(ListNode *head)
	{
		int cnt = 0;
		ListNode *p = head;
		while(p)
		{
			cnt++;
			p = p->next;
		}
		return cnt;
	}

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

void test1(ListNode **headA, ListNode **headB)
{
	ListNode *p, *tailA, *tailB;
	ListNode *x;

	p = new ListNode(4);
	*headA = p;
	tailA = p;
	p = new ListNode(1);
	tailA->next = p;
	tailA = p;
	p = new ListNode(8);
	tailA->next = p;
	tailA = p;
	x = p;
	p = new ListNode(4);
	tailA->next = p;
	tailA = p;
	p = new ListNode(5);
	tailA->next = p;
	tailA = p;

	p = new ListNode(5);
	*headB = p;
	tailB = p;
	p = new ListNode(0);
	tailB->next = p;
	tailB = p;
	p = new ListNode(1);
	tailB->next = p;
	tailB = p;

	tailB->next = x;
	tailB = x;
	//p = new ListNode(8);
	//tailB->next = p;
	//tailB = p;
	//p = new ListNode(4);
	//tailB->next = p;
	//tailB = p;
	//p = new ListNode(5);
	//tailB->next = p;
	//tailB = p;
}
	
int main(int argc, char *argv[])
{
	Solution so;
	ListNode *headA = NULL, *headB = NULL;

	test1(&headA, &headB);

	Solution::print(headA);
	Solution::print(headB);

    ListNode *p =  so.getIntersectionNode(headA, headB);
	if(p)
	{
		cout << "result: " << p->val << endl;
	}
	else
	{
		cout << "result: null" << endl;
	}

	Solution::print(headA);
	Solution::print(headB);

	//cout << "result: " << result << endl;
}
