#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

int main(int argc, char *argv[])
{
    long double deviation, vaule,average, standerd_deviation;
    long long int n, i, max, degree, *number;
    int output, j ;
    FILE *fpta;
    if(argc<2)
      fpta = fopen("doc_prob.txt","a");
    else  fpta = fopen(argv[1],"a");
       if(fpta == NULL)
      {
          printf("Error! for open the file.\n");
          exit(1);
      }

    while(1)
    {
        printf("Enter the no of output in sample :");
        scanf("%d",&output);
        if(output==0) break;
        average = (100.0/output);
        fprintf(fpta,"Number is output %d\n",output);
        printf("probability for every sample output is %0.9lf\n",(double)average);
         fprintf(fpta,"Probability for every sample output is %0.9lf\n",(double)average);
        number = (long long int *)malloc(output*sizeof(long long int));
        printf("Enter the initial Digit of no_exp :  ");
        scanf("%d",&j);
        for(i=1,n=1; i<j; ++i)
        {
            n*=10;
        }
        degree=n;
        printf("Enter the end Digit of no_exp : ");
        scanf("%d",&j);
        for(i=1,max =1; i<j; ++i)
        {
            max*=10;
        }
        for(j=1; n<= max; n=degree*j)
        {
            for(i=0; i<output; ++i)
            {
                number[i]=0;
            }
            srand(time(0)%(1000+rand()%1000));
            for(i=0; i<n; ++i)
            {
                ++number[rand()%output];
            }

            printf("Probability of output for no_exp %lld are respectively(in %%) :\n\t",n);
             fprintf(fpta,"Probability of output for no_exp %lld are respectively(in %%) :\n\t",n);
            for(i=0,deviation = 0,standerd_deviation=0; i<output; ++i)
            {
                vaule=((long double)number[i]/n)*100;
                standerd_deviation+=(vaule*vaule);
                if(vaule<average)
                {
                    deviation +=(average-vaule);
                }
                else
                {
                    deviation +=(vaule-average);
                }
                if(i) printf(",");
                printf(" %lf",(double)vaule);
                 fprintf(fpta," %lf",(double)vaule);
                if(i%3==2) printf("\n\t");
            }
            deviation/=output;
            standerd_deviation= sqrt((standerd_deviation/output)-(average*average));
            printf("\nMean deviation for no_exp %lld is %0.9lf\n",n,(double)deviation);
             fprintf(fpta,"\nMean deviation for no_exp %lld is %0.9lf\n",n,(double)deviation);
            printf("Standard deviation for no_exp %lld is %0.9lf\n\n",n,(double)standerd_deviation);
             fprintf(fpta,"Standard deviation for no_exp %lld is %0.9lf\n\n",n,(double)standerd_deviation);
              fprintf(fpta,"Again Other experiment start.\n");
            if((++j)>9)
            {
                degree*=10;
                j=1;
            }
        }
        free(number);
    }
    fclose(fpta);
    return 0;
}
