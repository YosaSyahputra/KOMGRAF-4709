#include <GL/freeglut.h> // Memasukkan library GLUT

int x1 = -7, y1 = -7; // Koordinat awal
int x2 = 7, y2 = 7;   // Koordinat akhir

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan buffer tampilan
    glColor3f(1.0, 1.0, 1.0); // Mengatur warna garis menjadi putih
    glBegin(GL_LINES); // Memulai penggambaran garis
    glVertex2f(x1, y1); // Menentukan titik awal garis
    glVertex2f(x2, y2); // Menentukan titik akhir garis
    glEnd(); // Mengakhiri penggambaran garis
    glFlush(); // Mengirimkan perintah untuk menggambar ke layar
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h); // Menentukan area tampilan di jendela
    glMatrixMode(GL_PROJECTION); // Mengaktifkan mode proyeksi
    glLoadIdentity(); // Mengatur matriks proyeksi sebagai matriks identitas
    glOrtho(-w / 12.0, w / 12.0, -h / 8.0, h / 8.0, -1.0, 1.0); // Mengatur proyeksi ortografis
    glMatrixMode(GL_MODELVIEW); // Kembali ke mode model tampilan
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Mode tampilan GLUT
    glutInitWindowSize(500, 500); // Ukuran jendela
    glutInitWindowPosition(100, 100); // Posisi jendela
    glutCreateWindow("DDA Line Drawing"); // Membuat jendela dengan judul "DDA Line Drawing"
    glClearColor(0.0, 0.0, 0.0, 1.0); // Mengatur latar belakang menjadi hitam
    glutDisplayFunc(display); // Mengatur fungsi yang akan memanggil tampilan
    glutReshapeFunc(reshape); // Mengatur fungsi perubahan ukuran jendela
    glutMainLoop(); // Memulai loop utama GLUT
    return 0;
}
