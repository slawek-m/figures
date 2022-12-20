#include "Canvas.h"
#include <iostream>

Canvas::Canvas() : m_x_size(0), m_y_size(0){};

Canvas::Canvas(int x_size, int y_size) : m_x_size(x_size), m_y_size(y_size) {
  m_canvas.resize(y_size);
  for (int y = 0; y < y_size; ++y) {
    m_canvas.at(y).resize(x_size, 0);
  }
};

Canvas::Canvas(const Canvas &canvas) {
  std::copy(canvas.m_canvas.begin(), canvas.m_canvas.end(),
            back_inserter(m_canvas));
  m_x_size = canvas.m_x_size;
  m_y_size = canvas.m_y_size;
}

int Canvas::GetColor(int x, int y) { return m_canvas.at(y).at(x); };

void Canvas::SetColor(int x, int y, int color) {
  m_canvas.at(y).at(x) += color;
};

void Canvas::GetSize(int &x_size, int &y_size) { x_size = m_x_size; };

void Canvas::DrawCanvas() {
  for (int y = 0; y < m_y_size; ++y) {
    for (int x = 0; x < m_x_size; ++x) {
      std::cout << m_canvas.at(y).at(x);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::unique_ptr<Canvas> Canvas::Clone() {
  return std::make_unique<Canvas>(*this);
}
