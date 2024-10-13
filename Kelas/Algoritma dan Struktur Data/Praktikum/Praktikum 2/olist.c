#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main(){
    ListStatik l;
    CreateListStatik(&l);
    readList(&l);

    ListStatik temporary_list;
    CreateListStatik (&temporary_list);

    ListStatik temporary_count;
    CreateListStatik (&temporary_count);
    
    int i;
    for (i = 0; i < listLength(l); i++){
        insertLast(&temporary_list, ELMT(l, i));
    }

    int j;
    if (listLength(l) >= 1){
        i = 0;
        while (i < listLength(temporary_list)){
            j = 0;
            while (j < listLength(temporary_list)){
                if (j == i){
                    break;
                }
                if (ELMT(temporary_list, j) == ELMT(temporary_list, i)){
                    deleteAt(&temporary_list, &ELMT(temporary_list, i), i);
                    i -= 1;
                }
                j += 1;
            }
            i += 1;
        }
    }
    
    printList(temporary_list);
    printf("\n");

    if (listLength(l) != 0){
        for (i = 0; i < listLength(temporary_list); i++){
            insertLast(&temporary_count, 0);
        }

        for (i = 0; i < listLength(l); i++){
            for (j = 0; j < listLength(temporary_list); j++){
                if (ELMT(l, i) == ELMT(temporary_list, j)){
                    ELMT(temporary_count, j) += 1;
                }
            }
        }

        for (i = 0; i < listLength(temporary_list); i++){
            printf("%d %d\n", ELMT(temporary_list, i), ELMT(temporary_count, i));
        }
    }
}