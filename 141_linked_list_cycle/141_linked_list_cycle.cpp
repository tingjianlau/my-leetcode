/*************************************************************************
	> File Name: 141_linked_list_cycle.cpp
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
 
 /**
  * 使用两个指针: low fast
  * low指针每次向前移动一步，fast每次向前移动两步
  * 如果链表中某个位置存在循环，则low指针肯定能追的上fast指针
  * 否则，fast指针将很快到达链表的尾部
  */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true; // has a cycle
        }
        
        return false; // no cycle
    }
};

