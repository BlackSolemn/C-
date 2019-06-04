#include<iostream>
#include<vector>
//#pragma warning(disable:4996)
//#include<stdio.h>
#include<cstring>

using namespace std;
///////////////////一个数字中从一到它  一出现的次数
//int PowerBase10(unsigned int n)
//{
//	int result = 1;
//	for (unsigned int i = 0; i < n; ++i)
//		result *= 10;
//	return result;
//}
//int NumOf1(const char* strN)
//{
//	if (!strN || *strN<'0' || *strN>'9' || *strN == '\0')
//		return 0;
//	int first = *strN - '0';
//	unsigned int length = static_cast<unsigned int>(strlen(strN));
//	if (length == 1 && first == 0)
//		return 0;
//	if (length == 1 && first > 0)
//		return 1;
//	int num = 0;
//	//假设数字n为21345
//		//num = 10000—19999中第一位中的数目
//	if (first > 1)
//		num = PowerBase10(length - 1);
//	else if (first == 1)
//		num = atoi(strN + 1) + 1;
//	//numO为12345—21345除第一位之外的位数的数字
//	int numO = first *(length - 1)*PowerBase10(length - 2);
//	//numR为1—1345中的数目
//	int numR = NumOf1(strN + 1);
//	return num + numO + numR;
//}
//int NumOfBetween(int n)
//{
//	if (n <= 0)
//		return 0;
//	char strN[50];
//	sprintf_s(strN,"%d", n);
//	return NumOf1(strN);
//}
//
//int main()
//{
//	int a = 111;
//	cout << NumOfBetween(a) << endl;
//	return 0;
//}




//输入一个整数数组，把数组里面所有数字拼接起来排成数字最小的数
//const int g_MaxNumberLength = 10;
//char* g_StrCom1 = new char[g_MaxNumberLength * 2 + 1];
//char* g_StrCom2 = new char[g_MaxNumberLength * 2 + 1];
//int compare(const void* strnumber1, const void* strnumber2)
//{
//	strcpy(g_StrCom1, *(const char**)strnumber1);
//	strcat(g_StrCom1, *(const char**)strnumber2);
//
//	strcpy(g_StrCom2, *(const char**)strnumber2);
//	strcat(g_StrCom2, *(const char**)strnumber1);
//	
//	return strcmp(g_StrCom1, g_StrCom2);
//
//}
//void Print(int* number, int length)
//{
//	if (number == nullptr || length <= 0)
//		return;
//	char** str = (char**)(new int[length]);
//	for (int i = 0; i < length; ++i)
//	{
//		str[i] = new char[g_MaxNumberLength + 1];
//		sprintf(str[i], "%d", number[i]);
//
//	}
//	qsort(str, length, sizeof(char*), compare);
//	for (int i = 0; i < length; ++i)
//	{
//		delete[] str[i];
//		
//	}
//	delete[] str;
//
//}
//
//int main()
//{
//	int arr[] = { 45,32 };
//	int length = sizeof(arr) / sizeof(int);
//	Print(arr, length);
//	int i = 0;
//	for (i = 0; i < length; ++i)
//	{
//		cout << arr[i] << "";
//	}
//	cout << endl;
//	return 0;
//}





////丑数：只包含2,3,5的数  例如6，8,25
//bool Isugly(int number)
//{
//	while (number % 2 == 0)
//		number /= 2;
//	while (number %3  == 0)
//		number /= 3;
//	while (number % 5 == 0)
//		number /= 5;
//	return (number == 1) ? true : false;
//}
//int GetUglyNumber(int index)
//{
//	if (index <= 0)
//		return 0;
//	int number = 0;
//	int ugly = 0;
//	while (ugly < index)
//	{
//		++number;
//		if (Isugly(number))
//			++ugly;
//	}
//	return number;
//}
//
//int Min(int number1, int number2, int number3)
//{
//	int min = (number1 < number2) ? number1 : number2;
//	min = (min < number3) ? min : number3;
//	return min;
//}
//int Getuglynumber(int index)
//{
//	if (index <= 0)
//		return 0;
//	int *uglynumber = new int[index];
//	uglynumber[0] = 1;
//	int nextindex = 1;
//	int *Multiply2 = uglynumber;
//	int *Multiply3 = uglynumber;
//	int *Multiply5 = uglynumber;
//	while (nextindex < index)
//	{
//		int min = Min(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
//		uglynumber[nextindex] = min;
//		while (*Multiply2 * 2 <= uglynumber[nextindex])
//			++Multiply2;
//		while (*Multiply3 * 3 <= uglynumber[nextindex])
//			++Multiply3;
//		while (*Multiply5 * 5 <= uglynumber[nextindex])
//			++Multiply5;
//		++nextindex;
//	}
//	int ugly = uglynumber[nextindex - 1];
//	delete[] uglynumber;
//	return ugly;
//
//}
//int main()
//{
//	cout << Getuglynumber(150) << endl;
//	//cout << Isugly(10) << endl;
//	return 0;
//}




///////一个字符串中只出现一次的字符
//char OneNotRepeating(char* string)
//{
//	if (string == nullptr)
//		return '\0';
//	const int size = 256;
//	unsigned int hashtable[size];
//	for (unsigned int i = 0; i < size; ++i)
//		hashtable[i] = 0;
//	char* HashKey = string;
//	while (*(HashKey) != '\0')
//		hashtable[*(HashKey++)]++;
//	HashKey = string;
//	while (*HashKey != '\0')
//	{
//		if (hashtable[*HashKey] == 1)
//			return *HashKey;
//		HashKey++;
//	}
//	return '\0';
//}
//int main()
//{
//	char arr[] = "aaaabbbbcccvddccccbbbb";
//	cout << OneNotRepeating(arr) << endl;
//}

int InversePairsCore(int *arr, int * copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = arr[start];
		return 0;
	}
	int length = (end - start) >>1;
	int left = InversePairsCore(copy, arr, start, start + length);
	int right = InversePairsCore(copy, arr, start+length+1, end);
	int i = start + length;
	int j = end;
	int index = end;
	int count = 0;
	while (i >= start&&j >= start + length + 1)
	{
		if (arr[i] > arr[j])
		{
			copy[index--] = arr[i--];
			count += j - start - length;
		}
		else
		{
			copy[index--] = arr[j--];
		}
	}
	for (; i >= start; --i)
		copy[index--] = arr[i];
	for (; j >= start + length + 1; --j)
		copy[index--] = arr[j];
	return left + right + count;

}

int InversePairs(int* arr, int length)
{
	if (arr==nullptr || length < 0)
		return 0;
	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = arr[i];
	int count = InversePairsCore(arr, copy, 0, length - 1);
	delete[] copy;
	return count;
}
int main()
{
	int arr[] = { 7,5,6,4,1,2 };
	int length = sizeof(arr) / sizeof(int);
	cout << InversePairs(arr, length) << endl;
	return 0;
}