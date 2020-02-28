#include <stdio.h>
#include <stdlib.h>


typedef struct stack{
    int code;
    struct stack *next;
    struct stack *back;
}stack;

void clear_stdin(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void push(stack *top, stack *aux){
    // If this is the first element in our stack, we add one
    if (top == NULL){
        top = (stack*)malloc(sizeof(stack));
        top->next = NULL;
        top->back = NULL;
        aux = top;
    }
    else {
        top = (stack*)malloc(sizeof(stack));
        aux->next = top;
        top->back = aux;
        aux = top;
    }
    puts("Type in a code:");
    scanf("%d", &top->code);
}

void pop(stack *top, stack *aux){
    if (top->next == NULL && top->back == NULL){
        free(top);
        top = NULL;
        aux = NULL;
    }
    else{
        aux = top;
        top = top->back;
        top->next = NULL;
        free(aux);
        aux = top;
    }
}

void print_top(stack *top){
    if (*top == NULL){
        puts("top is null");
        getchar();
        return;
    }
    printf("number: %i", *top->code);
    getchar();
}


int main(){
    int running = 1;
    char option;

    stack *top, *aux;

    while (running){
        system("clear");
        puts("Stack menu");
        puts("--------------------");
        puts("1. Push");
        puts("2. Pop");
        puts("3. Top");
        puts("");
        puts("0. Exit");
        puts("--------------------");
        puts("Choice:");
        scanf("%c", &option);
        //clear_stdin();

        if (option == '1'){
            push(top, aux);
        }
        else if (option == '2'){
            pop(top, aux);
        }
        else if (option == '3'){
            print_top(*top);
        }
        else if (option == '0'){
            running = 0;
        }
    }
    return 0;
}