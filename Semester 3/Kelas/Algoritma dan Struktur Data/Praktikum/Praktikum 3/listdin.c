#include <stdio.h>
#include "boolean.h"
#include "listdin.h"
#include "stdlib.h"

void CreateListDin(ListDin *l, int capacity){ //DONE
    BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l){ //DONE
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

int listLength(ListDin l){ //DONE
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){ //DONE
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){ //DONE
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i){ //DONE
    return (i >= 0 && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){ //DONE
    return (i >= 0 && i <= NEFF(l));
}

boolean isEmpty(ListDin l){ //DONE
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l){ //DONE
    return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l){ //DONE
    int N;
    int i;
    scanf("%d", &N);

    while (N < 0 || N > CAPACITY(*l)){
        scanf("%d", &N);
    }
    CreateListDin(l, N);

    if (N == 0){
        NEFF(*l) = 0;
    }
    else {
        NEFF(*l) = N;
        for (i = 0; i < N; i++){
            scanf("%d", &ELMT(*l, i));
        }   
    }
    
}

void printList(ListDin l){ //DONE
    int i;
    if (listLength(l) == 0){
        printf("[]");
    }
    else {
        printf("[");
        printf("%d", ELMT(l, 0));
        for (i = 1; i < NEFF(l); i++){
            printf(",%d", ELMT(l, i));
        }
        printf("]");
    }
}

void copyList(ListDin lIn, ListDin *lOut);
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){ //DONE
    int i;
    ListDin l3;
    CreateListDin (&l3, CAPACITY(l1));
    copyList(l1, &l3);
    if (plus){
        for (i = 0; i < NEFF(l1); i++){
            ELMT(l3,i) += ELMT(l2,i);
        }
    }
    else {
        for (i = 0; i < NEFF(l1); i++){
            ELMT(l3,i) -= ELMT(l2,i);
        }
    }
    return l3;
}

boolean isListEqual(ListDin l1, ListDin l2){ //DONE
    int i;
    if (NEFF(l1) == NEFF(l2)){
        for (i = 0; i < NEFF(l1); i++){
            if (ELMT(l1,i) != ELMT(l2,i)){
                return false;
            }
        }
        return true;
    }
    return false;
}

IdxType indexOf(ListDin l, ElType val){ //DONE
    int i;
    for (i = 0; i < NEFF(l); i++){
        if (ELMT(l, i) == val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min){ //DONE
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    int i;
    for (i = 1; i < NEFF(l); i++){
        if (ELMT(l, i) > *max){
            *max = ELMT(l, i);
        }
    }
    for (i = 1; i < NEFF(l); i++){
        if (ELMT(l, i) < *min){
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut){ //DONE
    int i;
    dealocateList(lOut);
    CreateListDin (lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}

ElType sumList(ListDin l){ //DONE
    int i;
    ElType count = 0;
    for (i = 0; i < NEFF(l); i++){
        count += ELMT(l, i);
    }
    return count;
}

int countVal(ListDin l, ElType val){ //DONE
    int i;
    int count;
    count = 0;
    for (i = 0; i < NEFF(l); i++){
        if (ELMT(l, i) == val){
            count += 1;
        }
    }
    return count;
}

void sort(ListDin *l, boolean asc){
    int i,j, temp;
    for(i=0; i<NEFF(*l);i++){
        for(j=i+1; j<NEFF(*l); j++){
            if(asc){
                if (ELMT(*l,i) > ELMT(*l,j)) {
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            } else{
                if (ELMT(*l,i) < ELMT(*l,j)) {
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){ //DONE
    if (!(isFull(*l))){
        ELMT(*l, NEFF(*l)) = val;
        NEFF(*l) += 1;
    }
}

void deleteLast(ListDin *l, ElType *val){ //DONE
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
}

void expandList(ListDin *l, int num){ //DONE
    CAPACITY(*l) += num;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num){ //DONE
    CAPACITY(*l) -= num;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l){ //DONE
    int selisih = CAPACITY(*l) - NEFF(*l);
    CAPACITY(*l) -= selisih;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}