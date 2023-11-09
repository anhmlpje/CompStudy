#include <stdio.h>
#include <math.h>
//求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字，为2。 例如，n=5时=2+22+222+2222+22222，n由键盘输入。
int main() {
    int n;
    int a = 2;
    int Sn = 0;
    int a1;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        a1 = a * pow(10, i) + a;
        Sn += a1;
    }
    printf("%d\n", Sn);

    return 0;

}