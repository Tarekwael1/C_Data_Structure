#include "project.h"

#define DELETE_NODE_AT_BEGINNING

static uint8 StackIsFull(stack_DA_t *stack_obj);
static uint8 StackIsEmpty(stack_DA_t *stack_obj);
static Return_Status_t ARRAYISFULL(Array_t *my_Array);
static Return_Status_t ARRAYISEMPTY(Array_t *my_Array);
static Return_Status_t STACK_IS_FULL(Stack_t *my_stack);
static Return_Status_t STACK_IS_EMPTY(Stack_t *my_stack);







/*Normal array*/

void Sum_Of_Array(uint32 my_Array[], uint32 Length_Of_array)
{
    uint32 sum = 0;
    uint32 counter = 0;
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        printf("\n");
        for(counter = 0; counter < Length_Of_array; counter++)
        {
            sum += my_Array[counter];
        }
        printf("Sum of array = %i \n\n",sum);
    }
}
Return_Status_t Delete_duplicate_Elements(uint32 my_Array[], uint32 Length_Of_array)
{
    Return_Status_t ret = R_NOK;
    uint32 i=0;
    uint32 j=0;
    uint32 val_dup = my_Array[0];
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        ret = NULL_Ptr;
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        ret = R_OK;
        for(i = 1; i < Length_Of_array; i++)
        {
            for(j = 0; j < i; j++)
            {
                if(my_Array[i] == my_Array[j])
                {
                    my_Array[j] = my_Array[j];
                    Length_Of_array--;
                }else{}
            }
        }
    }
}
void Enter_Data_Of_Array(uint32 my_Array[], uint32 Length_Of_array)
{
    uint32 counter = 0;
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        for(counter = 0; counter < Length_Of_array; counter++)
        {
            printf("Index [%i] = ",counter);
            scanf("%i",&my_Array[counter]);
        }
    }
}

Return_Status_t Delete_An_Element(uint32 my_Array[], uint32 Length_Of_array)
{
    Return_Status_t ret = R_NOK;
    uint32 i=0;
    uint32 pos;
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        ret = NULL_Ptr;
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        ret = R_OK;
        printf("Enter the position where you want to delete the element: ");
        scanf("%i",&pos);
        for(i = pos; i < Length_Of_array; i++)
        {
            my_Array[i-1] = my_Array[i];
        }
        my_Array[Length_Of_array-1] = 0;
    }
    return ret;
}

void Print_arr(uint32 my_Array[], uint32 Length_Of_array)
{
    int i = 0;
   if((NULL == my_Array) || (0 == Length_Of_array))
   {
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
   }
   else
   {
        printf("Array\n");
        for(i = 0; i < Length_Of_array; i++)
        {
            printf("-->[%i]", my_Array[i]);
        }
        printf("\n\n");
    }

}
void Get_Max_Num(uint32 my_Array[], uint32 Length_Of_array)
{
    uint32 max_num = 0;
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        max_num = my_Array[0];
        for(uint32 counter = 1; counter < Length_Of_array; counter++)
        {
            if(max_num < my_Array[counter])
            {
                max_num = my_Array[counter];
            }
        }
        printf("\nThe maximum number is %i \n",max_num);
    }
}
void Get_Min_Num(uint32 my_Array[], uint32 Length_Of_array)
{
    uint32 min_num = my_Array[0];
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        for(uint32 counter = 1; counter < Length_Of_array; counter++)
        {
            if(min_num > my_Array[counter])
            {
                min_num = my_Array[counter];
            }
        }
        printf("\nThe minimum number is %i \n",min_num);
    }
}

void Sort_Array(uint32 my_Array[], uint32 Length_Of_array)
{
    uint32 BS_Iteration = 0, Adjacent_Iteration = 0;
    uint32 Sort_Flag = 0;
    if((NULL == my_Array) || (0 == Length_Of_array))
    {
        printf("There is a problem (there is no array  or array is empty)\n");
        printf("You must quit the program and input a real size \n");
        exit(1);
    }
    else
    {
        for(BS_Iteration = 0; BS_Iteration < Length_Of_array-1; BS_Iteration++)
        {
            for(Adjacent_Iteration = 0; Adjacent_Iteration < Length_Of_array-1-BS_Iteration; Adjacent_Iteration++)
            {
                if(my_Array[Adjacent_Iteration] > my_Array[Adjacent_Iteration+1])
                {
                    Swap_Two_Numbers(&my_Array[Adjacent_Iteration], &my_Array[Adjacent_Iteration+1]);
                    Sort_Flag = 1;
                }
            }
            if(Sort_Flag == 0)
            {
                return;
            }
        }
    }
}

void Swap_Two_Numbers(uint32 *Npointer1, uint32 *Npointer2)
{
   uint32 Swap_var = *Npointer1;
   *Npointer1 = *Npointer2;
   *Npointer2 = Swap_var;
}

void Linear_Search_Array(uint32 my_Array[], uint32 Length_Of_array, uint32 Req_Data)
{
    int counter = 0;
    for(counter = 0; counter < Length_Of_array; counter++)
    {
        if(Req_Data == my_Array[counter])
        {
            printf("This value is in index ==> %i \n",counter);
            return;
        }
    }
    printf("Not found :( \n");
}

void Binary_Search_Array(uint32 my_Array[], uint32 S_Index, uint32 E_Index, uint32 Req_Data)
{
    int M_Index = 0;
    while(S_Index <= E_Index)
    {
        M_Index = S_Index + ((E_Index - S_Index)/2);

        if(Req_Data == my_Array[M_Index])
        {
            printf("This value is in index ==> %i \n",M_Index);
            return;
        }
        else if(Req_Data > my_Array[M_Index])
        {
            S_Index = M_Index + 1;
        }
        else
        {
            E_Index = M_Index - 1;
        }
    }
    printf("NOT FOUND :( \n");


}





/*Dynamic array*/

static Return_Status_t ARRAYISFULL(Array_t *my_Array)
{
    return (my_Array->Elementcount == my_Array->ArrayMaxSize);
}

static Return_Status_t ARRAYISEMPTY(Array_t *my_Array)
{
    return (my_Array->Elementcount == 0);
}


Array_t *Array_Create(uint32 maxSize, Return_Status_t *ret_status)
{
    Array_t *Localptr = NULL;
    if(!ret_status)
    {
        printf("Create has error !!\n");
        *ret_status = NULL_Ptr;
    }
    else
    {
        Localptr = (Array_t *)malloc(sizeof(Array_t));
        if(!Localptr)
        {
            printf("Malloc can't allocate the array !!\n");
            *ret_status = NULL_Ptr;
            Localptr = NULL;
        }
        else
        {
            Localptr->Elementcount = 0;
            Localptr->Array_Pointer = -1;
            Localptr->ArrayMaxSize = maxSize;
            Localptr->Array = (void **)calloc(Localptr->ArrayMaxSize, sizeof(void *));
            if(!Localptr->Array)
            {
                free(Localptr);
                Localptr = NULL;
                *ret_status = NULL_Ptr;
                printf("Calloc can't allocate the array !!\n");
            }
            else
            {
                *ret_status = R_OK;;
            }
        }
    }
    return Localptr;   //address of the first element
}

