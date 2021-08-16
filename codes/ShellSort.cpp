/**************************************************************************************************
 * 【希尔排序算法】
 *
 * 【基本思路】
 * 直接插入排序，每一轮确定一个最值，需要移动大量元素，才能确定一个元素有序。但直接插入排序，在对一个
 * 基本有序的数组进行排序时，其内部的元素移动循环操作，执行次数将减少，效率会更高，所以，需要想办法
 * 让数组趋于有序。
 * 希尔排序的核心思想就是分割，最开始从一个较大步长开始，按步长分割为一个个局部数组，对局部数组进行直接插入排序，
 * 因为步长一开始较大，所以移动元素很少，元素趋于有序。随着步长逐渐减小，虽然步长更小，但因为之前的
 * 局部直接插入排序使得数组已经趋于有序，所以移动元素也很少，当步长减少至1时，即退化为直接插入排序，
 * 但此时数组已经基本有序，元素移动操作大大减少，效率得以提升。
 * 
 * 需要注意的是，增量序列一般选择为 ArrayLength/2 递归，即集合 {...10,5,2,1}，
 * 但【互质】的增量序列集合，能进一步提升效率，并且，如果增量序列选的不好，甚至实际效率比直接插入排序还更低。
 * 比较优秀的增量序列有：Hibbard增量序列、Knuth增量序列、Sedgewick增量序列 等等。
 *
 * 【性能分析】
 * 时间复杂度：O(NlogN) 希尔排序的时间复杂度依赖于增量序列集合的选择，互质的增量序列，能提升效率
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 *
 * 【算法总结】
 * 希尔排序作为直接插入排序的改进版，是一种相对高效的元素交换排序算法。本质上，就是在直接插入排序算法的
 * 外层套了一层自定义步长的循环，通过使数组逐渐趋于有序，步长减小时，因为数组趋于有序，所以使用直接插入排序
 * 算法时能减少内层元素移动循环的执行次数。
 * 因为是跨步长分割，所以排序的稳定性就不能得到保证了。此外，希尔排序的时间复杂度分析起来比较困难，因为
 * 选取不同的增量序列，会有不同的时间复杂度情况，如果增量序列选择不好，甚至效率比直接插入排序还低。
 * 
 * 
 * @author FrankX
 * @date 2021-07-26
 **************************************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define TO_INT(num) static_cast<int>(num)

/** NumType为基础数字类型 */
template<typename NumType>
void ShellSort(vector<NumType>& dataArr)
{
	int dataSize = TO_INT(dataArr.size());
	int idx = 0;
	NumType curNum = 0;

	// 相当于在直接插入排序套了一层自定义步长，直接插入排序算法的步长为1 
	for (int step = TO_INT(dataSize / 2); step > 0; step = TO_INT(step / 2))
	{
		// 这里其实就是直接插入排序了，只不过自定义了步长 
		for (int n = step; n < dataSize; ++n)
		{
			idx = n;
			curNum = dataArr[idx];
			/**
			 * 在直接插入排序中，有序性越低的数组，执行此循环的次数也就越多，所以时间复杂度会达到O(N^2)；
			 * 而在希尔排序时，因为经过了多轮不同步长的局部插入排序，使得当步长减少至1时，
			 * 退化为直接插入排序，但此时，数组已经基本有序，直接插入效率能接近O(N)，
			 * 本质上就是这个while循环被执行的次数大大减少 
			 */
			while ((idx -= step) >= 0 && dataArr[idx] > curNum)
			{
				dataArr[idx + step] = dataArr[idx];
			}
			dataArr[idx + step] = curNum;
		}
	}
}

int main()
{
	vector<int> dataArr = { 1, 5, 6, 2, 4, 3, 7, 9, 8 };

	cout << "Array data:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";
	ShellSort(dataArr);
	cout << "\nAfter Shell Sort:\n";
	for (vector<int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}