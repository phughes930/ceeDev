int decode1(int *xp, int *yp, int *zp)
{
    int x = *xp; // 1 & 6
    int y = *yp; // 2 & 4
    int z = *zp; // 3 & 5

    *yp = x;
    *zp = y;
    *xp = z;

    return x;
}