Return_Status_t Array_Insert(Array_t *my_Array, uint32 value )
{
    Return_Status_t ret = R_NOK;
    if(NULL == my_Array)
    {
        printf("Insert has error !! :(\n");
        ret = NULL_Ptr;
    }
    else
    {
        if(ARRAYISFULL(my_Array))
        {
            ret = FULL;
            printf("Array is full  :)\n");
        }
        else
        {
            (my_Array->Array_Pointer)++;
            my_Array->Array[my_Array->Array_Pointer] = value;
            (my_Array->Elementcount)++;
            ret = R_OK;
        }
    }
    return ret;
}

uint32 *Array_Delete(Array_t *my_Array, Return_Status_t *Ret_State)
{
    void *loc_arr = R_NOK;
    if((NULL == my_Array) || (NULL == Ret_State))
    {
        printf("Delete has error !! :(\n");
        *Ret_State = NULL_Ptr;
        loc_arr = NULL;
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            *Ret_State = EMPTY;
            loc_arr = NULL;
            printf("Array is empty :( \n");
        }
        else
        {
            loc_arr = my_Array->Array[my_Array->Array_Pointer];
            (my_Array->Array_Pointer)--;
            (my_Array->Elementcount)--;
            *Ret_State = R_OK;
        }
    }
    return loc_arr;
}

Return_Status_t Array_Size(Array_t *my_Array, uint32 *Size)
{
    Return_Status_t ret = R_NOK;
    if((NULL == my_Array) || (NULL == Size))
    {
        ret = NULL_Ptr;
        printf("Array Size fun has error :( !!\n");
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            ret = EMPTY;
        }
        else
        {
            *Size = my_Array->Elementcount;
            ret = R_OK;
        }
    }
    return ret;
}

Return_Status_t Array_Max(Array_t *my_Array)
{
    Return_Status_t ret = R_NOK;
    uint32 max_Elem = 0;
    if(NULL == my_Array)
    {
        ret = NULL_Ptr;
        printf("Get max has error :( !!\n");
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            ret = EMPTY;
            printf("Array is empty :( \n");
        }
        else
        {
            max_Elem = my_Array->Array[0];
            for(int counter = 0; counter < (my_Array->Elementcount); counter++)
            {
                if(max_Elem < (my_Array->Array[counter]))
                {
                    max_Elem = (my_Array->Array[counter]);
                }
            }
            ret = R_OK;
            printf("The maximum number is %i \n",max_Elem);
        }
    }
    return ret;
}

Return_Status_t Array_Min(Array_t *my_Array)
{
    Return_Status_t ret = R_NOK;
    uint32 min_Elem = 0;
    if(NULL == my_Array)
    {
        ret = NULL_Ptr;
        printf("Get max has error :( !!\n");
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            ret = EMPTY;
            printf("Array is empty :( \n");
        }
        else
        {
            min_Elem = my_Array->Array[0];
            for(int counter = 0; counter < (my_Array->Elementcount); counter++)
            {
                if(min_Elem > my_Array->Array[counter])
                {
                    min_Elem = my_Array->Array[counter];
                }
            }
            ret = R_OK;
            printf("The minimum number is %i \n",min_Elem);
        }
    }
    return ret;
}

Return_Status_t Array_Display(Array_t *my_Array)
{
    Return_Status_t ret = R_NOK;
    if(NULL == my_Array)
    {
        ret = NULL_Ptr;
        printf("Display has error :( !!\n");
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            ret = EMPTY;
        }
        else
        {
            for(uint32 counter = 0; counter < (my_Array->Elementcount); counter++)
            {
                printf(" --> %i ",my_Array->Array[counter]);
            }
            printf("\n\n");
            ret = R_OK;
        }
    }
    return ret;
}

Return_Status_t Array_Sorting(Array_t *my_Array)
{
    Return_Status_t ret = R_NOK;
    uint32 BS_Iteration = 0, Adjacent_Iteration = 0;
    uint32 swap_Elements = ZERO;
    uint32 Sort_Flag = 0;
    if(NULL == my_Array)
    {
        ret = NULL_Ptr;
        printf("Sorting has error !! :( \n");
    }
    else
    {
        ret = R_OK;
        for(BS_Iteration = 0; BS_Iteration < (my_Array->Elementcount)-1; BS_Iteration++)
        {
            for(Adjacent_Iteration = 0; Adjacent_Iteration < (my_Array->Elementcount)-1-BS_Iteration; Adjacent_Iteration++)
            {
                if(my_Array->Array[Adjacent_Iteration] > my_Array->Array[Adjacent_Iteration+1])
                {
                    swap_Elements = my_Array->Array[Adjacent_Iteration];
                    my_Array->Array[Adjacent_Iteration] = my_Array->Array[Adjacent_Iteration+1];
                    my_Array->Array[Adjacent_Iteration+1] = swap_Elements;
                    Sort_Flag = 1;
                }
            }
            if(Sort_Flag == 0)
            {
                return;
            }
        }
    }
    return ret;
}
Array_t *Destroy_Array(Array_t *my_Array, Return_Status_t *Ret_state)
{
    Array_t *loc_Array = NULL;
    if((NULL == my_Array) || (NULL == Ret_state))
    {
        *Ret_state = NULL_Ptr;
        printf("Destroy has error !! :( \n");
    }
    else
    {
        free(my_Array->Array);
        free(my_Array);
        *Ret_state = R_OK;
    }
    return NULL;
}

/*Return_Status_t Linear_Search_DArray(Array_t *my_Array, uint32_t Req_Data)
{
    Return_Status_t ret = R_NOK;
    int index = 0;
    if(NULL == my_Array)
    {
        ret = NULL_Ptr;
        printf("Linear_Search_DArray NULL :( \n");
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            ret = EMPTY;
            printf("DArray is empty :( \n");
        }
        else
        {
            for(index = 0; index < (my_Array->Array_Pointer); index++)
            {
                if(Req_Data == (my_Array->Array[index]));
                {
                    printf("This value is in index ==> %i \n", index);
                    return ret = R_OK;
                }
            }
            printf("NOT FOUND :( \n");
            ret = R_NOK;
        }
    }
    return ret;
}
*/
Return_Status_t Binary_Search_DArray(Array_t *my_Array, uint32 S_Index, uint32 E_Index, uint32 Req_Data)
{
    Return_Status_t ret = R_NOK;
    int M_Index = 0;

    if(NULL == my_Array)
    {
        ret = NULL_Ptr;
        printf("Binary search NULL :( \n");
    }
    else
    {
        if(ARRAYISEMPTY(my_Array))
        {
            ret = EMPTY;
            printf("Array is empty :( \n");
        }
        else
        {
            while(S_Index <= E_Index)
            {
                M_Index = S_Index + ((E_Index - S_Index)/2);

                if(Req_Data == my_Array->Array[M_Index])
                {
                    printf("This value is in index ==> %i \n",M_Index);
                    ret = R_OK;
                    return ret;
                }
                else if(Req_Data > my_Array->Array[M_Index])
                {
                    S_Index = M_Index + 1;
                }
                else
                {
                    E_Index = M_Index - 1;
                }
            }
            printf("NOT FOUND :( \n");
        }
    }


    return ret;
}




