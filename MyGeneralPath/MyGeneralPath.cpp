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
    QPolygonF polygon;
    polygon <<
    QPointF( 50,  50) << // start here
    QPointF( 50,  70) << // going down
    QPointF(100,  70) << // going right
    QPointF(100, 180) << // going down
    QPointF(120, 180) << // going right
    QPointF(120,  70) << // going up
    QPointF(170,  70) << // going right
    QPointF(170,  50) << // going up
    QPointF( 50,  50);   // going left (back to start)
    scene->addPolygon(polygon);
    // try this instead
    // scene->addPolygon(polygon, QPen(), QBrush(Qt::red));
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
