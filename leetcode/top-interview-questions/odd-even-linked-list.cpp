#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *odd = head, *even = head->next;
        ListNode *fast = head->next->next;
        ListNode *q = NULL;
        while(fast != NULL)
        {
            cout << "val: " << fast->val << endl;
            q = fast;
            fast = fast->next;
            
            q->next = odd->next;
            odd->next = q;
            odd = q;
            
            if(fast)
            {
                cout << "val: " << fast->val << endl;
                q = fast;
                fast = fast->next;
                q->next = NULL;
                even->next = q;
                even = q;
            }
			else
			{
				even->next = NULL;
			}
        }
        return head;
    }
};

void print(ListNode *head)
{
	ListNode *p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Solution so;

	ListNode *head = new ListNode(1);
	ListNode *p = new ListNode(2);
	head->next = p;
	p = new ListNode(3);
	head->next->next = p;

	print(head);

	head = so.oddEvenList(head);
	print(head);
}
