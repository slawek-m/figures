#ifndef FIGURE_H
#define FIGURE_H

template <class T> class Canvas;

template <class T> class Figure {
public:
  Figure(Canvas<T> &owner_ref) : m_owner_ref(owner_ref){};
  virtual ~Figure() = default;

  virtual bool IsNotOverlaped() = 0;
  virtual void Clear() = 0;
  virtual void Draw(int offset_x = 0, int offset_y = 0) = 0;
  virtual void ReDraw(T color) = 0;

protected:
  Canvas<T> &m_owner_ref;
};

#endif
