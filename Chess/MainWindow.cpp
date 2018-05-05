#include "BoardView.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(BoardView::WIDTH, BoardView::HEIGHT);
    this->setCentralWidget(new BoardView(this));
}
