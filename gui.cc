#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <bits/stdint-uintn.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <GL/glut.h>

#include <sys/wait.h>
#include <thread>
#include <chrono>

class GUI {
    unsigned int width, height;
    uint8_t *bitmap;

  public:
    uint8_t *vram;
    GUI() {};
    GUI(unsigned int width, unsigned int height, uint8_t *vram)
    {
      Init(width, height, vram); }

    ~GUI() {}

    void Init(int width, int height, uint8_t *vram)
    {
      this->width = width;
      this->height = height;
      this->vram = vram;
      bitmap = (unsigned char *) calloc(width * height * 3, sizeof(unsigned char));
    }


    void convert2(const unsigned char *palette)
    {
      printf("start convert\n");
      unsigned char rgb[3];
      int x = 0;
      int y = 0;
      for (int i = 0x0000; i <= 0xffff; i++) {
        fflush(stdout);
        uint8_t col = vram[i];
        fflush(stdout);
        rgb[0] = palette[col * 3];
        rgb[1] = palette[col * 3 + 1];
        rgb[2] = palette[col * 3 + 2];
        
        int where = (y * width + x) * 3;
        bitmap[where] = rgb[0];
        bitmap[where + 1] = rgb[1];
        bitmap[where + 2] = rgb[2];

        x++;
        if (x >= width) {
          x = 0;
          y++;
          if (y >= height)
            return;
        }
      }
    }

    unsigned int get_width() { return width; }
    unsigned int get_height() { return height; }
    unsigned char * get_bitmap() { return bitmap; }
};

GUI gui;
uint8_t palette[0xff * 3] = {
  0x00, 0x00, 0x00,
  0xff, 0x00, 0x00,
  0x00, 0xff, 0x00,
  0xff, 0xff, 0x00,
  0x00, 0x00, 0xff,
  0xff, 0x00, 0xff,
  0x00, 0xff, 0xff,
  0xff, 0xff, 0xff,
  0xc6, 0xc6, 0xc6,
  0x84, 0x00, 0x00,
  0x00, 0x84, 0x00,
  0x84, 0x84, 0x84,
  0x00, 0x00, 0x84,
  0x84, 0x00, 0x84,
  0x00, 0x84, 0x84,
  0x84, 0x84, 0x84,
};


void disp()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  gui.convert2(palette);
  glClear(GL_COLOR_BUFFER_BIT);
  //glRasterPos2i(-1 , -1);
  glDrawPixels(gui.get_width() , gui.get_height() , GL_RGB , GL_UNSIGNED_BYTE , gui.get_bitmap());
  glutSwapBuffers();
}

void idle()
{
  glutPostRedisplay();
}

void start(GUI &gui, int *argc, char **argv)
{
  glutInit(argc, argv);
  glutInitWindowSize(gui.get_width() * 2, gui.get_height() * 2);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow("GUI TEST");
  glutDisplayFunc(disp);
  glutIdleFunc(idle);
  glPixelZoom(2.0, 2.0);
  glutMainLoop();
}
