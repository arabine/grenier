
/******************************************************/

void Bresenham(int x1, int y1, int x2, int y2, unsigned char couleur)
{
int c,dx,dy;
int x,y;

int incx, incy,i;

dx = abs(x2-x1);
dy = abs(y2-y1);

if (y2>y1) incy = 1;
else incy = -1;

if (x2>x1) incx = 1;
else incx = -1;

x = x1;
y = y1;


/* direction en x preponderante */
if (dx > dy) {
	c = 2*dy - dx;
	for (i=0;i<dx;i++) {
		PutPixel(x,y,couleur);
		x=x+incx;
		if (c<0) c = c + 2*dy;
		else {
			y = y+incy;
			c = c + 2*dy - 2*dx;
		}
	}
}

/* direction en y preponderante */
else {
	c = 2*dx - dy;
	for (i=0;i<dy;i++) {
		PutPixel(x,y,couleur);
		y=y+incy;
		if (c<0) c = c + 2*dx;
		else {
			x = x+incx;
			c = c + 2*dx - 2*dy;
		}
	}
}

}

/******************************************************/

