/**************************************************************************************************
 * 【计数排序算法】
 *
 * 【基本思路】
 * 生成一个序列，以计数序列中元素下标的下标值作为分类，统计在数组中，元素值等于序列下标时的数量，相较于桶排序，
 * 这个统计行为减少了一定的空间复杂度。和桶排序一样，为了保证数组元素一定有一个对应下标值的计数序列元素，
 * 需要找出数组的最大值。然后再次遍历数组，将计数序列中下标值与数组元素相同序列元素+1. 最后，按需要的顺序
 * 遍历计数序列，将非零的序列元素，取出元素值对应数量的下标值，追加到数组，即得到一个有序数组。
 *
 * 【性能分析】
 * 时间复杂度：O(N) 实际上是O(3N)，找出最大元素，将元素个数统计到计数序列中，从计数序列中生成元素，都要进行遍历
 * 空间复杂度：O(M) M表示计数序列元素的个数，可能会远远大于元素数量N
 * 稳定性：稳定 
 *
 * 【算法总结】
 * 和桶排序一样，只适合于数组元素最值跨度不大，比如跨度小于等于数组长度的情况。虽然计数排序理解实现都极为简单，
 * 但除非是在要求特别高（比如时间复杂度要低于O(NlogN)），或确定数组元素最值跨度会小于等于数组长度，
 * 否则一般不会选择计数排序算法，当需要桶排序时，优先考虑计数排序。
 * 计数排序，和桶排序以及基数排序一样，是一种非比较类型的排序，排序过程中并没有发生元素的比较。
 *
 * @author FrankX
 * @date 2021-07-27
 **************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void CountingSort(vector<unsigned int>& dataArr)
{
	// 找出最大值用于确定序列大小 
	vector<unsigned int>::iterator itr = dataArr.begin();
	unsigned int maxNum = *(itr++);
	for (typename vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
	{
		if (*itr > maxNum) maxNum = *itr;
	}

	vector<unsigned int> sequence;
	// +1相当于将下标0元素弃用，便于逻辑理解 
	sequence.resize(static_cast<unsigned int>(maxNum + 1));

	// 统计元素个数 
	for (itr = dataArr.begin(); itr != dataArr.end(); ++itr)
	{
		++sequence[*itr];
	}

	unsigned int idx = 0;
	// 依次从序列里生成元素追加到数组 
	for (unsigned int n = 0; n <= maxNum; ++n)
	{
		while (sequence[n] > 0)
		{
			dataArr[idx++] = n;
			--sequence[n];
		}
	}
}

int main()
{
	vector<unsigned int> dataArr = { 8,4,1,6,3,5,7,2,9,7,366,5,3 };

	cout << "Array data:\n";
	for (vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";
	CountingSort(dataArr);
	cout << "\nAfter Counting Sort:\n";
	for (vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}