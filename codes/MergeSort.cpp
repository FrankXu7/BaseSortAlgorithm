/**************************************************************************************************
 * 【归并排序算法】
 *
 * 【基本思路】
 *
 * 【性能分析】
 * 时间复杂度：
 * 空间复杂度：
 * 稳定性：
 *
 * 【算法总结】
 *
 * @author FrankX
 * @date 2021-07-19
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType为基础数字类型 */
template<typename NumType>
void RecursionCall(vector<NumType>& dataArr, vector<NumType>& tempArr, unsigned int minIdx, unsigned int maxIdx)
{
	if (minIdx >= maxIdx) return;

	unsigned int divIdx = static_cast<unsigned int>((minIdx + maxIdx) / 2);
	RecursionCall(dataArr, tempArr, minIdx, divIdx);
	RecursionCall(dataArr, tempArr, divIdx + 1, maxIdx);

	unsigned int leftIdx = minIdx;
	unsigned int rightIdx = divIdx + 1;
	unsigned int idx = minIdx;

	// 合并局部有序的部分 
	while (leftIdx <= divIdx && rightIdx <= maxIdx)
		tempArr[idx++] = (dataArr[leftIdx] < dataArr[rightIdx]) ?
			dataArr[leftIdx++] : dataArr[rightIdx++];

	// 有一部分区间已经合并完，追加剩余部分，以下两个while循环，只可能同时触发一个 
	while (leftIdx <= divIdx)
		tempArr[idx++] = dataArr[leftIdx++];
	while (rightIdx <= maxIdx)
		tempArr[idx++] = dataArr[rightIdx++];

	// 本次函数内始终操作的是[minIdx, maxIdx]，所以在合并排序完成后要同位置赋值回去 
	for (idx = minIdx; idx <= maxIdx; ++idx)
		dataArr[idx] = tempArr[idx];
}

/** NumType为基础数字类型 */
template<typename NumType>
void MergeSort_Recursion(vector<NumType>& dataArr)
{
	vector<NumType> tempArr(dataArr.size());
	RecursionCall(dataArr, tempArr, 0, dataArr.size() - 1);
}

/** NumType为基础数字类型 */
template<typename NumType>
void MergeSort_Iteration(vector<NumType>& dataArr)
{

}


int main()
{
	vector<int> arrRecursion = { 2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = arrRecursion.begin(); itr != arrRecursion.end(); ++itr)
		cout << *itr << ", ";
	MergeSort_Recursion(arrRecursion);
	cout << "\nAfter Merge Sort by Recursion:\n";
	for (vector<int>::iterator itr = arrRecursion.begin(); itr != arrRecursion.end(); ++itr)
		cout << *itr << ", ";

	//vector<int> arrIteration = { 2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6 };

	//cout << "\nArray data:\n";
	//for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
	//	cout << *itr << ", ";
	//MergeSort_Iteration(arrIteration);
	//for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
	//	cout << *itr << ", ";

	cout << endl;
	return 0;
}