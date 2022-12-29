#ifndef CANVAS_H
#define CANVAS_H

#include "CanvasImpl.h"
#include <memory>

template <class T> class Canvas {
public:
  Canvas(std::unique_ptr<CanvasImpl<T>> impl);
  Canvas(std::unique_ptr<CanvasImpl<T>> impl, int x_size, int y_size);
  Canvas(const Canvas &canvas);
  ~Canvas() = default;

  T GetColor(int x, int y);
  void SetColor(int x, int y, T color);
  void GetSize(int &x_size, int &y_size);
  void DrawCanvas();
  std::unique_ptr<Canvas> Clone();

private:
  std::unique_ptr<CanvasImpl<T>> m_impl; // must be pointer (not reference)
  int m_x_size;
  int m_y_size;
};

#endif
