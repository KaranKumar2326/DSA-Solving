class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL || list2==NULL)
            return (list1 == NULL)?list2:list1;
        
        ListNode* headA = NULL;
        if(list1->val < list2->val)
        {
            headA = list1;
            list1 = list1->next;
        }
        else
        {
            headA = list2;
            list2 = list2->next;
        }
        
        ListNode* tmp = headA;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val < list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;  
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }

        if(list1 == NULL)
            tmp->next = list2;
        else
            tmp->next = list1;
        
        return headA;
    }
};