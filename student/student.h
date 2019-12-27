#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> 
#define ListInitSize 20
#define ListIncrement 5
#define INIT_N 3
#define OK 1
#define ERROR 0

typedef struct Student
{
	char num [20];
	char name [20];
	char sex;
	int age;
	int score;
}stu;

typedef int Status;

typedef struct LNode
{
	stu *elem;	//����ռ�Ļ���ַ 
	Status length;	//��ǰ����
	Status listsize;	//��ǰ����Ĵ������� 
}LNode,*LinkList;

Status InitList( LinkList* L );
//��ʼ�����Ա�L;
Status ListInsert( LinkList L, Status i, stu s );
//�����¼
void print( LinkList L );
//��ӡ���Ա��е���Ϣ
void print_single( stu s );
//��ӡָ��ѧ������Ϣ
void Scan_In( LinkList L );
//������Ϣ
Status ListDelete( LinkList L, int i, stu* s );
//ɾ����i����¼
void Sort( LinkList L );
//����ѧ����������
int LocateElem( LinkList L, stu s, Status( *compare )( stu, stu ) );
//��λĳ��Ԫ�� 
void SearchName( LinkList L, Status( *equal )( stu, stu ) );
//���������� 
void Modifyinfo( LinkList L, Status( *equal )( stu, stu ) );
//�޸���Ϣ
Status EqualName( stu a, stu b );
//�Ƚ������Ƿ���ͬ
void menu( );
