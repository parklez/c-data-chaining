#include <stdio.h>
/* https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm */
#include <stdlib.h>
#include <string.h>

/* The following structure will store an integer code,
and a char name[10], as well as a pointer of the
structure type "chain" that points to another struct. */
typedef struct chain{
    int code;
    char name[10];
    struct chain *next;
}chain;

chain *link, *aux, *aux2, *start;

void clear_stdin(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void fullfill_struct(){
    puts("Integer code number:");
    scanf("%d", &link->code);
    clear_stdin();
    puts("10 char long name:");
    scanf("%s", &link->name);
    clear_stdin();
}

void append_new_data(){
   // If this is the very first data in our chain...
    if (start == NULL){
        puts("-> Creating the very first element of the chain.");
        // returns the adress of the new allocated structured of the type "chain" we have defined. (with its size)
        link = (chain*)malloc(sizeof(chain));
        fullfill_struct();
        start = link;
        link->next = NULL;
        aux = link;
    }
    // If this is not the first, then we need to go through every single one,
    // starting from the "start" until we find the last one to append.
    else {
        puts("-> Appending a new element to the chain.");
        link = start;
        // ???
        aux = start;
        // While there's still data to go through
        while (link->next != NULL){
            // sets link to its next struct
            link = link->next;
            // ???
            aux = link;
        }
       link = (chain*)malloc(sizeof(chain));
       // This line will make the last element point to the newly created link
       aux->next = link;
       // And by default the new element points to nothing
       link->next = NULL;
       // Now the aux will be poiting to the latest created element
       aux = link;
       fullfill_struct();
    }
}

int is_code_unique(int code){
    // This code will return 1 in case code exists in our chained data
    // and 0 in case it doesn't.

    if (start == NULL){
        return 0;
    }

    link = start;
    int exists = 0;
    int i = 0;
    
    while (link->next != NULL){
        link = link->next;
        i++;
    }

    link = start;
    for (int j = 0; j < i+1;j++){
        if (link->code == code){
            exists = 1;
            break;
        }
    }
    return exists;
}

int is_name_unique(char name[10]){
    // This code will return 1 in case code exists in our chained data
    // and 0 in case it doesn't.

    if (start == NULL){
        return 0;
    }

    link = start;
    int exists = 0;
    int i = 0;
    
    while (link->next != NULL){
        link = link->next;
        i++;
    }

    link = start;
    for (int j = 0; j < i+1;j++){
        if (strcmp(link->name, name) == 0){
            exists = 1;
            break;
        }
    }
    return exists;
}

void print_all_data(){
    system("clear");
    if (start == NULL){
        puts("This list is empty.");
        puts("Press [ENTER] to return.");
        getchar();
        return;
    }
    else{
        link = start;
        int i = 0;
        // Finding out how long is the chain
        while (link->next != NULL){
            link = link->next;
            i++;
        }

        // Printing the whole chain based off of the amount of times we must advance the pointers.
        link = start;
        puts("--------------------");
        for (int j = 0; j < i+1; j++){
            printf("Index: %i\n", j);
            printf("link->code: %i\n", link->code);
            printf("link->name: %s\n", link->name);
            puts("--------------------");
            link = link->next;
        }

        puts("Press [ENTER] to return.");
        getchar();
    }
}

int main(){
    link = NULL;
    aux = NULL;
    aux2 = NULL;
    start = NULL;

    int running = 1;
    char option;
    while (running){
        system("clear");
        puts("Menu");
        puts("--------------------");
        puts("1. Add new data element");
        puts("2. Print all chained data");
        puts("");
        puts("0. Exit");
        puts("--------------------");
        printf("Number: ");
        scanf(" %c", &option);
        clear_stdin();
        if (option == '1'){
            append_new_data();
        }
        else if (option == '2'){
            print_all_data();
        }
        else{
            running = 0;
        }
    }
    return 0;
}
