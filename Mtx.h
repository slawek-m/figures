#ifndef MTX_H
#define MTX_H

#include <mutex>

class Mtx {
public:
  Mtx() = default;
  virtual ~Mtx() = default;
  virtual void Lock() = 0;
  virtual void Unlock() = 0;
};

class MtxFree : public Mtx {
public:
  MtxFree() = default;
  ~MtxFree() = default;
  void Lock() final{

  };
  void Unlock() final{

  };
};

class MtxBlocking : public Mtx {
public:
  MtxBlocking() = default;
  ~MtxBlocking() = default;
  void Lock() final { mtx.lock(); };
  void Unlock() final { mtx.unlock(); };

private:
  std::mutex mtx;
};

#endif
