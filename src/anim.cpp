#include"anim.h"
using namespace akgl;

anim::anim(void) : StockSize(0)
{

    int arg = 0;
    glutInit(&arg, 0);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("My cool animation system");

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    
}
void anim::Keyboard(unsigned char Key, int x, int y)
{
    if (Key == 27)
        exit(0);
    if (Key == 'f')
        glutFullScreen();
}

void anim::Idle(void)
{
    long Time;
    static long OldTime = -1, StartTime;
    if (OldTime == -1)
        StartTime = OldTime = clock();
    else
    {
        Time = clock();
        TSK_SyncTime = (double)(Time - StartTime) / CLOCKS_PER_SEC;
        Time = Time - OldTime;
        if (Time > CLOCKS_PER_SEC)
            OldTime = clock();
        glutPostRedisplay();
    }
}

void anim::Reshape(int Width, int Height)
{
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(55, 55, 13, 0, 0, 0, 0, 1, 0);
}
void anim::Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glColor3d(0, 1, 0);
    glLineWidth(1);
    glutWireCube(14);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINES);

    glColor3d(1, 0, 0);
    glVertex3d(-3, -7, 0);
    glVertex3d(100, -7, 0);

    glColor3d(0, 1, 0);
    glVertex3d(0, -10, 0);
    glVertex3d(0, 100, 0);

    glColor3d(0, 0, 1);
    glVertex3d(0, -7, -3);
    glVertex3d(0, -7, 100);
    glEnd();
    glEnable(GL_LIGHTING);
    glPopMatrix();

    Instance.Timer();
    Instance.Render();
    glFinish();
    glutSwapBuffers();
}

anim::~anim(void)
{
    for (int i = 0; i < StockSize; i++)
        delete Stock[i], Stock[i] = NULL;
}

void anim::Render(void)
{
    for (int i = 0; i < StockSize; i++)
        Stock[i]->Render(*this);
}

void anim::Timer(void)
{
    for (int i = 0; i < StockSize; i++)
        Stock[i]->Response(*this);
}
