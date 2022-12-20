#ifndef CANVASMANAGER_H
#define CANVASMANAGER_H

#include <map>
#include <memory>

#include "Canvas.h"
#include "Figure.h"

class CanvasManager {
public:
  CanvasManager(const Canvas &canvas);
  CanvasManager(size_t x_size, size_t y_size);
  ~CanvasManager() = default;
  int AddRectangle(int ulx, int uly, int lrx, int lry, int color);
  int AddCircle(int x, int y, int radius, int color);
  int AddTriangle(int x, int y, int h, int color);
  void DrawFigure(int id);
  void RemoveFigure(int id);
  void MoveFigure(int id, int offset_x, int offset_y);
  void ColorFigure(int id, int color);
  bool Validate(int id);
  void ShowCanvas();
  std::unique_ptr<Canvas> CloneCanvas();

private:
  unsigned int m_next_id;
  Canvas m_canvas;
  size_t m_x_size;
  size_t m_y_size;

  std::map<unsigned int, std::unique_ptr<Figure>> m_figures;
};

#endif
