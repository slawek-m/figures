#ifndef FIGURE_H
#define FIGURE_H

class Canvas;

class Figure {
public:
  Figure(Canvas &owner_ref) : m_owner_ref(owner_ref){};
  virtual ~Figure() = default;

  virtual bool IsNotOverlaped() = 0;
  virtual void Clear() = 0;
  virtual void Draw(int offset_x = 0, int offset_y = 0) = 0;
  virtual void ReDraw(int color) = 0;

protected:
  Canvas &m_owner_ref;
};

#endif
