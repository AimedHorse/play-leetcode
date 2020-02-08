/*
 *  14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"


示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。


说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 *
 * date：2020-02-08 14:02:29
 */

char * longestCommonPrefix(char ** strs, int strsSize){
	int i, j;
	int minLen = 0;
	char * str = NULL;
	char * result = NULL;
	if (strsSize == 1) {
		return strs[0];
	} else if (strsSize == 0) {
        return "";
    }
	minLen = strlen(strs[0]);
	for (i = 0; i < strsSize; i++) {
		str = strs[i];
		minLen = (strlen(str) < minLen ? strlen(str) : minLen);
	}
	result = (char *)malloc(sizeof(char) * 128);
	if (NULL == result) {
		return NULL;
	}
	memset(result, 0, sizeof(char) * 128);

	for (i = 0; i < minLen; i++) {
		for (j = 1; j < strsSize; j++) {
			if (strs[j][i] == strs[0][i]) {
				continue;
			} else {
				goto end;
			}
		}
		result[i] = strs[0][i];
	}
end:
	return result;
}


