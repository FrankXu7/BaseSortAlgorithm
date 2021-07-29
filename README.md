# BaseSortAlgorithm
#### **➤ 插入排序算法**

**【基本思路】**

将数组从逻辑上分成两部分，比如前面部分为已经排好序的，后面这部分还未排好序的，默认首个元素已经排好序。以升序排序为例，从未排好序的那部分开始，从后往前逐一与已经排好序的元素比较，若当前比较元素小于已排序部分的元素，则将已排序的元素逐一后移，直到找到合适的插入位置。需要特别注意的是，默认首个元素已经排好序，所以初始从下标1开始作为未排序元素的部分。

**【性能分析】**

时间复杂度：O(N^2)

空间复杂度：O(1)

稳定性：稳定

**【算法总结】**

由于其最差O(N^2)的时间复杂度，显然是不适用于大量数据的。一般将插入排序作为快速排序的补充，比如数据元素的数量小于一定的阈值，就采用插入排序，否则就采用快速排序。当数据量较小时，插入排序是较优的选择。

[代码链接（**InsertionSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/InsertionSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/InsertionSort.cpp)









**➤ 希尔排序算法**

**【基本思路】**

直接插入排序，每一轮确定一个最值，需要移动大量元素，才能确定一个元素有序。但直接插入排序，在对一个基本有序的数组进行排序时，其内部的元素移动循环操作，执行次数将减少，效率会更高，所以，需要想办法让数组趋于有序。希尔排序的核心思想就是分割，最开始从一个较大步长开始，按步长分割为一个个局部数组，对局部数组进行直接插入排序，因为步长一开始较大，所以移动元素很少，元素趋于有序。随着步长逐渐减小，虽然步长更小，但因为之前的局部直接插入排序使得数组已经趋于有序，所以移动元素也很少，当步长减少至1时，即退化为直接插入排序，但此时数组已经基本有序，元素移动操作大大减少，效率得以提升。需要注意的是，增量序列一般选择为 ArrayLength/2 递归，即集合 {...10,5,2,1}，但【互质】的增量序列集合，能进一步提升效率，并且，如果增量序列选的不好，甚至实际效率比直接插入排序还更低。比较优秀的增量序列有：Hibbard增量序列、Knuth增量序列、Sedgewick增量序列 等等。

 **【性能分析】**

时间复杂度：O(NlogN) 希尔排序的时间复杂度依赖于增量序列集合的选择，互质的增量序列，能提升效率

空间复杂度：O(1)

稳定性：不稳定

**【算法总结】**

希尔排序作为直接插入排序的改进版，是一种相对高效的元素交换排序算法。本质上，就是在直接插入排序算法的外层套了一层自定义步长的循环，通过使数组逐渐趋于有序，步长减小时，因为数组趋于有序，所以使用直接插入排序算法时能减少内层元素移动循环的执行次数。因为是跨步长分割，所以排序的稳定性就不能得到保证了。此外，希尔排序的时间复杂度分析起来比较困难，因为选取不同的增量序列，会有不同的时间复杂度情况，如果增量序列选择不好，甚至效率比直接插入排序还低。

[代码链接（**ShellSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/ShellSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/ShellSort.cpp)









#### **➤ 选择排序算法**

**【基本思路】**

两层循环，外层是比较的轮数，进行的轮数即代表已经排序好的元素数量，内层是某一轮比较，假设按升序排序，记录本轮比较中最小的数据的下标，本轮比较结束后，将本轮最小数据与对应外层循环轮数的下标数据交换。需要特别注意的是，外层只需要进行 size-1 轮比较，因为进行了 size-1 轮比较后，剩余的最后一个元素已经与其它元素都比较过了，相当于已经确定了排序位置，没有必要再来一轮了；内层循环中，每一轮都能选出最小的元素，所以内层每次遍历的元素数量要比上一轮少1，避免不必要的处理。

**【性能分析】**

时间复杂度：O(N^2)

空间复杂度：O(1)

稳定性：不稳定

**【算法总结】**

选择排序的实现虽然比较简单，是一种效率低下的排序方式，适用于数据规模较小时使用。在各种情况下复杂度波动较小，时间复杂度最好和最坏都是O(N^2)，所以相比于冒泡排序来说是更优解的。

[代码链接（**SelectionSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/SelectionSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/SelectionSort.cpp)









