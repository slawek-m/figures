#ifndef CANVASMANAGER_H
#define CANVASMANAGER_H

#include <map>
#include <memory>

#include "Canvas.h"
#include "CanvasImpl.h"
#include "Figure.h"
#include "Mtx.h"

template <class T> class CanvasManager {
public:
  CanvasManager(const Canvas<T> &canvas);
  CanvasManager(std::unique_ptr<CanvasImpl<T>> canvas_impl, size_t x_size,
                size_t y_size, std::unique_ptr<Mtx> mtx);
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
  std::unique_ptr<Canvas<T>> CloneCanvas();

private:
  unsigned int m_next_id;
  Canvas<T> m_canvas;
  size_t m_x_size;
  size_t m_y_size;

  std::map<unsigned int, std::unique_ptr<Figure<T>>> m_figures;
  std::unique_ptr<Mtx> m_mtx;
};

#endif
