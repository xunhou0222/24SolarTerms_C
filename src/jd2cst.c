#include <stdio.h>
#include "solarterms.h"




void JD2CST(double JD, int CST[6]){

    double JD_CST, DJ_CST2[2];

    int year, mon, day, hour, min, sec;
    double fd;

    int i;


    JD_CST = JD + 8.0/24.0;
    split(JD_CST, DJ_CST2);
    
    i = iauJd2cal(DJ_CST2[0], DJ_CST2[1], &year, &mon, &day, &fd);
    if (i == 0){
        CST[0] = year;
        CST[1] = mon;
        CST[2] = day;
        CST[3] = (int)(24.0*fd);
        CST[4] = (int)(fd*24.0*60.0 - CST[3]*60.0);
        CST[5] = (int)(fd*24.0*3600.0 - CST[3]*3600.0 - CST[4]*60.0 + 0.5);  //四舍五入取整

        if (CST[5] == 60){
            CST[5] = 0;
            CST[4] = CST[4] + 1;
        }

        if (CST[4] == 60){
            CST[4] = 0;
            CST[3] = CST[3] + 1;
        }
    }
    else
        printf("ERROR! Unacceptable date!\n");

}