#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main(){
    ListStatik l;
    CreateListStatik(&l);
    readList(&l);

    int multiplier;
    multiplier = 1;
    int money;
    money = 0;
    int i;
    for (i = listLength(l) - 1; i >= 0; i--){
        money += (ELMT(l, i) * multiplier);
        multiplier *= 10;
    }

    money += 1;
    int temp_index, temp_multiplier, temp_result;
    temp_multiplier = 1;
    temp_index = 1;
    temp_result = money / temp_multiplier;
    while (temp_result >= 10){
        temp_index += 1;
        temp_multiplier *= 10;
        temp_result = money / temp_multiplier;
    }
    
    ListStatik result;
    CreateListStatik (&result);
    int helper;
    for (i = 0; i < temp_index; i++){
        helper = money / temp_multiplier;
        insertLast(&result, helper);
        money -= helper * temp_multiplier;
        temp_multiplier /= 10;
    }

    for (i = 0; i < listLength(l); i++){
        ELMT(l, i) = MARK;
    }

    for (i = 0; i < listLength(result); i++){
        ELMT(l, i) = ELMT(result, i);
    }

    printf("%d", ELMT(l, 0));
    for (i = 1; i < listLength(l); i++){
        printf(" %d", ELMT(l, i));
    }
    printf("\n");
    return 0;
}