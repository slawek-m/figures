#include "Triangle.h"
#include "Canvas.h"

template <class T>
Triangle<T>::Triangle(Canvas<T> &owner_ref, int x, int y, int h, T color)
    : Figure<T>(owner_ref), m_x(x), m_y(y), m_h(h), m_color(color){};

template <class T> bool Triangle<T>::IsNotOverlaped() {
  for (int i = 0; i <= m_h; ++i) {
    for (int j = 0; j <= i; ++j) {
      auto color = Figure<T>::m_owner_ref.GetColor(j + m_x, i + m_y);
      if (color != m_color)
        return false;
    }
  }

  return true;
}

template <class T> void Triangle<T>::Clear() { TriangleDraw(-m_color, 0, 0); };

template <class T> void Triangle<T>::Draw(int offset_x, int offset_y) {
  TriangleDraw(m_color, offset_x, offset_y);
};

template <class T> void Triangle<T>::ReDraw(T color) {
  m_color = color;
  TriangleDraw(m_color, 0, 0);
};

template <class T>
void Triangle<T>::TriangleDraw(T color, int offset_x, int offset_y) {
  m_x += offset_x;
  m_y += offset_y;

  int x_size;
  int y_size;
  Figure<T>::m_owner_ref.GetSize(x_size, y_size);

  for (int i = 0; i <= m_h; ++i) {
    for (int j = 0; j <= i; ++j) {
      Figure<T>::m_owner_ref.SetColor(j + m_x, i + m_y, color);
    }
  }
}

template class Triangle<int>;