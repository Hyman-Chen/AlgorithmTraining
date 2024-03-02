//
//  main.c
//  1
//
//  Created by Hyman on 2024/3/1.
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

/* 1 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    for (i=0;i<numsSize;i++){
        for (j=i+1;j<numsSize;j++){
            if (nums[i] + nums[j] == target){
                int*result = malloc(sizeof(int)*2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

/* 2 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 
 请你将两个数相加，并以相同形式返回一个表示和的链表。

 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ptr1 = l1, *ptr2 = l2,*head = NULL,*tail = NULL;
    int jinwei = 0;
    while (ptr1 || ptr2){
        int n1 = ptr1?ptr1->val:0;
        int n2 = ptr2?ptr2->val:0;
        int sum = n1 + n2 +jinwei;
        if (!head){
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            head->next = NULL;
            head->val = sum % 10;
            tail = head;
        } else {
            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = sum % 10;
            tail->next = NULL;
        }
        jinwei = sum / 10;
        if (ptr1) ptr1 = ptr1->next;
        if (ptr2) ptr2 = ptr2->next;
    }
    if (jinwei >= 1){
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail->next->val = jinwei;
        tail->next->next = NULL;
    }
    return head;
}
// 插入函数
void Insert(List *L,int X){
    List Tmp = (List)malloc(sizeof(struct ListNode));
    Tmp->next = *L;
    Tmp->val = X;
    *L = Tmp;
}
int main(int argc, const char * argv[]) {
//    int nums[4] = {2,7,11,15};
//    int target = 9;
//    int *returnSize = (int*)malloc(sizeof(int));
//    int *sum = twoSum(nums, 4, target, returnSize);
//    for (int i=0;i<*returnSize;i++)
//        printf("%d\n",nums[i]);
//
    List l1,l2;
    l1 = NULL;
    l2 = NULL;
    Insert(&l1,3);
    Insert(&l1,4);
    Insert(&l1,6);
    Insert(&l1,7);
    List L = l1;
    while (L){
        printf("%d",L->val);
        L = L->next;
    }
    Insert(&l2,9);
    Insert(&l2,1);
    Insert(&l2,6);
    List L2= l2;
    printf("\n");
    while (L2){
        printf("%d",L2->val);
        L2 = L2->next;
    }
    printf("\n");
    List returnList = addTwoNumbers(l1,l2);
    while (returnList){
        printf("%d",returnList->val);
        returnList = returnList->next;
    }
    printf("\n");

    return 0;
}
