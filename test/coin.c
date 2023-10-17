#include<stdio.h>
int main(){
	int m1,m2,m5;
	int n=0;
	float money;
	printf("Enter the money:");
	scanf("%f",&money);
	for(m5=1;m5<money/0.05;m5++){
		//printf("%d\n",m5);
		for(m2=1;m2<(money-0.05*m5)/0.02;m2++){
			//printf("%d\n",m2);
			for(m1=1;m1<=(money-0.05*m5-0.02*m2)/0.1;m1++){
				//printf("%d",m1\n);
				if(0.05 * m5 + 0.02 * m2 + 0.01 * m1 == money){ 
				    printf("0.1:%d个 0.2:%d个 0.5:%d个\n",m1,m2,m5);
				    n++;
				    }else{
                        continue;
                    }
				}
			}
		}
	printf("There have %d total methods\n",n);
	return 0;
}