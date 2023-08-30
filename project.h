#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>

#include "platform_types.h"

#define ZERO_INIT 0
#define ZERO      0


#define STACK_MAX_SIZE 5

#define STACK_DEBUG


typedef enum
{
    EMPTY,
    FULL,
    NOT_FULL,
    R_NOK,
    R_OK,
    NULL_Ptr
}Return_Status_t;

typedef struct
{
    void **Array  ;       /*Points to the array that allocated in the heap  */
    uint32 Elementcount;  /*Has the actual number of element in the array   */
    sint32 ArrayMaxSize;
    uint32 Array_Pointer;
}Array_t;

typedef struct
{
    sint32 stack_Pointer;
    uint32 Data[STACK_MAX_SIZE];
}Stack_t;

typedef struct
{
    void **stackArray  ;  /*Points to the array that allocated in the heap  */
    uint32 Elementcount;  /*Has the actual number of element in the stack   */
    sint32 StackMaxSize;  /*Has the maximum number of elements in the stack */
    sint32 StackTop    ;  /*Has the index of the top element in the stack   */
}stack_DA_t;

struct node_S
{
    uint32 NodeData;
    struct node_S *Link_Of_List;
};
struct node_D
{
    uint32 NodeData;
    struct node_D *RightNodePtr;
    struct node_D *LiftNodePtr;
};

/*Normal Array*/
void Enter_Data_Of_Array(uint32 my_Array[], uint32 Length_Of_array);
Return_Status_t Delete_An_Element(uint32 my_Array[], uint32 Length_Of_array);
void Print_arr(uint32 my_Array[], uint32 Length_Of_array);
void Sum_Of_Array(uint32 my_Array[], uint32 Length_Of_array);
Return_Status_t Delete_duplicate_Elements(uint32 my_Array[], uint32 Length_Of_array);
void Get_Max_Num(uint32 my_Array[], uint32 Length_Of_array);
void Get_Min_Num(uint32 my_Array[], uint32 Length_Of_array);
void Sort_Array(uint32 my_Array[], uint32 Length_Of_array);
void Swap_Two_Numbers(uint32 *Npointer1, uint32 *Npointer2);
void Linear_Search_Array(uint32 my_Array[], uint32 Length_Of_array, uint32 Req_Data);
void Binary_Search_Array(uint32 my_Array[], uint32 s_Index, uint32 E_Index, uint32 Req_Data);



/*Dynamic array*/
Array_t *Array_Create(uint32 maxSize, Return_Status_t *ret_status);
Return_Status_t Array_Insert(Array_t *my_Array, uint32 value );
uint32 *Array_Delete(Array_t *my_Array, Return_Status_t *Ret_State);
Return_Status_t Array_Size(Array_t *my_Array, uint32 *Size);
Return_Status_t Array_Max(Array_t *my_Array);
Return_Status_t Array_Min(Array_t *my_Array);
Return_Status_t Array_Display(Array_t *my_Array);
Return_Status_t Array_Sorting(Array_t *my_Array);
Array_t *Destroy_Array(Array_t *Array_obj, Return_Status_t *Ret_state);
Return_Status_t Linear_Search_DArray(Array_t *my_Array, uint32 Req_Data);
Return_Status_t Binary_Search_DArray(Array_t *my_Array, uint32 s_Index, uint32 E_Index, uint32 Req_Data);


/*stack based on array */
Return_Status_t Stack_init(Stack_t *my_stack);
Return_Status_t Stack_Push(Stack_t *my_stack, uint32 value);
Return_Status_t Stack_Pop(Stack_t *my_stack, uint32 *value);
Return_Status_t Stack_Top(Stack_t *my_stack, uint32 *value);
Return_Status_t Stack_Size(Stack_t *my_stack, uint32 *Size);
Return_Status_t Stack_Display(Stack_t *my_stack);
Return_Status_t Stack_Get_Max(Stack_t *my_stack);
Return_Status_t Stack_Get_Min(Stack_t *my_stack);
Return_Status_t Stack_Sorting(Stack_t *my_stack);
Return_Status_t Binary_Search_Stack(Stack_t *my_stack, uint32 S_Index, uint32 E_Index, uint32 Req_Data);
Return_Status_t Linear_Search_Stack(Stack_t *my_stack, uint32 Req_Data);


/*stack based on dynamic array */
stack_DA_t *CreateStack(uint32 maxSize, Return_Status_t *ret_status);
stack_DA_t *Destroy_Stack(stack_DA_t *stack_obj, Return_Status_t *ret_status);
Return_Status_t PushStack(stack_DA_t *stack_obj, uint32 itemptr);
void *PopStack (stack_DA_t *stack_obj, Return_Status_t *ret_status);
void *StackTop (stack_DA_t *stack_obj, Return_Status_t *ret_status);
Return_Status_t StackSize(stack_DA_t *stack_obj, uint32 *stack_count);
Return_Status_t StackMax(stack_DA_t *stack_obj);
Return_Status_t StackMin(stack_DA_t *stack_obj);
Return_Status_t StackSorting(stack_DA_t *stack_obj);
Return_Status_t StackDisplay(stack_DA_t *stack_obj);
Return_Status_t Binary_Search_DA_Stack(stack_DA_t *stack_obj, uint32 S_Index, uint32 E_Index, uint32 Req_Data);

/*Queue*/

/*Single linked list */
void Insert_At_Beginning(struct node_S **Head_Of_List);
void Insert_At_End(struct node_S **Head_Of_List);
void Insert_Node(struct node_S *Head_Of_List);
void Delete_From_Beginning(struct node_S **Head_Of_List);
void Delete_Element(struct node_S *Head_Of_List);
void Get_Middle_Of_SList(struct node_S *Head_Of_List);
void Reverse_Nodes (struct node_S **Head_Of_List);
void Display_All_Nodes(struct node_S *Head_Of_List);
uint32 Get_Length (struct node_S *Head_Of_List);
void Rotate(struct node_S** head_ref, uint32 position);
void printNthFromLast( struct node_S* head, uint32 pos_Last);
struct node_S* Delete_Middle(struct node_S* head);
void swapKth_from_Begin_Last(struct node_S** head_ref, uint32 Pos_Last_Begin);
void Insertion_SSort(struct node_S** head);
void Searching(struct node_S* head, int searchData);
void pair_Wise_Swap(struct node_S **head);


/*Double linked list */
void Insert_Node_At_Beginning(struct node_D **Head, uint32 Data);
void Insert_Node_At_End(struct node_D *Head, uint32 Data);
void Insert_Node_After(struct node_D *Head, uint32 Data, uint32 Position);
void Insert_Node_Before(struct node_D *Head, uint32 Data, uint32 Position);
void Delete_Node_At_Beginning(struct node_D **Head);
void Delete_Node_At_End(struct node_D *Head);
void Delete_Node_At_Intermediate(struct node_D *Head, uint32 Position);
uint32 Get_Length_Of_List(struct node_D *Head);
void Get_Middle_Of_DList(struct node_D *Head);
void Reverse_List(struct node_D **Head);
void Display_All_Nodes_Forward(struct node_D *Head);
void Display_All_Nodes_Reverse(struct node_D *Head);
uint32 Search(struct node_D* head, int value);
void Insertion_DSort(struct node_D** head);
void Bubble_Sort(struct node_D** head);
#endif // PROJECT_H
