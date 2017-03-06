#include<stdio.h>
#include<math.h>

int main()
{
    int ax, ay, by, bx, cx, cy, dx, dy, area, t, i=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
        dx = ax + cx - bx;
        dy = ay + cy - by;
        area = ((ax*by) + (bx*cy) + (cx*dy) + (dx*ay)) - ((ay*bx) + (by*cx) + (cy*dx) + (dy*ax));
        if(area<0)
            area = (-1) * area;
        printf("Case %d: %d %d %d\n",++i, dx, dy, area/2);
    }
    return 0;
}
