#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int *data;
    int head;
    int tail;
    int size;
}Queue ;

void CreateEmpty(Queue *Q, int Size){
    Q->head = -1;
    Q->tail = -1;
    Q->size = Size;
    Q->data = malloc(Size * sizeof(int));
}

int isEmpty(Queue Q){
    return Q.head == -1 && Q.tail == -1; //kosong jika head dan tail bernilai nil (-1)
}

int isFull(Queue Q){
    return nbEl(Q) == Q.size; //penuh jika  banyak elemen sama dengan size
}

int nbEl(Queue Q){//hitung jumlah elemen
    return Q.tail - Q.head + 1;
}

void Add(Queue *Q, int nilai){

    if(!isFull(*Q)){//jika kosong

        if(isEmpty(*Q)){
            //jika kosong head dan tail digeser agar tidak menunnjuk nil
            Q->head++;
            Q->tail++;

        } else {
            //jika tidak kosong head tidak bergeser
            Q->tail++;

        }
        Q->data[Q->tail] = nilai;

    } else {
        printf("\nQueue Penuh!\n");
    }

}

void Del(Queue *Q, int *nilai){

    if(!isEmpty(*Q)){//jika tidak kosong
        *nilai = Q->data[Q->head];
        int i;
        for(i=0;i<nbEl(*Q);i++){ //looping sebanyak elemen
            /*  data digeser
                contoh data[1] digeser ke data[0],
                    data[2] digeser ke data[1],
                    data[3] digeser ke data[2], dst
            */
            Q->data[i] = Q->data[i+1];
        }
        if(Q->head == Q->tail){ //head == tail adalah kondisi ketika hanya ada 1 elemen
            Q->head--; //jika elemen hanya 1, head akan bergeser ke nil
        }
        Q->tail--;
    } else {
        printf("\nQueue Kosong!\n");
    }

}

void printQueue(Queue Q){
    if(!isEmpty(Q)){ //jika tidka kosong
        printf("\n");
        int i;
        for(i=0;i<=nbEl(Q);i++){ //looping sebanyak elemen
            printf("[%d]",Q.data[i]);
        }
        printf("\n");
    }
}

int main()
{
    Queue Q1;
    CreateEmpty(&Q1,10);
    printf("is Empty?!\n %d\n", isEmpty(Q1));
    Add(&Q1,17);
    Add(&Q1,16);
    Add(&Q1,15);
    Add(&Q1,14);
    Add(&Q1,13);
    Add(&Q1,12);
    printQueue(Q1);
    puts("");
    int t;
      Del(&Q1,&t);
      Del(&Q1,&t);
      Del(&Q1,&t);
      Del(&Q1,&t);
    printQueue(Q1);
        Add(&Q1,20);
      Del(&Q1,&t);      Del(&Q1,&t);
      Del(&Q1,&t);
    puts("");
    printQueue(Q1);
//

    printf("\nis Empty?!\n %d", isEmpty(Q1));
    printf("\nnumber El?!\n %d", nbEl(Q1));
    printf("\nyang di delete?!\n %d", t);
    return 0;
}
