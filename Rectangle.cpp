#include "Rectangle.h"
#include "Canvas.h"

Rectangle::Rectangle(Canvas &owner_ref, int ulx, int uly, int lrx, int lry,
                     int color)
    : Figure(owner_ref), m_ulx(ulx), m_uly(uly), m_lrx(lrx), m_lry(lry),
      m_color(color){};

bool Rectangle::IsNotOverlaped() {
  for (int x = m_ulx; x < m_lrx; ++x) {
    for (int y = m_uly; y < m_lry; ++y) {
      auto color = m_owner_ref.GetColor(x, y);
      if (color != m_color)
        return false;
    }
  }
  return true;
}

void Rectangle::Clear() { RectangleDraw(-m_color, 0, 0); };

void Rectangle::Draw(int offset_x, int offset_y) {
  RectangleDraw(m_color, offset_x, offset_y);
};

void Rectangle::ReDraw(int color) {
  m_color = color;
  RectangleDraw(m_color, 0, 0);
};

void Rectangle::RectangleDraw(int color, int offset_x, int offset_y) {
  m_ulx += offset_x;
  m_uly += offset_y;
  m_lrx += offset_x;
  m_lry += offset_y;

  int x_size;
  int y_size;
  m_owner_ref.GetSize(x_size, y_size);

  if (m_lrx >= x_size) {
    m_lrx = x_size - 1;
  }

  if (m_lry >= y_size) {
    m_lry = y_size - 1;
  }

  for (int x = m_ulx; x < m_lrx; ++x) {
    for (int y = m_uly; y < m_lry; ++y) {
      m_owner_ref.SetColor(x, y, color);
    }
  }
}
