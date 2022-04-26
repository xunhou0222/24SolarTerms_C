int split(double JD, double FR[2]){

    FR[0] = (double)( (int)(JD) );
    FR[1] = JD - FR[0];

    if (JD > 0.0E0 || FR[1] == 0.0E0)
        return 0;
    else{
        FR[0] -= 1.0E0;
        FR[1] += 1.0E0;
        return 0;
    }

}