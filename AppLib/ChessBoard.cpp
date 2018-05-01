#include "ChessBoard.h"
#include <QDebug>
ChessBoard::ChessBoard(QObject *parent) : QObject(parent)
{
    qDebug() << "Created board";
}
