#include <stdio.h>
//给出一个不多于5位的整数，要求 
//1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字，例如原数为321,应输出123
int main() {
    int num, l, i = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    while(1){
        num / 10;
        i++;
    }
    printf("%d", i);
    printf("Length is %d\n", l);
    
    return 0;
}