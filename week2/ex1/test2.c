#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 函数用于检查输入是否为整数
bool isInteger(const char *str) {
    int i = 0;

    // 检查字符串是否以正负号开头
    if (str[0] == '+' || str[0] == '-')
        i = 1;

    // 遍历字符串检查每个字符是否为数字
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    char input[20]; // 用于存储输入的字符串

    printf("请输入一个整数: ");
    scanf("%s", input);

    // 检查输入是否为整数
    if (!isInteger(input)) {
        printf("输入不是有效的整数。\n");
        return 1; // 返回1表示程序出错
    }

    // 将输入字符串转换为整数
    int num = atoi(input);

    // 判断整数的奇偶性
    if (num % 2 == 0) {
        printf("%d 是偶数。\n", num);
    } else {
        printf("%d 是奇数。\n", num);
    }

    return 0;
}