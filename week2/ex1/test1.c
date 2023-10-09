#include <stdio.h>

int main() {
    // 声明变量来存储输入值
    float principal, rate, time;

    // 提示用户输入本金
    printf("Enter principal amount: ");
    scanf("%f", &principal);

    // 提示用户输入年利率（以百分比表示）
    printf("Enter annual interest rate (as a percentage): ");
    scanf("%f", &rate);

    // 将百分比利率转换为小数
    rate = rate / 100.0;

    // 提示用户输入时间（以年为单位）
    printf("Enter time (in years): ");
    scanf("%f", &time);

    // 计算简单利息
    float simpleInterest = (principal * rate * time);

    // 打印结果
    printf("Simple Interest = $%.2f\n", simpleInterest);

    return 0;
}