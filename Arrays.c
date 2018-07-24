#include <stdio.h>
#include <stdlib.h>

int main()
{
    int studentNumber[10];
    int count;
    for (count=1; count<11; count+=1)
    {
      printf("Please enter the student number %d:\n",count);
      scanf("%d",&studentNumber[count-1]);
    }
    printf("Student\t\tStudent Number\n");
    for (count=1;count<11; count+=1)
    {
        printf("%d\t\t%d\n",count,studentNumber[count-1]);
    }

    // Creating a two dimensional array for student numbers and their marks
    int studentMark[10][6];
    /* The six columns are considered for attendance, quiz_1, quiz_2
    , midterm, final and aggregate score. */

    count=1;
    int tempNumber;



    do
    {
        float score;
        int i,j;
        j=1000; // initializing with a non-sense number so later on if we find a match
        // we will put the right index inside j
        while (j==1000)

        {

            printf("Please enter a student 3-digit number:\n\n");
            scanf("%d",&tempNumber);

            for (i=0; i<10;i+=1)
                {
                    if(tempNumber==studentNumber[i])
                    {
                        j=i;
                    }
                }
            if(j==1000)
                printf("Invalid student number.\n\n");

        }

        printf("Please enter the student attendance:\n\n");
        scanf("%d",&studentMark[j][0]);
        printf("Please enter the student quiz_1:\n\n");
        scanf("%d",&studentMark[j][1]);
        printf("Please enter the student quiz_2:\n\n");
        scanf("%d",&studentMark[j][2]);
        printf("Please enter the student midterm:\n\n");
        scanf("%d",&studentMark[j][3]);
        printf("Please enter the student final:\n\n");
        scanf("%d",&studentMark[j][4]);
        score = (0.1*studentMark[j][0]+0.1*studentMark[j][1]+0.1*studentMark[j][2]+0.3*studentMark[j][3]+0.4*studentMark[j][4]);
        studentMark[j][5]=(int) score;
        printf("Student\t Student Number\t\t Attendance \t Quiz_1 \t Quiz_2 \t Midterm \t Final \t Final Mark\n");
        printf("%d\t      %d\t             %d\t          %d\t      %d\t      %d\t       %d\t     %d\t\n",j+1,studentNumber[j],studentMark[j][0],studentMark[j][1],studentMark[j][2],studentMark[j][3],studentMark[j][4],studentMark[j][5] );





        count+=1;
    }while(count<11);



    return 0;
}
