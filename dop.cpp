#include "middle_str.h"

long long itc_len(string str){
    long long len = 0;
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
}

int itc_find_str(string str1, string str2){
    for(int i = 0; itc_len(itc_slice_str(str1, i, i + itc_len(str2) - 1)) == itc_len(str2); i++){
        if(itc_slice_str(str1, i, i + itc_len(str2) - 1) == str2) return i;
    }
    return -1;
}

string itc_slice_str(string str, int start, int end){
    long long len = itc_len(str);
    string result;
    if((end > len) and (start < len)){
        for(int i = start; i < len; i++){
            result = result + str[i];
        }
        return result;
    }
    if(start > end){
        return str;
    }
    for(int i = start; i <= end; i++){
        result = result + str[i];
    }
    return result;
}

long long itc_bin_num(long long number){
    int cif;
    long long result = 0, chislo = 0, len = 0;
    while(number > 0){
        cif = number % 2;
        chislo = chislo * 10 + cif;
        number = number / 2;
        len++;
    }
    while(len > 0){
        cif = chislo % 10;
        result = result * 10 + cif;
        chislo = chislo / 10;
        len--;
    }
    return result;
}

string itc_ToString(int num){
    string res = "", result = "";
    int point;
    if(num == 0){
        return "0";
    }
    while(num > 0){
        point = num % 10;
        res += '0' + point;
        num = num / 10;
    }
    for(int i = itc_len(res) - 1; i >= 0; i--){
        result += res[i];
    }
    return result;
}

long long itc_ToInt(string str){
    long long num = 0;
    for(int i = 0; i < itc_len(str); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

string itc_covert_num(int num, int base){
    int cif;
    int result = 0, len = 0, chislo = 0;
    while(num > 0){
        cif = num % base;
        chislo = chislo * 10 + cif;
        num = num / base;
        len++;
    }
    while(len > 0){
        cif = chislo % 10;
        result = result * 10 + cif;
        chislo = chislo / 10;
        len--;
    }
    return itc_ToString(result);
}

int itc_abs(int num){
    if(num >= 0){
        return num;
    }
    else{
        return num * -1;
    }
}
