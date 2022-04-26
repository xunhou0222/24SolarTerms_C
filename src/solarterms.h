// Macros, structs and APIs that can be found in "ephcom" (in ephcom.h and libephcom.a precisely).
#define EPHCOM_NUMOBJECTS	16 /* Allocate memory for 16 solar sys objs */

struct ephcom_Header {
    int ksize;         /* block size, in first line of ASCII header */
    int ncoeff;        /* number of Chebyshev coefficients in data blocks */
    char ttl[3][86];   /* Hold up to 14*6=84 characters + "\n\0" */
    int ncon;          /* Number of assigned in cnam */
    char cnam[400][7]; /* Hold up to 400 6-character names ending with '\0' */
    int nval;          /* number of values for cval, to compare with ncon */
    double cval[400];  /* constant values, corresponding to cnam names */
    double au;         /* km/astronomical unit */
    double emrat;      /* Earth-Moon mass ratio */
    double clight;     /* Speed of light, km/sec */
    int numde;         /* ephemeris number */
    int numle;         /* lunar ephemeris number (can be same # as numde) */
    double ss[3];      /* start epoch, stop epoch, step size */
    int ipt[12][3];    /* index pointers into Chebyshev coefficients */
    int lpt[3];        /* libration pointer in a block */
    int maxcheby;      /* maximum Chebyshev coefficients for a body */
};

struct ephcom_Coords {
    int km;           /* 1 = positions in km; 0 = positions in AU            */
    int seconds;      /* 1 = timescale is seconds; 0 = timescale is days     */
    double et2[2];    /* Julian Day of interpolation;
                        et2[0] = whole JD; et2[1] = fractional JD           */
    double pv[EPHCOM_NUMOBJECTS][6]; /* x, y, z Position & Velocity          */
                     /* pv[00..14][]: See Object numbers in #defines above */
                     /* pv[15][]: Geocentric Moon, from original lunar eph  */
                     /* pv[16][]: User-defined object                       */
};
int ephcom_readbinary_header(FILE *infp, struct ephcom_Header *header);

int ephcom_get_coords(FILE *infp,
                      struct ephcom_Header *header,
                      struct ephcom_Coords *coords,
                      double *datablock);

int ephcom_pleph(struct ephcom_Coords *coords, int ntarg, int ncntr, double *r);


// APIs that can be found in SOFA package, or libsofa_c_20210512.a equivalently.
int iauCal2jd(int iy, int im, int id, double *djm0, double *djm);

double iauObl06(double date1, double date2);

void iauAb(double pnat[3], double v[3], double s, double bm1, double ppr[3]);

void iauPnm06a(double date1, double date2, double rbpn[3][3]);

int iauJd2cal(double dj1, double dj2, int *iy, int *im, int *id, double *fd);

int iauUtctai(double utc1, double utc2, double *tai1, double *tai2);

int iauTaitt(double tai1, double tai2, double *tt1, double *tt2);


// Self-defined APIs.
void utc2tdb(double UTC[2], double TT[2]);

double LightTime(struct ephcom_Header header, double prd[6]);

int termscheck(int *k, double JD, double lambda, double date[24], double angle[24]);

void termsprinter(double date[24], double angle[24]);

int split(double JD, double FR[2]);

void JD2CST(double JD, int CST[6]);