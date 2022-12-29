#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

template <class T> class Rectangle : public Figure<T> {
public:
  Rectangle(Canvas<T> &owner_ref, int ulx, int uly, int lrx, int lry, T color);
  ~Rectangle() = default;

  bool IsNotOverlaped() final;
  void Clear() final;
  void Draw(int offset_x = 0, int offset_y = 0) final;
  void ReDraw(T color) final;

private:
  int m_ulx;
  int m_uly;
  int m_lrx;
  int m_lry;
  T m_color;

  void RectangleDraw(T color, int offset_x, int offset_y);
};

#endif
