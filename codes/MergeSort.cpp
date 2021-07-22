/**************************************************************************************************
 * 【归并排序算法】
 *
 * 【基本思路】
 * 归并排序的基本思路就是“分治法”：
 * （1）分割：将数组对半分割，并在分割后的子数组中继续递归的对半分割；
 * （2）治理（解决）：分割到子数组只有一个元素的时候，可看作是有序；
 * （3）合并：从下往上，将有序的子数组两两合并，最终使整个数组有序；
 *
 * 【性能分析】
 * 时间复杂度：O(NlogN) 为平均复杂度，时间复杂度取值区间实际为 [O(N), O(NlogN)]
 * 空间复杂度：O(N) 对于递归版，除了单独的数组空间，还有递归的空间logN，递归版的实际空间复杂度为 O(N+logN)
 * 稳定性：稳定
 *
 * 【算法总结】
 * 一般认为，归并排序效率低于快速排序，虽然二者平均时间复杂度相同，且复杂度区间来看归并排序波动更小，但实际
 * 情况来看，快速排序，在连续内存的数组上效率要优于归并排序，而归并排序在链表数组上效率优于快速排序。
 * 归并排序中，最后的合并开销不可忽略，随着问题规模的增大，合并开销对效率的影响也越明显。但归并排序是稳定排序，
 * 通常情况下会选择快速排序，而当有稳定性需求时，就可以选择归并排序了。
 *
 * @author FrankX
 * @date 2021-07-21
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType为基础数字类型 */
template <typename NumType>
void RecursionCall(vector<NumType> &dataArr, vector<NumType> &tempArr, unsigned int minIdx, unsigned int maxIdx)
{
	if (minIdx >= maxIdx)
		return;

	unsigned int divIdx = static_cast<unsigned int>((minIdx + maxIdx) / 2);
	RecursionCall(dataArr, tempArr, minIdx, divIdx);
	RecursionCall(dataArr, tempArr, divIdx + 1, maxIdx);

	unsigned int leftIdx = minIdx;
	unsigned int rightIdx = divIdx + 1;
	unsigned int idx = minIdx;

	// 合并局部有序的部分
	while (leftIdx <= divIdx && rightIdx <= maxIdx)
		tempArr[idx++] = (dataArr[leftIdx] < dataArr[rightIdx]) ? dataArr[leftIdx++] : dataArr[rightIdx++];

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
template <typename NumType>
void MergeSort_Recursion(vector<NumType> &dataArr)
{
	vector<NumType> tempArr(dataArr.size());
	RecursionCall(dataArr, tempArr, 0, dataArr.size() - 1);
}

/** NumType为基础数字类型 */
template <typename NumType>
void MergeSort_Iteration(vector<NumType> &dataArr)
{
	unsigned int dataSize = dataArr.size();
	vector<NumType> tempArr(dataSize);

	unsigned int minIdx, divIdx, maxIdx, leftIdx, rightIdx, idx;
	minIdx = divIdx = maxIdx = leftIdx = rightIdx = idx = 0;

	for (unsigned int step = 1; step < dataSize; step *= 2)
	{
		for (unsigned int n = 0; n < dataSize;)
		{
			minIdx = n;
			/**
			 * 分割下标，将局部数组分割为 [minIdx, divIdx] 和 [divIdx+1, maxIdx] 
			 * 因为左子区间已经包含起始下标minIdx，所以分割下标要-1 
			 */
			divIdx = min(dataSize - 1, minIdx + step - 1);
			maxIdx = min(dataSize - 1, divIdx + step);
			// 更新下一波合并的起始下标
			n = maxIdx + 1;

			leftIdx = minIdx;
			rightIdx = min(dataSize, divIdx + 1);
			idx = minIdx;

			// 合并局部有序的部分
			while (leftIdx <= divIdx && rightIdx <= maxIdx)
				tempArr[idx++] = (dataArr[leftIdx] < dataArr[rightIdx]) ? dataArr[leftIdx++] : dataArr[rightIdx++];

			// 有一部分区间已经合并完，追加剩余部分，以下两个while循环，只可能同时触发一个
			while (leftIdx <= divIdx)
				tempArr[idx++] = dataArr[leftIdx++];
			while (rightIdx <= maxIdx)
				tempArr[idx++] = dataArr[rightIdx++];

			// 本次函数内始终操作的是[minIdx, maxIdx]，所以在合并排序完成后要同位置赋值回去
			for (idx = minIdx; idx <= maxIdx; ++idx)
				dataArr[idx] = tempArr[idx];
		}
	}
}

int main()
{
	vector<int> arrRecursion = {2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6, 9, 5};

	cout << "Array data:\n";
	for (vector<int>::iterator itr = arrRecursion.begin(); itr != arrRecursion.end(); ++itr)
		cout << *itr << ", ";
	MergeSort_Recursion(arrRecursion);
	cout << "\nAfter Merge Sort by Recursion:\n";
	for (vector<int>::iterator itr = arrRecursion.begin(); itr != arrRecursion.end(); ++itr)
		cout << *itr << ", ";

	vector<int> arrIteration = {2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6, 9, 5};

	cout << "\n\nArray data:\n";
	for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
		cout << *itr << ", ";
	MergeSort_Iteration(arrIteration);
	cout << "\nAfter Merge Sort by Iteration:\n";
	for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}