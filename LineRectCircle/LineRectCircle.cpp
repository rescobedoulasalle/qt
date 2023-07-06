// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

class MyWidget : public QMainWindow {

public:
  MyWidget(QWidget *parent = NULL) : QMainWindow(parent) {
    this->setWindowTitle("HelloGUI with Qt");
    this->resize(320, 240);
    QGraphicsScene* scene = new QGraphicsScene();
    scene->addLine(20.0, 50.0, 50.0, 200.0);
    scene->addRect(100.0, 50.0, 60.0, 80.0);
    // try this instead
    // scene->addRect(100.0, 50.0, 60.0, 80.0, QPen(), QBrush(Qt::red));
    scene->addEllipse(200.0, 100.0, 80.0, 80.0);
    QGraphicsView* view = new QGraphicsView(scene);
    setCentralWidget(view);
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
