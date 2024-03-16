/*
 ################################ clinic.h  ######################
 Author      : Aya Ramadan
 Version     : 1
 */

#ifndef CLINC_H_
#define CLINC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size_name 20 /* to name in struct */

/* Node to basic data */
typedef struct basic_information
{
    char name[size_name];
    char gender[7];
    short age;
    short ID;
    short slot;
    struct basic_information *next;

} patient;

/*creat node */
patient *node = NULL;
patient *head = NULL;
patient *tail = NULL;
int size = 0;

void admin_mode();

void operation();
void admin_operation();

void Add_new_patient();
void Edit_patient();
void Reserve_a_slot();
void Cancel_reservation();

void print(patient *ptr);
void print_slots();
short basic_data(patient *ptr);
void add_slots(short num);
short search(short element);
short search_edit(short element);
void delet_slots(short num);
/* to check if the slot is reserved before or not */
short check_slot(short n_slot);

void user_operation();
void veiw_record();
void todays_reservation();

/* useed to get position of the patient */
patient *pos_patient = NULL;
short patient_id;
/*arr to delet and add reservation */
char arr[5][15] = {"2pm to 2:30pm", "2:30pm to 3pm",
                   "3pm to 3:30pm", "4pm to 4:30pm",
                   "4:30pm to 5pm"};

/* arr to help me to identify the reservation time ,
used in add and delet reservation (function) and view the reservation */
char arr_reservation[5][15] = {"2pm to 2:30pm", "2:30pm to 3pm",
                               "3pm to 3:30pm", "4pm to 4:30pm",
                               "4:30pm to 5pm"};

/* to check if all reservation is reserved or not */
short num_slot = 5;
char cpy[25];
short ID_found = 0;

#endif