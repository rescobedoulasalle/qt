// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>

#include <QKeyEvent>
#include<math.h>

class Renderer : protected QOpenGLFunctions_2_0 {

public:
  Renderer() : t(0.0) {}

public:
  void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // view scene from the side
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef( -45.0f, 0.0f, 0.0f, 1.0f);
    glRotatef( -45.0f, 0.0f, 1.0f, 0.0f);
    glRotatef( 135.0f, 1.0f, 0.0f, 0.0f);

    if(true) {
      // interpolate rotation matrices, which is wrong
      float r0[16];
      float r1[16];
      float rt[16];

      glPushMatrix(); // save for later use

      glLoadIdentity();

      glGetFloatv(GL_MODELVIEW_MATRIX, r0);
      // rotate around z
      glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
      glGetFloatv(GL_MODELVIEW_MATRIX, r1);

      glPopMatrix(); // restore

      //interpolate
      for(unsigned i=0; i < 16; i++) {
        rt[i] = (1-t) * r0[i] + t * r1[i];
      }

      glMultMatrixf(rt);
    }else{
      // interpolate rotation angle, which is correct

      // rotate around z
      glRotatef(t*180.0f, 0.0f, 0.0f, 1.0f);

    }
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxisZ();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCoordinateAxisY();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCoordinateAxisX();
  }

  void init() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
  }

  void resize(int w, int h) {
    // ignore this for now
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (45.0, (float)w/(float)h, 0.1, 10.0);
  }
  void dispose() {

  }
public:
  float t; //time

private:
  void drawCoordinateAxisZ() {
    glBegin(GL_LINE_LOOP); // circle in x-y plane
    for(int a=0; a<360; a+=10) {
      float angle = M_PI / 180.0f * a;
      glVertex3f(cos(angle), sin(angle), 0.0);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.9f, 0.0f, 0.0f); // x-axis
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.9f, 0.0f); // y-axis
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f,-1.0f); // z-axis
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();

    glBegin(GL_TRIANGLES); // z-axis tip
    glVertex3f(0.0f,-0.1f, 0.9f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.1f, 0.9f);
    glEnd();
  }

  void drawCoordinateAxisX() {
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawCoordinateAxisZ();
    glPopMatrix();
  }

  void drawCoordinateAxisY() {
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    drawCoordinateAxisZ();
    glPopMatrix();
  }

  // implemention of gluPerspective to avoid GLU header
  void gluPerspective(double fovyInDegrees, double aspectRatio, double znear, double zfar) {
    double ymax = znear * tanf(fovyInDegrees * M_PI / 360.0);
    double xmax = ymax * aspectRatio;
    glFrustum(-xmax, xmax, -ymax, ymax, znear, zfar);
  }
};

class MyWidget : public QOpenGLWidget {

private:
  Renderer *renderer;

public:
  MyWidget(QWidget *parent = NULL) : QOpenGLWidget(parent) {
    this->setWindowTitle("Use the 1 key to interpolate rotation");
    this->resize(320, 320);
    renderer = new Renderer();
  }

  ~MyWidget() {
    makeCurrent();
    renderer->dispose();
    doneCurrent();
    delete renderer;
  }

protected:
  void initializeGL() { renderer->init(); }
  void resizeGL(int w, int h){ renderer->resize(w, h); }
  void paintGL() { renderer->display(); }
  void keyPressEvent(QKeyEvent* event){
    bool redraw = false;
    float offset = 0.02f;
    if(event->modifiers() & Qt::ControlModifier) offset = -offset;

    switch(event->key()) {
    case '1':
      renderer->t += offset;
      if(renderer->t < 0.0f) renderer->t = 1.0;
      if(renderer->t > 1.0f) renderer->t = 0.0;
      redraw = true;
      break;
    }
    if(redraw) {
      this->setWindowTitle(QString("Time %1").arg(renderer->t));
      this->update();
    }
  }
};

int main (int argc, char* argv[]) {
  // create a QApplication object that handles initialization,
  // finalization, and the main event loop
  QApplication appl(argc, argv);
  MyWidget widget;  // create a widget
  widget.show(); //show the widget and its children
  return appl.exec(); // execute the application
}
