#ifndef COMMANDS_H
#define COMMANDS_H

#include "Command.h"
#include "FigureParams.h"

class AddFigureCmd : public Command {
public:
  AddFigureCmd(CanvasManager &cm, const RectangleParams &params);
  AddFigureCmd(CanvasManager &cm, const CircleParams &params);
  AddFigureCmd(CanvasManager &cm, const TriangleParams &params);
  ~AddFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;
  int GetId() const;

private:
  int m_id;
};

class RemoveFigureCmd : public Command {
public:
  RemoveFigureCmd(CanvasManager &cm, int id);
  ~RemoveFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
};

class MoveFigureCmd : public Command {
public:
  MoveFigureCmd(CanvasManager &cm, int id, int offset_x, int offset_y);
  ~MoveFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
  int m_offset_x;
  int m_offset_y;
};

class ColorFigureCmd : public Command {
public:
  ColorFigureCmd(CanvasManager &cm, int id, int color);
  ~ColorFigureCmd() = default;
  void Execute() final;
  bool Validate(int &id) final;

private:
  int m_id;
  int m_color;
};

#endif
