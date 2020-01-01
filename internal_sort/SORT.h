#include<stdio.h>         
#include<stdlib.h>
#include<time.h>  
#ifndef SORT_H
#define SORT_H
#define init_length 10
#define init_size 10
#define OK 1
#define ERROR 0
typedef int KeyType;
typedef int Status;

typedef struct {
	KeyType key;
}RecordType,RcdType;

typedef struct {
	RcdType* rcd;//�洢�ռ��ַ
	int length;//��ǰ����,0Ϊ����λ
	int size;//��ǰ����
}RcdSqList;

void InsertSort( RcdSqList &L );
Status InitList( RcdSqList& L, RcdType rcd[], int length );
void PrintList( RcdSqList& L );
void  BubbleSort( );
void PrintfTime( RcdSqList& L, void ( InsertSort )( RcdSqList &) );
KeyType  SingleRandomNumberGeneration( );
RcdType* RandomNumberGeneration( int length );
#endif 