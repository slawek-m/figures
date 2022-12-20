#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
public:
  Triangle(Canvas &owner_ref, int x, int y, int h, int color);
  ~Triangle() = default;

  bool IsNotOverlaped() final;
  void Clear() final;
  void Draw(int offset_x = 0, int offset_y = 0) final;
  void ReDraw(int color) final;

private:
  int m_x;
  int m_y;
  int m_h;
  int m_color;

  void TriangleDraw(int color, int offset_x, int offset_y);
};

#endif
