/*
 ################################ main_clinic.c  ######################
 Author      : Aya Ramadan
 Version     : 1
 */

#include "clinic.h"

int main()
{

    printf("Please\nif you are an admin Enter \'1\'\n");
    printf("If you are a user  Enter \'2\'\n");
    printf("if you want to out enter\'0\' \n");
    int mode;
    fflush(stdin);
    scanf(" %d", &mode);
    printf("------------------------------------->>\n");
    if (mode == 1)
    {
        printf("You are in admin mode \n");
        admin_mode();
    }

    else if (mode == 2)
    {
        printf("You are in user mode \n");
        user_operation();
    }

    else if (mode == 0)
    {
        return 0;
    }
    else
    {
        printf("This mode is not found!!!\n");
        printf("---------------------------------------\n");
        main();
    }
    return 0;
}
//-----------------------------------------
void admin_mode()
{
    int pass_word;
    short num_tries = 3;
    do
    {
        printf("Please enter password number: ");
        fflush(stdin);
        scanf("%d", &pass_word);

        if (pass_word == 1234)
        {
            printf("------------------------------->>\n");
            num_tries = 3;
            admin_operation();
            break;
        }
        else
        {
            num_tries--;
            printf("\"this password is incorrect\"\n");
            if (num_tries == 0)
            {
                printf("you finished all tries\n");
                break;
            }
            printf("please Try again You have %d tries\n", num_tries);
            printf("---------------------------------\n");
        }

    } while (num_tries > 0);
}
//-----------------------------------------
void operation()
{
    printf("please choose the operation you want to do: \n");
    printf("   ----------------  \n");
    printf("If you want to Add new patient record enter \'1\' \n");
    printf("If you want to Edit patient record enter \'2\'\n");
    printf("If you want to Reserve a slot with the doctor enter \'3\'\n");
    printf("If you want to Cancel reservation enter \'4\'\n");
    printf("   ----------------  \n");
    printf("If you want to change mode enter \'5\'\n");
    printf("if you want to out enter\'0\' \n");
}
//-----------------------------------------
void admin_operation()
{
    int op;
    operation();
    fflush(stdin);
    scanf("%d", &op);

    if (op == 1)
        Add_new_patient();
    else if (op == 2)
        Edit_patient();
    else if (op == 3)
        Reserve_a_slot();
    else if (op == 4)
        Cancel_reservation();
    else if (op == 5)
    {
        main();
        return;
    }
    else if (op == 0)
        return;
    else
    {
        printf("This operaation is not found please choose correct operation \n");
        printf("   ----------------  \n");
    }

    admin_operation();
}
//-----------------------------------------
void Add_new_patient()
{
    node = (patient *)malloc(sizeof(patient));
    if (node == NULL)
        printf("This opeartion cann't done there is no enough memory");
    else
    {
        short check = 0;
        check = basic_data(node); // check if the enter data is valid or not valid
        if (size == 0 && check == 1)
        {
            head = node;
        }
        else if (check == 1)
        {
            /* chack  if id is found or not to avoid repeat ID*/
            ID_found = search(node->ID);
            if (ID_found == 1)
            {
                printf("This ID is founded before\n");
                printf("This add is fialed\n");
            }
            /* if the id is not found add this node*/
            if (ID_found == 0)
            {
                tail->next = node;
            }
        }
        /* if the id is not found and enter data is valid*/
        if (ID_found == 0 && check == 1)
        {
            node->slot = 0;
            node->next = NULL;
            tail = node;
            size++;
            printf("This add done succesfully\n");
        }
    }
}
//-----------------------------------------
void Edit_patient()
{
    short edit_found;
    printf("Enter the ID of patient you want to Edit his data :");
    scanf("%hd", &patient_id);
    ID_found = search(patient_id);
    if (ID_found == 0)
    {
        printf("This ID is not found\n");
    }
    else
    {

        patient *ptr = (patient *)malloc(sizeof(patient));
        basic_data(ptr);
        edit_found = search_edit(ptr->ID); // check if the edit ID is found before or not
        if (edit_found == 1)
        {
            printf("THis Id is founded before ,so the edit cannot be done\n");
            printf("   ----------------  \n");
            free(ptr);
        }
        else
        {
            strcpy(pos_patient->name, ptr->name);
            strcpy(pos_patient->gender, ptr->gender);
            pos_patient->age = ptr->age;
            pos_patient->ID = ptr->ID;
            printf("This Edit done succesfully\n");
        }
    }
}
//-----------------------------------------
void Reserve_a_slot()
{
    if (num_slot == 0)
    {
        printf("Reservation completed\n");
        return;
    }
    short n_slot, id;
    print_slots(&arr);

    printf("Enter the ID: ");
    scanf("%hd", &id);
    ID_found = search(id);
    if (ID_found == 0)
    {
        printf("This ID is not found\n");
        return;
    }
    else
    {
        short change = 0, check = 0;
        if (pos_patient->slot != 0)
        {
            printf("You are reserved befor at==> %s \n", arr_reservation[pos_patient->slot - 1]);
            printf("If you want to change before Reservation enter \'1\' \n");
            printf("otherwise this operation will be canceled '\n");
            scanf("%hd", &change);
            if (change == 1)
            {
                printf("Enter the slot: ");
                scanf("%hd", &n_slot);
                if (n_slot == 1 || n_slot == 2 || n_slot == 3 || n_slot == 4 || n_slot == 5)
                {
                    check = check_slot(n_slot);
                    if (check == 1)
                    {
                        printf("This slot is reserved for anthor persion\n");
                        return;
                    }
                    else
                    {
                        add_slots(pos_patient->slot);
                        pos_patient->slot = n_slot;
                        delet_slots(n_slot);
                        printf("This  edit Reservation is done succesfully\n");
                    }
                }
                else
                    printf("invalid slot");
            }
            else
            {
                printf("This peration canceled\n");
                return;
            }
        }
        else
        {
            printf("Enter the slot: ");
            scanf("%hd", &n_slot);

            if (n_slot == 1 || n_slot == 2 || n_slot == 3 || n_slot == 4 || n_slot == 5)
            {
                check = check_slot(n_slot);
                if (check == 1)
                {
                    printf("This slot is reserved for anthor persion");
                    return;
                }
                else
                {
                    pos_patient->slot = n_slot;
                    delet_slots(n_slot);
                    printf("This Reservation is done succesfully\n");
                }
            }
            else
                printf("invalid slot\n");
        }
    }
}
//-----------------------------------------
void Cancel_reservation()

