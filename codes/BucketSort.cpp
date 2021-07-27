/**************************************************************************************************
 * 【桶排序算法】
 *
 * 【基本思路】
 * 生成一个序列作为桶，序列中每个元素被当作是一个桶，以下标值作为分类，某个桶只放置其下标所表示的元素。
 * 为了保证数组元素一定有一个对应下标数值的桶，需要找出数组的最大值，并以此作为桶序列的大小。然后再次
 * 遍历数组，将元素放到桶序列中下标与数组元素相同某个桶内。最后，按需要的顺序遍历桶序列，将非空的桶内
 * 元素一一取出，追加到数组，即得到一个有序数组。
 *
 * 【性能分析】
 * 时间复杂度：O(N) 实际上是O(3N)，找出最大元素，将元素放入桶内，从桶中取出元素，都要进行一次遍历
 * 空间复杂度：O(M+N) M表示桶的个数，可能会远远大于元素数量N
 * 稳定性：稳定 稳定性取决于桶的数据结构，若用栈作为桶是不稳定的，因为可以做到稳定，所以桶排序是稳定的
 * 
 * 【算法总结】
 * 从桶的生成可以看出，桶排序只适合于数据数值大小均匀分布的情况，即最值跨度不会太大时，其排序效率是较高的。
 * 如果跨度过大，如数组 [1,2,3,1000]，虽然只有4个元素，却需要创建1000个桶结构，极大的浪费空间。虽然桶排序
 * 理解实现都极为简单，但除非是在要求特别高（比如时间复杂度要低于O(NlogN)），或确定数组元素最值跨度会小于
 * 等于数组长度，否则一般不会选择桶排序算法，即使如此，也更倾向于考虑计数排序算法。
 * 桶排序，和计数排序以及基数排序一样，是一种非比较类型的排序，排序过程中并没有发生元素的比较。
 * 
 * @author FrankX
 * @date 2021-07-27
 **************************************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void BucketSort(vector<unsigned int>& dataArr)
{
	// 找出最大元素 
	vector<unsigned int>::iterator itr = dataArr.begin();
	unsigned int maxNum = *(itr++);
	for (; itr != dataArr.end(); ++itr)
	{
		if (*itr > maxNum) maxNum = *itr;
	}

	vector<deque<unsigned int>> buckets;
	// +1相当于将下标0元素弃用，便于逻辑理解 
	buckets.resize(maxNum + 1);

	// 将元素放在桶里 
	for (itr = dataArr.begin(); itr != dataArr.end(); ++itr)
	{
		buckets[*itr].emplace_back(*itr);
	}

	unsigned int idx = 0;
	// 依次从桶里取出元素 
	for (typename vector<deque<unsigned int>>::iterator itd = buckets.begin(); itd != buckets.end(); ++itd)
	{
		// 运算符优先级（从高到低）：间接成员运算符(->) 直接成员运算符(.) 逻辑非(!) 解除引用(*) 
		while (!(*itd).empty())
		{
			dataArr[idx++] = (*itd).front();
			(*itd).pop_front();
		}
	}
}

int main()
{
	vector<unsigned int> dataArr = { 8,4,1,6,3,5,7,2,9,7,366,5,3 };

	cout << "Array data:\n";
	for (vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";
	BucketSort(dataArr);
	cout << "\nAfter Bucket Sort:\n";
	for (vector<unsigned int>::iterator itr = dataArr.begin(); itr != dataArr.end(); ++itr)
		cout << *itr << ", ";

	cout << endl;
	return 0;
}