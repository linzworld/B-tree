#define _CRT_SECURE_NO_WARNINGS
#include"SORT.h"
//��ʼ������ļ�¼˳���
Status InitList( RcdSqList& L,RcdType rcd[],int length ) {
	L.rcd = (RcdType* )malloc( ( length +1) * sizeof( RcdType ) );
	for (int i = 1; i <= length; i++)
	{
		L.rcd [i] = rcd [i];
		L.length = length;
		L.size = init_size;
	}
	return OK;
}

//ֱ�Ӳ�������
void InsertSort( RcdSqList& L ){
	int i, j;
	for (i = 1; i < L.length; ++i) {
		if (L.rcd[i+1].key < L.rcd[i].key) { 
			L.rcd [0] = L.rcd [i + 1];
			j = i + 1;
			do {
				j--;
				L.rcd [j + 1] = L.rcd [j];
			} while (L.rcd[0].key<L.rcd[j-1].key);
			L.rcd [j] = L.rcd [0];
		}
	}
}
//��ӡ˳����е�ֵ
void PrintList( RcdSqList &L){
	for (int  i = 1; i <= L.length; i++)
	{
		printf( "%d ",L.rcd[i].key );
	}
	printf( "\n" );
}
//��ӡ�����������ʱ��
void PrintfTime( RcdSqList& L,void ( Sort )( RcdSqList& ) ) {
	time_t c_start, c_end ;

	c_start = clock( );    //!< ��λΪms
	
	InsertSort( L );
	PrintList( L );
	//system( "pause" );
	c_end = clock( );

	//!<difftime��time_t, time_t����������time_t�������ʱ��������ʱ���
	printf( "The pause used %f ms by clock()\n", difftime( c_end, c_start ) );
	system( "pause" );

}

//�������������
KeyType SingleRandomNumberGeneration( )
{
	int a;
	     srand( (unsigned )clock(  )*100000 );  //��ȡϵͳʱ�䣬����һ��������ֵ
	     a = rand( );
	     printf( "%d\n", a );

	return a;
}

//��������ɵ�˳����еĴ洢�ռ�����
RcdType* RandomNumberGeneration( int length ) {
	if (length <= 0)
		return NULL;
	RcdType *rcd = (RcdType*)malloc( (length+1)*sizeof(RcdType) ); 
	for (int i = 0; i <= length; i++)
	{
		rcd [i].key = SingleRandomNumberGeneration();
	}
	return rcd;
}


