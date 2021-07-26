/**************************************************************************************************
 * 【快速排序算法】
 *
 * 【基本思路】
 * 进行多轮排序，每轮在区间内任意选择一个基准数字（简单点以首元素为基准，不过随机一个元素做基准，
 * 会进一步减少时间复杂度趋于O(N^2)的概率），使得最后基准数字会大于其左侧元素，小于其右侧元素，
 * 数组相较之前更有序，再分割子区间继续递归进行多轮排序，数组逐渐变得有序，直到最后完全有序。
 * 默认将首元素作为基准数字，利用左右指针分别指向区间首尾元素，通过左右指针指向元素与基准数字进行比较，
 * 当左右指针相遇时，能确定基准数字最后的位置，此时，以基准数字所在位置为界，将数组划分为了左右两个子区间，
 * 且左区间的元素均小于基准数字，右区间的元素均大于基准数字。对左右两个子区间，各取首元素作为子区间的基准数字，
 * 且每个子区间都有指向区间首尾元素的左右指针，这样递归的操作下去，当子区间初始的左右指针就相遇时，即终止，
 * 最终得到一个有序数组。假设按升序排列，大致过程：
 * （1）从右指针开始，向左移动，如果右指针指向的元素小于基准数字，则将基准数字与右指针指向元素交换；
 * （2）然后从左指针开始，向右移动，左指针指向的元素大于基准数字，则将基准数字与左指针指向元素交换；
 * （3）反复经过（1）（2）步骤，当左右指针相遇时，得以确认基准数字的位置，其所在位置的左侧元素均小于基准数字，
 *		右侧元素均大于基准数字；
 * （4）以前面步骤所得基准数字位置为界，可将数组分割为两部分，对分割后的左右子区间，递归执行（1）（2）（3），
 *		直到某个子区间在初始时的左右指针就相遇了；
 * 需要特别注意的是：为了减少频繁的元素交换，可先保存基准数字，然后将右指针指向元素赋值到左指针指向位置，反之亦然，
 * 这样左右交叉赋值后，当左右指针相遇退出本轮循环时，左指针指向的，必然是基准数字的元素位置，此时将之前保存的
 * 基准数字赋值到左指针指向位置，就完成了一轮处理，此时基准数字大于其左侧元素，小于其右侧元素，数组比之前更有序。
 * 
 * 【性能分析】
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(logN) 
 * 稳定性：不稳定
 *
 * 【算法总结】
 * 虽然快速排序和归并排序，复杂度在数值上看区别不大，但一般认为，快速排序要优于归并排序。首先，快速排序最差
 * 时间复杂度O(N^2)这种情况出现概率极小极小；其次，快速排序更多的是比较操作，以及少量的赋值或交换操作，相比于
 * 归并排序大量的合并操作，效率上也更高；再者，并且快速排序是原地排序，只需要栈空间开销，而归并排序需要一个
 * 和数组同样长度的额外空间，且如果是递归实现，也需要栈空间开销。所以通常情况下，如果没有稳定性要求，首选快速排序。
 * 此外，如果数组元素是随机分部的，即有序性比较低，用快速排序会效率更高，
 * 与快速排序的硬件优化有关，内存高命中率之类的。
 *
 * @author FrankX
 * @date 2021-07-22
 **************************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/** NumType是基础的数字类型 */
template<typename NumType>
void QuickSort_Recursion(vector<NumType>& dataArr, unsigned int minIdx, unsigned int maxIdx)
{
	if (minIdx >= maxIdx) return;

	unsigned int leftIdx = minIdx;
	unsigned int rightIdx = maxIdx;
	// 记录基准数字，这样在左右指针需要交换时，不用每次都进行交换操作
	NumType baseNum = dataArr[minIdx];

	/**
	 * 循环到左右指针相遇，跳出循环时，左指针指向的就是基准数字的位置，
	 * 此时直接将保存到baseNum的基准数字赋值即可，减少在内部循环时的频繁元素交换操作
	 */
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
	stack<pair<unsigned int, unsigned int>> recorders;
	recorders.push((make_pair(0, dataArr.size() - 1)));

	pair<unsigned int, unsigned int> idxRange;
	// 每次确定一个基准数字的位置后，就能以此分割出两个子区间，其实就是模拟了类似递归的开栈过程 
	pair<unsigned int, unsigned int> rangeLeft;
	pair<unsigned int, unsigned int> rangeRight;

	unsigned int leftIdx = 0;
	unsigned int rightIdx = 0;
	unsigned int idx = 0;
	// 记录基准数字，这样在左右指针需要交换时，不用每次都进行交换操作
	NumType baseNum = 0;

	while (!recorders.empty())
	{
		idxRange = recorders.top();
		recorders.pop();

		leftIdx = idxRange.first;
		rightIdx = idxRange.second;
		idx = idxRange.first;
		baseNum = dataArr[idxRange.first];

		/**
		 * 循环到左右指针相遇，跳出循环时，左指针指向的就是基准数字的位置，
		 * 此时直接将保存到baseNum的基准数字赋值即可，减少在内部循环时的频繁元素交换操作
		 */
		while (leftIdx < rightIdx)
		{
			while (leftIdx < rightIdx && dataArr[rightIdx] >= baseNum)
			{
				--rightIdx;
			}
			dataArr[leftIdx] = dataArr[rightIdx];

			while (leftIdx < rightIdx && dataArr[leftIdx] <= baseNum)
			{
				++leftIdx;
			}
			dataArr[rightIdx] = dataArr[leftIdx];
		}
		dataArr[leftIdx] = baseNum;

		// 这一波就相当于递归时，在确认了基准数字位置后，分割出两个子空间 
		rangeLeft.first = idxRange.first;
		rangeLeft.second = (leftIdx == 0 ? 0 : leftIdx - 1);
		rangeRight.first = leftIdx + 1;
		rangeRight.second =	idxRange.second;

		// 这一波就相当于递归调用时的截止条件，有入栈数据，则会继续循环 
		if (rangeLeft.first < rangeLeft.second) recorders.push(rangeLeft);
		if (rangeRight.first < rangeRight.second) recorders.push(rangeRight);
	}
}

int main()
{
	vector<int> arrRecursion = { 1111, 1, 8, 2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6, 9, 5, 0 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = arrRecursion.begin(); itr != arrRecursion.end(); ++itr)
		cout << *itr << ", ";
	QuickSort_Recursion(arrRecursion, 0, arrRecursion.size() - 1);
	cout << "\nAfter Quick Sort by Recursion:\n";
	for (vector<int>::iterator itr = arrRecursion.begin(); itr != arrRecursion.end(); ++itr)
		cout << *itr << ", ";

	vector<int> arrIteration = { 1, 8, 2, 4, 54, 23, 44, 65, 25, 76, 16, 54, 77, 3, 7, 6, 9, 5, 0 };

	cout << "\n\nArray data:\n";
	for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
		cout << *itr << ", ";
	QuickSort_Iteration(arrIteration);
	cout << "\nAfter Quick Sort by Iteration:\n";
	for (vector<int>::iterator itr = arrIteration.begin(); itr != arrIteration.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}