/*************************************************************************
	> File Name: 21_merge_two_sorted_lists.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // 将两个链表合并到新的链表中，需要申请一个新的节点
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));  // 新建一个头结点，指向构造的新链表
    struct ListNode* p= head;
    
    while(l1 && l2){
        if(l1->val < l2->val){  // 取值较小的节点插入新链表中
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    p->next = l1 ? l1 : l2;     // 剩余原链表节点的处理
    
    return head->next;
}

 // 将两个链表合并到新的链表中，不需要申请新的节点
struct ListNode* mergeTwoLists_2(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* p= NULL;
    
    if(!l1 && !l2) return NULL;
    if(!l1 && l2) return l2;
    if(l1 && !l2) return l1;
    
    while(l1 && l2){
        if(l1->val < l2->val){  // 取值较小的节点插入新链表中
            if(head){
                p->next = l1;
            }else{  // head还没定义时
                head = l1;
            }
            p = l1;
            l1 = l1->next; 
        }else{
            if(head){
                p->next = l2;
            }else{  // head还没定义时
                head = l2;
            }
            p = l2;
            l2 = l2->next; 
        }
    }
    p->next = l1 ? l1 : l2;     // 剩余原链表节点的处理

    return head;
}

