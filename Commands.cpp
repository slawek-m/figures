#include "Commands.h"
#include <iostream>

template <class T>
AddFigureCmd<T>::AddFigureCmd(CanvasManager<T> &cm,
                              const RectangleParams &params)
    : Command<T>(cm) {
  m_id = Command<T>::m_cm.AddRectangle(params.ulx, params.uly, params.lrx,
                                       params.lry, params.color);
};

template <class T>
AddFigureCmd<T>::AddFigureCmd(CanvasManager<T> &cm, const CircleParams &params)
    : Command<T>(cm) {
  m_id = Command<T>::m_cm.AddCircle(params.center_x, params.center_y,
                                    params.radius, params.color);
};

template <class T>
AddFigureCmd<T>::AddFigureCmd(CanvasManager<T> &cm,
                              const TriangleParams &params)
    : Command<T>(cm) {
  m_id = Command<T>::m_cm.AddTriangle(params.vertex_x, params.vertex_y,
                                      params.height, params.color);
};

template <class T> void AddFigureCmd<T>::Execute() {
  Command<T>::m_cm.DrawFigure(m_id);
  std::cout << "added figure id: " << m_id << std::endl;
};

template <class T> bool AddFigureCmd<T>::Validate(int &id) {
  id = m_id;
  return Command<T>::m_cm.Validate(m_id);
};

template <class T> int AddFigureCmd<T>::GetId() const { return m_id; }

template <class T>
RemoveFigureCmd<T>::RemoveFigureCmd(CanvasManager<T> &cm, int id)
    : Command<T>(cm), m_id(id){};

template <class T> void RemoveFigureCmd<T>::Execute() {
  Command<T>::m_cm.RemoveFigure(m_id);
  std::cout << "removed figure id: " << m_id << std::endl;
};

template <class T> bool RemoveFigureCmd<T>::Validate(int &id) {
  id = m_id;
  return Command<T>::m_cm.Validate(m_id);
};

template <class T>
MoveFigureCmd<T>::MoveFigureCmd(CanvasManager<T> &cm, int id, int offset_x,
                                int offset_y)
    : Command<T>(cm), m_id(id), m_offset_x(offset_x), m_offset_y(offset_y){};

template <class T> void MoveFigureCmd<T>::Execute() {
  Command<T>::m_cm.MoveFigure(m_id, m_offset_x, m_offset_y);
  std::cout << "moved figure id: " << m_id << std::endl;
};

template <class T> bool MoveFigureCmd<T>::Validate(int &id) {
  id = m_id;
  return Command<T>::m_cm.Validate(m_id);
};

template <class T>
ColorFigureCmd<T>::ColorFigureCmd(CanvasManager<T> &cm, int id, int color)
    : Command<T>(cm), m_id(id), m_color(color){};

template <class T> void ColorFigureCmd<T>::Execute() {
  Command<T>::m_cm.ColorFigure(m_id, m_color);
  std::cout << "color figure id: " << m_id << std::endl;
};

template <class T> bool ColorFigureCmd<T>::Validate(int &id) {
  id = m_id;
  return Command<T>::m_cm.Validate(m_id);
};

template class AddFigureCmd<int>;
template class RemoveFigureCmd<int>;
template class MoveFigureCmd<int>;
template class ColorFigureCmd<int>;