/*Stack based on array*/
static Return_Status_t STACK_IS_FULL(Stack_t *my_stack)
{
    if(my_stack->stack_Pointer == STACK_MAX_SIZE - 1)
    {
        return FULL; // 1
    }
    else
    {
        return NOT_FULL; //2
    }
}

static Return_Status_t STACK_IS_EMPTY(Stack_t *my_stack)
{
    if(my_stack->stack_Pointer == -1)
    {
        return EMPTY; // 1
    }
    else
    {
        return NOT_FULL; //2
    }
}


Return_Status_t Stack_init(Stack_t *my_stack)
{
    Return_Status_t ret = R_NOK;
    if(NULL == my_stack)
    {
        ret = R_NOK;
    }
    else
    {
        my_stack->stack_Pointer = -1;
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Push(Stack_t *my_stack, uint32 value)
{
    Return_Status_t ret = R_NOK;
    if((NULL == my_stack) || (FULL == STACK_IS_FULL(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf(" ==> Error !! stack is full , can not push (%i)\n",value);
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        (my_stack->stack_Pointer)++;
        my_stack->Data[my_stack->stack_Pointer] = value;
                #ifdef STACK_DEBUG
        printf("==> value (%i) pushed to the stack \n\n",value);
        #endif // STACK_DEBUG
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Pop(Stack_t *my_stack, uint32 *value)
{
    Return_Status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == value) || (EMPTY == STACK_IS_EMPTY(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf("==> Error !! stack is Empty , can not pop \n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        *value = my_stack->Data[my_stack->stack_Pointer];
        (my_stack->stack_Pointer)--;
        #ifdef STACK_DEBUG
        printf("==> Popped value is (%i) \n",*value);
        #endif // STACK_DEBUG
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Top(Stack_t *my_stack, uint32 *value)
{
    Return_Status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == value) || (EMPTY == STACK_IS_EMPTY(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf("==> Error !! stack is empty , can not get the top of it \n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        *value = my_stack->Data[my_stack->stack_Pointer];
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Size(Stack_t *my_stack, uint32 *Size)
{
    Return_Status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == Size) || (EMPTY == STACK_IS_EMPTY(my_stack)))
    {
        ret = R_NOK;
    }
    else
    {
        *Size = (my_stack->stack_Pointer);
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Display(Stack_t *my_stack)
{
    sint32 Counter = 0;
    Return_Status_t ret = R_NOK;

    if((NULL == my_stack) || (EMPTY == STACK_IS_EMPTY(my_stack)))
    {
        ret = R_NOK;
    }
    else
    {
        printf("Stack Data : \n");
        for(Counter = my_stack->stack_Pointer; Counter >= ZERO; Counter--)
        {
            printf("Element at index[%i] = %i \n",Counter,my_stack->Data[Counter]);
        }
        printf("\n");
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Get_Max(Stack_t *my_stack)
{
    Return_Status_t ret = R_NOK;
    uint32 Get_Max = ZERO;
    uint32 Size = ZERO;

    ret = Stack_Size(my_stack, &Size);

    if(NULL == my_stack)
    {
        printf("Get Max has error !! \n");
        ret = R_NOK;
    }
    else
    {
        for(uint32 counter = 0; counter < Size-1; counter++)
        {
            if((my_stack->Data[counter]) <  (my_stack->Data[counter+1]))
            {
                Get_Max = (my_stack->Data[counter+1]);
            }
            else
            {
                Get_Max = (my_stack->Data[counter]);
            }
        }
        printf("The maximum number in the stack is %i \n",Get_Max);
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Get_Min(Stack_t *my_stack)
{
    Return_Status_t ret = R_NOK;
    uint32 Get_Min = ZERO;
    uint32 Size = ZERO;

    ret = Stack_Size(my_stack, &Size);

    if(NULL == my_stack)
    {
        printf("Get min has error !! \n");
        ret = R_NOK;
    }
    else
    {
        for(int counter = 0; counter < Size-1; counter++)
        {
            if((my_stack->Data[counter]) <  (my_stack->Data[counter+1]))
            {
                Get_Min = (my_stack->Data[counter]);
            }
            else
            {
                Get_Min = (my_stack->Data[counter+1]);
            }
        }
        printf("The minimum number in the stack is %i \n",Get_Min);
        ret = R_OK;
    }
    return ret;
}

Return_Status_t Stack_Sorting(Stack_t *my_stack)
{

    Return_Status_t ret = R_NOK;
    uint32 BS_Iteration = 0, Adjacent_Iteration = 0;
    uint32 Size = ZERO;
    uint32 Swap_Var = ZERO;
    uint32 Sort_Flag = 0;
    ret = Stack_Size(my_stack, &Size);

    if(NULL == my_stack)
    {
        printf("Sorting has error !! \n");
        ret = R_NOK;
    }
    else
    {
        ret = R_OK;
        for(BS_Iteration = 0; BS_Iteration < Size-1; BS_Iteration++)
        {
            for(Adjacent_Iteration = 0; Adjacent_Iteration < Size-1-BS_Iteration; Adjacent_Iteration++)
            {
                if(my_stack->Data[Adjacent_Iteration] > my_stack->Data[Adjacent_Iteration+1])
                {
                    Swap_Var = my_stack->Data[Adjacent_Iteration];
                    my_stack->Data[Adjacent_Iteration] = my_stack->Data[Adjacent_Iteration+1];
                    my_stack->Data[Adjacent_Iteration+1] = Swap_Var;
                    Sort_Flag = 1;
                }
            }
            if(Sort_Flag == 0)
            {
                return;
            }
        }
        return ret;
    }
}

Return_Status_t Linear_Search_Stack(Stack_t *my_stack, uint32 Req_Data)
{
    Return_Status_t ret = R_NOK;
    uint32 counter = 0;
    if(NULL == my_stack)
    {
        ret = NULL_Ptr;
        printf("Linear_Search_Stack NULL :( \n");
    }
    else
    {
        for(counter = 0; counter <= my_stack->stack_Pointer; counter++)
        {
            if(Req_Data == my_stack->Data[counter])
            {
                printf("This value is in index ==> %i \n",counter);
                ret = R_OK;
                return ret;
            }
        }
        printf("Not found :( \n");
        ret = R_NOK;
    }
    return ret;
}

Return_Status_t Binary_Search_Stack(Stack_t *my_stack, uint32 S_Index, uint32 E_Index, uint32 Req_Data)
{
    uint32 M_Index = 0;
    Return_Status_t ret = R_NOK;
    if(NULL == my_stack)
    {
        ret = NULL_Ptr;
        printf("Linear_Search_Stack NULL :( \n");
    }
    else
    {
        while(S_Index <= E_Index)
        {
            M_Index = S_Index + ((E_Index - S_Index)/2);

            if(Req_Data == my_stack->Data[M_Index])
            {
                printf("This value is in index ==> %i \n",M_Index);
                ret =R_OK;
                return ret;
            }
            else if(Req_Data > my_stack->Data[M_Index])
            {
                S_Index = M_Index + 1;
            }
            else
            {
                E_Index = M_Index - 1;
            }
        }
        printf("NOT FOUND :( \n");
        ret = R_NOK;
    }
    return ret;
}






/*stack Dynamic array*/

stack_DA_t *CreateStack(uint32 maxSize, Return_Status_t *ret_status)
{
    stack_DA_t *My_Stack = NULL;
    if(NULL == ret_status)
    {
        *ret_status = NULL_Ptr;
        My_Stack = NULL;
        printf("Create function NULL :(\n");
    }
    else
    {
        My_Stack = (stack_DA_t *)malloc(sizeof(stack_DA_t));
        if(!My_Stack)
        {
            *ret_status = NULL_Ptr;
            My_Stack = NULL;
            printf("Malloc function NULL :( \n");
        }
        else
        {
            My_Stack->StackTop = -1;
            My_Stack->Elementcount = 0;
            My_Stack->StackMaxSize = maxSize;
            My_Stack->stackArray = (void **)calloc(My_Stack->StackMaxSize, sizeof(void *));
            if(!My_Stack->stackArray)
            {
                free(My_Stack);
                My_Stack = NULL;
                *ret_status = NULL_Ptr;
                printf("Calloc function NULL :( \n");
            }
            else
            {
                *ret_status = R_OK;
                printf("Create Done successfully :) \n");
            }
        }
    }
    return My_Stack;
}

stack_DA_t *Destroy_Stack(stack_DA_t *stack_obj, Return_Status_t *ret_status)
{
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        *ret_status = NULL_Ptr;
        printf("Destroy NULL :( \n");
    }
    else
    {
        free(stack_obj->stackArray);
        free(stack_obj);
        *ret_status = R_OK;
        printf("Destroy done successfully :) \n");
    }
    return NULL;
}

Return_Status_t PushStack(stack_DA_t *stack_obj, uint32 itemptr)
{
    Return_Status_t ret = R_NOK;
    if(NULL == stack_obj)
    {
        ret = NULL_Ptr;
        printf("Push function NULL :( \n");
    }
    else
    {
        if(StackIsFull(stack_obj))
        {
            ret = FULL;
            printf("Stack is full :) \n");
        }
        else
        {
            (stack_obj->StackTop)++;
            stack_obj->stackArray[stack_obj->StackTop] = itemptr;
            (stack_obj->Elementcount)++;
            ret = R_OK;
            printf("Push success :) \n");
        }
    }
    return ret;
}

void *PopStack (stack_DA_t *stack_obj, Return_Status_t *ret_status)
{
    void *My_Stack = NULL;
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        *ret_status = NULL_Ptr;
        printf("Pop NULL :( \n");
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = EMPTY;
            printf("Stack is empty :) \n");
        }
        else
        {
            My_Stack = stack_obj->stackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->Elementcount)--;
            *ret_status = R_OK;
            printf("Pop done successfully :) \n");
        }
    }
    return My_Stack;
}

void *StackTop (stack_DA_t *stack_obj, Return_Status_t *ret_status)
{
    void *My_Stack = NULL;
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        *ret_status = NULL_Ptr;
        printf("Pop NULL :( \n");
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = EMPTY;
            printf("Stack is empty :) \n");
        }
        else
        {
            My_Stack = stack_obj->stackArray[stack_obj->StackTop];
            *ret_status = R_OK;
            printf("top done successfully :) \n");
        }
    }
    return My_Stack;
}

Return_Status_t StackSize(stack_DA_t *stack_obj, uint32 *stack_count)
{
    Return_Status_t ret = R_NOK;
    if((NULL == stack_obj) || (NULL == stack_count))
    {
        ret = NULL_Ptr;
        printf("Stack size function NULL :( \n");
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            ret = EMPTY;
            printf("The stack is Empty :( \n");
        }
        else
        {
            stack_count = stack_obj->Elementcount;
            ret = R_OK;
            printf("The size is ==> %i \n",stack_count);
        }
    }
    return ret;
}

Return_Status_t StackMax(stack_DA_t *stack_obj)
{
    Return_Status_t ret = R_NOK;
    uint32 max_Elem = ZERO;
    if(NULL == stack_obj)
    {
        ret = NULL_Ptr;
        printf("Max function NULL :( \n");
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            ret = EMPTY;
            printf("Stack is empty :( \n--> Please Push elements and try again <--\n");
        }
        else
        {
            max_Elem = stack_obj->stackArray[0];
            for(int counter = 0; counter < (stack_obj->Elementcount); counter++)
            {
                if(max_Elem < (stack_obj->stackArray[counter]))
                {
                    max_Elem = (stack_obj->stackArray[counter]);
                }
            }
            ret = R_OK;
            printf("The maximum number is %i \n",max_Elem);
        }
    }
    return ret;
}

Return_Status_t StackMin(stack_DA_t *stack_obj)
{
    Return_Status_t ret = R_NOK;
    uint32 min_Elem = ZERO;
    if(NULL == stack_obj)
    {
        ret = NULL_Ptr;
        printf("Min function NULL :( \n");
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            ret = EMPTY;
            printf("Stack is empty :( \n--> Please Push elements and try again <--\n");
        }
        else
        {
            min_Elem = stack_obj->stackArray[0];
            for(int counter = 0; counter < (stack_obj->Elementcount); counter++)
            {
                if(min_Elem > (stack_obj->stackArray[counter]))
                {
                    min_Elem = (stack_obj->stackArray[counter]);
                }
            }
            ret = R_OK;
            printf("The minimum number is %i \n",min_Elem);
        }
    }
    return ret;
}

Return_Status_t StackSorting(stack_DA_t *stack_obj)
{
    Return_Status_t ret = R_NOK;
    uint32 BS_Iteration = 0, Adjacent_Iteration = 0;
    uint32 swap_Elements = ZERO;
    uint32 Sort_Flag = 0;
    if(NULL == stack_obj)
    {
        ret = NULL_Ptr;
        printf("Sorting has error !! :( \n");
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            ret = EMPTY;
            printf("Stack is empty :( \n");
        }
        else
        {
            for(BS_Iteration = 0; BS_Iteration < (stack_obj->Elementcount)-1; BS_Iteration++)
            {
                for(Adjacent_Iteration = 0; Adjacent_Iteration < (stack_obj->Elementcount)-1-BS_Iteration; Adjacent_Iteration++)
                {
                    if(stack_obj->stackArray[Adjacent_Iteration] > stack_obj->stackArray[Adjacent_Iteration+1])
                    {
                        swap_Elements = stack_obj->stackArray[Adjacent_Iteration];
                        stack_obj->stackArray[Adjacent_Iteration] = stack_obj->stackArray[Adjacent_Iteration+1];
                        stack_obj->stackArray[Adjacent_Iteration+1] = swap_Elements;
                        Sort_Flag = 1;
                    }
                }
                if(Sort_Flag == 0)
                {
                    return;
                }
            }
            ret = R_OK;
            printf("Sorting done :) \n");
        }
    }
    return ret;
}

Return_Status_t StackDisplay(stack_DA_t *stack_obj)
{
    Return_Status_t ret = R_NOK;
    sint32 Counter = 0;
    if(NULL == stack_obj)
    {
        ret = NULL_Ptr;
        printf("Display NULL  :(\n");
    }
    else
    {
        printf("Stack Data : \n");
        for(Counter = stack_obj->Elementcount-1; Counter >= ZERO; Counter--)
        {
            printf("Element at index[%i] = %i \n",Counter, stack_obj->stackArray[Counter]);
        }
        ret = R_OK;
        printf("Display success :) \n");
    }
    return ret;
}
static uint8 StackIsFull(stack_DA_t *stack_obj)
{
    return (stack_obj->Elementcount == stack_obj->StackMaxSize); // if it return 1 that mean the stack is full
}

static uint8 StackIsEmpty(stack_DA_t *stack_obj)
{
    return (stack_obj->Elementcount == 0);    // if it return 1 that mean it is empty
}

Return_Status_t Binary_Search_DA_Stack(stack_DA_t *stack_obj, uint32 S_Index, uint32 E_Index, uint32 Req_Data)
{
    Return_Status_t ret = R_NOK;
    int M_Index = 0;

    if(NULL == stack_obj)
    {
        ret = NULL_Ptr;
        printf("Binary search NULL :( \n");
    }
    else
    {
        if(ARRAYISEMPTY(stack_obj))
        {
            ret = EMPTY;
            printf("stack is empty :( \n");
        }
        else
        {
            while(S_Index <= E_Index)
            {
                M_Index = S_Index + ((E_Index - S_Index)/2);

                if(Req_Data == stack_obj->stackArray[M_Index])
                {
                    printf("This value is in index ==> %i \n",M_Index);
                    ret = R_OK;
                    return ret;
                }
                else if(Req_Data > stack_obj->stackArray[M_Index])
                {
                    S_Index = M_Index + 1;
                }
                else
                {
                    E_Index = M_Index - 1;
                }
            }
            printf("NOT FOUND :( \n");
            ret = R_NOK;
        }
    }


    return ret;
}





/*Queue*/



/*Single liked list*/
void Insert_At_Beginning(struct node_S **Head_Of_List)
{
    struct node_S *List_Insertion = NULL;

    List_Insertion = (struct node_S *)malloc(sizeof(struct node_S));

    if(NULL != List_Insertion)
    {
        printf("Enter the node value : ");
        scanf("%i",&List_Insertion->NodeData);

        if(NULL == Head_Of_List)
        {
            List_Insertion->Link_Of_List = NULL;
            *Head_Of_List = List_Insertion;
        }
        else
        {
            List_Insertion->Link_Of_List = *Head_Of_List;
            *Head_Of_List = List_Insertion;
        }
    }else{/*NOTHING*/}
}

void Insert_At_End(struct node_S **Head_Of_List)
{
    struct node_S *List_Insertion = NULL;
    struct node_S *LastNode = NULL;

    List_Insertion = (struct node_S *)malloc(sizeof(struct node_S));
    if(NULL != List_Insertion)
    {
        printf("Enter the node value : ");
        scanf("%i",&List_Insertion->NodeData);

        List_Insertion->Link_Of_List = NULL;

        if(NULL == *Head_Of_List)
        {
            *Head_Of_List = List_Insertion;
        }
        else
        {
            LastNode = *Head_Of_List;
            while(NULL != LastNode->Link_Of_List)
            {
                LastNode = LastNode->Link_Of_List;
            }
            LastNode->Link_Of_List = List_Insertion;
        }
    }else{/*NOTHING*/}
}

void Insert_Node(struct node_S *Head_Of_List)
{
    struct node_S *List_Insertion = NULL;
    struct node_S *Motion_ptr = NULL;
    uint32 nodeposition = 0;
    uint32 LengthOfList = 0;
    uint32 NodeCounter = 1;

    printf("Enter position after you need to insert(First = 1 ) : ");
    scanf("%i",&nodeposition);

    LengthOfList = Get_Length(Head_Of_List);

    if(nodeposition > LengthOfList)
    {
        printf("Invalid node position , The list has length = %i ",LengthOfList);
    }
    else
    {
        Motion_ptr = Head_Of_List;
        while(NodeCounter < nodeposition)
        {
            NodeCounter++;
            Motion_ptr = Motion_ptr->Link_Of_List;
        }
        List_Insertion = (struct node_S *)malloc(sizeof(struct node_S));

        if(NULL != List_Insertion)
        {
            printf("Enter the data of the node : ");
            scanf("%i",&List_Insertion->NodeData);

            List_Insertion->Link_Of_List = Motion_ptr->Link_Of_List;
            Motion_ptr->Link_Of_List = List_Insertion;
        }
        else{/*NOTHING*/}
    }
}

void Delete_From_Beginning(struct node_S **Head_Of_List)
{
    struct node_S *List_Insertion = *Head_Of_List;
    if(NULL == *Head_Of_List)
    {
        printf("The list is empty !!\n");
    }
    else
    {
        *Head_Of_List = List_Insertion->Link_Of_List;
        List_Insertion->Link_Of_List = NULL;
        free(List_Insertion);
    }
}

void Delete_Element(struct node_S *Head_Of_List)
{
    struct node_S *List_Insertion = Head_Of_List;
    struct node_S *Motion_ptr = Head_Of_List;
    uint32 LengthList   = 0;
    uint32 NodeCounter  = 1;
    uint32 nodeposition = 0;

    printf("Enter the position to delete without (1) : ");
    scanf("%i",&nodeposition);

    LengthList = Get_Length(Head_Of_List);

    if((nodeposition > LengthList) || LengthList == 1)
    {
        printf("please use Delete_From_Beginning \n");
    }
    else
    {
        while(NodeCounter < (nodeposition-1))
        {
            NodeCounter++;
            List_Insertion = List_Insertion->Link_Of_List;
        }
        Motion_ptr = List_Insertion->Link_Of_List;
        List_Insertion->Link_Of_List = Motion_ptr->Link_Of_List;
        free(Motion_ptr);
    }
}

void Display_All_Nodes(struct node_S *Head_Of_List)
{
    struct node_S *List_Insertion = Head_Of_List;
    printf("Nodes values : ");
    while(List_Insertion != NULL)
    {
        printf(" %i -> ",List_Insertion->NodeData);
        List_Insertion = List_Insertion->Link_Of_List;
    }
    if(NULL == List_Insertion)
    {
        printf("NULL \n");
    }
}

void Get_Middle_Of_SList(struct node_S *Head_Of_List)
{
    struct node_S *List_Ptr  = Head_Of_List;
    uint32 Length_Of_List  = 0;
    uint32 Counter_Of_List = 1;

    Length_Of_List = Get_Length(Head_Of_List);

    if(0 == Length_Of_List)
    {
        printf("The list is empty \n");
    }
    else
    {
        if((Length_Of_List % 2) == 1)
        {
            while(Counter_Of_List < (Length_Of_List/2)+1)
            {
                Counter_Of_List++;
                List_Ptr = List_Ptr->Link_Of_List;
            }
            printf("Middle --> %i \n",List_Ptr->NodeData);
        }
        else
        {
            while(Counter_Of_List < (Length_Of_List/2))
            {
                Counter_Of_List++;
                List_Ptr = List_Ptr->Link_Of_List;
                if(Counter_Of_List == (Length_Of_List/2))
                {
                    printf("Middle --> %i ,",List_Ptr->NodeData);
                }
                List_Ptr = List_Ptr->Link_Of_List;
            }
            printf(" %i \n",List_Ptr->NodeData);
        }
    }
}

void Reverse_Nodes (struct node_S **Head_Of_List)
{
    struct node_S *Prevptr = NULL;
    struct node_S *Currentptr = *Head_Of_List;
    struct node_S *Nextptr = NULL;

    if(NULL == *Head_Of_List)
    {
        printf("The list is empty !!\n");
    }
    else
    {
        while(NULL != Currentptr)
        {
            Nextptr = Currentptr->Link_Of_List;
            Currentptr->Link_Of_List = Prevptr;
            Prevptr = Currentptr;
            Currentptr = Nextptr;
        }
        *Head_Of_List = Prevptr;
    }
}

uint32 Get_Length (struct node_S *Head_Of_List)
{
    struct node_S *Listcounter = Head_Of_List;

    uint32 Counter_Of_Length = 0;

    while(NULL != Listcounter)
    {
        Counter_Of_Length++;
        Listcounter = Listcounter->Link_Of_List;
    }
    return Counter_Of_Length;
}

void Rotate(struct node_S** head_ref, uint32 position)
{
    int count = 1;

    if (position == 0)
        return;

    // Let us understand the below code for example k = 4
    // and list = 10->20->30->40->50->60.
    struct node_S* current = *head_ref;

    // current will either point to kth or NULL after this
    // loop. current will point to node 40 in the above
    // example

    while (count < position && current != NULL) {
        current = current->Link_Of_List;
        count++;
    }

    // If current is NULL, k is greater than or equal to
    // count of nodes in linked list. Don't change the list
    // in this case
    if (current == NULL)
        return;

    // current points to kth node. Store it in a variable.
    // kthNode points to node 40 in the above example
    struct node_S* kthNode = current;

    // current will point to last node after this loop
    // current will point to node 60 in the above example
    while (current->Link_Of_List != NULL)
        current = current->Link_Of_List;

    // Change next of last node to previous head
    // Next of 60 is now changed to node 10
    current->Link_Of_List = *head_ref;

    // Change head to (k+1)th node
    // head is now changed to node 50
    *head_ref = kthNode->Link_Of_List;

    // change next of kth node to NULL
    // next of 40 is now NULL
    kthNode->Link_Of_List = NULL;
}

void printNthFromLast( struct node_S* head, uint32 pos_Last)
{
    int len = 0, i;
    struct node_S* temp = head;

    // Count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->Link_Of_List;
        len++;
    }

    // Check if value of N is not
    // more than length of the linked list
    if (len < pos_Last)
        return;
    temp = head;

    // Get the (len-N+1)th node from the beginning
    for (i = 1; i < len - pos_Last + 1; i++)
        temp = temp->Link_Of_List;
    printf("====> %i", temp->NodeData);
    return;
}

struct node_S* Delete_Middle(struct node_S* head)
{
    struct node_S* copyHead = head;
    // Find the count of nodes
    int count = Get_Length(head);
    // Find the middle node
    int mid = count / 2;
    // Base cases
    if (head == NULL)
    {
        printf("List is empty :( \n");
        return NULL;
    }
    else
    {
        if (head->Link_Of_List == NULL)
        {
            free(head);
            return NULL;
        }
        else
        {
            // Delete the middle node
            while(mid-->1)
              head = head->Link_Of_List;
            // Delete the middle node
            head->Link_Of_List = head->Link_Of_List->Link_Of_List;
        }
    }
    return copyHead;
}

void swapKth_from_Begin_Last(struct node_S** head_ref, uint32 Pos_Last_Begin)
{
    // Count nodes in linked list
    int Length = Get_Length(*head_ref);
    // Check if k is valid
    if (Length < Pos_Last_Begin)
        return;
    // If x (kth node from start) and y(kth node from end)
    // are same
    if (2 * Pos_Last_Begin - 1 == Length)
        return;
    // Find the kth node from the beginning of the linked
    // list. We also find previous of kth node because we
    // need to update next pointer of the previous.
    struct node_S* x = *head_ref;
    struct node_S* x_prev = NULL;
    for (int i = 1; i < Pos_Last_Begin; i++) {
        x_prev = x;
        x = x->Link_Of_List;
    }
    // Similarly, find the kth node from end and its
    // previous. kth node from end is (n-k+1)th node from
    // beginning
    struct node_S* y = *head_ref;
    struct node_S* y_prev = NULL;
    for (int i = 1; i < Length - Pos_Last_Begin + 1; i++) {
        y_prev = y;
        y = y->Link_Of_List;
    }
    // If x_prev exists, then new next of it will be y.
    // Consider the case when y->next is x, in this case,
    // x_prev and y are same. So the statement "x_prev->next
    // = y" creates a self loop. This self loop will be
    // broken when we change y->next.
    if (x_prev)
        x_prev->Link_Of_List = y;
    // Same thing applies to y_prev
    if (y_prev)
        y_prev->Link_Of_List = x;
    // Swap next pointers of x and y. These statements also
    // break self loop if x->next is y or y->next is x
    struct node_S* temp = x->Link_Of_List;
    x->Link_Of_List = y->Link_Of_List;
    y->Link_Of_List = temp;
    // Change head pointers when k is 1 or n
    if (Pos_Last_Begin == 1)
        *head_ref = y;
    if (Pos_Last_Begin == Length)
        *head_ref = x;
}

// Function to sort the linked list using insertion sort
void Insertion_SSort(struct node_S **head)
{
    // If the list is empty or contains only one element, it is already sorted
    if (*head == NULL || (*head)->Link_Of_List == NULL) {
        return;
    }

    struct node_S* sortedList = NULL; // Sorted part of the list
    struct node_S* current = *head;   // Current node being inserted

    while (current != NULL) {
        struct node_S* nextNode = current->Link_Of_List; // Next node to be inserted

        // Find the correct position to insert the current node in the sorted list
        if (sortedList == NULL || current->NodeData < sortedList->NodeData) {
            // Insert at the beginning of the sorted list
            current->Link_Of_List = sortedList;
            sortedList = current;
        } else {
            struct node_S* temp = sortedList;
            while (temp->Link_Of_List != NULL && current->NodeData > temp->Link_Of_List->NodeData) {
                temp = temp->Link_Of_List;
            }
            // Insert between temp and temp->Link_Of_List
            current->Link_Of_List = temp->Link_Of_List;
            temp->Link_Of_List = current;
        }

        current = nextNode; // Move to the next node for insertion
    }

    *head = sortedList; // Update the head to the sorted list
}

void Searching(struct node_S* head, int searchData)
{
    struct node_S* current = head;
    int counter = 1;
    while (current != NULL)
    {
        if (current->NodeData == searchData)
        {
            printf("This data is in position number ==> %i \n",counter);
            return ;
        }
        else
        {
            counter++;
            current = current->Link_Of_List;
        }
    }
    printf("Data NOT found :( \n");
}

 /* UTILITY FUNCTIONS */
/* Function to swap two integers */
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to pairwise swap elements of a linked list */
void pair_Wise_Swap(struct node_S **head)
{
    struct node_S* temp = *head;

    /* Traverse further only if there are at-least two nodes left */
    while (temp != NULL && temp->Link_Of_List != NULL) {
        /* Swap data of node with its next node's data */
        swap(&temp->NodeData, &temp->Link_Of_List->NodeData);

        /* Move temp by 2 for the next pair */
        temp = temp->Link_Of_List->Link_Of_List;
    }
}



/*Double linked list */

void Insert_Node_At_Beginning(struct node_D **Head, uint32 Data)
{
    struct node_D *HeadPtr = NULL;
    HeadPtr = (struct node_D *)malloc(sizeof(struct node_D));

    if(NULL == HeadPtr)
    {
        printf("Malloc can't allocate the list \n");
    }
    else
    {
        HeadPtr->NodeData = Data;
        if(NULL == *Head)
        {
            HeadPtr->RightNodePtr = NULL;
            HeadPtr->LiftNodePtr  = NULL;
            (*Head) = HeadPtr;
        }
        else
        {
            HeadPtr->RightNodePtr = (*Head);
            HeadPtr->LiftNodePtr  = NULL;
            (*Head)->LiftNodePtr  = HeadPtr;
            (*Head) = HeadPtr;
        }
    }
}

void Insert_Node_At_End(struct node_D *Head, uint32 Data)
{
    struct node_D *HeadPtr = NULL;
    struct node_D *HeadCounter = NULL;

    HeadPtr = (struct node_D *)malloc(sizeof(struct node_D));
    if(NULL == HeadPtr)
    {
        printf("Malloc can't allocate the list \n");
    }
    else
    {
        HeadPtr->NodeData = Data;
        HeadPtr->RightNodePtr = NULL;
        HeadCounter = Head;

        while(NULL != HeadCounter->RightNodePtr)
        {
            HeadCounter = HeadCounter->RightNodePtr;
        }

        HeadPtr->LiftNodePtr = HeadCounter;
        HeadCounter->RightNodePtr = HeadPtr;
    }
}

void Insert_Node_After(struct node_D *Head, uint32 Data, uint32 Position)
{
    struct node_D *HeadPtr = NULL;
    struct node_D *HeadCounterOne = NULL;
    struct node_D *HeadCounterTwo = NULL;
    uint32 counter = 1;

    HeadPtr = (struct node_D *)malloc(sizeof(struct node_D));

    if(NULL == HeadPtr)
    {
        printf("Malloc can't allocate the new node \n");
    }
    else
    {
        HeadPtr->NodeData = Data;
        HeadCounterOne = Head;

        while(counter < Position)
        {
            counter++;
            HeadCounterOne = HeadCounterOne->RightNodePtr;
        }

        HeadCounterTwo = HeadCounterOne->RightNodePtr;

        HeadCounterOne->RightNodePtr = HeadPtr;
        HeadCounterTwo->LiftNodePtr = HeadPtr;
        HeadPtr->LiftNodePtr = HeadCounterOne;
        HeadPtr->RightNodePtr = HeadCounterTwo;
    }
}

void Insert_Node_Before(struct node_D *Head, uint32 Data, uint32 Position)
{
    struct node_D *HeadPtr = NULL;
    struct node_D *HeadCounterOne =NULL;
    struct node_D *HeadCounterTwo =NULL;
    uint32 Counter = 1;

    HeadPtr = (struct node_D *)malloc(sizeof(struct node_D));

    if(NULL == HeadPtr)
    {
        printf("Malloc can't allocate new node \n");
    }
    else
    {
        if(1 == Position)
        {
            printf("Please use Insert_Node_At_Beginning \n");
        }
        else
        {
            HeadPtr->NodeData =Data;
            HeadCounterOne = Head;

            while(Counter < (Position-1))
            {
                Counter++;
                HeadCounterOne = HeadCounterOne->RightNodePtr;
            }

            HeadCounterTwo = HeadCounterOne->RightNodePtr;

            HeadCounterOne->RightNodePtr = HeadPtr;
            HeadCounterTwo->LiftNodePtr  = HeadPtr;

            HeadPtr->LiftNodePtr  = HeadCounterOne;
            HeadPtr->RightNodePtr = HeadCounterTwo;
        }
    }
}

void Delete_Node_At_Beginning(struct node_D **Head)
{
    struct node_D *HeadPtr = (*Head);
    if(NULL == (*Head))
    {
        printf("The list is empty \n");
    }
    else
    {
        #ifdef DELETE_NODE_AT_BEGINNING
            /* Update the head node */
            *Head = (*Head)->RightNodePtr;
            (*Head)->LiftNodePtr = NULL;
            /* Free the first node */
            free(HeadPtr);
            HeadPtr = NULL;
        #else
            *Head = (*Head)->RightNodePtr;
            free((*Head)->LiftNodePtr);
            (*Head)->LiftNodePtr = NULL;
        #endif
    }
}

void Delete_Node_At_End(struct node_D *Head)
{
    struct node_D *HeadPtr = NULL;
    struct node_D *HeadPtrOne = Head;

    while(NULL != HeadPtrOne->RightNodePtr)
    {
        HeadPtrOne = HeadPtrOne->RightNodePtr;
    }
    HeadPtr = HeadPtrOne->LiftNodePtr;
    HeadPtr->RightNodePtr = NULL;
    free(HeadPtrOne);
    HeadPtrOne = NULL;
}

void Delete_Node_At_Intermediate(struct node_D *Head, uint32 Position)
{
    struct node_D *HeadPtrOne = NULL;
    struct node_D *HeadPtrTWO = NULL;
    uint32 Counter =1;

    if(1 == Position)
    {
        printf("please use Delete_Node_At_Beginning \n");
    }
    else
    {
        HeadPtrOne = Head;
        while(Counter < Position)
        {
            Counter++;
            HeadPtrOne = HeadPtrOne->RightNodePtr;
        }
        HeadPtrTWO = HeadPtrOne->LiftNodePtr;
        HeadPtrTWO->RightNodePtr = HeadPtrOne->RightNodePtr;
        HeadPtrOne->RightNodePtr->LiftNodePtr = HeadPtrTWO;
        free(HeadPtrOne);
        HeadPtrOne = NULL;
    }
}

uint32 Get_Length_Of_DList(struct node_D *Head)
{
    struct node_D *HeadPtr = Head;
    uint32 LENGTH = 1;

    if(NULL == Head)
    {
        LENGTH = 0;
    }
    else
    {
        while(HeadPtr->RightNodePtr != NULL)
        {
            HeadPtr = HeadPtr->RightNodePtr;
            LENGTH++;

        }
    }
    return LENGTH;
}

void Get_Middle_Of_DList(struct node_D *Head)
{
    struct node_D *HeadPtr = Head;
    uint32 counter =1;
    uint32 LENGTH = 0;

    LENGTH = Get_Length_Of_DList(Head);

    if(LENGTH%2 == 1)
    {
        while(counter < (LENGTH/2)+1)
        {
            counter++;
            HeadPtr = HeadPtr->RightNodePtr;
        }
        printf("Middle = %i \n",HeadPtr->NodeData);
    }
    else
    {
        while(counter < (LENGTH/2))
        {
            counter++;
            HeadPtr = HeadPtr->RightNodePtr;
        }
        printf("Middle = %i , %i \n",HeadPtr->NodeData,HeadPtr->RightNodePtr->NodeData);
    }

}

void Reverse_List(struct node_D **Head)
{
    struct node_D *HeadPtr = NULL;
    struct node_D *Current = (*Head);

    while(Current != NULL)
    {
        HeadPtr = Current->LiftNodePtr;
        Current->LiftNodePtr = Current->RightNodePtr;
        Current->RightNodePtr = HeadPtr;
        Current = Current->LiftNodePtr;
    }
    if(HeadPtr != NULL)
    {
        *Head = HeadPtr->LiftNodePtr;
    }

}

void Display_All_Nodes_Forward(struct node_D *Head)
{
    struct node_D *HeadPtr = Head;

    printf("Forward data : ");
    printf("%d ", HeadPtr->NodeData);
    while(HeadPtr->RightNodePtr != NULL)
    {
        HeadPtr = HeadPtr->RightNodePtr;
        printf(" --> %d ",HeadPtr->NodeData);
    }
    if(NULL == HeadPtr->RightNodePtr)
    {
        printf("NULL");
    }
    printf("\n");
}

void Display_All_Nodes_Reverse(struct node_D *Head)
{
    struct node_D *HeadPtr = Head;

    while(HeadPtr->RightNodePtr != NULL)
    {
        HeadPtr = HeadPtr->RightNodePtr;
    }

    printf("Revers data : ");

    while(HeadPtr != NULL)
    {
        printf(" --> %i ",HeadPtr->NodeData);
        HeadPtr = HeadPtr->LiftNodePtr;
    }
    if(NULL == HeadPtr)
    {
        printf("NULL");
    }
}

void Bubble_Sort(struct node_D** head)
{
    if (head == NULL || (*head)->RightNodePtr == NULL) {
        // Empty list or single node, no need to sort
        return;
    }

    int swapped = 0;
    struct node_D* current;
    struct node_D* last = NULL;

    do {
        swapped = 0;
        current = *head;

        while (current->RightNodePtr != last) {
            if (current->NodeData > current->RightNodePtr->NodeData) {
                // Swap adjacent nodes
                int temp = current->NodeData;
                current->NodeData = current->RightNodePtr->NodeData;
                current->RightNodePtr->NodeData = temp;
                swapped = 1;
            }
            current = current->RightNodePtr;
        }
        last = current;
    } while (swapped);
}

void Insertion_DSort(struct node_D** head)
{
    if (*head == NULL || (*head)->RightNodePtr == NULL) {
        // Empty list or single node, no need to sort
        return;
    }

    struct node_D* sorted = NULL;
    struct node_D* current = *head;

    while (current != NULL) {
        struct node_D* nextNode = current->RightNodePtr;

        // Insert current node into the sorted portion of the list
        struct node_D* temp = sorted;
        while (temp != NULL && temp->NodeData < current->NodeData) {
            temp = temp->RightNodePtr;
        }

        if (temp == NULL) {
            // Insert at the end of the sorted list
            if (sorted != NULL) {
                sorted->RightNodePtr = current;
            }
            current->LiftNodePtr = sorted;
            current->RightNodePtr = NULL;
            sorted = current;
        } else if (temp->LiftNodePtr == NULL) {
            // Insert at the beginning of the sorted list
            current->LiftNodePtr = NULL;
            current->RightNodePtr = sorted;
            sorted->LiftNodePtr = current;
            sorted = current;
        } else {
            // Insert in the middle of the sorted list
            current->LiftNodePtr = temp->LiftNodePtr;
            current->RightNodePtr = temp;
            temp->LiftNodePtr->RightNodePtr = current;
            temp->LiftNodePtr = current;
        }

        current = nextNode;
    }

    *head = sorted;
}
uint32 Search(struct node_D* head, int value)
{
    uint32 counter = 1;
    struct node_D* current = head;
    while (current != NULL)
        {
        if (current->NodeData == value)
        {
            return counter;
        }
        counter++;
        current = current->RightNodePtr;
    }
    return NULL;  // Value not found
}


