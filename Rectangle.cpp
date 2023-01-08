#include "Rectangle.h"
#include "Canvas.h"
//#include <iostream>

template <class T>
Rectangle<T>::Rectangle(Canvas<T> &owner_ref, int ulx, int uly, int lrx,
                        int lry, T color)
    : Figure<T>(owner_ref), m_ulx(ulx), m_uly(uly), m_lrx(lrx), m_lry(lry),
      m_color(color){};

template <class T> bool Rectangle<T>::IsNotOverlaped() {
  for (int x = m_ulx; x < m_lrx; ++x) {
    for (int y = m_uly; y < m_lry; ++y) {
      auto color = Figure<T>::m_owner_ref.GetColor(x, y);
      if (color != m_color)
        return false;
    }
  }
  return true;
}

template <class T> void Rectangle<T>::Clear() {
  RectangleDraw(-m_color, 0, 0);
};

template <class T> void Rectangle<T>::Draw(int offset_x, int offset_y) {
  RectangleDraw(m_color, offset_x, offset_y);
};

template <class T> void Rectangle<T>::ReDraw(T color) {
  m_color = color;
  RectangleDraw(m_color, 0, 0);
};

template <class T>
void Rectangle<T>::RectangleDraw(T color, int offset_x, int offset_y) {
  m_ulx += offset_x;
  m_uly += offset_y;
  m_lrx += offset_x;
  m_lry += offset_y;

  int x_size;
  int y_size;
  Figure<T>::m_owner_ref.GetSize(x_size, y_size);

  if (m_lrx >= x_size) {
    m_lrx = x_size - 1;
  }

  if (m_lry >= y_size) {
    m_lry = y_size - 1;
  }

  for (int x = m_ulx; x < m_lrx; ++x) {
    for (int y = m_uly; y < m_lry; ++y) {
      // std::cout << m_color;
      Figure<T>::m_owner_ref.SetColor(x, y, color);
    }
  }
}

template <class T> std::unique_ptr<Figure<T>> Rectangle<T>::Clone() {
  return std::make_unique<Rectangle<T>>(*this);
}

template class Rectangle<int>;
