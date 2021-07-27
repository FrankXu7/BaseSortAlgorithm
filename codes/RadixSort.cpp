/**************************************************************************************************
 * 【基数排序算法】
 *
 * 【基本思路】
 * 桶排序和计数排序，空间复杂度会很高，特别是在数组元素最值跨度很大的时候。基数排序通过牺牲了一定的时间
 * 复杂度，来减少空间复杂度。大致过程：
 * （1）申请一个大小为10个元素的基数序列，因为单个十进制数字有10种；
 * （2）从低位开始，取个位数作为基数序列下标，将数组元素存入该下标所在的基数序列容器中；
 * （3）依次将基数序列各元素容器中的元素追加到数组；
 * （4）然后从下一位个位数开始，重复（2）（3）步骤，直到最大元素的最高位处理完毕，这里需要注意的是，数位
 *		较短的元素补0，其实就是放到基数序列下标为0的元素容器中；
 * 
 * 基数排序依据从低位还是高位开始处理，分两种情况：
 * LSD（Least sgnificant digital）：先从低位开始进行排序；
 * MSD（Most sgnificant digital）：先从高位开始进行排序；
 * 
 * 【性能分析】
 * 时间复杂度：O(N*K) 这里的K指的是最大值元素的位数
 * 空间复杂度：O(N) 实际是O(N+10)，需要一个长度为10的基数序列作为元素分类的容器
 * 稳定性：稳定
 *
 * 【算法总结】
 * 相比于桶排序和计数排序，基数排序拥有更优的空间复杂度，但是牺牲了一定的时间复杂度。如果一定要选择一种
 * 非选择类型的排序，但数组元素最值跨度很大，又或者同时对空间复杂度有所要求，那么基数排序是个不错的选择。
 * 基数排序，和桶排序以及计数排序一样，是一种非比较类型的排序，排序过程中并没有发生元素的比较。
 *
 * @author FrankX
 * @date 2021-07-27
 **************************************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
#include <array>
using namespace std;

void RadixSort(vector<unsigned int>& dataArr)
{
	array<deque<unsigned int>, 10> sequence;
	array<deque<unsigned int>, 10>::iterator itrSeq;
	vector<unsigned int>::iterator itrArr;

	// 统计当前的操作数，如果本轮所有小于10的操作数之和刚好是数组长度，表示这是最后一轮了 
	unsigned int lastDigitCount = 0;
	unsigned int dataSize = dataArr.size();
	// 除数，每轮需要乘上10，相当于从低位开始，逐位排除 
	unsigned int divNum = 1;
	unsigned int curNum = 0;
	
	while (lastDigitCount < dataSize)
	{
		lastDigitCount = 0;

		// 依据当前位数的值，分配到基数序列 
		for (itrArr = dataArr.begin(); itrArr != dataArr.end(); ++itrArr)
		{
			curNum = static_cast<unsigned int>(*itrArr / divNum);
			sequence[curNum % 10].emplace_back(*itrArr);

			if (curNum < 10) ++lastDigitCount;
		}

		divNum *= 10;
		itrArr = dataArr.begin();

		// 从基数序列依次取出元素追加到数组
		for (itrSeq = sequence.begin(); itrSeq != sequence.end(); ++itrSeq)
		{
			while (!(*itrSeq).empty())
			{
				*(itrArr++) = (*itrSeq).front();
				(*itrSeq).pop_front();
			}
		}
	}
}

int main()
{
	vector<unsigned int> dataArr = { 12,435,346,34,77,34,67,3,875,3444,65,99,36,84,473,689,3452,753 };

	cout << "Array data:\n";
	for (vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";
	RadixSort(dataArr);
	cout << "\nAfter Radix Sort:\n";
	for (vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}