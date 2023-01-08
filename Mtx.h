#ifndef MTX_H
#define MTX_H

#include <mutex>

class Mtx {
public:
  Mtx() = default;
  virtual ~Mtx() = default;
  virtual void lock() = 0;
  virtual void unlock() = 0;
};

class MtxFree : public Mtx {
public:
  MtxFree() = default;
  ~MtxFree() = default;
  void lock() final{

  };
  void unlock() final{

  };
};

class MtxBlocking : public Mtx {
public:
  MtxBlocking() = default;
  ~MtxBlocking() = default;
  void lock() final { mtx.lock(); };
  void unlock() final { mtx.unlock(); };

private:
  std::mutex mtx;
};

#endif
