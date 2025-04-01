#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Create an empty queue */
struct list_head *q_new()  // 建立新的「空」佇列
{
    struct list_head *new_qhead = malloc(sizeof(struct list_head));
    if (!new_qhead)  // malloc失敗
        return NULL;
    INIT_LIST_HEAD(new_qhead);  // 初始化一個空的循環雙向鏈表
    return new_qhead;
}

/* Free all storage used by queue */
void q_free(
    struct list_head *l)  // 釋放佇列所佔用的記憶體(包括所有節點以及佇列頭)
{
    if (!l)
        return;  // 鏈表不存在 不做後續操作

    element_t *entry,
        *safe;  // entry當前元素
                // //safe是entry的下一個節點(避免之後無法訪問下一個節點)
    list_for_each_entry_safe(entry, safe, l, list) {
        free(entry->value);
        free(entry);
    }

    INIT_LIST_HEAD(l);  // 清空 list，確保指標不指向已釋放的記憶體
    free(l);            // 釋放 list_head 本身
}

static inline element_t *e_new(
    char *s)  // 創建並初始化一個新的元素（element_t）
{
    if (!s)
        return NULL;

    element_t *new_e = malloc(sizeof(element_t));
    if (!new_e)
        return NULL;
    INIT_LIST_HEAD(&new_e->list);

    size_t slen = strlen(s) + 1;
    new_e->value = malloc(slen);
    if (!new_e->value) {
        free(new_e);
        return NULL;
    }
    memcpy(new_e->value, s, slen);

    return new_e;
}

/* Insert an element at head of queue */
bool q_insert_head(
    struct list_head *head,
    char *s)  // 在佇列開頭 (head) 插入 (insert) 給定的新節點 (以 LIFO 準則);
{
    if (!head || !s)
        return false;
    element_t *new_e = e_new(s);
    if (!new_e)
        return false;
    list_add(&new_e->list, head);
    return true;
}


/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    if (!head || !s)  // 檢查是否為 NULL
        return false;

    element_t *new_e = e_new(s);  // 創建新節點
    if (!new_e)
        return false;

    list_add_tail(&new_e->list, head);  // 插入到鏈結串列的尾端
    return true;
}


/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    return NULL;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    return NULL;
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if (!head)
        return 0;

    int len = 0;
    struct list_head *li;

    list_for_each(li, head)
        len++;
    return len;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
