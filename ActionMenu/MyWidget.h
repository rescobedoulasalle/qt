#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QKeySequence>

class MyWidget : public QMainWindow {
    Q_OBJECT
public:
  MyWidget(QWidget *parent = NULL) : QMainWindow(parent) {
    this->resize(320, 240);
    this->setWindowTitle("HelloGUI with Qt");
    counter = 0;
    label = new QLabel("Hello World", this);
    label->setGeometry(120, 20, 150, 30);
    QPushButton* button = new QPushButton( "Increment", this);
    button->setGeometry(120, 50, 150, 30);
    createActions();
    createMenus();
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));          
    QObject::connect(incrementAct, SIGNAL(triggered()), this, SLOT(buttonClicked()));
    QObject::connect(resetAct, SIGNAL(triggered()), this, SLOT(resetClicked()));
  }

public slots:
  void buttonClicked() {
      counter++;
      label->setText(QString("Click #%1").arg(counter));
  }
  void resetClicked() {
      counter = 0;
      label->setText(QString("Click #%1").arg(counter));
  }
private:
  void createActions() {
    incrementAct = new QAction("Increment", this);
    incrementAct->setShortcut(QKeySequence(Qt::ALT + Qt::Key_I));
    incrementAct->setToolTip(tr("Increment the counter"));
    resetAct = new QAction("Reset", this);
    resetAct->setShortcut(QKeySequence(Qt::ALT + Qt::Key_R));
    resetAct->setToolTip(tr("Reset the counter"));
  }
  void createMenus() {
    QMenuBar* bar = menuBar();
    QMenu* fileMenu = bar->addMenu(tr("Counter"));
    fileMenu->addAction(incrementAct);
    fileMenu->addAction(resetAct);
  }
private:
  int counter;
  QLabel* label;
  QAction* incrementAct;
  QAction* resetAct;

};

#endif // MYWIDGET_H
