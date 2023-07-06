// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <QApplication>
#include <QLabel>
#include <QWidget>

class MyWidget : public QWidget{
 public:
    MyWidget(QWidget *parent = NULL) : QWidget(parent) {
        this->resize(320, 240);
        this->setWindowTitle("HelloGUI with Qt");
        QLabel* label = new QLabel("Hello World", this); // create a label
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
