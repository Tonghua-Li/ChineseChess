#include "BoardView.h"
#include "WayPoint.h"

#include <QDebug>
#include <QMessageBox>
#include <QPainter>

BoardView::BoardView(QWidget *parent)
    : QWidget(parent)
{
    _board = new ChessBoard(this);

    createWayPoints();
    refreshBoard();
}

void BoardView::drawBackground(QPainter &painter, const QBrush &brush)
{
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, WIDTH, HEIGHT);
    painter.restore();
}

bool BoardView::TryShowWinner()
{
    auto winner = _board->getWinner();
    if(winner == Player::None){
        return false;
    }
    QMessageBox msgBox;
    QString msg = winner==Player::Red? "Red wins!":"Black wins!";
    msgBox.setText(msg);
    msgBox.exec();
    return true;
}

void BoardView::onPieceViewClicked(PieceView *pieceView)
{
    auto p = pieceView->piece();
    _board->onPieceClicked(p); // attack or select
    refreshBoard();

    auto isWin = TryShowWinner();
    if(isWin){
        _board->reset();
        refreshBoard();
    }
}

void BoardView::onWayPointClicked(WayPoint *wayPoint)
{
    auto wpPos = wayPoint->position();
    _board->moveSelectedTo(wpPos);
    refreshBoard();

}
void BoardView::createWayPoints()
{
    for (int i = 0; i < V_LINE_COUNT; i++) {
        for (int j = 0; j < H_LINE_COUNT; j++) {
            auto wp = new WayPoint(this);
            wp->setPosition(i, j);
            QObject::connect(wp, &WayPoint::clicked, this, &BoardView::onWayPointClicked);
        }
    }
}

void BoardView::refreshBoard()
{
    foreach(auto pv, _pieceViews){
        delete pv;
    }
    _pieceViews.clear();

    auto pieces = _board->chessPieces();
    foreach (auto p, pieces) {
        auto v = new PieceView(this, p);
        v->show();
        QObject::connect(v, &PieceView::selected, this, &BoardView::onPieceViewClicked);
        _pieceViews.append(v);
    }
}

void BoardView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    auto s = PieceView::SIZE;
    QBrush backgroundBrush(QColor(211, 194, 129));
    drawBackground(painter, backgroundBrush);

    for (int i = 0; i < V_LINE_COUNT; i++) {
        auto x = s * (i + 1);
        painter.drawLine(x, s, x, HEIGHT - s);
    }

    for (int i = 0; i < H_LINE_COUNT; i++) {
        auto y = s * (i + 1);
        painter.drawLine(s, y, WIDTH - s, y);
    }

    // river
    painter.fillRect(s+1, 5*s+1, 8*s-1, s-1, backgroundBrush);
    // top x
    painter.drawLine(4*s, s, 6*s, 3*s);
    painter.drawLine(6*s, s, 4*s, 3*s);
    // bottom x
    painter.drawLine(4*s, 8*s, 6*s, 10*s);
    painter.drawLine(6*s, 8*s, 4*s, 10*s);

    QWidget::paintEvent(event);
}
