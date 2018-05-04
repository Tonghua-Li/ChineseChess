#include "BoardView.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(680, 760);
    this->setCentralWidget(new BoardView(this));
}
