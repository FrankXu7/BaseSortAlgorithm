/**************************************************************************************************
 * 【冒泡排序算法】
 * 
 * 【基本思路】
 * 两层循环，外层是比较的轮数，内层是某一轮比较，内层每轮遍历，对数据进行两两比较，若按升序排序，
 * 本轮比较会将最大的数逐渐冒泡到数组末端。需要注意的是，外层需要进行 size-1 轮比较，因为当进行
 * 了 size-1 轮比较后，只剩下最后一个元素，且所有其它元素都和它比较过，没必要再来一轮了；每一轮
 * 比较都能冒泡确定一个数的排序位置，所以内层每次遍历的元素数量要比上一轮少1，避免不必要的处理。
 * 
 * 【性能分析】
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 * 
 * 【算法总结】
 * 冒泡排序是一种效率十分低下的排序，简单粗暴，适用于数据规模较小时使用。不过一般情况下，不会用冒泡排序。
 * 
 * @author FrankX
 * @date 2021-07-19
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType为基础的数字类型 */
template<typename NumType>
void BubbleSort(vector<NumType>& dataArr)
{
	unsigned int dataSize = dataArr.size();
	NumType tempData = 0;
	// 标记本轮比较是否发生过交换，如果没有，标识数组已经有序，中止下轮比较 
	bool markExchange = false;
	
	// 进行 dataSize-1 轮排序后剩余的最后一个元素，已经和其它所有元素比较过了，是有序的，没必要再来一轮 
	for (unsigned int n = 1; n < dataSize; ++n)
	{
		// 每轮都能冒泡确定一个数的排序位置，所以不必每轮都比较所有元素 
		for (unsigned int idx = 0; idx < dataSize - n; ++idx)
		{
			if (dataArr[idx] > dataArr[idx + 1])
			{
				tempData = dataArr[idx + 1];
				dataArr[idx + 1] = dataArr[idx];
				dataArr[idx] = tempData;

				markExchange = true;
			}
		}

		if (!markExchange) break;

		markExchange = false;
	}
}

int main()
{
	vector<int> dataArr = { 1, 34, 56, 32, 45, 3, 6, 8, 9, 0, 23, 55, 4 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	BubbleSort(dataArr);

	cout << "\nAfter Bubble Sort:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}