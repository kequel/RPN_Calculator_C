#include <stdio.h>
#include "ONP.h"

int getIntFromStack(stackType* stack){
    while(top(stack)==' ' || top(stack)=='\n') pop(stack);
    int dec=1;
    int i=0;
    int number=0;
    stackType numberStack;
    while(!isEmpty(stack) && top(stack)!=' ') {
        push(&numberStack, pop(stack));
        i++;
    }
    while(i!=0){
        number=number+((pop(&numberStack)-'0')*dec);
        dec=dec*10;
        i--;
    }
    return number;
}
void printIntStack(intStackType* stack){
    intStackType reversedTmpStack;
    int i=0;
    while(!isEmptyInt(stack)){ //wydrukuj number stak
        printf("%d ", topInt(stack));
        pushInt(&reversedTmpStack, popInt(stack));
        i++;
    }
    printf("\n");
    while(i>0){ // przywroc go
        pushInt(stack, popInt(&reversedTmpStack));
        i--;
    }
}
int count(stackType* stack, int* result){
    intStackType numbers;
    initInt(&numbers);
    *result=0;
    int tmp;
    while(!isEmpty(stack)) {
        switch(top(stack)){
            case '+':
                printf("+ ");
                printIntStack(&numbers);
                *result= popInt(&numbers)+ popInt(&numbers);
                pushInt(&numbers, *result);
                pop(stack);
                break;
            case '-':
                printf("- ");
                printIntStack(&numbers);
                tmp=popInt(&numbers);
                *result= popInt(&numbers)-tmp ;
                pushInt(&numbers, *result);
                pop(stack);
                break;
            case '*':
                printf("* ");
                printIntStack(&numbers);
                *result= popInt(&numbers)* popInt(&numbers);
                pushInt(&numbers, *result);
                pop(stack);
                break;
            case '/':
                printf("/ ");
                printIntStack(&numbers);
                tmp=popInt(&numbers);
                if (tmp == 0) {
                    clearIntStack(&numbers);
                    clearStack(stack);
                    printf("ERROR\n");
                    return -1;
                }
                *result= popInt(&numbers)/tmp ;
                pushInt(&numbers, *result);
                pop(stack);
                break;
            case 'N':
                printf("N ");
                printIntStack(&numbers);
                *result= popInt(&numbers)*(-1) ;
                pushInt(&numbers, *result);
                pop(stack);
                break;
            case 'F': {
                printf("IF ");
                printIntStack(&numbers);
                int c = popInt(&numbers);
                int b = popInt(&numbers);
                int a = popInt(&numbers);
                if (a > 0) *result = b;
                else *result = c;
                pushInt(&numbers, *result);
                pop(stack);
                break;
            }
            case 'A': {
                pop(stack); // Usunięcie A
                int count = getIntFromStack(stack);
                printf("MAX%d ", count);
                printIntStack(&numbers);
                *result = popInt(&numbers);
                for (int i = 1; i < count; i++) {
                    if (topInt(&numbers) > *result) *result = popInt(&numbers);
                    else popInt(&numbers);
                }
                pushInt(&numbers, *result);
                break;
            }

            case 'I': {
                pop(stack); // Usunięcie I
                int count = getIntFromStack(stack);
                printf("MIN%d ", count);
                printIntStack(&numbers);
                *result = popInt(&numbers);
                for (int i = 1; i < count; i++) {
                    if (topInt(&numbers) < *result) *result = popInt(&numbers);
                    else popInt(&numbers);
                }
                pushInt(&numbers, *result);
                break;
            }
            case ' ':
                pop(stack);
                break;
            default:
                pushInt(&numbers, getIntFromStack(stack));
                break;
        }
    }
    clearIntStack(&numbers);
    clearStack(stack);
    return 0;
}
int main() {
    stackType tmp, output, toCount;
    init(&tmp);
    init(&output);
    init(&toCount);
    int N;
    int result;
    printf("NUMBER OF EQUATIONS:\n");
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        printf("    EQUATION %d:\n", i+1);
        convertToONP(&output, &tmp);
        printf("    CONVERTED TO ONP: ");
        firstPrint(&output, &toCount);
        printf("    COUNTING PROCESS:\n");
        if( count(&toCount, &result)==0){
            printf("    RESULT: ");
            printf("%d", result);
            printf("\n\n");
        }
    }
    return 0;
}