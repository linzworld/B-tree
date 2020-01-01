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


void swap( int* a, int* b ) {
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}


//ð������
void  BubbleSort( RcdSqList& L ) {
	char func_buf [50] = { 0 };
	sprintf( func_buf, "%s", __FUNCTION__ );
	printf( "======%s \n", func_buf );
	int i, j;
	int flag = 1;
	for (i = 1; i < L.length && flag; i++)
	{
		flag = 0;
		for (j = L.length; j > i; j--)		//ð��һ���ǴӺ���ǰ�Ƚ�
		{
			if (L.rcd [j].key < L.rcd [j - 1].key)
			{
				swap( &L.rcd[j].key, &L.rcd [j-1].key );
				flag = 1;						//���û�н���˵���Ѿ��ź�����
			}
		}
	}

}

//ֱ�Ӳ�������
void InsertSort( RcdSqList& L ){
	char func_buf [50] = { 0 };
	sprintf( func_buf, "%s", __FUNCTION__ );
	printf( "======%s \n", func_buf );
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

//һ��ϣ������
void ShellInsert( RcdSqList& L, int dk ) {
	int i, j;
	for(i=1;i==L.length-dk;++i)
		if (L.rcd[i+dk].key<L.rcd[i].key)
		{
			L.rcd [0] = L.rcd [i + dk];
			j = i + dk;
			do
			{
				j -= dk;
				L.rcd [j + dk] = L.rcd [j];
			} while (j-dk>0&&L.rcd[0].key<L.rcd[j-dk].key);
			L.rcd [j] = L.rcd [0];
		}

}
//ϣ������
void ShellSort( RcdSqList& L, int d[],int t) {
	int k;
	for (k = 0; k < t; k++) {
		ShellInsert( L, d [k] );
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
	
	Sort( L );
	PrintList( L );
	//system( "pause" );
	c_end = clock( );
 
	//!<difftime��time_t, time_t����������time_t�������ʱ��������ʱ���
	printf( "The sort used %f ms by clock()\n", difftime( c_end, c_start ) );
	//system( "pause" );

}

void PrintfTimeForShellSort( RcdSqList& L, void ( Sort )( RcdSqList& L, int d[], int t ) ) {
	time_t c_start, c_end;
	const int t = 3;
	int d [t] = { 5,3,1 };
	c_start = clock( );    //!< ��λΪms

	ShellSort( L,d,t );
	PrintList( L );
	//system( "pause" );
	c_end = clock( );

	//!<difftime��time_t, time_t����������time_t�������ʱ��������ʱ���
	printf( "The sort used %f ms by clock()\n", difftime( c_end, c_start ) );
}

//�������������
KeyType SingleRandomNumberGeneration( )
{
	int a;
	     srand( (unsigned )clock(  )*100000 );  //��ȡϵͳʱ�䣬����һ��������ֵ
	     a = rand( );
	     //printf( "%d\n", a );

	return a;
}

//��������ɵ�˳����еĴ洢�ռ�����
RcdType* RandomNumberGeneration( int length ) {
	if (length <= 0)
		return NULL;
	RcdType *rcd = (RcdType*)malloc( (length+1)*sizeof(RcdType) ); 
	rcd [0].key = 0;
	for (int i = 1; i <= length; i++)
	{
		rcd [i].key = SingleRandomNumberGeneration();
	}
	return rcd;
}


