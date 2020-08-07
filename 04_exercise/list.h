#ifndef __KERNEL_LIST_H__
#define __KERNEL_LIST_H__

#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

struct list_head
{
    struct list_head *next,*prev;
};

#define INIT_LIST_HEAD(ptr) do{\
    (ptr)->next = (ptr);(ptr)->prev = (ptr);\
}while(0)

static inline void __list_add(struct list_head *new,
                struct list_head *prev,
                struct list_head *next)
{
    next->prev = new;
    new->next = next;
    prev->next = new;
    new->prev = prev;
}

static inline void list_add(struct list_head *new,struct list_head *head)
{
    __list_add(new,head,head->next);
}

static inline void list_add_tail(struct list_head *new,struct list_head *head)
{
    __list_add(new,head->prev,head);
}

static inline void __list_del(struct list_head *prev,struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}





