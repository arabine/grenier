
void TransfoAffineInversePoint(int xp,int yp, int *x, int *y,int dx, int dy, int angle, double scale);
void TransfoAffineInverse(int zx, int zy,IMAGE *I0,IMAGE *I1, IMAGE *I2, int dx, int dy, int angle, double scale);
void EstimerTransfoAffine(int i1, int j1, int i2, int j2, int i1p, int j1p, int i2p, int j2p,int *dx, int *dy, int *angle, double *scale);
IMAGE *RaccordAffine(int dx, int dy,int angle, double scale, IMAGE *I, IMAGE *J);
