/*
4. 寻找两个有序数组的中位数

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/*
 * 思路解析：数学思维
 * 详细思路查看链接 ：
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu-b/
 *
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	int m, n, imin, imax, halfLen, i, j, maxLeft, minRight;
	int *array1, *array2;
	if (nums1Size > nums2Size) {
		array1 = nums2;
		array2 = nums1;
		m = nums2Size;
		n = nums1Size;
	} else {
		array1 = nums1;
		array2 = nums2;
		m = nums1Size;
		n = nums2Size;
	}

	imin = 0;
	imax = m;
	halfLen = (m + n + 1) / 2;

	while(imin <= imax) {
		i = (imin + imax) / 2;
		j = halfLen - i;
		if (i < imax && array1[i] < array2[j - 1]) {
			imin = i + 1;
		} else if (i > imin && array1[i - 1] > array2[j]) {
			imax = i - 1;
		} else {
			if (i == 0) {
				maxLeft = array2[j - 1];
			} else if (j == 0) {
				maxLeft = array1[i - 1];
			} else {
				maxLeft = array1[i - 1] > array2[j - 1] ? array1[i - 1] : array2[j - 1];
			}
			if ( (m + n) % 2 == 1) {
				return maxLeft;
			} 

			if (i == m) {
				minRight = array2[j];
			} else if (j == n) {
				minRight = array1[i];
			} else {
				minRight = array1[i] < array2[j] ? array1[i] : array2[j];
			}

			return ((maxLeft + minRight) / 2.0);
		}
	}
	return 0;
}

