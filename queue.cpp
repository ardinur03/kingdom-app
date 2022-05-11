#include "queue.h"
#include "header.h"

address *front = NULL;
address *rear = NULL;

void CreateEmpty(Queue *Q)
{
    // *Q = NULL;  => original code
    front = rear = NULL; // => new code
}

// bool IsEmpty(Queue Q)
// {
//     return (isEmpty(Q));
// }

/**
 * original code
 *
 */
// void Enqueue(Queue *Q,infotype X){
// 	address a = NULL;
// 	Create_Node(&a);
// 	Isi_Node(&a, X);
// 	Ins_Akhir(&(*Q),a);
// }
// void Dequeue(Queue *Q,infotype *X){
// 	Del_Awal(&(*Q),&(*X));
// }

/**
 * new code
 */
// int SearchList(Queue Q, nbType x)
// {
//     int count = 1;
//     while (!IsEmpty(Q))
//     {
//         if (data(Q)->data == x)
//         {
//             return count;
//         }
//         else
//         {
//             Q = next(Q);
//             count++;
//         }
//     }
//     return 0;
// }

// void insertion(){
//     address temp = (address *) malloc(sizeof(tElmtList));
//     //printf (" Masukkan data :  "); scanf ("%d",&temp->data);
//     //strcpy(temp->data,data);
//     temp->next = NULL;
//     if (rear == NULL){
//         front = temp;
//         rear = temp;
//     } else {
//         rear->link=temp;
//         rear = rear->link;
//     }
// } 