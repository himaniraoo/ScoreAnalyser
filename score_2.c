#include <stdio.h>
#include <math.h>  // Required for ceil()

void gradeCalc(int result)
{
    // Get the tens place of the result to use in the switch-case statement
    switch (result / 10)
    {
        case 10:  // Covers 100
        case 9:   // Covers 90-99
            printf("Grade Obtained: S\n");
            break;
        case 8:   // Covers 80-89
            printf("Grade Obtained: A\n");
            break;
        case 7:   // Covers 70-79
            printf("Grade Obtained: B\n");
            break;
        case 6:   // Covers 60-69
            printf("Grade Obtained: C\n");
            break;
        case 5:   // Covers 50-59
            printf("Grade Obtained: D\n");
            break;
        case 4:   // Covers 40-49
            printf("Grade Obtained: E\n");
            break;
        default:  // Covers anything below 40
            printf("Grade Obtained: F\n");
            break;
    }
}

int main()
{
    int sub, result, i1, i2, a1, e1, lab;

    printf("Welcome to Score Analyser!\n");
    printf("Enter the following codes w.r.t the Subjects:\n");
    printf("1.DDCO , 2.DSA , 3.WEB TECH , 4.AFLL , 5.MATH , 6.CIE\n");
    scanf("%d", &sub);
    
    if (sub == 4 || sub == 5)  // AFLL and MATH
    {
        printf("Enter your marks (or predictions):\n");
        printf("1.ISA 1:\n2.ISA 2:\n3.Assignment (/10):\n4.ESA\n");
        scanf("%d%d%d%d", &i1, &i2, &a1, &e1);

        // Use ceil() to round up the fractional results
        result = (int)ceil(i1 / 2.0) + (int)ceil(i2 / 2.0) + a1 + (int)ceil(e1 / 2.0);
        printf("Marks Obtained (/100): %d\n", result);
        gradeCalc(result);
    }
    else if (sub == 3)  // WEB TECH
    {
        printf("Enter your marks (or predictions):\n");
        printf("1.ISA 1:\n2.ISA 2:\n3.Assignment (/20):\n4.ESA\n");
        scanf("%d%d%d%d", &i1, &i2, &a1, &e1);

        // For WEB TECH, different weightings are applied
        result = (int)ceil(i1 * 0.375) + (int)ceil(i2 * 0.375) + a1 + (int)ceil(e1 / 2.0);
        printf("Marks Obtained (/100): %d\n", result);
        gradeCalc(result);
    }
    else if(sub==1 || sub==2)
    {
        printf("Enter your marks (or predictions):\n");
        printf("1.ISA 1:\n2.ISA 2:\n3.Assignment (/10):\n4.ESA\n5.Lab (/20)\n");
        scanf("%d%d%d%d", &i1, &i2, &a1, &e1 , &lab);

        // For DSA, DDCO lab is considered
        result = (int)ceil(i1 / 2.0) + (int)ceil(i2 / 2.0) + a1 + (int)ceil(e1 / 2.0)+ (int)ceil(lab);
        result=(result*10)/12;
        printf("Marks Obtained (/100): %d\n", result);
        gradeCalc(result);
    }

    return 0;
}
