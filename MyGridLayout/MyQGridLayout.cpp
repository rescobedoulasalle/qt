// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>

class MyWidget : public QWidget {

public:
  MyWidget(QWidget *parent = NULL) : QWidget(parent) {
    this->setWindowTitle("HelloGUI with Qt");
     QPushButton* but1 = new QPushButton("Button 1");
     QPushButton* but2 = new QPushButton("Button 2");
     QPushButton* but3 = new QPushButton("Button 3");
     QPushButton* but4 = new QPushButton("Button 4");
     QLineEdit* edit = new QLineEdit();

     QGridLayout* layout = new QGridLayout();
     layout->addWidget(but1, 0, 0);
     layout->addWidget(but2, 0, 1);
     layout->addWidget(but3, 1, 0);
     layout->addWidget(but4, 1, 1);
     layout->addWidget(edit, 2, 0, 1, 2);
     this->setLayout(layout);
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
