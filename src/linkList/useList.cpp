#include "./Link_List.h"

int main(int argc, char const *argv[])
{
    int array[6] = {1323, 314, 13, 15, 8356, 425};

    List_Node * headNode = Creat_New_List(headNode, *array);

    for (int index = 1; index < 6; ++index)
    {
        Add_Node(headNode, array[index]);
    }

    Print_Node(headNode);

    List_Node * targetNode = Find_Node(headNode, 425);

    if (targetNode) 
    { 
        printf("Find Node, Address: %p\n", targetNode);
        targetNode->value /= 2;
    }
    else
    {
        printf("The Node is not exist in this List.\n");
    }

    Print_Node(headNode);

    Free_Resource(headNode);
    return 0;
}


