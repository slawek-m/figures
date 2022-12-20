#include "Circle.h"
#include "Canvas.h"

Circle::Circle(Canvas &owner_ref, int x, int y, int radius, int color)
    : Figure(owner_ref), m_x(x), m_y(y), m_radius(radius), m_color(color){};

bool Circle::IsNotOverlaped() {
  for (int w = 0; w < m_radius * 2; w++) {
    for (int h = 0; h < m_radius * 2; h++) {
      int dx = m_radius - w;
      int dy = m_radius - h;
      if ((dx * dx + dy * dy) <= (m_radius * m_radius)) {
        auto color = m_owner_ref.GetColor(m_x + dx, m_y + dy);
        if (color != m_color)
          return false;
      }
    }
  }

  return true;
}

void Circle::Clear() { CircleDraw(-m_color, 0, 0); };

void Circle::Draw(int offset_x, int offset_y) {
  CircleDraw(m_color, offset_x, offset_y);
};

void Circle::ReDraw(int color) {
  m_color = color;
  CircleDraw(m_color, 0, 0);
};

void Circle::CircleDraw(int color, int offset_x, int offset_y) {
  m_x += offset_x;
  m_y += offset_y;

  int x_size;
  int y_size;
  m_owner_ref.GetSize(x_size, y_size);

  for (int w = 0; w < m_radius * 2; w++) {
    for (int h = 0; h < m_radius * 2; h++) {
      int dx = m_radius - w;
      int dy = m_radius - h;
      if ((dx * dx + dy * dy) <= (m_radius * m_radius)) {
        int x = m_x + dx;
        int y = m_y + dy;
        if (x > (x_size - 1)) {
          x = x_size - 1;
        }
        if (y > (y_size - 1)) {
          y = y_size - 1;
        }
        if (x < 0) {
          x = 0;
        }
        if (y < 0) {
          y = 0;
        }
        m_owner_ref.SetColor(x, y, color);
      }
    }
  }
}
