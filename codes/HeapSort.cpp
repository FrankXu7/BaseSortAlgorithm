/**************************************************************************************************
 * 【堆排序算法】
 *
 * 【基本思路】
 * 前置知识：大顶堆，即每个节点的值都大于其左右孩子的值；小顶堆，即每个节点的值都小于其左右孩子的值。
 * 这里需要注意的是，左右孩子并没有要求有序，只要它们都大于或小于父节点即可。数组构成的是一个完全二叉树。
 * 基于二叉树的结构，可以得出：
 * （1）对任一节点，假设其在数组下标为 index ，则该节点左右孩子下标为：2*index-1 和 2*index+1；
 * （2）对除根节点外任一节点，假设其在数组下标为 index，则其父节点为下标为：(i-1)/2，小数部分向下取整；
 * （3）从上到下，从左到右，最底部（大）的非叶子节点下标为：(ArrayLength/2)-1，小数部分向下取整；
 * 
 * 由上述规律，可知在任意局部三节点二叉树结构中，
 *		大顶堆必须满足：array[index] >= array[2*index+1] && array[index] >= array[2*index+2]
 *		小顶堆必须满足：array[index] <= array[2*index+1] && array[index] <= array[2*index+2]
 * 
 * 首先，数组是从后往前逐渐开始有序的，每一轮构建顶堆之后，都会将最值元素放到根节点位置，然后将根节点元素
 * 与数组未排序部分的末尾元素交换即可。当数组剩余未排序部分的元素为空时，即排序完成。算法的难点在于顶堆的构建，
 * 顶堆构建从最大非叶子节点开始，之所以从最大非叶子节点开始，是为了将二叉树最底部最左侧的非叶子节点所构成的
 * 三节点局部二叉树进行局部有序，将局部三个节点（也可能是两个节点，但不可能是一个节点，否则就是叶子节点了），
 * 然后依次往前，逐渐将每轮的最值元素逐渐上浮到根节点。
 *
 * 【性能分析】
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 *
 * 【算法总结】
 * 堆排序在保证了稳定的O(NlogN)时间复杂度的情况下（最好最坏和平均时间复杂度都相同），还有常数级别的空间复杂度。
 * 所以，基于堆排序比快速排序有更稳定的时间复杂度，且相比于快速排序和归并排序有常数级别的空间复杂度，
 * 在超大规模数据（比如百万千万级别以上）的排序中，会优先选择堆排序。因为堆排序花费时间主要是在构建顶堆的过程，
 * 而构建顶堆是从最大非叶子下标开始的，最大非叶子下标 (ArrayLength/2)-1 直接就将遍历数据减少一半，
 * 所以当数据规模越来越大时，排除在顶堆构建过程中的叶子节点也越来越多，堆排序的优势也就越发明显了。
 *
 * @author FrankX
 * @date 2021-07-26
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/** NumType为基础数字类型 */
template<typename NumType>
void SwapNum(NumType& a, NumType& b)
{
	NumType temp = a;
	a = b;
	b = temp;
}

/** NumType为基础数字类型 */
template<typename NumType>
void HeapSort(vector<NumType>& dataArr)
{
	int dataSize = dataArr.size();
	// 最大的非叶子节点下标 
	int maxNonLeafIdx = static_cast<int>(dataSize / 2) - 1;
	// 当前要操作的下标，每轮堆构建都需要初始化为首个非叶子节点下标 
	int opIdx = maxNonLeafIdx;
	// 当前排序到的下标 
	int curSortIdx = dataSize - 1;

	// 每轮排序确定一个最大（小）元素 
	while (curSortIdx >= 0)
	{
		// 构造顶堆过程，从最大非叶子下标开始构造 
		while (opIdx >= 0)
		{
			int leftIdx = 2 * opIdx + 1;
			/**
			 * leftIdx <= curSortIdx 其实会一直满足，因为顶堆构建是从非叶子节点开始的，
			 * 基于完全二叉树的结构特性，顶堆构建时，参与遍历的一定是非叶子节点
			 */
			if (leftIdx <= curSortIdx && dataArr[leftIdx] > dataArr[opIdx])
			{
				SwapNum(dataArr[leftIdx], dataArr[opIdx]);
			}

			int rightIdx = 2 * opIdx + 2;
			if (rightIdx <= curSortIdx && dataArr[rightIdx] > dataArr[opIdx])
			{
				SwapNum(dataArr[rightIdx], dataArr[opIdx]);
			}

			--opIdx;
		}
		/**
		 * 当前排序的下标比最大非叶子节点下标更小，此时不必再从最大非叶子节点下标开始，
		 * 直接从当前排序下标开始就可以，避免对已经排序好的元素重复处理
		 */
		opIdx = curSortIdx <= maxNonLeafIdx ? curSortIdx : maxNonLeafIdx;

		// 构造顶堆完成后，首元素必为最大（小）值，与当前排序下标进行交换
		SwapNum(dataArr[0], dataArr[curSortIdx--]);
	}
}

int main()
{
	vector<int> dataArr = { 1,5,3,4,7,6,2,9,8 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";
	HeapSort(dataArr);
	cout << "\nAfter Heap Sort:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}