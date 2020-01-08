//����һЩ���õĹ���
#define _CRT_SECURE_NO_WARNINGS
#include"SORT.h"
extern int delay_time ;//��ʱʱ�������

//��ʽ������ַ���
void FormattingPrint(char* str) {
	printf("=====");
	printf("%s",str);
	printf("=====");
	printf("\n");
}

//��ӡ˳����е�ֵ
void PrintList(RcdSqList& L) {
	for (int i = 1; i <= L.length; i++)
	{
		Sleep(delay_time);// ��ͣ1s��ӡa

		printf("%d ", L.rcd[i].key);
	}
	printf("\n");
}
//��ӡ�����������ʱ��
void PrintfTime(RcdSqList& L, void (Sort)(RcdSqList&)) {
	time_t c_start, c_end;
	c_start = clock();    //!< ��λΪms
	Sort(L);
	c_end = clock();
	PrintList(L);

	//!<difftime��time_t, time_t����������time_t�������ʱ��������ʱ���
	printf("The sort used %f ms by sort()\n", difftime(c_end, c_start));
}
//ϣ������Ĵ�ӡ����
void PrintfTimeForShellSort(RcdSqList& L, int d[], int d_length) {
	time_t c_start, c_end;
	c_start = clock();    //!< ��λΪms
	ShellSort(L, d, d_length);
	c_end = clock();
	PrintList(L);

	//!<difftime��time_t, time_t����������time_t�������ʱ��������ʱ���
	printf("The sort used %f ms by sort()\n", difftime(c_end, c_start));
}
//��������Ĵ�ӡ����
void PrintfTimeForQuickSort(RcdSqList& L, int low, int high) {
	time_t c_start, c_end;
	c_start = clock();    //!< ��λΪms
	QuickSort(L, low, high);
	c_end = clock();
	PrintList(L);
	//!<difftime��time_t, time_t����������time_t�������ʱ��������ʱ���
	printf("The sort used %f ms by sort()\n", difftime(c_end, c_start));
}
//��������ɵ�˳����еĴ洢�ռ�����
RcdType* RandomNumberGeneration(int length) {
	if (length <= 0)
		return FALSE;
	RcdType* rcd = (RcdType*)malloc(((unsigned long long)length + 1) * sizeof(RcdType));
	// ����C6086����
	if (rcd == NULL)
		return NULL;
	rcd[0].key = 0;

	srand((unsigned)time(NULL));

	int i;
	for ( i = 1; i <= length; i++)
	{
		rcd[i].key = rand()%length;
	}
	return rcd;
}