#### **➤ 堆排序算法**

**【基本思路】**

前置知识：大顶堆，即每个节点的值都大于其左右孩子的值；小顶堆，即每个节点的值都小于其左右孩子的值。这里需要注意的是，左右孩子并没有要求有序，只要它们都大于或小于父节点即可。数组构成的是一个完全二叉树。基于二叉树的结构，可以得出：

（1）对任一节点，假设其在数组下标为 index ，则该节点左右孩子下标为：2*index-1 和 2*index+1；

（2）对除根节点外任一节点，假设其在数组下标为 index，则其父节点为下标为：(i-1)/2，小数部分向下取整；

（3）从上到下，从左到右，最底部（大）的非叶子节点下标为：(ArrayLength/2)-1，小数部分向下取整；由上述规律，可知在任意局部三节点二叉树结构中，

​			大顶堆必须满足：array[index] >= array[2*index+1] && array[index] >= array[2*index+2]

​			小顶堆必须满足：array[index] <= array[2*index+1] && array[index] <= array[2*index+2]

首先，数组是从后往前逐渐开始有序的，每一轮构建顶堆之后，都会将最值元素放到根节点位置，然后将根节点元素与数组未排序部分的末尾元素交换即可。当数组剩余未排序部分的元素为空时，即排序完成。算法的难点在于顶堆的构建，顶堆构建从最大非叶子节点开始，之所以从最大非叶子节点开始，是为了将二叉树最底部最左侧的非叶子节点所构成的三节点局部二叉树进行局部有序，将局部三个节点（也可能是两个节点，但不可能是一个节点，否则就是叶子节点了），然后依次往前，逐渐将每轮的最值元素逐渐上浮到根节点。

**【性能分析】**

时间复杂度：O(NlogN)

空间复杂度：O(1)

稳定性：不稳定

**【算法总结】**

堆排序在保证了稳定的O(NlogN)时间复杂度的情况下（最好最坏和平均时间复杂度都相同），还有常数级别的空间复杂度。所以，基于堆排序比快速排序有更稳定的时间复杂度，且相比于快速排序和归并排序有常数级别的空间复杂度，在超大规模数据（比如百万千万级别以上）的排序中，会优先选择堆排序。因为堆排序花费时间主要是在构建顶堆的过程，而构建顶堆是从最大非叶子下标开始的，最大非叶子下标 (ArrayLength/2)-1 直接就将遍历数据减少一半，所以当数据规模越来越大时，排除在顶堆构建过程中的叶子节点也越来越多，堆排序的优势也就越发明显了。

[代码链接（**HeapSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/HeapSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/HeapSort.cpp)









#### **➤ 冒泡排序算法**

**【基本思路】**

两层循环，外层是比较的轮数，内层是某一轮比较，内层每轮遍历，对数据进行两两比较，若按升序排序，本轮比较会将最大的数逐渐冒泡到数组末端。需要注意的是，外层需要进行 size-1 轮比较，因为当进行了 size-1 轮比较后，只剩下最后一个元素，且所有其它元素都和它比较过，没必要再来一轮了；每一轮比较都能冒泡确定一个数的排序位置，所以内层每次遍历的元素数量要比上一轮少1，避免不必要的处理。

**【性能分析】**

时间复杂度：O(N^2)

空间复杂度：O(1)

稳定性：稳定

**【算法总结】**

冒泡排序是一种效率十分低下的排序，简单粗暴，适用于数据规模较小时使用。不过一般情况下，不会用冒泡排序。

[代码链接（**BubbleSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/BubbleSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/BubbleSort.cpp)









#### **➤ 快速排序算法**

**【基本思路】**

进行多轮排序，每轮在区间内任意选择一个基准数字（简单点以首元素为基准，不过随机一个元素做基准，会进一步减少时间复杂度趋于O(N^2)的概率），使得最后基准数字会大于其左侧元素，小于其右侧元素，数组相较之前更有序，再分割子区间继续递归进行多轮排序，数组逐渐变得有序，直到最后完全有序。默认将首元素作为基准数字，利用左右指针分别指向区间首尾元素，通过左右指针指向元素与基准数字进行比较，当左右指针相遇时，能确定基准数字最后的位置，此时，以基准数字所在位置为界，将数组划分为了左右两个子区间，且左区间的元素均小于基准数字，右区间的元素均大于基准数字。对左右两个子区间，各取首元素作为子区间的基准数字，且每个子区间都有指向区间首尾元素的左右指针，这样递归的操作下去，当子区间初始的左右指针就相遇时，即终止，最终得到一个有序数组。假设按升序排列，大致过程：

