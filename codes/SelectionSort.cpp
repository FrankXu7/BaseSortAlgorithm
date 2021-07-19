/**************************************************************************************************
 * 【选择排序算法】
 *
 * 【基本思路】
 * 两层循环，外层是比较的轮数，进行的轮数即代表已经排序好的元素数量，内层是某一轮比较，假设按升序排序，
 * 记录本轮比较中最小的数据的下标，本轮比较结束后，将本轮最小数据与对应外层循环轮数的下标数据交换。
 * 需要特别注意的是，外层只需要进行 size-1 轮比较，因为进行了 size-1 轮比较后，剩余的最后一个元素
 * 已经与其它元素都比较过了，相当于已经确定了排序位置，没有必要再来一轮了；内层循环中，每一轮都能选出
 * 最小的元素，所以内层每次遍历的元素数量要比上一轮少1，避免不必要的处理。
 *
 * 【性能分析】
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 *
 * 【算法总结】
 * 选择排序的实现虽然比较简单，是一种效率低下的排序方式，适用于数据规模较小时使用。在各种情况下复杂度波动较小，
 * 时间复杂度最好和最坏都是O(n^2)，所以相比于冒泡排序来说是更优解的。
 *
 * @author FrankX
 * @date 2021-07-19
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType为基础的数字类型 */
template<typename NumType>
void SelectionSort(vector<NumType>& dataArr)
{
	unsigned int dataSize = dataArr.size();
	NumType tempData = 0;
	// 标记每一轮中的最小数据下标，用以交换 
	unsigned int minDataIdx = 0;

	// 进行 dataSize-1 轮排序后剩余的最后一个元素，已经和其它所有元素比较过了，是有序的，没必要再来一轮 
	for (unsigned int n = 0; n < dataSize - 1; ++n)
	{
		minDataIdx = n;
		// 每轮都能比较选择出一个最值元素，所以不必每轮都比较所有元素 
		for (unsigned int idx = n + 1; idx < dataSize; ++idx)
		{
			if (dataArr[idx] < dataArr[minDataIdx])
			{
				minDataIdx = idx;
			}
		}

		tempData = dataArr[n];
		dataArr[n] = dataArr[minDataIdx];
		dataArr[minDataIdx] = tempData;
	}
}

int main()
{
	vector<int> dataArr = { 0,1,4,6,7,8,3,12,5,45,88,23,67,345,87,34,22 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	SelectionSort(dataArr);

	cout << "\nAfter Selection Sort:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}