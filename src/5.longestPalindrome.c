/*
5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


date:2020年2月4日
*/

/*
 * 思路：从中间向两端扩展。在扩展的时候有2种情况，及"aba"型与"abba"型
 */
char * longestPalindrome(char * s){
#define MAX_LONGEST_PALINDROME_LEN 1024
	char *result;
	int len =0, halfLen = 0, i, left = 0, right = 0, step = 0;
	int curLen = 0, longHead = 0, maxLen = 0;
	len = strlen(s);
	if (len <= 1) {
		return s;
	}
	result = (char *)malloc(sizeof(char) * MAX_LONGEST_PALINDROME_LEN);
	if (NULL == result) {
		return NULL;
	}
	memset(result, 0 ,MAX_LONGEST_PALINDROME_LEN);
	halfLen = (len + 1) / 2;
	for (i = 0; i < len; i++) {
		/*----------处理"aba"型开始--------------*/
		left = i;
		right = i;
		for (step = 1; step <= halfLen; step++) {
			if (left - step >= 0 && right + step < len) {
				if (s[left - step] == s[right + step]) {
					continue;
				} else {
					/*不满足回文字符串特性*/
					break;
				}
			} else {
				/*数组下标不合法*/
				break;
			}
		}
		curLen = 2 * (step - 1) + 1;
		if (curLen > maxLen) {
			maxLen = curLen;
			longHead = left - step + 1;
			//更新数组头下标
		}
		/*----------处理"aba"型结束--------------*/

		/*----------处理"abba"型开始--------------*/
		left = i;
		right = i + 1;
		if (right < len && s[left] == s[right]) {
			for (step = 1; step <= halfLen; step++) {
				if (left - step >= 0 && right + step < len) {
					if (s[left - step] == s[right + step]) {
						continue;
					} else {
						/*不满足回文字符串特性*/
						break;
					}
				} else {
					/*数组下标不合法*/
					break;
				}
			}
			curLen = 2 * (step - 1) + 2;
			if (curLen > maxLen) {
				maxLen = curLen;
				longHead = left - step + 1;
				//更新数组头下标
			}
		}
		/*----------处理"abba"型结束--------------*/
	}

	//result has been memset,so no need to set tail '\0'
	strncpy(result,(char *)(s + longHead), maxLen);

	return result;
}