（1）从右指针开始，向左移动，如果右指针指向的元素小于基准数字，则将基准数字与右指针指向元素交换；

（2）然后从左指针开始，向右移动，左指针指向的元素大于基准数字，则将基准数字与左指针指向元素交换；

（3）反复经过（1）（2）步骤，当左右指针相遇时，得以确认基准数字的位置，其所在位置的左侧元素均小于基准数字，右侧元素均大于基准数字；

（4）以前面步骤所得基准数字位置为界，可将数组分割为两部分，对分割后的左右子区间，递归执行（1）（2）（3），直到某个子区间在初始时的左右指针就相遇了；

需要特别注意的是：为了减少频繁的元素交换，可先保存基准数字，然后将右指针指向元素赋值到左指针指向位置，反之亦然，这样左右交叉赋值后，当左右指针相遇退出本轮循环时，左指针指向的，必然是基准数字的元素位置，此时将之前保存的基准数字赋值到左指针指向位置，就完成了一轮处理，此时基准数字大于其左侧元素，小于其右侧元素，数组比之前更有序。

**【性能分析】**

时间复杂度：O(NlogN)

空间复杂度：O(logN) 

稳定性：不稳定

**【算法总结】**

虽然快速排序和归并排序，复杂度在数值上看区别不大，但一般认为，快速排序要优于归并排序。首先，快速排序最差时间复杂度O(N^2)这种情况出现概率极小极小；其次，快速排序更多的是比较操作，以及少量的赋值或交换操作，相比于归并排序大量的合并操作，效率上也更高；再者，并且快速排序是原地排序，只需要栈空间开销，而归并排序需要一个和数组同样长度的额外空间，且如果是递归实现，也需要栈空间开销。所以通常情况下，如果没有稳定性要求，首选快速排序。此外，如果数组元素是随机分部的，即有序性比较低，用快速排序会效率更高，与快速排序的硬件优化有关，内存高命中率之类的。

[代码链接（**QuickSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/QuickSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/QuickSort.cpp)









#### **➤ 归并排序算法**

**【基本思路】**

归并排序的基本思路就是“分治法”：

（1）分割：将数组对半分割，并在分割后的子数组中继续递归的对半分割；

（2）治理（解决）：分割到子数组只有一个元素的时候，可看作是有序；

（3）合并：从下往上，将有序的子数组两两合并，最终使整个数组有序；

**【性能分析】**

时间复杂度：O(NlogN) 为平均复杂度，时间复杂度取值区间实际为 [O(N), O(NlogN)]

空间复杂度：O(N) 对于递归版，除了单独的数组空间，还有递归的空间logN，递归版的实际空间复杂度为 O(N+logN)

稳定性：稳定

**【算法总结】**

一般认为，归并排序效率低于快速排序，虽然二者平均时间复杂度相同，且复杂度区间来看归并排序波动更小，但实际情况来看，快速排序，在连续内存的数组上效率要优于归并排序，而归并排序在链表数组上效率优于快速排序。归并排序中，最后的合并开销不可忽略，随着问题规模的增大，合并开销对效率的影响也越明显。但归并排序是稳定排序，通常情况下会选择快速排序，而当有稳定性需求时，就可以选择归并排序了。此外，如果能确认数组本身是基本有序的，可以用归并排序算法。

[代码链接（**MergeSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/MergeSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/MergeSort.cpp)









#### **➤ 桶排序算法**

**【基本思路】**

生成一个序列作为桶，序列中每个元素被当作是一个桶，以下标值作为分类，某个桶只放置其下标所表示的元素。为了保证数组元素一定有一个对应下标数值的桶，需要找出数组的最大值，并以此作为桶序列的大小。然后再次遍历数组，将元素放到桶序列中下标与数组元素相同某个桶内。最后，按需要的顺序遍历桶序列，将非空的桶内元素一一取出，追加到数组，即得到一个有序数组。

**【性能分析】**

时间复杂度：O(N) 实际上是O(3N)，找出最大元素，将元素放入桶内，从桶中取出元素，都要进行一次遍历

