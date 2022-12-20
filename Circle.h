#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
public:
  Circle(Canvas &owner_ref, int x, int y, int radius, int color);
  ~Circle() = default;

  bool IsNotOverlaped() final;
  void Clear() final;
  void Draw(int offset_x = 0, int offset_y = 0) final;
  void ReDraw(int color) final;

private:
  int m_x;
  int m_y;
  int m_radius;
  int m_color;

  void CircleDraw(int color, int offset_x, int offset_y);
};

#endif
