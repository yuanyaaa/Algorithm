ListNode* reverseList(ListNode* head) {
        // 采用三个指针循环替换即可，思路比较简单
        if(head == nullptr){
            return head;
        }
        ListNode *first = nullptr;
        ListNode *second = head;
        ListNode *tmp = nullptr;
        while(second != nullptr){
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        return first;
   }