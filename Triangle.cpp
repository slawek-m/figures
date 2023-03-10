#include "Triangle.h"
#include "Canvas.h"

Triangle::Triangle(Canvas &owner_ref, int x, int y, int h, int color)
    : Figure(owner_ref), m_x(x), m_y(y), m_h(h), m_color(color){};

bool Triangle::IsNotOverlaped() {
  for (int i = 0; i <= m_h; ++i) {
    for (int j = 0; j <= i; ++j) {
      auto color = m_owner_ref.GetColor(j + m_x, i + m_y);
      if (color != m_color)
        return false;
    }
  }

  return true;
}

void Triangle::Clear() { TriangleDraw(-m_color, 0, 0); };

void Triangle::Draw(int offset_x, int offset_y) {
  TriangleDraw(m_color, offset_x, offset_y);
};

void Triangle::ReDraw(int color) {
  m_color = color;
  TriangleDraw(m_color, 0, 0);
};

void Triangle::TriangleDraw(int color, int offset_x, int offset_y) {
  m_x += offset_x;
  m_y += offset_y;

  int x_size;
  int y_size;
  m_owner_ref.GetSize(x_size, y_size);

  for (int i = 0; i <= m_h; ++i) {
    for (int j = 0; j <= i; ++j) {
      m_owner_ref.SetColor(j + m_x, i + m_y, color);
    }
  }
}
