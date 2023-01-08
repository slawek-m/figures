#ifndef COMMANDS_H
#define COMMANDS_H

#include "Command.h"
#include "FigureParams.h"

template <class T> class AddFigureCmd : public Command<T> {
public:
  AddFigureCmd(CanvasManager<T> &cm, const RectangleParams &params);
  AddFigureCmd(CanvasManager<T> &cm, const CircleParams &params);
  AddFigureCmd(CanvasManager<T> &cm, const TriangleParams &params);
  ~AddFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;
  int GetId() const;

private:
  int m_id;
};

template <class T> class RemoveFigureCmd : public Command<T> {
public:
  RemoveFigureCmd(CanvasManager<T> &cm, int id);
  ~RemoveFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
};

template <class T> class MoveFigureCmd : public Command<T> {
public:
  MoveFigureCmd(CanvasManager<T> &cm, int id, int offset_x, int offset_y);
  ~MoveFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
  int m_offset_x;
  int m_offset_y;
};

template <class T> class ColorFigureCmd : public Command<T> {
public:
  ColorFigureCmd(CanvasManager<T> &cm, int id, int color);
  ~ColorFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
  int m_color;
};

template <class T> class CopyFigureCmd : public Command<T> {
public:
  CopyFigureCmd(CanvasManager<T> &cm, int id, int offset_x, int offset_y);
  ~CopyFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
  int m_offset_x;
  int m_offset_y;
};

#endif
