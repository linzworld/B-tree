#ifndef _BTREE_H
#define _BTREE_H
#define MAXM 10                     //����B�������Ľ���
#define BTREELENGTH 50
#define BTLEN (sizeof(BTNode))
#define MAXINT 100  
typedef enum status
{
	TRUE,
	FALSE,
	OK,
	ERROR,
	OVERFLOW,
	EMPTY
}Status;
typedef int KeyType;

//**********************************B��****************************************
#define  m  3   // B���Ľף�����Ϊ4
typedef struct
{
	KeyType  key;
	char     data;
} Record;
typedef struct BTNode
{
	int             keynum;        // ����йؼ��ָ����������Ĵ�С
	struct BTNode* parent;        // ָ��˫�׽��
	KeyType         key [m + 1];      // �ؼ���������0�ŵ�Ԫδ��
	struct BTNode* ptr [m + 1];      // ����ָ������
//  Record         *recptr[m + 1];   // ��¼ָ��������0�ŵ�Ԫδ��
									 //�ڴ���������Զ�������
} BTNode, * BTree;                // B������B��������
typedef struct
{
	BTNode* pt;      // ָ���ҵ��Ľ��
	int      i;       // 1..m���ڽ���еĹؼ������
	int      tag;     // 1:���ҳɹ���0:����ʧ��
} Result;           // ��B���Ĳ��ҽ������   
//**********************************B��****************************************

//**********************************����***************************************
typedef struct LNode {
	BTree data;     // ������
	struct LNode* next;     // ָ����
} LNode, * LinkList;
//**********************************����***************************************

Status InitQueue_L( LinkList& L );
#endif 