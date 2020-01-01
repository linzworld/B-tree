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

void swap( int* a, int* b );
void  BubbleSort( RcdSqList& L );
void InsertSort( RcdSqList& L );
//void ShellSort( RcdSqList& L );
void ShellSort( RcdSqList& L, int d[], int t );
void ShellInsert( RcdSqList& L, int dk );


Status InitList( RcdSqList& L, RcdType rcd[], int length );
void PrintList( RcdSqList& L );
void PrintfTime( RcdSqList& L, void ( InsertSort )( RcdSqList &) );
KeyType  SingleRandomNumberGeneration( );
RcdType* RandomNumberGeneration( int length );

void PrintfTimeForShellSort( RcdSqList& L, void ( Sort )( RcdSqList& L, int d[], int t ) );

#endif 