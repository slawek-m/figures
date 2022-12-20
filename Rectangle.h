#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
public:
  Rectangle(Canvas &owner_ref, int ulx, int uly, int lrx, int lry, int color);
  ~Rectangle() = default;

  bool IsNotOverlaped() final;
  void Clear() final;
  void Draw(int offset_x = 0, int offset_y = 0) final;
  void ReDraw(int color) final;

private:
  int m_ulx;
  int m_uly;
  int m_lrx;
  int m_lry;
  int m_color;

  void RectangleDraw(int color, int offset_x, int offset_y);
};

#endif
