#include "middle_str.h"

string itc_Cezar(string str, int k){
    long long len = itc_len(str);
    char point = k;
    string otv;
    if(str == ""){
        return "";
    }
    k = (k + 26) % 26;
    char pos;
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' and str[i] <= 'z'){
            pos = 25 - ('z' - str[i]);
            pos += k;
            if(pos > 25){
                pos = pos - 26;
            }
            else if(pos < 0){
                pos = 26 + pos;
            }
            otv += 'a' + pos;
        }
        else if(str[i] >= 'A' and str[i] <= 'Z'){
            pos = 25 - ('Z' - str[i]);
            pos += k;
            if(pos > 25){
                pos = pos - 26;
            }
            else if(pos < 0){
                pos = 26 + pos;
            }
            otv += 'A' + pos;
        }
        else{
            otv += str[i];
        }
    }
    return otv;
}


string itc_rmFreeSpace(string str){
    long long len = itc_len(str);
    string result;
    for(int i = 0; i < len; i++){
        if(str[i] != ' ' and str[i + 1] != ' '){
            result += str[i];
        }
        if(str[i + 1] == ' ' and str[i] != ' '){
            result += str[i];
            result += ' ';
        }
    }
    int len2 = itc_len(result);
    if(result[len2 - 1] == ' '){
        return itc_slice_str(result, 0, itc_len(result) - 2);
    }
    return result;
}

bool itc_isIp(string str){
    long long len = itc_len(str), count = 0;
    string nov;
    long long len1 = itc_len(nov);
    for(int i = 0; i < len; i++){
        if(str[i] != '.'){
            nov += str[i];
        }
        if(str[i] == '.'){
            if(itc_ToInt(nov) > 255 or itc_ToInt(nov) < 0){
                return false;
            }
            if(itc_len(nov) > 3){
                return false;
            }
            nov = "";
            count++;
        }
    }
    if(count != 3){
        return false;
    }
    return true;
}

string itc_DecToBin(string str){
    long long len = itc_len(str), number;
    string point = "", result = "";
    if(str == ""){
        return "";
    }
    for(int i = 0; i < len + 1; i++){
        if(str[i] >= '0' and str[i] <= '9'){
            point += str[i];
        }
        else{
            number = itc_ToInt(point);
            number = itc_bin_num(number);
            if(point != ""){
                result += itc_ToString(number);
            }
            if(str[i] != '\0'){
                result += str[i];
            }
            point = "";
        }
    }
    return result;
}
