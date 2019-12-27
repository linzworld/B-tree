#define _CRT_SECURE_NO_WARNINGS
#include"student.h"
#include<stdio.h>

Status InitList( LinkList* L )
{
	L.elem = (stu* )malloc( ListInitSize * sizeof( stu ) );
	if (!L.elem)
		exit( -2 );
	L.length = 0;
	L.listsize = ListInitSize;
	return OK;
}

Status ListInsert( LinkList L, Status i, stu s )
{
	stu* newstu;
	int j;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		newstu = (stu* )malloc( sizeof( stu ) * ( ListInitSize + ListIncrement ) );
		if (!newstu)
			exit( -2 );
		L.elem = newstu;
		L.listsize += ListIncrement;
	}
	for (j = L.length; j >= i; j--)
	{
		L.elem [j] = L.elem [j - 1];
		L.elem [i - 1] = s;
		L.length++;
	}
	return OK;
}


void print( LinkList L )
{
	int i = 0;
	if (L.length == 0)
	{
		printf( "�ձ����κμ�¼��\n\n" );
		printf( "ѧ�� ���� �Ա� ���� �ɼ�\n" );
		printf( "************************" );
	}
	for (i = 0; i < L.length; i++)
	{
		printf( "%s %s", L.elem [i].num, L.elem [i].name );
		if (L.elem [i].sex == 'm')
			printf( "��" );
		else
			printf( "Ů" );
		printf( "%d %d", L.elem [i].age, L.elem [i].score );
		printf( "\n" );
	}
	printf( "------------------------------\n" );
}

void print_single( stu s )
{
	printf( "ѧ�� ���� �Ա� ���� �ɼ�\n" );
	printf( "******************************\n" );
	printf( "%s %s", s.num, s.name );
	if (s.sex == 'm')printf( "��" );
	else printf( "Ů" );
	printf( "%d %d", s.age, s.score );
	printf( "\n" );
	printf( "------------------------------\n" );
}

void Scan_In( LinkList L )
{
	char a [2], b [2];
	int i;
	printf( "������Ҫ�����ѧ����Ϣ��\n" );
	do {
		stu s;
		printf( "\t������ѧ�ţ�\n" );
		scanf( "%s", s.num );
		printf( "\t������������\n" );
		scanf( "%s", s.name );
		printf( "\t�������Ա𣺣�m���У�f��Ů��\n" );
		scanf( "%c", &s.sex );
		printf( "\t���������䣺\n" );
		scanf( "%d", &s.age );
		printf( "\t������ƽ���ɼ���\n" );
		scanf( "%d", &s.score );
		printf( "\t ��������Ҫ�����λ��(1<=i<=%d)��", L.length + 1 );
		scanf( "%d", &i );
		printf( "\t�Ƿ���Ϣ���󣬲�����Ϣ����y/n��\n" );
		scanf( "%c", a );
		if (strcmp( a, "y" ) == 0 || strcmp( a, "Y" ) == 0)
			ListInsert( L, i, s );
		printf( "\t�Ƿ�������룿��y/n��\n" );
		scanf( "%c", b );
	} while (strcmp( b, "y" ) == 0 || strcmp( b, "Y" ) == 0);
}

Status ListDelete( LinkList L, int i, stu s )
{
	int j;
	if (i<1 || i>L.length)
		return ERROR;
	else {
		s = L.elem [i - 1];
		for (j = i; j <= L.length; j++)L.elem [j - 1] = L.elem [j];
		L.length--;
		return OK;
	}
}

void Sort( LinkList L )
{
	stu s;
	int i, j;
	for (i = 0; i < L.length - 1; i++)
		for (j = 0; j < L.length - i - 1; j++)
		{
			if (strcmp( L.elem [j].num, L.elem [j + 1].num ) > 0)
			{
				s = L.elem [j];
				L.elem [j] = L.elem [j + 1];
				L.elem [j + 1] = s;
			}
		}
	printf( "*****������������ɹ���******\n\n" );
}

