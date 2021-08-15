    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 第一种方法 用哈希表将链表存储起来，然后遍历第链表，第一个重复的值就是相交起始节点
        // unordered_map<ListNode*, int>map;
        // ListNode *tmp = headA;
        // while(tmp != NULL){
        //     map.insert(make_pair(tmp, 1));
        //     tmp = tmp->next;
        // }
        // while(headB != NULL){
        //     if(map.find(headB) != map.end()){
        //         return headB;
        //     }
        //     headB = headB->next;
        // }
        // return NULL;
        //------------------
        // 第二种方案 采用答案所给的双指针，不得不说，太秀了
        if(headB == NULL || headA == NULL){
            return NULL;
        }
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != NULL || pb != NULL){
            if(pa == pb){
                return pa;
            }
            if(pa == NULL){
                pa = headB;
            }else{
                pa = pa->next;
            }

            if(pb == NULL){
                pb = headA;
            }else{
                pb = pb->next;
            }
        }
        return NULL;
    }