#include "CanvasManager.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <algorithm>
#include <iostream>

CanvasManager::CanvasManager(size_t x_size, size_t y_size)
    : m_next_id(1), m_canvas(x_size, y_size){};

CanvasManager::CanvasManager(const Canvas &canvas)
    : m_next_id(1), m_canvas(canvas){};

int CanvasManager::AddRectangle(int ulx, int uly, int lrx, int lry, int color) {
  auto id = m_next_id++;
  m_figures[id] =
      std::make_unique<Rectangle>(m_canvas, ulx, uly, lrx, lry, color);
  return id;
};

int CanvasManager::AddCircle(int x, int y, int radius, int color) {
  auto id = m_next_id++;
  m_figures[id] = std::make_unique<Circle>(m_canvas, x, y, radius, color);
  return id;
};

int CanvasManager::AddTriangle(int x, int y, int h, int color) {
  auto id = m_next_id++;
  m_figures[id] = std::make_unique<Triangle>(m_canvas, x, y, h, color);
  return id;
};

void CanvasManager::DrawFigure(int id) { m_figures.at(id)->Draw(); }

void CanvasManager::RemoveFigure(int id) {
  if (m_figures.count(id)) {
    m_figures.at(id)->Clear();
    m_figures.erase(id);
  }
};

void CanvasManager::MoveFigure(int id, int offset_x, int offset_y) {
  if (m_figures.count(id)) {
    m_figures.at(id)->Clear();
    m_figures.at(id)->Draw(offset_x, offset_y);
  }
};

void CanvasManager::ColorFigure(int id, int color) {
  if (m_figures.count(id)) {
    m_figures.at(id)->Clear();
    m_figures.at(id)->ReDraw(color);
  }
};

bool CanvasManager::Validate(int id) {
  if (m_figures.count(id)) {
    return m_figures.at(id)->IsNotOverlaped();
  }
  return true;
}

void CanvasManager::ShowCanvas() { m_canvas.DrawCanvas(); }

std::unique_ptr<Canvas> CanvasManager::CloneCanvas() {
  return m_canvas.Clone();
}