int LocateElem( LinkList L, stu s, Status( *compare )( stu, stu ) )
{
	int i = 1;
	stu* p = L.elem;
	for (i = 1; i <= L.length && !compare( *p++, s ); i++)
	{
		if (i <= L.length)
			return i;
		else
			return 0;
	}
	return 0;
}

void searchName( LinkList L, Status( *equal )( stu, stu ) )
{
	stu s;
	int j;
	char a [2];
	do {
		printf( "\t ��������Ҫ���ҵ�ѧ����������" );
		scanf( "%s", s.name );
		j = LocateElem( L, s, equal );
		if (!j)printf( "û�в��ҵ�����Ҫ���ҵ�ѧ����¼��\n" );
		else print_single( L.elem [j - 1] );
		printf( "\t �������������(y/n)\t" );
		scanf( "%s", a );
	} while (strcmp( a, "y" ) == 0 || strcmp( a, "Y" ) == 0);
}

void ModifyName( LinkList L, Status( *equal )( stu, stu ) )
{
	stu s;
	int j;
	char num_new [20], name_new [20], sex_new;
	int age_new, score_new;
	char a [2];
	do {
		printf( "\t ��������Ҫ���ĵ�ѧ����������" );
		scanf( "%s", s.name );
		j = LocateElem( L, s, equal );
		if (!j)
			printf( "û�в��ҵ�����Ҫ���ҵ�ѧ����¼��\n" );
		else {
			print_single( L.elem [j - 1] );
			int isOrNo = 1;
			printf( "\n�޸�ͨѶ¼��1 ѧ�ţ�2 ������3 �Ա�4 ���䣬5 �ɼ���0 ȡ��\n" );
			while (isOrNo)
			{
				printf( "--------------------------\n" );
				printf( "��ѡ����Ҫ�޸ĵ�������ţ�" );
				scanf( "%d", &isOrNo );
				switch (isOrNo) {
					case 1:
						printf( "��������ĺ��ѧ�ţ�" );
						scanf( "%s", num_new );
						strcpy( L.elem [j - 1].num, num_new );
						break;
					case 2:
						printf( "��������ĺ��������" );
						scanf( "%s", name_new );
						strcpy( L.elem [j - 1].name, name_new );
						break;
					case 3:
						printf( "��������ĺ���Ա�" );
						scanf( "%c", &sex_new );
						break;
					case 4:
						printf( "��������ĺ�����䣺" );
						scanf( "%d", &age_new );
						L.elem [j - 1].age = age_new;
						break;
					case 5:
						printf( "��������ĺ�ĳɼ���" );
						scanf( "%d", &score_new );
						L.elem [j - 1].score = score_new;
						break;
				}
			}
			printf( "\n****���ĺ������¼��Ϊ****\n\n" );
			print_single( L.elem [j - 1] );
		}
		printf( "��������޸���(y/n)\t" );
		scanf( "%s", a );
	} while (strcmp( a, "y" ) == 0 || strcmp( a, "Y" ) == 0);
}

void menu( )
{
	printf( "\t*********************\n" );
	printf( "\t**��ӭʹ��ѧ��ͨѶ¼����ϵͳ**\n" );
	printf( "\t*********************\n" );
	printf( "\t**��ѡ�����²������������**\n" );
	printf( "\t  0���˳�ϵͳ\n" );
	printf( "\t  1������ʼѧ����¼�������Ա�\n" );
	printf( "\t  2����ʾ���Ա�����������\n" );
	printf( "\t  3�������Ա�������һ����¼\n" );
	printf( "\t  4�������Ա���ɾ��һ����¼\n" );
	printf( "\t  5�����������޸�һ����¼\n" );
	printf( "\t  6��������������һ����¼\n" );
	printf( "\t  7������ѧ����������ͨѶ¼\n" );
	printf( "\t*********************\n" );
	printf( "\t  �������ʲô��������ѡ��\n" );
}