空间复杂度：O(M+N) M表示桶的个数，可能会远远大于元素数量N

稳定性：稳定 稳定性取决于桶的数据结构，若用栈作为桶是不稳定的，因为可以做到稳定，所以桶排序是稳定的

**【算法总结】**

从桶的生成可以看出，桶排序只适合于数据数值大小均匀分布的情况，即最值跨度不会太大时，其排序效率是较高的。如果跨度过大，如数组 [1,2,3,1000]，虽然只有4个元素，却需要创建1000个桶结构，极大的浪费空间。虽然桶排序理解实现都极为简单，但除非是在要求特别高（比如时间复杂度要低于O(NlogN)），或确定数组元素最值跨度会小于等于数组长度，否则一般不会选择桶排序算法，即使如此，也更倾向于考虑计数排序算法。桶排序，和计数排序以及基数排序一样，是一种非比较类型的排序，排序过程中并没有发生元素的比较。

[代码链接（**BucketSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/BucketSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/BucketSort.cpp)









#### **➤ 计数排序算法**

**【基本思路】**

生成一个序列，以计数序列中元素下标的下标值作为分类，统计在数组中，元素值等于序列下标时的数量，相较于桶排序，这个统计行为减少了一定的空间复杂度。和桶排序一样，为了保证数组元素一定有一个对应下标值的计数序列元素，需要找出数组的最大值。然后再次遍历数组，将计数序列中下标值与数组元素相同序列元素+1. 最后，按需要的顺序遍历计数序列，将非零的序列元素，取出元素值对应数量的下标值，追加到数组，即得到一个有序数组。

**【性能分析】**

时间复杂度：O(N) 实际上是O(3N)，找出最大元素，将元素个数统计到计数序列中，从计数序列中生成元素，都要进行遍历

空间复杂度：O(M) M表示计数序列元素的个数，可能会远远大于元素数量N

稳定性：稳定 

**【算法总结】**

和桶排序一样，只适合于数组元素最值跨度不大，比如跨度小于等于数组长度的情况。虽然计数排序理解实现都极为简单，但除非是在要求特别高（比如时间复杂度要低于O(NlogN)），或确定数组元素最值跨度会小于等于数组长度，否则一般不会选择计数排序算法，当需要桶排序时，优先考虑计数排序。计数排序，和桶排序以及基数排序一样，是一种非比较类型的排序，排序过程中并没有发生元素的比较。

[代码链接（**CountingSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/CountingSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/CountingSort.cpp)









#### **➤ 基数排序算法**

**【基本思路】**

桶排序和计数排序，空间复杂度会很高，特别是在数组元素最值跨度很大的时候。基数排序通过牺牲了一定的时间复杂度，来减少空间复杂度。大致过程：

（1）申请一个大小为10个元素的基数序列，因为单个十进制数字有10种；

（2）从低位开始，取个位数作为基数序列下标，将数组元素存入该下标所在的基数序列容器中；
（3）依次将基数序列各元素容器中的元素追加到数组；

（4）然后从下一位个位数开始，重复（2）（3）步骤，直到最大元素的最高位处理完毕，这里需要注意的是，数位较短的元素补0，其实就是放到基数序列下标为0的元素容器中；

基数排序依据从低位还是高位开始处理，分两种情况：

LSD（Least sgnificant digital）：先从低位开始进行排序；

MSD（Most sgnificant digital）：先从高位开始进行排序；

**【性能分析】**

时间复杂度：O(N*K) 这里的K指的是最大值元素的位数

空间复杂度：O(N) 实际是O(N+10)，需要一个长度为10的基数序列作为元素分类的容器

稳定性：稳定

**【算法总结】**

相比于桶排序和计数排序，基数排序拥有更优的空间复杂度，但是牺牲了一定的时间复杂度。如果一定要选择一种非选择类型的排序，但数组元素最值跨度很大，又或者同时对空间复杂度有所要求，那么基数排序是个不错的选择。基数排序，和桶排序以及计数排序一样，是一种非比较类型的排序，排序过程中并没有发生元素的比较。

[代码链接（**RadixSort.cpp**）：https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/RadixSort.cpp](https://github.com/FrankXu7/BaseSortAlgorithm/blob/main/codes/RadixSort.cpp)