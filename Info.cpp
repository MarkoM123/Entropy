#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE* ptr;
    char ch, chnxt;
    int sum = 0;
    int zbir[95]={0};
    double prob[95] = { 0 };
    double prob2[95][95] = { 0 };
    int cnt[95] = { 0 };
    int mtx[95][95] = { 0 };
    double H0 = 0, H1 = 0, HMAX = 0;


    ptr=fopen("C:\\Users\\Korisnik\\Downloads\\basnee.txt", "r");

    if (NULL == ptr) {
        printf("ERROR \n");
    }

    ch = fgetc(ptr);
    chnxt = fgetc(ptr);

     do {

        cnt[ch - 32] += 1;
        mtx[ch - 32][chnxt - 32] += 1;
        ch = chnxt;
        chnxt = fgetc(ptr);
        sum++;

    } while (chnxt != EOF);
    for( int i=0;i<=94;i++){
        for(int j=0;j<=94;j++){
         zbir[i]+=(double)mtx[j][i];
	}
    }

    for (int i = 0; i <= 94; i++)
    {
        prob[i] = (double)cnt[i] / sum;
    
    }

    for (int i = 0; i <= 94; i++)
    {
        for (int j = 0; j <= 94; j++)
        {
        	if((double)zbir[i]!=0){
			
            prob2[i][j]=(double)mtx[i][j]/(double)zbir[i];
        }
		}
    }
   

    //H0
    for (int i = 0; i <= 94; i++)
    {
        if (prob[i] != 0)
        H0 += prob[i] * log2(1 / prob[i]);
    }

    //H1
    for (int i = 0; i <= 94; i++)
    {
        for (int j = 0; j <= 94; j++)
        {
            if(prob2[i][j] != 0)
                        H1 += (double)(prob[i] * prob2[i][j] * log2(1 / (prob2[i][j])));
        }
    }
    

    //HMAX
    HMAX = log2(95);

    printf("\n");
    printf("%f ", H0);
    printf("%f ", H1);
    printf("%f ", HMAX);
    
    fclose(ptr);
    return 0;
}
