#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculateCharges (float);
double hypotenuseCalc(double, double);
int integerPower(int, int);
int even(int);
int timeCalc(int,int,int);
float celsius(int);
float fahrenheit(int);
int main()
{
        int Choice;
	int MaxChoices;
	// set up your Maximum Choice here
	MaxChoices = 7;
	// It creates a menu with 10 items
	Choice = 0;
	while (Choice < MaxChoices)
	{
		printf("%s\n", "************** MAIN MENU ****************");
		printf("%s\n", "Please Enter one of the following Choices");
		printf("%s\n\n", "************** MAIN MENU ****************");
		printf("%s\n\n", "1: Parking Charge Calculator");
		printf("%s\n\n", "2: Hypotenuse Calculator");
		printf("%s\n\n", "3: Exponent Calculator");
		printf("%s\n\n", "4: Even or Odd Determiner");
		printf("%s\n\n", "5: Time in Seconds Calculator");
		printf("%s\n\n", "6: Temperature Convertor");
		printf("%s\n\n", "7: Exit The Program");

		printf("%s", "Please give me your choice?");
		// Print Your choices here
		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1: // (if Choice == 1)
			// run first item for example
			printf("Parking Charge Calculator is chosen\n\n");
			printf("Please Enter the First Customer's Hours:\n\n");
			float hours_1;
			float hours_2;
			float hours_3;
			scanf("%f",&hours_1);
			printf("Please Enter the Second Customer's Hours:\n\n");
			scanf("%f",&hours_2);
			printf("Please Enter the Third Customer's Hours:\n\n");
			scanf("%f",&hours_3);
			printf("Car         Hours           Charge\n\n");
			printf("Car 1       %f         %f\n\n",hours_1,calculateCharges(hours_1));
			printf("Car 2       %f         %f\n\n",hours_2,calculateCharges(hours_2));
			printf("Car 3       %f         %f\n\n",hours_3,calculateCharges(hours_3));
			printf("Total       %f         %f\n\n",(hours_1+hours_2+hours_3),(calculateCharges(hours_1)+calculateCharges(hours_2)+calculateCharges(hours_3)));
			break;
		case 2:
			// run Second item for example
			printf("Hypotenuse Calculator is chosen\n\n");
			printf("Please Enter the Triangle's First Side Length:\n\n");
			double side_1;
			double side_2;
			scanf("%lf",&side_1);
			printf("Please Enter the Triangle's Second side Length:\n\n");
			scanf("%lf",&side_2);
			printf("Side_1 :%lf         Side_2 :%lf         Hypotenuse : %lf\n\n",side_1,side_2,hypotenuseCalc(side_1,side_2));
            break;
        case 3:
			// run Second item for example
			printf("Exponent Calculator is chosen\n\n");
			printf("Please Enter Your Base:\n\n");
			int base,exponent;
			scanf("%d",&base);
			printf("Please Enter Your Exponent:\n\n");
			scanf("%d",&exponent);
			printf("integerPower(%d,%d) is %d\n\n",base,exponent,integerPower(base,exponent));
			break;
        case 4:
			// run Second item for example
			printf("Even and Odd Determiner is chosen\n\n");
			printf("Please Enter Your Number\n\n");
			int num;
			scanf("%d",&num);
			printf("%d\n\n",even(num));
			break;
        case 5:
			// run Second item for example
			printf("Time in Seconds Calculator is chosen\n\n");
			int hour,minutes,seconds;
			printf("Please Enter the Hour:\n\n");
			scanf("%d",&hour);
			printf("Please Enter the Minutes:\n\n");
			scanf("%d",&minutes);
			printf("Please Enter the Seconds:\n\n");
			scanf("%d",&seconds);
			printf("The Amount of Time in Seconds Since the Last Time Clock Struck 12 is:%d\n\n",timeCalc(hour,minutes,seconds));
            break;

        case 6:
			// run Second item for example
			printf("Temperature Convertor is chosen\n\n");
			printf("Celsius Temperature            Fahrenheit Temperature\n\n");
			int temp;
			for(temp=0; temp<=100; temp+=1)
            {
                printf("%d                         %f\n\n",temp,fahrenheit(temp));
            }
            printf("Fahrenheit Temperature         Celsius Temperature\n\n");
            for(temp=32; temp<=212; temp+=1)
            {
                printf("%d                         %f\n\n",temp,celsius(temp));
            }
			break;
        case 7:
			return 0;
		}

	}

    return 0;
}

float calculateCharges(float hours)
{
    float hoursInput;
    hoursInput = ceil(hours);
    float charges;
    if(hoursInput<=3)
    {
        charges=2.0;
    }
    if(hoursInput>3)
    {
        charges=2.0+(hoursInput-3)*0.5;
    }

    if(charges>10)
    {
        charges=10;
    }

    return charges;

}

double hypotenuseCalc(double side_1, double side_2)
{
    double hypotenuse;
    hypotenuse = sqrt(pow(side_1,2)+pow(side_2,2));
    return hypotenuse;
}

int integerPower(int base, int exponent)
{
    int result =1;
    int counter;
    for (counter=0; counter<exponent; counter+=1)
    {
        result*=base;
    }
    return result;
}

int even(int num)
{
    if(num%2==0)
    {
        return 1;
    }

    if(num%2!=0)
    {
        return 0;
    }

}

int timeCalc(int h, int m, int s)
{
    int AmPm;
    int time;
    if((h>=0)&&(h<12))
    {
        AmPm=0;
    }
    if((h>=12)&&(h<24))
    {
        AmPm=1;
    }
    if(h==24)
    {
        h=0;
        AmPm=0;
    }
    switch(AmPm)
    {
    case 0 :
            time = (h*3600)+(m*60)+(s);
            return time;
            break;

    case 1:
            time=((h-12)*3600)+(m*60)+(s);
            return time;
            break;
    }


}

float fahrenheit(int temp)
{

    return (1.8*temp)+32;
}

float celsius (int temp)
{
    return (temp-32)/1.8;
}