{
    short id;
    printf("Enter ID: ");
    scanf("%hd", &id);
    ID_found = search(id);
    if (ID_found == 0)
    {
        printf("This ID is not found\n");
        return;
    }
    else
    {

        if (pos_patient->slot == 0)
        {
            printf("There is no reservation to Cancel\n");
        }
        else
        {
            add_slots(pos_patient->slot);
            pos_patient->slot = 0;
            printf("This cancel is done succesfully\n");
        }
    }
}
//-----------------------------------------
short basic_data(patient *ptr)
{
    printf("Enter the patient name: ");
    scanf("%s", &ptr->name);
    printf("Enter the patient gender: ");
    scanf("%s", &ptr->gender);
    printf("Enter the patient age:  ");
    if (scanf("%hd", &ptr->age) == 0)
    {
        printf("invalid age\n");
        printf("This add is fialed\n");
        return 0;
    }
    printf("Enter the patient ID number:  ");
    if (scanf("%hd", &ptr->ID) == 0)
    {
        printf("invalid ID\n");
        printf("This add is fialed\n");
        return 0;
    }
    return 1;
}
//-----------------------------------------
short search(short element)
{
    patient *found = head;
    while (found != NULL)
    {
        if (found->ID == element)
        {
            pos_patient = found; // position of patient
            return 1;
        }
        found = found->next;
    }

    return 0;
}
//-----------------------------------------
short search_edit(short element)
{
    patient *found = head;
    while (found != NULL)
    {
        if (found->ID == element && found != pos_patient) /*expect the id I want to edit*/
        {
            return 1;
        }
        found = found->next;
    }

    return 0;
}
//-----------------------------------------
void print(patient *ptr)
{
    printf("%s\n", ptr->name);
    printf("%s\n", ptr->gender);
    printf("%hd\n", ptr->age);
    printf("%hd\n", ptr->ID);
}
//-----------------------------------------
/*print the exist slots */
void print_slots(char arr[][15])
{
    for (int i = 0; i < 5; i++)
    {
        if (arr[i][0] == '\0')
            continue;
        printf(" %s enter %d \n", arr[i], i + 1);
    }
}
//-----------------------------------------
/* delet slot after  the reservation */
void delet_slots(short num)
{
    strcpy(arr[num - 1], cpy);
    arr[num - 1][0] = '\0';
    num_slot--;
}
//-----------------------------------------
short check_slot(short n_slot)
{

    patient *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->slot == n_slot)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}
//-----------------------------------------
/*add slot after cancel the reservation*/
void add_slots(short num)
{
    strcpy(arr[num - 1], arr_reservation[num - 1]);
    num_slot++;
}
//-----------------------------------------
/*User mode*/
void user_operation()
{
    int operation;
    printf("please choose the operation you want to do: \n");
    printf("   ----------------  \n");
    printf("If you want to View patient record enter \'1\' \n");
    printf("If you want to View today's reservation enter \'2\'\n");
    printf("   ----------------  \n");
    printf("If you want to change mode enter \'5\'\n");
    printf("if you want to out enter\'0\' \n");
    fflush(stdin);
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        veiw_record();
        break;
    case 2:
        todays_reservation();
        break;
    case 5:
    {
        main();
        return;
    }
    break;
    case 0:
    {
        return;
    }
    break;
    default:
    {
        printf("This operaation is not found please choose correct operation \n");
        printf("   ----------------  \n");
    }
    }
    user_operation();
}
//-----------------------------------------
void veiw_record()
{
    short id;
    printf("Enter ID: ");
    scanf("%hd", &id);
    ID_found = search(id);
    if (ID_found == 0)
    {
        printf("This ID is not found\n");
        return;
    }
    print(pos_patient);
}
//-----------------------------------------
void todays_reservation()
{
    if (num_slot == 5)
    {
        printf("There is no any reservation today\n");
        return;
    }
    patient *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->slot != 0)
        {
            printf("ID-->>%hd --->>  at %s \n", ptr->ID, arr_reservation[ptr->slot - 1]);
        }
        ptr = ptr->next;
    }
}