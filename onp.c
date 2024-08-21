#include <stdio.h>
#include <stdlib.h>
#include "ONP.h"

void init(stackType* head) {
    head->next = NULL;
}
void push(stackType* stack, char value) {
    stackType* newNode = (stackType*)malloc(sizeof(stackType));
    newNode->value = value;
    newNode->next = stack->next;
    stack->next = newNode;
}
int isEmpty(stackType* stack) {
    return stack->next == NULL;
}
char pop(stackType* stack) {
    char element = stack->next->value;
    stackType* toBeRemoved = stack->next;
    stack->next = stack->next->next;
    free(toBeRemoved);
    return element;
}
char top(stackType* stack) {
    if(isEmpty(stack)){
        return 0;
    } return stack->next->value;
}
void clearStack(stackType* stack){
    while(!isEmpty(stack)){
        pop(stack);
    }
}

void initInt(intStackType* head) {
    head->next = NULL;
}
void pushInt(intStackType* stack, int value) {
    intStackType* newNode = (intStackType*)malloc(sizeof(intStackType));
    newNode->value = value;
    newNode->next = stack->next;
    stack->next = newNode;
}
int isEmptyInt(intStackType* stack) {
    return stack->next == NULL;
}
int popInt(intStackType* stack) {
    int element = stack->next->value;
    intStackType* toBeRemoved = stack->next;
    stack->next = stack->next->next;
    free(toBeRemoved);
    return element;
}
int topInt(intStackType* stack) {
    if(isEmptyInt(stack)){
        return 0;
    } return stack->next->value;
}
void clearIntStack(intStackType* stack){
    while(!isEmptyInt(stack)){
        popInt(stack);
    }
}

void firstPrint(stackType* stack, stackType* reversedCopy) {
    stackType reversedStack;
    init(&reversedStack);
    while (!isEmpty(stack)) { //odwrocenie stosu
        char c= pop(stack);
        push(&reversedStack, c);
        push(reversedCopy, c);
    }
    printf("\n");
    char toPrint = pop(&reversedStack); //do pierwszego by nie byl spacja
    if(toPrint != ' '){
        switch (toPrint) {
            case 'F':
                printf("IF");
                break;
            case 'I':
                printf("MIN");
                break;
            case 'A':
                printf("MAX");
                break;
            default:
                printf("%c", toPrint);
                break;
        }
    }
    while (!isEmpty(&reversedStack)) {
        char toprint = pop(&reversedStack);
        switch (toprint) {
            case 'F':
                printf("IF");
                break;
            case 'I':
                printf("MIN");
                break;
            case 'A':
                printf("MAX");
                break;
            default:
                printf("%c", toprint);
                break;
        }
    }
    printf("\n");
}
void convertToChar(stackType* stack, int toConvert){
    char *tab;
    int size=0;
    int toConvertTmp=toConvert; //do zliczenia
    while(toConvertTmp){
        toConvertTmp= toConvertTmp / 10;
        size++;
    }
    tab=(char*)malloc(size*sizeof(char));
    for(int i=0; i<size; i++){
        tab[i]= (toConvert % 10) + '0';
        toConvert= toConvert / 10;
    }
    for(int j=size-1; j>=0; j--){
        push(stack,tab[j]);
    }
    free(tab);
}
void addSpace(stackType* stack){
    if(top(stack)!=' '){
        push(stack, ' ');
    }
}
void convertToONP(stackType* output, stackType* tmp) {
    char item;
    do {
        item = getchar();
        int minmaxcounter = 1;
        switch (item) {
            case '(':
                push(tmp, item);
                break;
            case ')': {
                while (top(tmp)) {
                    char tmpItem = pop(tmp);
                    if (tmpItem == ',') {
                        minmaxcounter++;
                    } else if (tmpItem != '(') {
                        addSpace(output);
                        push(output, tmpItem);
                    } else break;
                }
                if (top(tmp) == 'I' || top(tmp) == 'A') {
                    addSpace(output);
                    push(output, pop(tmp));
                    convertToChar(output, minmaxcounter);
                }
            }
                break;
            case '*':
            case '/':
                while (1) {
                    if (isEmpty(tmp) || top(tmp) == '(' || top(tmp) == '+' || top(tmp) == '-'|| top(tmp)==',') {
                        push(tmp, item);
                        break;
                    } else {
                        addSpace(output);
                        push(output, pop(tmp));
                    }
                }
                break;
            case '+':
            case '-':
                while (1) {
                    if (isEmpty(tmp) || top(tmp) == '(' || top(tmp)==',') {
                        addSpace(output);
                        push(tmp, item);
                        break;
                    } else {
                        addSpace(output);
                        push(output, pop(tmp));
                    }
                }
                break;
            case 'M': {
                char next, nextnext;
                next = getchar(); //I lub A
                nextnext = getchar(); //N lub X

                if (next == 'I' && nextnext == 'N') {
                    push(tmp, next);
                } else if (next == 'A' && nextnext == 'X') {
                    push(tmp, next);
                } else printf("Nieprawidłowy format MIN/MAX\n");
            }
                break;
            case 'I':{
                char next;
                next=getchar();
                if(next=='F'){
                    push(tmp, next);
                    break;
                }else{
                    printf("Nieprawidłowy format IF\n");
                    return;
                }
            }
            case 'N':{
                while (1) {
                    if (isEmpty(tmp) || top(tmp) == '(' || top(tmp) == '+' || top(tmp) == '-'|| top(tmp)==','|| top(tmp) == '*'|| top(tmp)=='/'|| top(tmp)=='N') {
                        push(tmp, item);
                        break;
                    } else {
                        addSpace(output);
                        push(output, pop(tmp));
                    }
                }
                break;
            }
            case ',':{
                while(top(tmp)!='('){
                    if(top(tmp)!=',') {
                        addSpace(output);
                        push(output, pop(tmp));
                    } else {
                        break;
                    }
                }
                push(tmp, item);
            }
                break;
            case '.':
                while (!isEmpty(tmp)) {
                    addSpace(output);
                    push(output, pop(tmp));
                }
                break;
            case ' ':
                if(top(output)==' ') break;
                else push(output, item);
                break;
            case '\n':
                break;
            default:
                push(output, item);
                break;
        }
    } while (item != '.');
    clearStack(tmp);
}