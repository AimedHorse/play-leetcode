/*
3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


date:2020年2月2日

*/

int lengthOfLongestSubstring(char * s)
{
	int begin = 0, end = 0, record = 0, max = 0, current = 0;
	int len = strlen(s);
	if (len == 0) {
		return 0;
	} else if (len == 1) {
		return 1;
	}
	//len - record > max解释：
	//当剩余的字符串长度，不足以超过目前统计的字符串长度时，后面的计算不再需要
	for (end = 0; end < len && len - record > max; end++) {
		current++;
		for (begin = record; begin <= end; begin++) {
			if (s[begin] == s[end + 1]) {
				/*发现有相同的字符时，需要更新信息
				 1. 更新头部指针信息
				 2. 更新当前不重复字符串长度*/
				if (current > max) {
					max = current;
				}
				record = begin + 1;
				current = end - record + 1;
			}
		}
	}
	if (current > max) {
		return current;
	}
	return max;
}


int lengthOfLongestSubstring_4ms(char * s){
    int begin = 0, end = 0, record = 0, max = 0, current = 0;

	for (end = 0 ; s[end] != '\0'; end++) {
		for (begin = record; begin < end; begin++) {
			if (s[begin] == s[end]) {
				record = begin + 1;
				current = end - begin;
				break;
			}
		}
		if (begin == end) {
			current++;
		}
		if (current > max) {
			max = current;
		}
	}
	return max;
}



/*
 * 心的：利用桶来实现过滤并且记录的功能
 */
int lengthOfLongestSubstring_bucket(char * s){
	//char使用128的桶就够了，使用ASCII字符对应的int值来实现映射
	int bucket[128];
	int strLen = strlen(s);//计算出字符串的长度
	int i;//用于遍历给定的字符串
	int head = 0;//用于记录无重复字符的最长子串的串头
	int curLen = 0;//计算当前无重复字符的子串的长度
	int maxLen = 0;//记录当前无重复字符的最长子串的长度
	//初始化桶的元素为-1，桶中用于记录该字符最近出现的索引位置
	memset(bucket, -1, sizeof(int) * 128);

	for (i = 0; i < strLen; i++) {
		//当前字符对应桶中的元素在之前已经出现过
		//需要进行更新无重复字符的子串的串头
		if (bucket[s[i]] >= head) {
			//无重复字符的子串的串头索引值为该字符上次出现的索引位置+1
			head = bucket[s[i]] + 1;
		}
		//更新当前字符对应桶中的索引值
		bucket[s[i]] = i;
		//计算当前字符串长度
		curLen = i - head + 1;
		if (curLen > maxLen) {
			maxLen = curLen;
		}
	}

	return maxLen;
}































