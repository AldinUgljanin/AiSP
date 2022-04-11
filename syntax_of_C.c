#include <stdio.h>

// FUNCTIONS
int addNumbers(int num1, int num2){
    return num1 + num2;
}

int main(){

    // Printing
    printf("Hello World\n");
    
    // Variables
    char testGrade = 'A'; // single 8-bit character
    char name[] = "Aldin"; // array of characters (string)

    // you can make them unsigned by adding "unsigned" prefix
    short age0 = 10;	    // at least 16-bits signed integer
    int age1 = 20;	    // at least 16-bits signed integer
    long age2 = 30; 	    // at least 32-bits signed integer
    long long age3 = 40;    // at least 64-bits signed integer

    float gpa0 = 2.5;	    // single percision floating point
    double  gpa1 = 3.5;	    // double percision floating point
    long double gpa2 = 3.5; // extended-percision floating point
    
    int isTall;		    // 0 ig false, non-zero if true
    isTall = 1;

    // change value of variable
    testGrade = 'F';

    printf("%s, yout grade is %c \n", name, testGrade);

    /*
     * %c character
     * %d integer number (bas 10)
     * %e exponential floating-point number
     * %f floating-point number
     * %i  integer (base10)
     * %o octal number (base 8)
     * %s a string of characters
     * %u unsigned decimal (integer) number
     * %x number in hexadecimal (base 16)
     * %% print a precent sign
     * \% print a precent sign
     */

    // CASTING
    printf("%d \n", (int)3.14);
    printf("%.2f \n", (double)3 / 2);

    // POINTERS
    int num = 10;
    printf("%p \n", &num);

    int *pNum = &num;
    printf("pNum: %p \n", pNum);
    printf("*pNum: %d \n", *pNum);

    // NUMBERS
    printf("%d \n", 2 * 3);	    // Basic arithmetic: +, -, /, *    
    printf("%d \n", 10 % 3);	    // Modulus Op. : returns remainder of 10/3
    printf("%d \n", 1 + 2 * 3);	    // order of operations
    printf("%f \n", 10 / 3.0);	    // int's and doubles

    int NUM = 10;
    NUM += 100;			    // +=, -=, /=, *=
    printf("%d \n", NUM);

    NUM++;
    printf("%d \n", NUM);

    // USER INPUT
    char user_name[10];
    printf("Enter your name: ");
    fgets(user_name, 10, stdin);
    printf("Hello %s! \n", name);

    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You are %d \n", age);

    // ARRAYS
    int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
    //		indexes:  0, 1,  2,  3,  4,  5

    luckyNumbers[0] = 90;
    printf("%d \n", luckyNumbers[0]);
    printf("%d \n", luckyNumbers[1]);

    // N Dimensial Arrays
    int numberGrid[2][3] ={
	{1, 2, 3},
	{4, 5, 6}
    };

    // CALL FUNCTION
    int sum = addNumbers(4, 60);
    printf("%d \n", sum);

    // IF STATEMENTS
    int isStudent = 0;
    int isSmart = 0;

    if(isStudent !=0 && isSmart != 0){
	printf("You are student\n");
    } else if(isStudent !=0 && isSmart == 0){
	printf("You are not a smart student\n");
    } else{
	printf("You are not a student and not smart\n");
    }

    // >, <, >=, <=, !=, ==
    if(1 > 3){
	printf("number comparison was true\n");
    }

    // SWITCH STATEMENTS
    char myGrade = 'A';
    switch(myGrade){
	case 'A':
	    printf("You Pass\n");
	    break;
	case 'F':
	    printf("You Fail\n");
	    break;
	default:
	    printf("Invalid grade\n");
    }

    // WHILE LOOP
    int index = 1;
    while(index <=5){
	printf("%d \n", index);
	index++;
    }

    // DO-WHILE LOOP
    index = 1;
    do{
	printf("%d \n", index);
	index++;
    }while(index <= 5);

    // FOR LOOP
    for(int i = 0; i < 5; i++){
	printf("%d \n", i);
    }

    // STRUCTS
    struct Student{
	int s_age;
	float s_gpa;
	char s_grade;
    };

    struct Student student1;
    student1.s_age = 19;
    student1.s_gpa = 3.4;
    student1.s_grade = 'B';

    printf("%d \n", student1.s_age);
    
    return 0;
}
