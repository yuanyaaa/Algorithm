    bool isPalindrome(ListNode* head) {
        // 暴力， 将链表所有的值用数组保存，然后对数组进行查找
        // 还有比较牛的方法，比如快慢指针找中间，然后反转后半部分
        // 再例如采用递归的手段，通过节点是否未null作为末尾的信号，依次向前判断，但是这样栈的开销依然很大
        vector<int> nodeList;
        ListNode* node = head;
        while(node != nullptr){
            nodeList.push_back(node->val);
            node = node->next;
        }
        // 此处用for循环会更加简单，初始化front和end，然后每次end--，front++
        int front, end;
        front = 0;
        end = nodeList.size() - 1;
        while(end > front){
            if(nodeList.at(front) != nodeList.at(end)){
                return false;
            }
            front++;
            end--;
        }
        return true;
    }