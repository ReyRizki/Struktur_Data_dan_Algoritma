/*----------------------------------------------------------------------*/
/*File           : queue.h                                              */
/*Deskripsi      : Header ADT queue menggunakan list                    */
/*Dibuat oleh    : Ardhiansyah                                          */
/*Tanggal dibuat :                                                      */
/*Tanggal update : 23 April 2011                                        */
/*----------------------------------------------------------------------*/

#ifndef queue_H
#define queue_H

#include <stdio.h>
#include "list.h"
#include "boolean.h"
#define Front(Q) (Q).front
#define Rear(Q) (Q).rear

typedef struct queue{
	address front;
	address rear;
};

boolean IsEmpty(queue Q);
void Initial(queue *Q);
void SetFront(queue *Q);
void SetRear(queue *Q);
void Delete(queue *Q, infotype *data);
void Insert(queue *Q, infotype data, infotype pos);
void Tampil(queue Q);

#endif