/*************************************************************************
	> File Name: 83_remove_duplicates_from_sorted_list.cpp
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        
        while(p){
            if(!p->next) break; // 在while内进行判断可以省去判断链表为空的情况
            
            if(p->val == p->next->val){ // 这种写法可以避免申请两个节点指针
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        
        return head;
    }
};

