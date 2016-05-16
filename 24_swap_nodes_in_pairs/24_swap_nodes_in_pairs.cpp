/*************************************************************************
	> File Name: 24_swap_nodes_in_pairs.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p;
        ListNode* dummy = new ListNode(0); // 虚拟头结点
        
        dummy->next = head;
        p = dummy;
        
        while(head && head->next){
            p->next = head->next;
            head->next = p->next->next;
            p->next->next = head;
            
            // 更新指针
            p = head;
            head = head->next;  // 注意不是head = head->next->next; 因为此时head指向交换后的后一个node
        }
        
        return dummy->next;
    }
};

