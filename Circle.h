#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

template <class T> class Circle : public Figure<T> {
public:
  Circle(Canvas<T> &owner_ref, int x, int y, int radius, T color);
  ~Circle() = default;

  bool IsNotOverlaped() final;
  void Clear() final;
  void Draw(int offset_x = 0, int offset_y = 0) final;
  void ReDraw(T color) final;
  std::unique_ptr<Figure<T>> Clone() final;

private:
  int m_x;
  int m_y;
  int m_radius;
  T m_color;

  void CircleDraw(T color, int offset_x, int offset_y);
};

#endif
