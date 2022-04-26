#include <math.h>
#include <stdio.h>
#include "solarterms.h"




int termscheck(int *k, double JD, double lambda, double date[24], double angle[24]){
    double precision = 1.0/3600.0/1000.0;    //毫角秒精度 
    int i, j = 0; 


    for (i = 0; i<24; i++){

        if ( i != 0 )
            if( fabs(15.0*i - lambda) < precision ){
                date[*k] = JD;
                angle[*k] = lambda;
                j = 1;
                *k = *k + 1;      
                break;     
            }

        if ( i == 0){
            if ( lambda < precision || 360.0 - lambda < precision ){
                date[*k] = JD;
                angle[*k] = lambda;
                j = 1;
                *k = *k + 1;
                break;
            }          
        }

    }

    return(j);         
}


void termsprinter(double date[24], double angle[24]){

    int i, j, CST[6];


    printf("\n\n%18s%18s%15s\n\n", "DATES(CST)   ", "SOLAR TERMS", "ANGLES  ");

    for (i=0; i<24; i++){

        JD2CST(date[i], CST);

        if (fabs(angle[i] - 270.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n", 
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "冬至",
                           angle[i]);

        else if (fabs(angle[i] - 285.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "小寒", 
                           angle[i]);

        else if (fabs(angle[i] - 300.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",                           
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5],
                           "大寒",
                           angle[i]);

        else if (fabs(angle[i] - 315.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "立春", 
                           angle[i]);
        
        else if (fabs(angle[i] - 330.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "雨水", 
                           angle[i]);

        else if (fabs(angle[i] - 345.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "惊蛰", 
                           angle[i]);

        else if ( fabs(angle[i]) < 1.0 || fabs(angle[i] - 360.0) < 1.0 )
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "春分", 
                           angle[i]);

        else if (fabs(angle[i] - 15.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "清明", 
                           angle[i]);

        else if (fabs(angle[i] - 30.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "谷雨", 
                           angle[i]);

        else if (fabs(angle[i] - 45.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "立夏", 
                           angle[i]);

        else if (fabs(angle[i] - 60.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "小满", 
                           angle[i]);

        else if (fabs(angle[i] - 75.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "芒种", 
                           angle[i]);

        else if (fabs(angle[i] - 90.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "夏至", 
                           angle[i]);

        else if (fabs(angle[i] - 105.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "小暑", 
                           angle[i]);

        else if (fabs(angle[i] - 120.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "大暑", 
                           angle[i]);

        else if (fabs(angle[i] - 135.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "立秋", 
                           angle[i]);

        else if (fabs(angle[i] - 150.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "处暑", 
                           angle[i]);

        else if (fabs(angle[i] - 165.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "白露", 
                           angle[i]);

        else if (fabs(angle[i] - 180.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "秋分", 
                           angle[i]);

        else if (fabs(angle[i] - 195.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "寒露", 
                           angle[i]);

        else if (fabs(angle[i] - 210.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "霜降", 
                           angle[i]);

        else if (fabs(angle[i] - 225.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "立冬", 
                           angle[i]);

        else if (fabs(angle[i] - 240.0) < 1.0)
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "小雪", 
                           angle[i]);

        else 
            printf("%04d/%02d/%02d %02d:%02d:%02d%15s%20.8lf\n",
                           CST[0], CST[1], CST[2], 
                           CST[3], CST[4], CST[5], 
                           "大雪", 
                           angle[i]);
    }

}