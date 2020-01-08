#include<iostream>
#include<algorithm>
#include <windows.h>
#include <cstdio>
#include <malloc.h>
#include <time.h>
using namespace std;
#define TRUE 1
#define FALSE 0
const int NUMBER = 6; //����������㷨����
const int Max = 1000000;
int arr[Max] = { 0 }, b[Max];
long long int 
	compare_number[NUMBER] = { 0 }, //�Ƚ�
	swap_number[NUMBER] = { 0 },
	move_number[NUMBER] = { 0 };
typedef struct {
	long long int num;
	long long int sort_time;
	int ranking;//�����㷨������ʱ��Ķ���˳��
} Time;

int CompareWithSortTime(const Time& a, const Time& b) {
	return a.sort_time < b.sort_time;
}

int CompareWithNum(const Time& a, const Time& b) {
	return a.num < b.num;
}
//��ʼ�����������
void Init(int num) {
	int i;
	if (num >= Max) {
		printf("��������̫�󣡣�����������");
		exit(2);
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < num; i++) {
		b[i] = arr[i] = rand() % 10000;
	}
	return;
}

//��ԭ
void Restore(int num) {
	int i;
	for (i = 0; i < num; i++) {
		arr[i] = b[i];
	}
}
//��������
void InsertSort(int R[], int n) { // �������ݴ���R[]��,Ĭ��Ϊ����,����Ϊn
	int i = 0, j = 0, temp = 0;
	for (i = 2; i <= n; i++) { /*  ������±�1��ʼ�洢,��һ��Ԫ������,���Դӵڶ���Ԫ�ؿ�ʼ����  */
		if (R[i] < R[i - 1]) {
			compare_number[0]++;
			move_number[0]++;
			temp = R[i];   // ��������Ԫ����ʱ����temp��
			j = i - 1;
			while (temp < R[j] && j >= 1) { // �����ѭ�����Ѱ�Ҳ���λ�õĹ���
				compare_number[0]++;
				move_number[0]++;
				R[j + 1] = R[j];
				swap_number[0]++;
				j--;
			}
		}
		R[j + 1] = temp;
		// �ҵ�����λ�ú�temp���ݴ�Ĵ�����Ԫ�ز���
	}
}
//ϣ������
void ShellSort(int arr[], int len) {
	int h = 0, i = 0, j = 0, temp; //���ò���
	for (h = 1; h < len; h = 3 * h + 1) move_number[1]++;
	while (h) {
		h /= 3;
		move_number[1] += h / 3;
		if (h < 1) break;
		for (i = h; i < len; i++) for (j = i; j >= h; j -= h) {
			if (arr[j - h] < arr[j]) break;
			compare_number[1] += h / 3;
			swap_number[1] += h / 3;
			move_number[1] += h / 3;
			temp = arr[j - h];
			arr[j - h] = arr[j];
			arr[j] = temp;
		}
	}
}
//��ѡ������
void SelectSort(int R[], int n) {
	int i, j, k;
	int  temp;
	for (i = 0; i <= n - 1; ++i) {
		k = i;
		for (j = i + 1; j <= n; ++j)  /*���ѭ�����㷨�Ĺؼ���������������������һ����С��Ԫ��*/
			if (R[k] > R[j]) {
				move_number[2]++;
				swap_number[2]++;
				compare_number[2]++;
				k = j;
			}  //ÿ�������Ƚ�ʱ���ǰ�С�������������ҽ��������һ�ֱȽ�������
		/*�����3�������СԪ�����������е�һ��Ԫ�صĽ���*/
		swap_number[2]++;
		compare_number[2]++;
		move_number[2] += 3;
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}

int Partition(int arr[], int low, int high) {
	int key;
	key = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= key) {
			high--;
			compare_number[3]++;
		}

		if (low < high) {
			move_number[3]++;
			swap_number[3]++;
			arr[low++] = arr[high];
			compare_number[3]++;
		}

		while (low < high && arr[low] <= key) {
			low++;
			compare_number[3]++;
		}

		if (low < high) {
			swap_number[3]++;
			compare_number[3]++;
			move_number[3]++;
			arr[high--] = arr[low];
		}

	}
	arr[low] = key;
	return low;
}
//��������
void QuickSort(int arr[], int start, int end) {
	int pos;
	if (start < end) {
		compare_number[3]++;
		swap_number[3]++;
		pos = Partition(arr, start, end);
		QuickSort(arr, start, pos - 1);
		QuickSort(arr, pos + 1, end);
	}
	return;
}

