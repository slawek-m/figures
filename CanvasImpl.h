#ifndef CANVASIMPL_H
#define CANVASIMPL_H

#include <memory>

template <class T> class CanvasImpl {
public:
  CanvasImpl() = default;
  virtual ~CanvasImpl() = default;
  virtual void Resize(int x_size, int y_size) = 0;
  virtual T GetColor(int x, int y) = 0;
  virtual void SetColor(int x, int y, T color) = 0;
  virtual void GetSize(int &x_size, int &y_size) = 0;
  virtual void DrawCanvas() = 0;
  virtual std::unique_ptr<CanvasImpl<T>> Clone() = 0;
};

#endif
