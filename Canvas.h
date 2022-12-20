#ifndef CANVAS_H
#define CANVAS_H

#include <memory>
#include <vector>

class Canvas {
public:
  Canvas();
  Canvas(int x_size, int y_size);
  Canvas(const Canvas &canvas);
  ~Canvas() = default;

  int GetColor(int x, int y);
  void SetColor(int x, int y, int color);
  void GetSize(int &x_size, int &y_size);
  void DrawCanvas();
  std::unique_ptr<Canvas> Clone();

private:
  int m_x_size;
  int m_y_size;
  std::vector<std::vector<int>> m_canvas;
};

#endif
