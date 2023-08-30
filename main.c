#include <stdio.h>
#include <stdlib.h>

#include "project.h"

uint32 Size_Of_Array = ZERO;
uint32 arr[] = {0};

uint32 Array_size = 0, Array_count = 0;
Array_t *Array = NULL;
uint32 *Array_Return = NULL;

Stack_t stack ;
uint32 stack_pop_value = ZERO_INIT;
uint32 stack_top_value = ZERO;
uint32 Stack_Size_TT = ZERO;

uint32 stack1_size = 0, stack1_count = 0;
stack_DA_t *stack1 = NULL;
uint32 *stack1_Return = NULL;

struct node *ListHead = NULL;

struct Node *DLL_1 = NULL;
uint32 Return_Val = 0;

int main()
{
    uint8 Choice = 0;
    uint32 type = 0;
    uint32 Input_value = 0;
    uint32 Input1_value = 0;
    uint32 ListLength = 0;
    uint32 Input_pos = 0;
    Return_Status_t ret = R_NOK;
    uint32 Inputdata = 0;
    uint32 InputPosition = 0;



    printf("===================\* Welcome to final project of Data Structure \*===================\n");
    printf("\nWith my great instructor ENG\\ Ahmed Abd El Ghafar \n");
tarek:
    while(1)
    {
        printf("\n=============================\n");
        printf("---> Please choice from this list <--- \n");
        printf("1- Normal array.\n");
        printf("2- Dynamic array.\n");
        printf("3- Stack based on array.\n");
        printf("4- Stack based on dynamic array.\n");
        printf("5- Queue.(Not completed :( ) \n");
        printf("6- Single liked list.\n");
        printf("7- Double liked list.(Not completed :( )\n");
        printf("8- Exit.\n");
        printf("\n=============================\n");

        printf("\n chosen number is : ");
        scanf("%i",&Choice);
        printf("\n=============================\n");

        switch(Choice)
        {
        case 1:
            printf("\nEnter size of array ");
            scanf("%i",&Size_Of_Array);
            printf("Elements is \n");
            Enter_Data_Of_Array(arr, Size_Of_Array);
            printf("\n");
            while(1)
            {
                printf("\n=============================\n");
                printf("1-Delete an element \n");
                printf("2-Delete duplicate element \n");
                printf("3-Sum of elements \n");
                printf("4-Get the maximum number \n");
                printf("5-Get the minimum number \n");
                printf("6-Sort the elements \n");
                printf("7-Search about elements \n");
                printf("8-Display\n");
                printf("9-Return to the main window\n");
                printf("\n=============================\n");

                printf("chose the operation : ");
                scanf("%i",&Choice);
                switch(Choice)
                {

                case 1:
                    ret = Delete_An_Element(arr, Size_Of_Array);
                    if(R_OK == ret)
                    {
                        Size_Of_Array--;
                    }
                    break;
                case 2:
                    ret = Delete_duplicate_Elements(arr, Size_Of_Array);
                    if(R_OK == ret)
                    {
                        Size_Of_Array--;
                    }
                    break;
                case 3:
                    Sum_Of_Array(arr, Size_Of_Array);
                    break;
                case 4:
                    Get_Max_Num(arr, Size_Of_Array);
                    break;
                case 5:
                    Get_Min_Num(arr, Size_Of_Array);
                    break;
                case 6:
                    Sort_Array(arr, Size_Of_Array);
                    break;
                case 7:
                    printf("\nPlease type of searching :) \n");
                    printf("1- Linear search \n");
                    printf("2- Binary search \n");
                    printf("Type that chosen ");
                    scanf("%i",&type);
                    if(1 == type)
                    {
                        printf("\nPlease enter the data that you need to search :) ==> ");
                        scanf("%i",&Input_value);
                        Linear_Search_Array(arr, Size_Of_Array, Input_value);
                    }
                    else if(2 == type)
                    {
                        printf("\nPlease be sure that the elements are sorting from smallest to biggest \n");
                        printf("Please enter the data that you need to search :) ==> ");
                        scanf("%i",&Input_value);
                        Binary_Search_Array(arr, 0, Size_Of_Array-1, Input_value);
                    }
                    else
                    {
                        printf("User Choice out of range !!\n");
                    }
                    break;
                case 8:
                    Print_arr(arr, Size_Of_Array);
                    break;
                case 9:
                    goto tarek;
                    break;
                default:
                    printf("User Choice out of range !!\n");
                    break;
                }
                printf("==========================\n");
            }
            break;
        case 2:
            printf("Please enter the size of array :) -> ");
            scanf("%i",&Array_size);
            Array = Array_Create(Array_size, &Array_Return);
            if(Array)
            {
                printf("Array created :) \n\n");
            }

            while(1)
            {
                printf("\n=============================\n");
                printf("Chose operation from list of D-Array :) \n\n");
                printf("1-Insert an element \n");
                printf("2-Delete an element \n");
                printf("3-Size of array \n");
                printf("4-Get the maximum number \n");
                printf("5-Get the minimum number \n");
                printf("6-Sort the elements \n");
                printf("7-Search about the elements \n");
                printf("8-Display\n");
                printf("9-Return to the main window\n");
                printf("\n=============================\n");

                printf("\nChose the operation : ");
                scanf("%i",&Choice);

                switch(Choice)
                {

                case 1:
                    printf("\nEnter the value --> ");
                    scanf("%i",&Input_value);
                    ret = Array_Insert(Array, Input_value);
                    break;
                case 2:
                    Array_Return = Array_Delete(Array, &ret);
                    printf("Deleted value is ==> %i \n",Array_Return);
                    break;
                case 3:
                    ret = Array_Size(Array, &Array_count);
                    printf("Array size is ==> %i \n",Array_count);
                    break;
                case 4:
                    ret = Array_Max(Array);
                    break;
                case 5:
                    ret = Array_Min(Array);
                    break;
                case 6:
                    ret = Array_Sorting(Array);
                    break;
                case 7:
                    printf("\nPlease be sure that the elements are sorting from smallest to biggest \n");
                    printf("Please enter the data that you need to search :) ==> ");
                    scanf("%i",&Input_value);
                    ret = Binary_Search_DArray(Array, 0, Array_count-1, Input_value);
                    printf("Search_Array state is %i \n",ret);

                    break;
                case 8:
                    ret = Array_Display(Array);
                    break;
                case 9:
                    Array = Destroy_Array(Array, &ret);
                    if(!Array)    // if it any thing nor null(true if it = null)
                    {
                        printf("Array destroyed \n");
                    }
                    goto tarek;
                    break;
                default:
                    printf("User Choice out of range !!\n");
                    break;
                }

                printf("==========================\n");
            }

            break;
        case 3:
            ret = Stack_init(&stack);

            if(R_NOK == ret)
            {
                printf("stack failed \n");
            }
            else
            {
                while(1)
                {
                    printf("\n=============================");
                    printf("\n Please chose from list of stack operations \n\n");
                    printf("1-Push\n");
                    printf("2-Pop\n");
                    printf("3-Top\n");
                    printf("4-Size\n");
                    printf("5-Display\n");
                    printf("6-Get Max element \n");
                    printf("7-Get min element \n");
                    printf("8-Sorting stack elements \n");
                    printf("9-Search about stack elements \n");
                    printf("10-Return to the main window\n");
                    printf("\n=============================\n");

                    printf("Please chose an operation : ");
                    scanf("%i",&Choice);

                    switch(Choice)
                    {
                    case 1:
                        printf("Enter the value to push : ");
                        scanf("%i",&Input_value);
                        printf("\n");
                        ret = Stack_Push(&stack,Input_value);
                        break;
                    case 2:
                        ret = Stack_Pop(&stack, &stack_pop_value);
                        if(R_OK == ret)
                        {
                            printf("stack popped value = (%i)\n",stack_pop_value);
                        }
                        break;
                    case 3:
                        ret = Stack_Top(&stack, &stack_top_value);
                        if(R_OK == ret)
                        {
                            printf("stack top value = (%i)\n\n",stack_top_value);
                        }
                        break;
                    case 4:
                        ret = Stack_Size(&stack, &Stack_Size_TT);
                        printf("The size is %i elements \n\n",Stack_Size_TT);
                        break;
                    case 5:
                        ret = Stack_Display(&stack);
                        break;
                    case 6:
                        ret = Stack_Get_Max(&stack);
                        break;
                    case 7:
                        ret = Stack_Get_Min(&stack);
                        break;
                    case 8:
                        ret = Stack_Sorting(&stack);
                        break;
                    case 9:
                        ret = Stack_Size(&stack, &Stack_Size_TT);
                        printf("\nPlease type of searching :) \n");
                        printf("1- Linear search \n");
                        printf("2- Binary search \n");
                        printf("Type that chosen ");
                        scanf("%i",&type);
                        if(1 == type)
                        {
                            printf("\nPlease enter the data that you need to search :) ==> ");
                            scanf("%i",&Input_value);
                            ret = Linear_Search_Stack(&stack, Input_value);
                        }
                        else if(2 == type)
                        {
                            printf("\nPlease be sure that the elements are sorting from smallest to biggest \n");
                            printf("Please enter the data that you need to search :) ==> ");
                            scanf("%i",&Input_value);
                            printf("\n");
                            ret = Binary_Search_Stack(&stack, 0, Stack_Size_TT-1, Input_value);
                        }
                        else
                        {
                            printf("User Choice out of range !!\n");
                        }
                        break;
                    case 10:
                        printf("Quit from application \n");
                        exit(1);
                        break;
                    default:
                        printf("User Choice out of range !!\n");
                        break;
                    }
                }
            }

            break;
        case 4:
            printf("Please enter the size of stack :) -> ");
            scanf("%i",&stack1_size);
            stack1 = CreateStack(stack1_size, &stack1_Return);

            while(1)
            {
                printf("\n=============================\n");
                printf("Chose operation from list of D-Stack_array :) \n\n");

                printf("1-Push an element \n");
                printf("2-Pop an element \n");
                printf("3-Stack top. \n");
                printf("4-Size of array \n");
                printf("5-Get the maximum number \n");
                printf("6-Get the minimum number \n");
                printf("7-Sort the elements \n");
                printf("8-Display\n");
                printf("9-Return to the main window\n");
                printf("\n=============================\n");

                printf("\nChose the operation : ");
                scanf("%i",&Choice);

                switch(Choice)
                {

                case 1:
                    printf("\nEnter the value --> ");
                    scanf("%i",&Input_value);
                    ret = PushStack(stack1, Input_value);
                    printf("Push State is --> %i\n",ret);
                    break;
                case 2:
                    stack1_Return = PopStack(stack1, &ret);
                    printf("pop State is --> %i\n",ret);
                    printf("Deleted value is ==> %i \n",stack1_Return);
                    break;
                case 3:
                    stack1_Return = StackTop(stack1, &ret);
                    printf("top State is --> %i\n",ret);
                    printf("top is ==> %i \n",stack1_Return);
                    break;
                case 4:
                    ret = StackSize(stack1, &stack1_count);
                    printf("size State is --> %i\n",ret);
                    printf("Array size is ==> %i \n",Array_count);
                    break;
                case 5:
                    ret = StackMax(stack1);
                    printf("Get max State is --> %i\n",ret);
                    break;
                case 6:
                    ret = StackMin(stack1);
                    printf("Get min State is --> %i\n",ret);
                    break;
                case 7:
                    ret = StackSorting(stack1);
                    printf("sort State is --> %i\n",ret);
                    break;
                case 8:
                    ret = StackDisplay(stack1);
                    printf("Display State is --> %i\n",ret);
                    break;
                case 9:
                    stack1 = Destroy_Stack(stack1, &ret);
                    //pass satck1 by value because it is a pointer not parameter pointer to function
                    //this is the stack that i allocation it and here i need to destroy it
                    //the destroy function will return null when it success
                    goto tarek;
                    break;
                default:
                    printf("User Choice out of range !!\n");
                    break;
                }

                printf("==========================\n");
            }
        case 5:
            //create
            printf(" \n");
            printf(" \n");
            printf(" \n");
            printf(" \n");
            printf(" \n");

            scanf("%i",&Choice);

            switch(Choice)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            }

            break;
        case 6:
            printf("-> Hello to Single Linked List \n");
            while(1)
            {
                printf("\n");
                printf("===============================\n");
                printf("-> 1) Insert_Node_At_Beginning .\n");
                printf("-> 2) Insert_Node_At_End .\n");
                printf("-> 3) Insert_Node_After .\n");
                printf("-> 4) Sorting_(Insertion) .\n");
                printf("-> 5) Get_Middle_Of_List .\n");
                printf("-> 6) Reverse_Nodes .\n");
                printf("-> 7) pair_Wise_Swap nodes .\n");
                printf("-> 8) Rotate_Nodes .\n");
                printf("-> 9) Delete_Node_At_Beginning .\n");
                printf("-> 10) Delete_Node .\n");
                printf("-> 11) Delete_Middle .\n");
                printf("-> 12) swapKth_from_Begin_Last .\n");
                printf("-> 13) Searching .\n");
                printf("-> 14) print Nth From Last .\n");
                printf("-> 15) Display_All_Nodes .\n");
                printf("-> 16) Get_Length .\n");
                printf("-> 17) Quit from application .\n");
                printf("===============================\n");

                printf("\n");
                printf("UserChoice : ");
                scanf("%i", &Choice);

                switch(Choice){
                case 1:
                    Insert_At_Beginning(&ListHead);
                break;
                case 2:
                    Insert_At_End(&ListHead);
                break;

                case 3:
                    Insert_Node(ListHead);
                break;
                case 4:
                    Insertion_SSort(&ListHead);
                break;
                case 5:
                    Get_Middle_Of_SList(ListHead);
                break;
                case 6:
                    Reverse_Nodes(&ListHead);
                break;
                case 7:
                    Reverse_Nodes(&ListHead);
                break;
                case 8:
                    printf("\nPlease enter the position (All nodes after it go to begin) :) ");
                    scanf("%i",&Input_pos);
                    Rotate(&ListHead, Input_pos);
                break;
                case 9:
                    Delete_From_Beginning(&ListHead);
                break;
                case 10:
                    Delete_Element(ListHead);
                break;
                case 11:
                    ListHead = Delete_Middle(ListHead);
                break;

                case 12:
                    printf("Enter the position (from the last is the same from begin) :)? ==> ");
                    scanf("%i",&Input_value);
                    swapKth_from_Begin_Last(&ListHead, Input_value);
                break;
                case 13:
                    printf("Enter the data that you need to search about it ==> ");
                    scanf("%i",&Input_value);
                    Searching(ListHead, Input_value);
                break;
                case 14:
                    printf("Enter the position from the last :)? ==> ");
                    scanf("%i",&Input1_value);
                    printNthFromLast(ListHead, Input1_value);
                break;
                case 15:
                    Display_All_Nodes(ListHead);
                break;
                case 16:
                    ListLength = Get_Length(ListHead);
                    printf("List Length : << %i >> Nodes\n", ListLength);
                break;
                case 17:
                    printf("Quit from application \n");
                    goto tarek;
                    break;
                default:
                    printf("User Choice out of range !!\n");
                    break;
                }
            }


            break;
        case 7:
            printf("-> Hello to Double Linked List \n");
            while(1)
            {
                printf("\n");
                printf("===============================\n");
                printf("-> 1) Insert_Node_At_Beginning .\n");
                printf("-> 2) Insert_Node_At_End .\n");
                printf("-> 3) Insert_Node_After .\n");
                printf("-> 4) Insert_Node_Before .\n");
                printf("-> 5) Get_Middle_Of_List .\n");
                printf("-> 6) Reverse_Nodes .\n");
                printf("-> 7) Delete_Node_At_Beginning .\n");
                printf("-> 8) Delete_Node_At_End .\n");
                printf("-> 9) Delete_Node_At_Intermediate .\n");
                printf("-> 10) Searching .\n");
                printf("-> 11) Sorting .\n");
                printf("-> 12) Display_All_Nodes_Forward .\n");
                printf("-> 13) Display_All_Nodes_Reverse .\n");
                printf("-> 14) Get_Length .\n");
                printf("-> 15) Quit from application .\n");
                printf("===============================\n");

                printf("\n");
                printf("UserChoice : ");
                scanf("%i", &Choice);

                switch(Choice)
                {
                case 1:
                    printf("Enter the data ==> ");
                    scanf("%i",&Inputdata);
                    Insert_Node_At_Beginning(&DLL_1, Inputdata);
                    break;

                case 2:
                    printf("Enter the data ==> ");
                    scanf("%i",&Inputdata);
                    Insert_Node_At_End(DLL_1, Inputdata);
                    break;

                case 3:
                    printf("Enter the data ==> ");
                    scanf("%i",&Inputdata);
                    printf("  Enter position -->  ");
                    scanf("%i",&InputPosition);
                    Insert_Node_After(DLL_1, Inputdata, InputPosition);
                    break;

                case 4:
                    printf("Enter the data ==> ");
                    scanf("%i",&Inputdata);
                    printf("  Enter position --> ");
                    scanf("%i",&InputPosition);
                    Insert_Node_Before(DLL_1, Inputdata, InputPosition);
                    break;

                case 5:
                    Get_Middle_Of_DList(DLL_1);
                    break;

                case 6:
                    Reverse_List(&DLL_1);
                    break;

                case 7:
                    Delete_Node_At_Beginning(&DLL_1);
                    break;

                case 8:
                    Delete_Node_At_End(DLL_1);
                    break;

                case 9:
                    printf("  Enter position  -->");
                    scanf("%i",&InputPosition);
                    Delete_Node_At_Intermediate(DLL_1, InputPosition);
                    break;

                case 10:
                    printf("Enter your search data ==> ");
                    scanf("%i",&Inputdata);
                    Return_Val = Search(DLL_1, Inputdata);
                    printf("This data is in position number ==> %i \n",Return_Val);
                    break;
                case 11:
                    printf("1-Bubble sort .\n");
                    printf("2-Insertion sort .\n");
                    printf("\nChose type of sorting :) ==> ");
                    scanf("%i",&type);
                    if(1 == type)
                    {
                        Bubble_Sort(&DLL_1);
                    }
                    else if(2 == type)
                    {
                        Insertion_DSort(&DLL_1);
                    }
                    else
                    {
                        printf("Your choice is out of range :( \n");
                    }
                    break;
                case 12:
                    Display_All_Nodes_Forward(DLL_1);
                    break;

                case 13:
                    Display_All_Nodes_Reverse(DLL_1);
                    break;

                case 14:
                    ListLength = Get_Length_Of_DList(DLL_1);
                    printf("List Length : << %i >> Nodes\n", ListLength);
                    break;

                case 15:
                    printf("Quit from application \n");
                    exit(1);
                    break;

                default:
                    printf("User Choice out of range !!\n");
                    break;
                }
            }
        }
    }

    return 0;
}
