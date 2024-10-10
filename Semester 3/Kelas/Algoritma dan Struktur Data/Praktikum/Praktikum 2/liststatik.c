#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){ //DONE
    int i;
    for (i = 0; i < CAPACITY; i++){
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l){ //DONE
    int count = 0;
    int i;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) == MARK){
            break;
        }
        count += 1;
    }
    return count;
}

IdxType getFirstIdx(ListStatik l){ //DONE
    int i = 0;
    return i;
}

IdxType getLastIdx(ListStatik l){ //DONE
    int i;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) == MARK){
            return (i - 1);
        }
    }
}

boolean isIdxValid(ListStatik l, IdxType i){ //DONE
    if (0 <= i && i < CAPACITY){
        return true;
    }
    else{
        return false;
    }
}

boolean isIdxEff(ListStatik l, IdxType i){ //DONE
    if (0 <= i && i < listLength(l)){
        return true;
    }
    else {
        return false;
    }
}

boolean isEmpty(ListStatik l){ //DONE
    if (listLength(l) == 0){
        return true;
    }
    else {
        return false;
    }
}

boolean isFull(ListStatik l){ //DONE
    if (listLength(l) == CAPACITY){
        return true;
    }
    else {
        return false;
    }
}

void readList(ListStatik *l){ //DONE
    int panjang;
    int i;
    scanf("%d", &panjang);
    CreateListStatik(l);
    while(panjang < 0 || panjang > CAPACITY){
        scanf("%d", &panjang);
    }
    for (i = 0; i < panjang; i++){
        scanf("%d", &ELMT(*l, i));
    }    
}

void printList(ListStatik l){ //DONE
    int i;
    if (listLength(l) == 0){
        printf("[]");
    }
    else {
        printf("[");
        for (i = 0; i < listLength(l); i++){
            printf("%d", ELMT(l, i));
            if (i < (listLength(l) - 1)){
                printf(",");
            }
        }
        printf("]");
    }
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){ //DONE
    int i;
    if (plus){
        for (i = 0; i < listLength(l1); i++){
            ELMT(l1, i) += ELMT(l2, i);
        }
        return l1;
    }
    else {
        for (i = 0; i < listLength(l1); i++){
            ELMT(l1, i) -= ELMT(l2, i);
        }
        return l1;
    }
}

boolean isListEqual(ListStatik l1, ListStatik l2){ //DONE
    int i;
    if (listLength(l1) == listLength(l2)){
        for (i = 0; i < listLength(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)){
                return false;
            }
        }
        return true;
    }
    return false;
}

int indexOf(ListStatik l, ElType val){ //DONE
    int i;
    if (listLength(l) == 0){
        return IDX_UNDEF;
    }
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l, i) == val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){ //DONE
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l, i) > *max){
            *max = ELMT(l, i);
        }
    }
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l, i) < *min){
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){ //DONE
    int i;
    for (i = (listLength(*l) - 1); i >= 0; i--){
        ELMT(*l, i + 1) = ELMT(*l, i);
    }
    ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){ //DONE
    int i;
    for (i = (listLength(*l) - 1); i >= idx; i--){
        ELMT(*l, i + 1) = ELMT(*l, i);
    }
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){ //DONE
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){ //DONE
    int i;
    *val = ELMT(*l, 0);
    for (i = 0; i < listLength(*l); i++){
        ELMT(*l, i) = ELMT(*l, (i + 1));
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){ //DONE
    int i;
    *val = ELMT(*l, idx);
    for (i = idx; i < listLength(*l); i++){
        ELMT(*l, i) = ELMT(*l, (i + 1));
    }
}

void deleteLast(ListStatik *l, ElType *val){ //DONE
    *val = ELMT(*l, (listLength(*l) - 1));
    ELMT(*l, (listLength(*l) - 1)) = ELMT(*l, (listLength(*l)));
}

void sortList(ListStatik *l, boolean asc){ //DONE
    int temp;
    if (asc){
        for (int i = 0; i < listLength(*l); i++){
            for (int j = 0; j < (listLength(*l) - 1); j++){
                if (ELMT(*l, j) > ELMT(*l, (j + 1))){
                    temp = ELMT(*l, j);
                    ELMT (*l, (j)) = ELMT(*l, (j + 1));
                    ELMT(*l, (j + 1)) = temp;
                }
            }
        }
    }
    else {
        for (int i = 0; i < listLength(*l); i++){
            for (int j = 0; j < (listLength(*l) - 1); j++){
                if (ELMT(*l, j) < ELMT(*l, (j + 1))){
                    temp = ELMT(*l, j);
                    ELMT (*l, (j)) = ELMT(*l, (j + 1));
                    ELMT(*l, (j + 1)) = temp;
                }
            }
        }
    }
}