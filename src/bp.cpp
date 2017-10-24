#define _CRT_SECURE_NO_WARNINGS
#include"bp.h"

using namespace akgl;
void bp::Render(anim &Ani)
{
    double u, v;
    glDisable(GL_LIGHTING);
    glLineWidth(0.5);
    glColor3d(0, 1, 1);
    for (int i = 0; i < 10; i++)
    {
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j < 10; j++)
            glVertex3d(ps[i][j].x, ps[i][j].y, ps[i][j].z);
        glEnd();
    }
    for (int j = 0; j < 10; j++)
    {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < 10; i++)
            glVertex3d(ps[i][j].x, ps[i][j].y, ps[i][j].z);
        glEnd();
    }
        glEnable(GL_LIGHTING);

}
void bp::Response(anim &Ani)
{
    double u, v;
    int k = 0, m = 0;
    for (u = 0; u <= 1; u += 0.1)
    {
        for (v = 0; v <= 1; v += 0.1)
        {
            vec p;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    p.x += P[i][j].x * B(i, 3, u) * B(j, 3, v);
                    p.y += P[i][j].y * B(i, 3, u) * B(j, 3, v);
                    p.z += P[i][j].z * B(i, 3, u) * B(j, 3, v);
                }
            ps[k][m] = p;
            m++;
        }
        k++;
        m = 0;
    }
    /*for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            P[i][j].y = 5 * sin(0.003*clock() + i);*/
    P[0][0].y = 6 * sin(0.003*clock() + 1);
    P[0][1].y = 5 * sin(0.002*clock() + 2);
    P[0][2].y = 3 * sin(0.004*clock() + 3);
    P[0][3].y = 2 * sin(0.0055*clock() + 4);
    P[1][0].y = 9 * sin(0.0077*clock() + 5);
    P[1][1].y = 4 * sin(0.003*clock() + 6);
    P[1][2].y = 1 * sin(0.002*clock() + 7);
    P[1][3].y = 1 * sin(0.007*clock() + 8);
    P[2][0].y = 5 * sin(0.0062*clock() + 9);
    P[2][1].y = 8 * sin(0.004*clock() + 10);
    P[2][2].y = 3 * sin(0.0051*clock() + 11);
    P[2][3].y = 4 * sin(0.0037*clock() + 12);
    P[3][0].y = 4 * sin(0.0045*clock() + 13);
    P[3][1].y = 2 * sin(0.0058*clock() + 14);
    P[3][2].y = 5 * sin(0.0034*clock() + 15);
    P[3][3].y = 8 * sin(0.0044*clock() + 16);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            P[i][j].x = 3 * cos(0.002*clock()) + j;
            P[i][j].z = 3 * sin(0.002*clock()) + i;
        }
}