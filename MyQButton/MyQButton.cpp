#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>

class MyWidget : public QMainWindow {
 public:
    MyWidget(QWidget *parent = NULL) : QMainWindow(parent) {
        this->resize(320, 240);
        this->setWindowTitle("HelloGUI with Qt");
        QLabel* label = new QLabel("Hello World", this);
        label->setGeometry(120, 20, 150, 30);
        QPushButton* button = new QPushButton( "Button text", this);
        button->setGeometry(120, 50, 150, 30);
        createMenus();
    }
  private:
    void createMenus() {
      QMenuBar *bar = menuBar();
      QMenu *fileMenu = bar->addMenu(tr("&File"));
      fileMenu->addAction(new QAction("Open", this));
      fileMenu->addAction(new QAction("Close", this));
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
