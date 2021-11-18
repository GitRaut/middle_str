#include "middle_str.h"

string itc_decToBase(int num, int base){
    int cif;
    int result = 0, len = 0, chislo = 0, i = 0;
    string res, otv;
    if(base > 0 and base < 11){
        res = itc_covert_num(num, base);
        return res;
    }
    if(base >= 11){
        while(num > 0){
            cif = num % base;
            num = num / base;
            if(cif > 9){
                res += 'Z' - 25 + itc_abs(10 - cif);
            }
            if(cif <= 9){
                res += itc_ToString(cif);
            }
        }
        int len = itc_len(res) - 1;
        while(i <= len){
            otv += res[len - i];
            i++;
        }
    }
    return otv;
}
