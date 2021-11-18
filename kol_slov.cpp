#include "middle_str.h"

int itc_countWords(string str)
{
    int len = itc_len(str);
    string point;
    int count = 0, flag = 0;
    for(int i = 0; i < len; i++){
        if(str[i] != ' '){
            point += str[i];
        }
        if(str[i] == ' ' or str[i + 1] == '\0'){
            for(int j = 0; j < itc_len(point); j++){
                if(point[j] >= 'A' and point[j] <= 'Z' or point[j] >= 'a' and point[i] <= 'z'){
                    count++;
                }
            }
            if(count == itc_len(point)){
                flag++;
            }
            point = "";
            count = 0;
        }
    }
    return flag;
}

string itc_maxCharWord(string str)
{
    long long len = itc_len(str), count = 0;
    string nov, result = "";
    for(int i = 0; i < len + 1; i++){
        if((str[i] == ' ' or str[i] == '\0') and (itc_len(nov) > itc_len(result))){
            result = nov;
            nov = "";
        }
        if((str[i] >= 'A' and str[i] <= 'Z') or (str[i] >= 'a' and str[i] <= 'z')){
            nov += str[i];
        }
        if(str[i] == ' ' and str[i + 1] != ' '){
            nov = "";
            count++;
        }
    }
    if(count == 0){
        return "error";
    }
    return result;
}

char itc_sameChar(string str){
    long long len = itc_len(str);
    int count = 0;
    char result;
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(str[i] == str[j]){
                count++;
            }
        }
        if(count == 2){
            return str[i];
        }
        count = 0;
    }
    return 0;
}

bool itc_isFirstInSecond(string s1, string s2){
	if (itc_find_str(s2, s1) != -1)
		return true;
	return false;
}
