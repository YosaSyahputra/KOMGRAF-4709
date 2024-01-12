#include <GL/glut.h>
#include <cmath>

// Deklarasi variabel global untuk koordinat titik A dan B
int xa, ya, xb, yb;

// Fungsi untuk menggambar satu piksel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Implementasi algoritma Bresenham untuk menggambar garis
void bresenhamLine(int xa, int ya, int xb, int yb) {
    int dx = abs(xb - xa);
    int dy = abs(yb - ya);
    int x, y;
    int p = 2 * dy - dx;

    if (xa > xb) {
        x = xb;
        y = yb;
        xb = xa;
    } else {
        x = xa;
        y = ya;
    }

    drawPixel(x, y);

    for (x; x < xb; x++) {
        if (p < 0) {
            p += 2 * dy;
        } else {
            if ((xb - xa) * (yb - ya) > 0) {
                y++;
            } else {
                y--;
            }
            p += 2 * (dy - dx);
        }
        drawPixel(x, y);
    }
}

// Fungsi untuk menampilkan hasil pada layar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Warna garis putih
    bresenhamLine(xa, ya, xb, yb);
    glFlush();
}

// Inisialisasi pengaturan awal OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Warna latar belakang hitam
    gluOrtho2D(0, 500, 0, 500);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    init();

    // Masukkan koordinat titik A dan B di sini
    xa = 10;
    ya = 30;
    xb = 90;
    yb = 90;

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
