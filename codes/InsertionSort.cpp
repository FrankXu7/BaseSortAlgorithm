/**************************************************************************************************
 * 【插入排序算法】
 *
 * 【基本思路】
 * 将数组从逻辑上分成两部分，比如前面部分为已经排好序的，后面这部分还未排好序的，默认首个元素已经排好序。
 * 以升序排序为例，从未排好序的那部分开始，从后往前逐一与已经排好序的元素比较，若当前比较元素小于已排序部分
 * 的元素，则将已排序的元素逐一后移，直到找到合适的插入位置。需要特别注意的是，默认首个元素已经排好序，所以
 * 初始从下标1开始作为未排序元素的部分。
 *
 * 【性能分析】
 * 时间复杂度：O(N^2)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 *
 * 【算法总结】
 * 由于其最差O(N^2)的时间复杂度，显然是不适用于大量数据的。一般将插入排序作为快速排序的补充，比如数据元素
 * 的数量小于一定的阈值，就采用插入排序，否则就采用快速排序。当数据量较小时，插入排序是较优的选择。
 *
 * @author FrankX
 * @date 2021-07-19
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType代表基本的数字类型 */
template <typename NumType>
void InsertionSort(vector<NumType> &dataArr)
{
	unsigned int dataSize = dataArr.size();
	unsigned idx = 0;
	NumType tempData = 0;

	for (unsigned int n = 1; n < dataSize; ++n)
	{
		idx = n;
		tempData = dataArr[n];

		// 此处需要注意分支语句中，自加/减运算会先执行，然后再进行比较
		while (--idx >= 0 && dataArr[idx] > tempData)
		{
			// 插入排序的数据后移
			dataArr[idx + 1] = dataArr[idx];
		}

		// 这一步才是 dataArr[n] 元素确认排序位置的操作
		dataArr[idx + 1] = tempData;
	}
}

int main()
{
	vector<int> dataArr = {2, 3, 21, 2, 16, 43, 55, 65, 57, 8, 99, 65, 163, 7};

	cout << "Array data:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	InsertionSort(dataArr);

	cout << "\nAfter Insertion Sort:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}