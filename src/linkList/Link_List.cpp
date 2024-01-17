#include "Link_List.h"

List_Node *Creat_New_List(List_Node * &_head_node, int _head_value)
{
    _head_node = new List_Node(_head_value);

    return _head_node;
}

void Add_Node(List_Node * &_head_node, int _node_value)
{
    List_Node *new_node = new List_Node(_node_value);

    if (_head_node == nullptr) { _head_node = new_node; }
    else
    {
        List_Node *temp_node = _head_node;

        while (temp_node->next != nullptr)
        {
            temp_node = temp_node->next;
        }
        temp_node->next = new_node;
    }
}

bool Insert_Node(List_Node * &_head_node, int _node_value, int _new_value)
{
    List_Node *new_node = new List_Node(_new_value);

    /*指向目标节点的指针*/
    List_Node *pre = _head_node;

    /*搜索整个表，找到这个节点的指针*/
    while (pre != nullptr && pre->value != _node_value)
    {
        pre = pre->next;
    }

    /*找不到就报错*/
    if (pre == nullptr)
    {
        std::fprintf(stderr, "Node NOT FOUND Value: %d\n", _node_value);
        return false;
    }

    new_node->next = pre->next;
    pre->next = new_node;

    if (pre == _head_node) { _head_node = new_node; }

    return true;
}

List_Node * Find_Node(List_Node * &__head_node, const int __find_value)
{
    if (!__head_node ||  __head_node->value == __find_value) { return __head_node; }

    if (auto targetPointer = Find_Node(__head_node->next, __find_value)) { return targetPointer; }

    return nullptr;
}

bool Delete_Node(List_Node * &_head_node, int _target)
{
    /*首先头节点不得为空*/
    if (_head_node == nullptr) { return false; }

    /*
        如果要删除头节点会丢失整个表，
        因此需要将下一个节点变成新头节点，
        再删除原头节点
    */
    if (_head_node->value == _target)
    {
        List_Node *temp = _head_node;
        _head_node = _head_node->next;

        delete temp;

        return true;
    }

    List_Node *current_node = _head_node;
    List_Node *prev = nullptr;

    /*搜索整个链表*/
    while (current_node->value != _target && current_node != nullptr)
    {
        prev = current_node;
        current_node = current_node->next;
    }

    /*处理找不到的情况*/
    if (current_node == nullptr) { return false; }

    prev->next = current_node->next;
    delete current_node;

    return true;
}

void Print_Node(List_Node *&_head_node)
{
    List_Node *current_node = _head_node;
    size_t node_count = 0;

    while (current_node != nullptr)
    {
        std::cout << current_node->value << '\t';
        current_node = current_node->next;
        ++node_count;
    }
    std::cout << "[" << node_count << "] nodes." << std::endl;
}

void Free_Resource(List_Node * &_head_node)
{
    if (_head_node != nullptr)
    {
        List_Node * current_node = _head_node;

        while (current_node != nullptr)
        {
            List_Node *temp = current_node;
            current_node = current_node->next;
            delete temp;
        }

        _head_node = nullptr;
    }
}