/**************************************************************************************************
 * 【快速排序算法】
 *
 * 【基本思路】
 *
 * 【性能分析】
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(logN) 
 * 稳定性：
 *
 * 【算法总结】
 * 
 *
 * @author FrankX
 * @date 2021-07-21
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType是基础的数字类型 */
template<typename NumType>
void QuickSort_Recursion(vector<NumType>& dataArr, unsigned int minIdx, unsigned int maxIdx)
{
	if (minIdx >= maxIdx) return;

	unsigned int leftIdx = minIdx;
	unsigned int rightIdx = maxIdx;
	NumType baseNum = dataArr[minIdx];

	while (leftIdx < rightIdx)
	{
		while (leftIdx < rightIdx && dataArr[rightIdx] >= baseNum)
		{
			--rightIdx;
		}
		// 从最右侧起，找到首个小于当前基准的数据，并赋值到基准所在下标 
		dataArr[leftIdx] = dataArr[rightIdx];

		while (leftIdx < rightIdx && dataArr[leftIdx] <= baseNum)
		{
			++leftIdx;
		}
		// 从最左侧起，找到首个大于当前基准的数据，并赋值到基准所在下标 
		dataArr[rightIdx] = dataArr[leftIdx];
	}
	// 将记录的基准数据赋值到循环比较后所确定的新位置 
	dataArr[leftIdx] = baseNum;

	QuickSort_Recursion(dataArr, minIdx, (leftIdx == 0 ? 0 : leftIdx - 1));
	QuickSort_Recursion(dataArr, leftIdx + 1, maxIdx);
}

/** NumType是基础的数字类型 */
template<typename NumType>
void QuickSort_Iteration(vector<NumType>& dataArr)
{

}

int main()
{
	vector<int> arrIteration = { 1, 8, 2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6, 9, 5 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
		cout << *itr << ", ";
	QuickSort_Recursion(arrIteration, 0, arrIteration.size() - 1);
	cout << "\nAfter Quick Sort by Recursion:\n";
	for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}