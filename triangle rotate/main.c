#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

GLfloat  tri[3][3] = {{50.0,150.0,100.0},{25.0,25.0,100.0},{1.0,1.0,1.0}};
GLfloat rot_mat[3][3] = {{0},{0},{0}};
GLfloat res[3][3] = {{0},{0},{0}};
GLfloat h = 50.0;
GLfloat k = 25.0;
GLfloat th;


void drawTriangle(){

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(tri[0][0],tri[1][0]);
    glVertex2f(tri[0][1],tri[1][1]);
    glVertex2f(tri[0][2],tri[1][2]);
    glEnd();
}

void multiply(){
    int i,j,l;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            res[i][j] = 0;
            for(l=0;l<3;l++){
                res[i][j] = res[i][j] + rot_mat[i][l]*tri[l][j];
            }
        }
    }
}

void rotate(){
    GLfloat m,n;
    m = -h*(cos(th)-1) + k*(sin(th));
    n = -k*(cos(th)-1) - h*(sin(th));
    rot_mat[0][0] = cos(th);
    rot_mat[0][1] = -sin(th);
    rot_mat[0][2] = m;
    rot_mat[1][0] = sin(th);
    rot_mat[1][1] = cos(th);
    rot_mat[1][2] = n;
    rot_mat[2][0] = 0;
    rot_mat[2][1] = 0;
    rot_mat[2][2] = 1;

    multiply();
}


void drawRotatedTriangle(){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(res[0][0],res[1][0]);
    glVertex2f(res[0][1],res[1][1]);
    glVertex2f(res[0][2],res[1][2]);
    glEnd();
}
void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    rotate();
    drawRotatedTriangle();
    glFlush();
}


void myinit()
{

    glClearColor(1.0,1.0,1.0,1.0);
    glPointSize(1.0);
    glLineWidth(5.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,550.0,0.0,550.0);

}

void main(int argc,char **argv)
{
    printf("enter angle to rotate\n");
    scanf("%f",&th);
    th = th*(3.14/180);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("triangle");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}
