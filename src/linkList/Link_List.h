#ifndef _LINK_LIST_
#define _LINK_LIST_

#include <iostream>

struct List_Node
{
    int value;
    List_Node *next;

    List_Node() : value(0), next(nullptr) {}
    List_Node(int x) : value(x), next(nullptr) {}
    List_Node(int x, struct List_Node *next) : value(x), next(next) {}
};

/**
 * 创建新链表 Creat_New_List
 * @param _head_node 链表头节点指针的引用
 * @param _head_value 头节点的值
 * 
 * @return 返回链表头节点的指针
*/
List_Node *Creat_New_List(List_Node * &_head_node, int _head_value);

/**
 * 从尾部追加节点
 * @param _head_node 链表头节点指针的引用
 * @param _node_value 新节点的值
 * 
 * @return non-return
*/
void Add_Node(List_Node *&_head_node, int _node_value);

/**
 * 在值为 _node_value 的节点之后的位置插入新节点
 * @param _head_node 链表头节点指针的引用
 * @param _node_value 目标节点值，我们要在表中搜索这个值，并在这个节点后插入新节点
 * @param _new_value  要插入的新节点的值
 * 
 * @return bool type 判断是否插入成功
*/
bool Insert_Node(List_Node * &_head_node, int _node_value, int _new_value);

/**
 * @brief 查询目标链表中是否含有目标值的节点，若有则返回该节点的地址，若没有则返回空。
 * 
 * @param __head_node  链表头节点指针的引用
 * @param __find_value 要查询的目标值
 * 
 * @return 若有则返回该节点的地址，若没有则返回空
*/
List_Node * Find_Node(List_Node * &__head_node, const int __find_value);

/**
 * 通过节点值删除目标节点 Delete_Node
 * 
 * @param _target 目标节点值
 * 
 * @return bool type 判断是否删除成功
*/
bool Delete_Node(List_Node *&_head_node, int _target);

/**
 * 打印链表值
 * 
 * @param _head_node 链表头节点指针的引用
 * 
 * @return no return
*/
void Print_Node(List_Node *&_head_node);

/**
 * 删除整个链表
 * 
 * @param _head_node 链表头节点指针的引用
 * 
 * @return no return
*/
void Free_Resource(List_Node * &_head_node);

#endif