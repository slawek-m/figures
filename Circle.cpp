#include "Circle.h"
#include "Canvas.h"

template <class T>
Circle<T>::Circle(Canvas<T> &owner_ref, int x, int y, int radius, T color)
    : Figure<T>(owner_ref), m_x(x), m_y(y), m_radius(radius), m_color(color){};

template <class T> bool Circle<T>::IsNotOverlaped() {
  for (int w = 0; w < m_radius * 2; w++) {
    for (int h = 0; h < m_radius * 2; h++) {
      int dx = m_radius - w;
      int dy = m_radius - h;
      if ((dx * dx + dy * dy) <= (m_radius * m_radius)) {
        auto color = Figure<T>::m_owner_ref.GetColor(m_x + dx, m_y + dy);
        if (color != m_color)
          return false;
      }
    }
  }

  return true;
}

template <class T> void Circle<T>::Clear() { CircleDraw(-m_color, 0, 0); };

template <class T> void Circle<T>::Draw(int offset_x, int offset_y) {
  CircleDraw(m_color, offset_x, offset_y);
};

template <class T> void Circle<T>::ReDraw(T color) {
  m_color = color;
  CircleDraw(m_color, 0, 0);
};

template <class T>
void Circle<T>::CircleDraw(T color, int offset_x, int offset_y) {
  m_x += offset_x;
  m_y += offset_y;

  int x_size;
  int y_size;
  Figure<T>::m_owner_ref.GetSize(x_size, y_size);

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
        Figure<T>::m_owner_ref.SetColor(x, y, color);
      }
    }
  }
}

template <class T> std::unique_ptr<Figure<T>> Circle<T>::Clone() {
  return std::make_unique<Circle<T>>(*this);
}

template class Circle<int>;
