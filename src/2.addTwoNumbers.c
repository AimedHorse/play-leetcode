/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};
/*
 * 思路：此问题容易出现遗漏的情况。注意仔细分析。
 * date: 2020年2月1日
 */
struct ListNode* my_addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* result = NULL;
	struct ListNode* entry = NULL;
	struct ListNode* tail = NULL;
	struct ListNode* left = l1;
	struct ListNode* right = l2;
	struct ListNode* bigger = NULL;
	int flag = 0;
	if (!l1 || !l2) {
		return NULL;
	}
	
	while (left && right) {
		entry = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (NULL == entry) {
			return NULL;
		}
		
		entry->val = left->val + right->val + flag;
		entry->next = NULL;
		flag = 0;
		
		if (entry->val > 9) {
			flag = 1;
			entry->val -= 10;
		}
		
		if (NULL == result) {
			result = entry;
		}

		if (NULL != tail) {
			tail->next = entry;
		}
		tail = entry;

		left = left->next;
		right = right->next;
	}

	if (left) {
		bigger = left;
	} else if (right) {
		bigger = right;
	}

	if ( bigger ) {
		while (bigger) {
			entry = (struct ListNode *)malloc(sizeof(struct ListNode));
			if (NULL == entry) {
				return NULL;
			}

			entry->val = bigger->val + flag;
			entry->next = NULL;
			flag = 0;

			if (entry->val > 9) {
				flag = 1;
				entry->val -= 10;
			}

			if (NULL == result) {
				result = entry;
			}

			if (NULL != tail) {
				tail->next = entry;
			}
			tail = entry;

			bigger = bigger->next;
		}
	}

	if (flag) {
		entry = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (NULL == entry) {
			return NULL;
		}

		entry->val = 1;
		entry->next = NULL;
		if (NULL != tail) {
			tail->next = entry;
		}
		tail = entry;
	}

	return result;
}

/*
 * 心的：利用一个空的数据结构来提供便利
 */
struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *next1, *next2, *result, *res;
    int pending = 0;
    int val1 = 0;
    int val2 = 0;

    next1 = l1;
    next2 = l2;
    res = result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = NULL;
    struct ListNode zero = {.val = 0, .next=NULL};

    while (next1->next || next2->next) {
        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        val1 = next1->val;
        val2 = next2->val;

        if (next1->next) 
            next1 = next1->next;
        else
            next1 = &zero;

        if (next2->next)
            next2 = next2->next;
        else
            next2 = &zero;
    
        result->val = (val1 + val2 + pending) % 10;
        printf("debug:%d\n", result->val);
        if (val1 + val2 + pending >= 10)
            pending = 1;
        else
            pending = 0;

        result = result->next;
        result->val = 0;
        result->next = NULL;
    }

    result->val = (next1->val + next2->val + pending) % 10;
    printf("debug1:%d\n", result->val);
    if (next1->val + next2->val + pending >= 10) {
        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result->next->val = 1;
        result->next->next = NULL;
    }

    return res;
}



/*
 * 心的：先将所有计算计算完毕，最后进行调整进位的操作
 */
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2){
	if(l1==NULL && l2==NULL){return l1;}


	struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->next=NULL;
	struct ListNode* sum=head;
	struct ListNode* add;

	struct ListNode* p1=l1;
	struct ListNode* p2=l2;

	while(p1!=NULL && p2!=NULL){
		add=(struct ListNode*)malloc(sizeof(struct ListNode));
		add->val=p1->val + p2->val;
		add->next=NULL;
		sum->next=add;
		//printf("sum=%d",sum->next->val);
		sum=sum->next;
		p1=p1->next;
		p2=p2->next;
	}

    sum->next = (p1!=NULL) ? p1:p2;

    struct ListNode* headnew=head->next;

    while(headnew->next != NULL){
        if(headnew->val >=10){
            headnew->val=headnew->val - 10;
            headnew->next->val=headnew->next->val + 1;
        }else{
            headnew=headnew->next;
        }
    }

    if(headnew->val >= 10){
        headnew->val=headnew->val - 10;
        add=(struct ListNode*)malloc(sizeof(struct ListNode));
        add->val=1;
        add->next=NULL;
        headnew->next=add;
    }  

	return head->next;

}

