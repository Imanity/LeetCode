#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;
		ListNode* ptr = NULL;
		int carry = 0;
		bool l1NotEnd = true, l2NotEnd = true;
		while (l1NotEnd || l2NotEnd) {
			int tmp = carry;
			if (l1NotEnd) {
				tmp += l1->val;
				l1 = l1->next;
				if (l1 == NULL)	{
					l1NotEnd = false;
				}
			}
			if (l2NotEnd) {
				tmp += l2->val;
				l2 = l2->next;
				if (l2 == NULL)	{
					l2NotEnd = false;
				}
			}
			if (tmp >= 10) {
				carry = 1;
				tmp -= 10;
			} else {
				carry = 0;
			}
			if (ptr == NULL) {
				ptr = new ListNode(tmp);
				result = ptr;
			} else {
				ListNode *tmpNode = new ListNode(tmp);
				ptr->next = tmpNode;
				ptr = tmpNode;
			}
		}
		if (carry == 1) {
			ListNode *tmpNode = new ListNode(1);
			ptr->next = tmpNode;
			ptr = tmpNode;
		}
		return result;
	}
};

int main() {
	return 0;
}
