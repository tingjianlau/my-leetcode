/*************************************************************************
	> File Name: 242_valid_anagram.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/15
 ************************************************************************/

bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    int len = strlen(s);
    int i;
        
    if(len != strlen(t)) return false;
        
    for(i = 0; i < len; i++){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
        
    for(i = 0; i < 26; i++) if(count[i]) 
        return false;
        
   return true;
}