void Merge(int src[], int des[], int low, int high, int mid) {
	int i = low;
	int k = low;
	int j = mid + 1;
	while ((i <= mid) && (j <= high)) {
		compare_number[4]++;
		if (src[i] < src[j]) {
			des[k++] = src[i++];
		}
		else {
			des[k++] = src[j++];
		}
	}
	while (i <= mid) {
		compare_number[4]++;
		move_number[4]++;
		swap_number[4]++;
		des[k++] = src[i++];
	}
	while (j <= high) {
		compare_number[4]++;
		move_number[4]++;
		swap_number[4]++;
		des[k++] = src[j++];
	}
}
void MSort(int src[], int des[], int low, int high, int max_size) {
	int mid = (low + high) / 2;
	if (low == high) {
		compare_number[4]++;
		move_number[4]++;
		swap_number[4]++;
		des[low] = src[low];
	}
	else {
		swap_number[4]++;
		int mid = (low + high) / 2;
		int* des_space = (int*)malloc(sizeof(int) * max_size);
		if (NULL != des_space) {
			swap_number[4]++;
			move_number[4]++;
			MSort(src, des_space, low, mid, max_size);
			MSort(src, des_space, mid + 1, high, max_size);
			Merge(des_space, des, low, high, mid);
		}
		free(des_space);
	}
}
//�鲢����
void MegerSort(int arr[], int low, int high, int len) {
	MSort(arr, arr, low, high, len);
}

//ð������
void  BubbleSort(int arr[], int n) {

	int i, j;
	int flag = 1;
	int  temp;
	for (i = 1; i < n  && flag; i++)
	{
		flag = 0;
		for (j = n; j > i; j--)		//ð��һ���ǴӺ���ǰ�Ƚ�
		{
			compare_number[5]++;
			if (arr[j] <arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;

				swap_number[5]++;
				
				move_number[5] += 3;

				flag = 1;						//���û�н���˵���Ѿ��ź�����
			}
		}
	}

}

