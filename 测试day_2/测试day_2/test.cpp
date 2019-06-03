#include<iostream>
#include<set>
#include<vector>
using namespace std;
//void Permutation_(char* str, char* strbegin)
//{
//	if (*strbegin == '\0')
//		cout << str << endl;
//	else
//	{
//		for (char* pch = strbegin; *pch != '\0'; ++pch)
//		{
//			char tmp = *pch;
//			*pch = *strbegin;
//			*strbegin = tmp;
//			Permutation_(str, strbegin + 1);
//			tmp = *pch;
//			*pch = *strbegin;
//			*strbegin = tmp;
//		}
//	}
//}
//void Permutation(char* str)
//{
//	if (str == nullptr)
//		return;
//	Permutation_(str, str);
//}
//
//int main()
//{
//	//string <char>str("hello");
//	char str[] = "abc";
//	Permutation(str);
//	return 0;
//}





///////////////////////////////////////////

///////////////////一个数组中出现次数超过长度一半的数字
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
bool g_binput = false;
bool CheckArray(int* num, int length)
{
	g_binput = false;;
	if (num == nullptr&&length <= 0)
	{
		g_binput = true;
	}
	return g_binput;
}
bool ChackMorehalf(int* num, int length, int result)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (num[i] == result)
			times++;
	}
	bool isMore = true;
	if (times * 2 <= length)
	{
		g_binput = true;
		isMore = false;
	}
	return isMore;
}
int Partition(int* num, int length, int start, int end)
{

	if (num == nullptr || length <= 0 || start < 0 || end >= length)
		throw new exception("Invalid Parameters");
	int index = length >> 1;
	Swap(&num[index], &num[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (num[index] < num[end])
		{
			++small;
			if (small != index)
				Swap(&num[index], &num[small]);
		}
	}
	++small;
	Swap(&num[small], &num[end]);
	return small;
}
int MoreThanhalf(int* num, int length)
{
	if (length = 1)
		return num[0];
	if (CheckArray(num, length))
		return 0;
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(num, length, start, end);
	while (index != middle)
	{

		if (index > middle)
		{
			end = index - 1;
			index = Partition(num, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(num, length, start, end);
		}
	}
	int result = num[middle];
	if (ChackMorehalf(num, length, result))
		result = 0;
	return result;
}
int MoreHalfnum(int* num, int length)
{
	if (length = 1)
		return num[0];
	if (CheckArray(num, length))
		return 0;
	int result = num[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = num[i];
			times = 1;
		}
		else if (num[i] == result)
			times++;
		else
			times--;
	}
	if (ChackMorehalf(num, length, result))
		result = 0;
	return result;
}
//int main()
//{
//	int num[] = {1};
//	int length = sizeof(num) / sizeof(int);
//	//cout << length << endl;
//	cout<<MoreThanhalf(num, length)<<endl;
//	//cout << Partition(num, length, 0, length - 1) << endl;
//	//cout << Quick_1(num, 0, length - 1) << endl;
//	cout << MoreHalfnum(num, length) << endl;
//	return 0;
//}



//void GetLeast(int* input, int n, int* output, int k)
//{
//	if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
//		return;
//	int start = 0;
//	int end = n - 1;;
//	int index = Partition(input, n, start, end);
//	while (index != k - 1)
//	{
//		if (index > k - 1)
//		{
//			end = index - 1;
//			index = Partition(input, n, start, end);
//		}
//		else
//		{
//			start = index + 1;
//			index = Partition(input, n, start, end);
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		output[i] = input[i];
//	}
//}
//typedef multiset<int,int>  intSet;
//typedef multiset<int,int>::iterator  setIterator;
//void GetLeast(const vector<int>&data, intSet& leastNumbers, int k)
//{
//	leastNumbers.clear();
//	if (k < 1 || data.size() < k)
//		return;
//	vector<int>::const_iterator it = data.begin();
//	for (; it != data.end(); ++it)
//	{
//		if ((leastNumbers.size()) < k)
//			leastNumbers.insert(*it);
//		else
//		{
//			setIterator iter = leastNumbers.begin();
//			if (*it < *(leastNumbers.begin()))
//			{
//				leastNumbers.erase(iter);
//				leastNumbers.insert(*it);
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	vector<int> v1;
//	v1.insert(6,5);
//	int k = 3;
//	GetLeast(v1, k);
//	return 0;
//}








//////////////////////////////////
////////数组子数组的最大和
bool g_Invalid = false;
int Findaddmax(int* sum, int length)
{
	if (sum == nullptr || length <= 0)
		return 0;
	g_Invalid = false;
	int cursum = 0;
	int greatsum = 0x80000000;
	for (int i = 0; i < length; ++i)
	{

		if (cursum <= 0)
			cursum = sum[i];
		else
			cursum += sum[i];
		if (cursum > greatsum)
		{
			greatsum = cursum;
		}
		
	}
	return greatsum;
}
//int main()
//{
//	int num []= {1,2,3,44,5,-90};
//	int length = sizeof(num) / sizeof(int);
//	cout<<Findaddmax(num, length)<<endl;
//
//}

int numofnum_1(unsigned int i)
{
	int num = 0;
	while (i)
	{
		if (i % 10 == 1)
			num++;
		i = i / 10;
	}
	return num;
}
int numofnum(unsigned int n)
{

	int num = 0;
	for (unsigned int i = 1; i < n; ++i)
		num += numofnum_1(i);
	return num;
}
int main()
{
	unsigned int i = 30;
	cout<<numofnum(i)<<endl;

}

