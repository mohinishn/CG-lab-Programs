#include <stdio.h>
#include <GL/glut.h>

int x1,x2,y1,y2;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,400,0,400);
}

void draw_Pixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void draw_Line(int x1,int x2,int y1,int y2)
{
    int x,y;
    int dx,dy,i,e;
    int incx,incy,inc1,inc2;

    dx=x2-x1;
    dy=y2-y1;
    if(dx<0) dx=-dx;
    if(dy<0) dy=-dy;
    incx=1;
    if(x2<x1) incx=-1;
    incy=1;
    if(y2<y1) incy=-1;
    x=x1;
     y=y1;

    if(dx>dy)
    {
        draw_Pixel(x,y);
        e=2*dy-dx;
        inc1=2*(dy-dx);
        inc2=2*dy;
        for(i=0;i<dx;i++)
        {
            if(e>=0)
            {
                y+=incy;
                e+=inc1;
            }
            else
            e+=inc2;
            x+=incx;
            draw_Pixel(x,y);
        }
    } else
    {
    draw_Pixel(x,y);
    e = 2*dx-dy;
    inc1=2*(dx-dy);
    inc2=2*dx;
    for(i=0;i<dy;i++)
    {
        if(e>=0)
        {
            x+=incx;
            e+=inc1;
        }
        else e+=inc2;
        y+=incy;
        draw_Pixel(x,y);
    }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    draw_Line(x1,x2,y1,y2);

}
int main(int argc,char **argv)
{
    printf("enter x1,y1,x2,y2");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,25);
    glutCreateWindow("bhm line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}











