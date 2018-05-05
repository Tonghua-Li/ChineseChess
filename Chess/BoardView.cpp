#include "BoardView.h"
#include "WayPoint.h"

#include <QDebug>
#include <QLabel>
#include <QPainter>

BoardView::BoardView(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(HEIGHT);
    setMinimumWidth(WIDTH);

    _board = new ChessBoard(this);

    createWayPoints();
    createPieceViews(_board);
}

void BoardView::drawBackground(QPainter &painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(211, 194, 129)));
    painter.drawRect(0, 0, WIDTH, HEIGHT);
    painter.restore();
}

void BoardView::onPieceViewClicked(PieceView *pieceView)
{
    PieceView *clicked = nullptr;
    // select
    foreach (auto pv, _pieceViews) {
        if (pv == pieceView) {
            clicked = pv;
        } else {
            pv->unselect();
        }
    }
    if (clicked == nullptr) {
        return;
    }
    auto p = clicked->piece();
    if (_board->canSelect(p)) {
        clicked->select();
    }
}

void BoardView::onWayPointClicked(WayPoint *wayPoint)
{
    PieceView *selectedPv = nullptr;
    foreach (auto pv, _pieceViews) {
        if (pv->isSelected()) {
            selectedPv = pv;
            break;
        }
    }
    if (selectedPv == nullptr) {
        return;
    }
    auto wpPos = wayPoint->position();
    auto p = selectedPv->piece();
    if (p->canMoveTo(_board, wpPos.x(), wpPos.y())) {
        _board->nextPlayer();
        selectedPv->movePosition(wayPoint->position());
    }
    selectedPv->unselect();
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

void BoardView::createPieceViews(ChessBoard *board)
{
    auto pieces = board->chessPieces();
    foreach (auto p, pieces) {
        auto v = new PieceView(this, p);
        v->movePosition(p->position());
        QObject::connect(v, &PieceView::selected, this, &BoardView::onPieceViewClicked);
        _pieceViews.append(v);
    }
}

void BoardView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    auto space = PieceView::SIZE;

    drawBackground(painter);

    for (int i = 0; i < V_LINE_COUNT; i++) {
        auto x = space * (i + 1);
        painter.drawLine(x, space, x, HEIGHT - space);
    }

    for (int i = 0; i < H_LINE_COUNT; i++) {
        auto y = space * (i + 1);
        painter.drawLine(space, y, WIDTH - space, y);
    }

    QWidget::paintEvent(event);
}
