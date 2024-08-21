#ifndef ONP_H
#define ONP_H

typedef struct list {
    char value;
    struct list* next;
} stackType;

typedef struct intList {
    int value;
    struct intList* next;
} intStackType;

void init(stackType* head);
void push(stackType* stack, char value);
int isEmpty(stackType* stack);
char pop(stackType* stack);
char top(stackType* stack);
void clearStack(stackType* stack);

void initInt(intStackType* head);
void pushInt(intStackType* stack, int value);
int isEmptyInt(intStackType* stack);
int popInt(intStackType* stack);
int topInt(intStackType* stack);
void clearIntStack(intStackType* stack);


void firstPrint(stackType* stack, stackType* reversedCopy);
void convertToChar(stackType* stack, int toConvert);
void addSpace(stackType* stack);
void convertToONP(stackType* output, stackType* tmp);

#endif