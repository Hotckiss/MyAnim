#include"anim.h"
using namespace akgl;
// ñòàíäàðòíûÿ èíèöèàëèçàöèÿ îïåí ãë
anim::anim(void) : StockSize(0)
{
    ///!!! âìåñòî ýòèõ 2 ñòî÷åê íóæíî â ìýéíå â íà÷àëå íàïèñàòü glutInit(&arg, argv);
    int arg = 0;
    glutInit(&arg, 0);
    ///
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("My cool animation system");
    // âêëþ÷èòü îñâåùåíèå
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_DEPTH_TEST);
    ///
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
/// ýòî òîæå íå íóæíî, íó ïðîñòî ïåðåïèñàòü, ýòî òèïî òàéìåð
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
// èçìåíåíèå ðàçìåðà è ðàñïîëîæåíèå íàáëþäàòåëÿ(ïî ñóòè òî÷êà îòêóäà ìû ñìîòðèì è êóäà, âñå)
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
    /// êóáèê, ýòî áóäåò òèïî êóáèê âíóòðè êîòîðîãî âñå ïðîèñõîäèò))
    glColor3d(0, 1, 0);
    glLineWidth(1);
    glutWireCube(14);
    // âêëþ÷èòü è âûêëþ÷èòü ñâåò íóæíî ÷òîáû ëèíèè ñòàëè ÿð÷å ñêàçàë ñîìñ...
    glDisable(GL_LIGHTING);
   // îòðèñîâêà êîîðäèíàòíûõ îñåé x y z
    glBegin(GL_LINES);
    //x êðàñíûé
    glColor3d(1, 0, 0);
    glVertex3d(-3, -7, 0);
    glVertex3d(100, -7, 0);
    // y çåëåíûé
    glColor3d(0, 1, 0);
    glVertex3d(0, -10, 0);
    glVertex3d(0, 100, 0);
    //z ñèíèé
    glColor3d(0, 0, 1);
    glVertex3d(0, -7, -3);
    glVertex3d(0, -7, 100);
    glEnd();
    glEnable(GL_LIGHTING);
    glPopMatrix();
    // âûçûâàåì ïåðåðèñîâêó âñåõ îáúåêòîâ è îáíîâëÿåì âðåìÿ
    Instance.Timer();
    Instance.Render();
    glFinish();
    glutSwapBuffers();
}
// ïðîøëèñü âñå óäàëèëè.
anim::~anim(void)
{
    for (int i = 0; i < StockSize; i++)
        delete Stock[i], Stock[i] = NULL;
}
// ïðîùëèñü ïî âñåì è íàðèñîâàëè
void anim::Render(void)
{
    for (int i = 0; i < StockSize; i++)
        Stock[i]->Render(*this);
}
// ïðîøëè ïî âñåì è âñåì ïîìåíÿëè òàì ðàñïîëîæåíèå è òä 
void anim::Timer(void)
{
    for (int i = 0; i < StockSize; i++)
        Stock[i]->Response(*this);
}
