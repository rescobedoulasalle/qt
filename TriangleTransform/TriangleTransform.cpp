// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>

class Renderer : protected QOpenGLFunctions_2_0 {

private:
    void drawTriangle() {
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f( 0.5f, -0.5f, 0.0f);
        glVertex3f( 0.0f,  0.5f, 0.0f);
        glEnd();
    }

public:
    void init() {
      initializeOpenGLFunctions();
    }
    void resize(int w, int h) {
        glViewport(0, 0, w, h);
    }
    void display() {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawTriangle();

        glColor3f(0.0f, 0.0f, 1.0f);
        glScalef(0.5f, 0.5f, 0.0f); // resize to 50%
        drawTriangle();
        
        glColor3f(1.0f, 0.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f); //rotate by 45 degrees
        drawTriangle();

        glColor3f(0.0f, 1.0f, 0.0f);
        glTranslatef(0.5f, 0.5f, 0.0f); // translate
        drawTriangle();
    }
    void dispose() {}
};

class MyWidget : public QOpenGLWidget {

private:
    Renderer *renderer;

public:
    MyWidget(QWidget *parent = NULL) : QOpenGLWidget(parent) {
        this->setWindowTitle("OpenGL with Qt");
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
};

int main (int argc, char* argv[]) {
  // create a QApplication object that handles initialization,
  // finalization, and the main event loop
  QApplication appl(argc, argv);
  MyWidget widget;  // create a widget
  widget.show(); //show the widget and its children
  return appl.exec(); // execute the application
}
