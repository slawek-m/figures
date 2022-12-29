#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

template <class T> class Triangle : public Figure<T> {
public:
  Triangle(Canvas<T> &owner_ref, int x, int y, int h, T color);
  ~Triangle() = default;

  bool IsNotOverlaped() final;
  void Clear() final;
  void Draw(int offset_x = 0, int offset_y = 0) final;
  void ReDraw(T color) final;

private:
  int m_x;
  int m_y;
  int m_h;
  T m_color;

  void TriangleDraw(T color, int offset_x, int offset_y);
};

#endif
