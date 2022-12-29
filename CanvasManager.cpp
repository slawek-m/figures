#include "CanvasManager.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <algorithm>
#include <iostream>

template <class T>
CanvasManager<T>::CanvasManager(std::unique_ptr<CanvasImpl<T>> canvas_impl,
                                size_t x_size, size_t y_size)
    : m_next_id(1), m_canvas(std::move(canvas_impl), x_size, y_size){};

template <class T>
CanvasManager<T>::CanvasManager(const Canvas<T> &canvas)
    : m_next_id(1), m_canvas(canvas){};

template <class T>
int CanvasManager<T>::AddRectangle(int ulx, int uly, int lrx, int lry,
                                   int color) {
  auto id = m_next_id++;
  m_figures[id] =
      std::make_unique<Rectangle<T>>(m_canvas, ulx, uly, lrx, lry, color);
  return id;
};

template <class T>
int CanvasManager<T>::AddCircle(int x, int y, int radius, int color) {
  auto id = m_next_id++;
  m_figures[id] = std::make_unique<Circle<T>>(m_canvas, x, y, radius, color);
  return id;
};

template <class T>
int CanvasManager<T>::AddTriangle(int x, int y, int h, int color) {
  auto id = m_next_id++;
  m_figures[id] = std::make_unique<Triangle<T>>(m_canvas, x, y, h, color);
  return id;
};

template <class T> void CanvasManager<T>::DrawFigure(int id) {
  m_figures.at(id)->Draw();
}

template <class T> void CanvasManager<T>::RemoveFigure(int id) {
  if (m_figures.count(id)) {
    m_figures.at(id)->Clear();
    m_figures.erase(id);
  }
};

template <class T>
void CanvasManager<T>::MoveFigure(int id, int offset_x, int offset_y) {
  if (m_figures.count(id)) {
    m_figures.at(id)->Clear();
    m_figures.at(id)->Draw(offset_x, offset_y);
  }
};

template <class T> void CanvasManager<T>::ColorFigure(int id, int color) {
  if (m_figures.count(id)) {
    m_figures.at(id)->Clear();
    m_figures.at(id)->ReDraw(color);
  }
};

template <class T> bool CanvasManager<T>::Validate(int id) {
  if (m_figures.count(id)) {
    return m_figures.at(id)->IsNotOverlaped();
  }
  return true;
}

template <class T> void CanvasManager<T>::ShowCanvas() {
  m_canvas.DrawCanvas();
}

template <class T> std::unique_ptr<Canvas<T>> CanvasManager<T>::CloneCanvas() {
  return m_canvas.Clone();
}

template class CanvasManager<int>;
