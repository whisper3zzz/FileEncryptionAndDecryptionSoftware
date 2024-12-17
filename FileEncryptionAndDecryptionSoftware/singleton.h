#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>

template<typename T>
class Singleton {
  public:
    static T& instance() {
        static T instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

  protected:
    Singleton() = default;
    ~Singleton() = default;
};

#endif // SINGLETON_H
