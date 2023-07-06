// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QGroupBox>

class MyWidget : public QWidget {

public:
  MyWidget(QWidget *parent = NULL) : QWidget(parent) {
    this->setWindowTitle("HelloGUI with Qt");
     QPushButton* but1 = new QPushButton("Button 1");
     QPushButton* but2 = new QPushButton("Button 2");
     QPushButton* but3 = new QPushButton("Button 3");
     QPushButton* but4 = new QPushButton("Button 4");


     QGroupBox *groupBox = new QGroupBox("Some more important buttons");
     QPushButton* impBut1 = new QPushButton("Important 1");
     QPushButton* impBut2 = new QPushButton("Important 2");
     QPushButton* impBut3 = new QPushButton("Important 3");

     QHBoxLayout *hlayout = new QHBoxLayout;
     hlayout->addWidget(impBut1);
     hlayout->addWidget(impBut2);
     hlayout->addWidget(impBut3);


     QGridLayout* layout = new QGridLayout();
     layout->addWidget(but1, 0, 0);
     layout->addWidget(but2, 0, 1);
     layout->addWidget(but3, 1, 0);
     layout->addWidget(but4, 1, 1);

     // comment these two lines
     groupBox->setLayout(hlayout);
     layout->addWidget(groupBox, 2, 0, 1, 2);

     // and try this line instead
     //layout->addLayout(hlayout, 2, 0, 1, 2);

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
