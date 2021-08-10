   // 双指针：fast指针每次走两步，slow指针每次走一步，如果有环，则一定会相遇。
    // 如果相遇，slow从头开始，fast从相遇点开始继续走，再次相遇点即环的入口，这个可以通过数学进行证明
    ListNode *detectCycle(ListNode *head) {
 		ListNode *fast = head;
		ListNode *slow = head;
        // 判断是否有环
		do{
			if(fast == NULL || fast->next == NULL || fast->next->next == NULL){
				return NULL;
			}else{
				fast = fast->next->next;
				slow = slow->next;
                // std::cout << 1;
			}
		}while(fast != slow);

        // 寻找环的位置
		slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;       
    }