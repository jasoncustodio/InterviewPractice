
#include "DataStructure.h"

int main()
{
	ListNode<int> * head = nullptr;

	LinkedListPractice driver;

	driver.append(head, 1);
	driver.append(head, 2);

	for (head; head; head = head->next)
		cout << head->value;

	return 0;
}

