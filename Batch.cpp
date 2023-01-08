#include <algorithm>

#include "Batch.h"

template <class T> Batch<T>::Batch(CanvasManager<T> &cm) : m_cm(cm){};

template <class T>
Batch<T> &Batch<T>::AddFigure(const RectangleParams &params) {
  m_batch.push_back(std::make_unique<AddFigureCmd<T>>(m_cm, params));
  return *this;
};

template <class T> Batch<T> &Batch<T>::AddFigure(const CircleParams &params) {
  m_batch.push_back(std::make_unique<AddFigureCmd<T>>(m_cm, params));
  return *this;
};

template <class T> Batch<T> &Batch<T>::AddFigure(const TriangleParams &params) {
  m_batch.push_back(std::make_unique<AddFigureCmd<T>>(m_cm, params));
  return *this;
};

template <class T> Batch<T> &Batch<T>::RemoveFigure(int id) {
  m_batch.push_back(std::make_unique<RemoveFigureCmd<T>>(m_cm, id));
  return *this;
};

template <class T>
Batch<T> &Batch<T>::MoveFigure(int id, int offset_x, int offset_y) {
  m_batch.push_back(
      std::make_unique<MoveFigureCmd<T>>(m_cm, id, offset_x, offset_y));
  return *this;
};

template <class T> Batch<T> &Batch<T>::ColorFigure(int id, int color) {
  m_batch.push_back(std::make_unique<ColorFigureCmd<T>>(m_cm, id, color));
  return *this;
};

template <class T>
Batch<T> &Batch<T>::CopyFigure(int id, int offset_x, int offset_y) {
  m_batch.push_back(
      std::make_unique<CopyFigureCmd<T>>(m_cm, id, offset_x, offset_y));
  return *this;
};

template <class T> Batch<T> &Batch<T>::Execute() {
  std::for_each(m_batch.begin(), m_batch.end(),
                [](auto &ptr) { ptr->Execute(); });
  return *this;
};

template <class T> bool Batch<T>::Validate() {
  std::vector<std::pair<int, bool>> overlap_status;
  std::for_each(m_batch.begin(), m_batch.end(), [&overlap_status](auto &ptr) {
    int id;
    bool res = ptr->Validate(id);
    overlap_status.push_back(std::make_pair(id, res));
  });

  bool res = true;
  if (std::find_if(overlap_status.begin(), overlap_status.end(),
                   [](const auto &pair) { return pair.second == false; }) !=
      overlap_status.end())
    res = false;

  m_batch.clear();

  return res;
}

template class Batch<int>;