//��������
void RunSort(int num) {
	int i;
	Time t[NUMBER];
	long long int total_sort_time  = 0, total_start = 0, start = 0, total_end = 0, end = 0;

	printf("\t\|                                                   \|\n");
	printf("\t ----------------------------------------------------\n");
	printf("\t\|  ���Ե�......                                     \|\n");

	printf("\t\|                                                   \|\n");

	total_start = start = GetTickCount64();
	Init(num);//��ʼ������
	InsertSort(arr, num);
	end = GetTickCount64();
	t[0].sort_time = end - start;
	t[0].num = 0;

	Restore(num);
	start = GetTickCount64();
	ShellSort(arr, num);
	end = GetTickCount64();
	t[1].sort_time = end - start;
	t[1].num = 1;

	Restore(num);
	start = GetTickCount64();
	SelectSort(arr, num);
	end = GetTickCount64();
	t[2].sort_time = end - start;
	t[2].num = 2;

	Restore(num);
	start = GetTickCount64();
	QuickSort(arr, 0, num);
	end = GetTickCount64();
	t[3].sort_time = end - start;
	t[3].num = 3;

	Restore(num);
	start = GetTickCount64();
	MegerSort(arr, 0, num - 1, num);
	end = GetTickCount64();
	t[4].sort_time = end - start;
	t[4].num = 4;


	Restore(num);
	start = GetTickCount64();
	BubbleSort(arr, num);
	end = GetTickCount64();
	t[5].sort_time = end - start;
	t[5].num = 5;

	sort(t, t + NUMBER, CompareWithSortTime);
	t[0].ranking = 1;
	for (i = 1; i < NUMBER; i++) {
		if (t[i].sort_time == t[i - 1].sort_time)
			t[i].ranking = t[i - 1].ranking;
		else
			t[i].ranking = i + 1;
	}
	sort(t, t + NUMBER, CompareWithNum);
	total_end = end = GetTickCount64();
	total_sort_time  = total_end - total_start;

	printf("\t\|  �ܹ���ʱΪ��%I64d����\n", total_sort_time);
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\|                 -----      �����㷨���ܱȽϽ������          ------              \|\n");
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\| �� �� �� ��\| �ȽϵĴ��� \| �����Ĵ��� \| �ƶ��Ĵ��� \|ʱ�䣨ms��\|ʱ������\|ʱ�临�Ӷ�\|\n");
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\|ֱ�Ӳ�������\|%12lld\|%12lld\|%12lld\|%10lld\|%10d\|    n*n   \|\n", compare_number[0], swap_number[0], move_number[0], t[0].sort_time, t[0].ranking);
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\| ϣ �� �� ��\|%12lld\|%12lld\|%12lld\|%10lld\|%10d\|  n*log2n \|\n", compare_number[1], swap_number[1], move_number[1], t[1].sort_time, t[1].ranking);	
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\|��ѡ������\|%12lld\|%12lld\|%12lld\|%10lld\|%10d\|    n*n   \|\n", compare_number[2], swap_number[2], move_number[2], t[2].sort_time, t[2].ranking);
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\| �� �� �� ��\|%12lld\|%12lld\|%12lld\|%10lld\|%10d\|  n*log2n \|\n", compare_number[3], swap_number[3], move_number[3], t[3].sort_time, t[3].ranking);
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\| �� �� �� ��\|%12lld\|%12lld\|%12lld\|%10lld\|%10d\|  n*log2n \|\n", compare_number[4], swap_number[4], move_number[4], t[4].sort_time, t[4].ranking);
	printf("\t ----------------------------------------------------------------------------------\n");
	printf("\t\| ð �� �� ��\|%12lld\|%12lld\|%12lld\|%10lld\|%10d\|  n*log2n \|\n", compare_number[5], swap_number[5], move_number[5], t[5].sort_time, t[5].ranking);
	printf("\t ----------------------------------------------------------------------------------\n");
	return;
}










//����������ֽ��з������жϸ�ʽ�Ƿ�ȫΪʮ����
int NumberJudge() {
	int n;
	int sign = 0;
	int retur;
	do {
		sign = 0;
		retur = scanf_s("%d", &n);//��������n��ʮ�������֣��򷵻�1�����������Ĳ�����
		if (retur == 0) {		//����ѭ����ֱ�������n��ʮ�������֣����˳�ѭ��
			printf("\n�Ƿ����룬���������룡\n");
			for (; getchar() != '\n';);
			sign = -1;
		}
	} while (sign == -1);
	return n;
}

int main() {
	system("color 0A");
	int num;//����Ԫ�صĸ���
	system("cls");
	printf("\t\|                                                   \|\n");
	printf("\t\|  ����������������е�����Ԫ�صĸ��� n(��0�˳�)������Խ��ʱ��Խ��������ʮ�����������ĵȴ�����");
	num = NumberJudge();
	if (num == 0) {
		printf("�˳��������\n");
		return 0;
	}

	RunSort(num);
	system("pause");
	while (num !=0)
	{
		system("cls");
		printf("\t\|                                                   \|\n");
		printf("\t\|  ����������������е�����Ԫ�صĸ��� n(��0�˳�)������Խ��ʱ��Խ��������ʮ�����������ĵȴ�����");
		num = NumberJudge();
		if (num == 0) {
			printf("�˳��������\n");
			return 0;
		}
		RunSort(num);
		system("pause");
	}
	printf("�˳�����\n");
	return 0;
}


