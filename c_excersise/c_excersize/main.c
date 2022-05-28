#include <stdio.h>
#include <stdlib.h>
int max(int num1, int num2, int num3);
void calc(void);
int main()
{
    //char input[30];
    //printf("Hey user get me some input :\n");
    //fgets(input, 30, stdin);
    //printf("Your input is : %s", input);
    //printf("Max number is: %d\n",max(22,13,7));
    while(1){
        calc();
    }

    return 0;
}
void calc(void){
    double num1, num2;
    char op;
printf("Enter a number: ");
scanf("%lf", &num1);
printf("Enter operator: ");
scanf(" %c", &op);
printf("Enter a number: ");
scanf("%lf", &num2);

switch(op){
case '+':
    printf("Result %f\n", num1+num2);
    break;
case '-':
    printf("Result %f\n", num1-num2);
    break;
case '*':
    printf("Result %f\n", num1*num2);
    break;
case '/':
    printf("Result %f\n", num1/num2);
    break;
default:
    printf("Wrong operation\n");
    break;
}

}
int max(int num1, int num2, int num3){
    int result;
    if(num1>=num2 && num1>=num3){
        result= num1;
    }
    else if(num2>=num1 && num2>=num3){
        result= num3;
    }
    else(result= num3);
    return result;
}
