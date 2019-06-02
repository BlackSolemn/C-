#include<iostream>
#include<stack>
using namespace std;

/////////两个数组 一个是输入栈一个是输出栈  判断正误
//bool IsPop(const int *push, const int *pop, int Length)
//{
//	bool Possible = false;
//	if (push != nullptr&&pop != nullptr&&Length > 0)
//	{
//		const int* pnextpush = push;
//		const int* pnextpop = pop;
//		stack<int> ST;
//		while (pnextpop - pop < Length)
//		{
//			while (ST.empty() || ST.top() != *pnextpop)
//			{
//				if (pnextpush - push == Length)
//					break;
//				ST.push(*pnextpush);
//				pnextpush++;
//			}
//			if (ST.top() != *pnextpop)
//				break;
//			ST.pop();
//			pnextpop++;
//		}
//		if (ST.empty() && pnextpop - pop == Length)
//			Possible = true;
//
//	}
//	return Possible;
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7 };
//	int b[] = { 7,6,5,4,3,2,1 };
//	int c = sizeof(a) / sizeof(int);
//	cout << c << endl;
//	cout << IsPop(a, b, c) << endl;
//}






///////按照顺时针打印二维数组
//void Print(int** arr, int cols, int rows, int start)
//{
//	int endx = cols - 1 - start;
//	int endy = rows - 1 - start;
//	for (int i = start; i <= endx; i++)
//	{
//		int a = arr[start][i];
//		cout << a << " ";
//	}
//	if (start < endy)
//	{
//		for (int i = start + 1; i <= endy; ++i)
//		{
//			int a = arr[i][endx];
//			cout << a << " ";
//		}
//	}
//	if (start < endx&&start < endy)
//	{
//		for (int i = endx - 1; i >= start; --i)
//		{
//			int a = arr[endy][i];
//			cout << a << " ";
//		}
//	}
//	if (start < endx&&start < endy-1)
//	{
//		for (int i = endy - 1; i >= start + 1; --i)
//		{
//			int a = arr[i][start];
//			cout << a << " ";
//		}
//	}
//}
//void PrintMatrix(int** arr, int cols, int rows)
//{
//	if (arr == nullptr || cols <= 0 || rows <= 0)
//		return;
//	int start = 0;
//	while (cols > start * 2 && rows > start * 2)
//	{
//		Print(arr, cols, rows, start);
//		++start;
//	}
//}
//
//int main()
//{
//	int arr[5][5] = { 1,2,3,4,5,
//					  6,7,8,9,10,
//					  11,12,13,14,15,
//					  16,17,18,19,20,
//					  21,22,23,24,25 };
//	int* a = &arr[0][0];
//	int c = 5;
//	int b = 5;
//	PrintMatrix(&a, b,c);
//	return 0;
//}









//struct BinartTreeNode
//{
//	int _data;
//	BinartTreeNode* _left;
//	BinartTreeNode* _right;
//};
//
//void PrintBottom(BinartTreeNode* root)
//{
//	if (!root)
//		return;
//	deque<BinartTreeNode*>dequeTreeNode;
//	dequeTreeNode.push_back(root);
//	while (dequeTreeNode.size())
//	{
//		BinartTreeNode* pNode = dequeTreeNode.front();
//		dequeTreeNode.pop_front();
//		cout << pNode->_data << " ";
//		if (pNode->_left)
//			dequeTreeNode.push_back(pNode->_left);
//		if(pNode->_right)
//			dequeTreeNode.push_back(pNode->_right);
//	}
//}





////////////////输入一个数组  判断是不是后序遍历的二叉树
bool VerifyofBST(int* arr, int length)
{
	if (arr == nullptr || length <= 0)
		return false;
	int root = arr[length - 1];
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (arr[i] > root)
			break;
	}
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
		left = VerifyofBST(arr, i);
	bool right = true;
	if (i < length - 1)
		right = VerifyofBST(arr + i, length - i - 1);
	return (left&&right);

}
int main()
{
	int arr[] = { 5,7,11,10,8,6 };
	int c = sizeof(arr) / sizeof(int);
	cout << VerifyofBST(arr, c) << endl;
	return 0;

}