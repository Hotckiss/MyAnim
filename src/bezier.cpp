#include"bezier.h"

using namespace akgl;

void bez::Render(anim &Ani)
{

    glDisable(GL_LIGHTING);

    glLineWidth(7.0);

    glEnable(GL_LINE_SMOOTH);

    glBegin(GL_LINE_STRIP);

    glColor3d(col.x, col.y, col.z);

    for (int i = 0; i < 500; i++)
        glVertex3d(positions[i].x, positions[i].y, positions[i].z);
    glEnd();
    glEnable(GL_LIGHTING);

}
void bez::Response(anim &Ani)
{

    double t;
    int j = 0;
    for (t = 0; t <= 1; t += 0.002)
    {
        vec p;
        for (int i = 0; i < size; i++)
        {
            p.x += P[i].x * pow(1 - t, size - i - 1) * pow(t, i) * C(i, size - 1);
            p.y += P[i].y * pow(1 - t, size - i - 1) * pow(t, i) * C(i, size - 1);
            p.z += P[i].z * pow(1 - t, size - i - 1) * pow(t, i) * C(i, size - 1);
        }
        positions[j++] = p;
    }

    for (int i = 0; i < size; i++)
    {
        P[i] += dir[i] * 0.05;
        if ((P[i].x < -7) || (P[i].x > 7))
            dir[i].x = -dir[i].x;
        if ((P[i].y < -7) || (P[i].y > 7))
            dir[i].y = -dir[i].y;
        if ((P[i].z < -7) || (P[i].z > 7))
            dir[i].z = -dir[i].z;
    }
}
