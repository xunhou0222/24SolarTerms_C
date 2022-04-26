#include <stdio.h>
#include <math.h>
#include "solarterms.h"




void utc2tdb(double UTC[2], double TT[2]){

    double TAI[2];
    int i,j;

    i = iauUtctai(UTC[0], UTC[1], &TAI[0], &TAI[1]);
    if (i == 0){
        j = iauTaitt(TAI[0], TAI[1], &TT[0], &TT[1]);
        if (j != 0)
            printf("%s","Errors occured while Converting TAI TO TT!");
    }
    else 
        printf("%s","Errors occured while Converting UTC TO TAI!");
}


double LightTime(struct ephcom_Header header, double PRD[6]){

/*
******************************************************************************
计算给定历元下的太阳相对于地球的位置与速度，并考虑了光行时修正
      Input:
            (1)AU
                     double      天文单位AU，单位km
            (2)clight
                     double      光速，单位km/s
            (3)JD
                     double      历元儒略日（UTC）
            (4)set
                     int         选择是否考虑光行差，set == 1，考虑；set == 0，不考虑。

         
      Output:
            pos(x, y, z), vol(vx, vy, vz)
******************************************************************************
*/

    double AU, clight;
    double pos[3], vol[3], r, DTDB1, DTDB2;
    double d2s = 86400.0;
    int i;


    AU = header.au;
    clight = header.clight;

    pos[0] = PRD[0]*AU;
    pos[1] = PRD[1]*AU;
    pos[2] = PRD[2]*AU;
    vol[0] = PRD[3]*AU/d2s;
    vol[1] = PRD[4]*AU/d2s;
    vol[2] = PRD[5]*AU/d2s;
    
    r = sqrt(pos[0]*pos[0] + pos[1]*pos[1] +pos[2]*pos[2]);
    DTDB1 = 0.0;
    DTDB2 = r/clight/d2s;
    while (fabs(DTDB1 - DTDB2) > (1.0/d2s/1000.0)){
        DTDB1 = DTDB2;
        pos[0] = pos[0] - vol[0]*DTDB1*d2s;
        pos[1] = pos[1] - vol[1]*DTDB1*d2s;
        pos[2] = pos[2] - vol[2]*DTDB1*d2s;
        r = sqrt(pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2]); 
        DTDB2 = r/clight/d2s;      
    }

   return(DTDB2); 
}