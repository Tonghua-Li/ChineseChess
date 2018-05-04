#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QWidget>

class PieceView : public QWidget
{
    Q_OBJECT
public:
    static const int SIZE = 80;
    explicit PieceView(QWidget *parent = nullptr);
    void movePosition(const QPoint &pos);
    void movePosition(int x, int y);
    void select();
    void unselect();
    bool isSelected(){return _isSelected;}
signals:
    void selected(PieceView *view);
public slots:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    const int PADDING = 5;
    QBrush _currentBrush;
    bool _isSelected=false;
};

#endif // PIECEVIEW_H
