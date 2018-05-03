#ifndef BING_H
#define BING_H

#include "ChessPiece.h"


#include <QObject>

class Bing : public ChessPiece {
  Q_OBJECT
public:
  Bing(QObject *parent = nullptr);

  // ChessPiece interface
public:
  bool CanMoveTo(const IBoard *board, int x, int y) const;
};

#endif // BING_H
