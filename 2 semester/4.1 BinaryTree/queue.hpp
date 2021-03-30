#ifndef INC_4_1_BINARYTREE_QUEUE_HPP
#define INC_4_1_BINARYTREE_QUEUE_HPP

#include <exception>

class WrongQueueSize : public std::exception
{
public:
  explicit WrongQueueSize(const char* what):
    what_(what)
  {
  }

  const char* what() const noexcept override
  {
    return what_;
  }

private:
  const char* what_;
};

class QueueOverflow: public std::exception
{
public:
  explicit QueueOverflow(const char* what):
    what_(what)
  {
  }

  const char* what() const noexcept override
  {
    return what_;
  }

private:
  const char* what_;
};

class QueueUnderflow: public std::exception
{
public:
  explicit QueueUnderflow(const char* what):
    what_(what)
  {
  }

  const char* what() const noexcept override
  {
    return what_;
  }

private:
  const char* what_;
};

template <class T>
class Queue
{
public:
  virtual ~Queue() {}

  // Абстрактные операции со стеком

  virtual void enQueue(const T& e) = 0; // Добавление элемента в стек

  virtual T deQueue() = 0;// Удаление и возвращение верхнего элемента.
  // Если элементов нет, может возникнуть QueueUnderflow

  virtual bool isEmpty() const = 0; // Проверка на пустоту
};

template <typename T>
class QueueArray final : public Queue<T>
{
public:
  QueueArray(size_t size);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src) noexcept;

  virtual ~QueueArray() override
  {
    delete[] array_;
  }

  QueueArray<T>& operator=(const QueueArray<T>& src) = delete;
  QueueArray<T>& operator=(QueueArray<T>&& src);

  void enQueue(const T& e) override;
  T deQueue() override;
  bool isEmpty() const override
  {
    return head_ == tail_;
  }
  size_t getSize() const
  {
    return (tail_ - head_);
  }

private:
  size_t size_;
  size_t head_;
  size_t tail_;
  T* array_;

  void swap(QueueArray<T> &right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size):
  size_(size),
  head_ (0),
  tail_ (0)
{
    if(size <= 0)
    {
      throw WrongQueueSize("The queue size should be a positive number");
    }
    array_ = new T[size];

}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
  std::swap(array_, right.array_);
  std::swap(head_,  right.head_);
  std::swap(tail_,  right.tail_);
  std::swap(size_,  right.size_);

}

template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src) noexcept
{
  size_ = src.size_;
  src.size_ = 0;
  head_ = src.head_;
  src.head_ = 0;
  tail_ = src.tail_;
  src.tail_ = 0;
  array_ = src.array_;
  src.array_ = nullptr;
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
  size_ = src.size_;
  src.size_ = 0;
  head_ = src.head_;
  src.head_ = 0;
  tail_ = src.tail_;
  src.tail_ = 0;
  array_ = src.array_;
  src.array_ = nullptr;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
  if (tail_ == size_ && head_ == 0)
  {
    throw QueueOverflow("The queue is full already"); // нет места для нового элемента
  }
  else if(head_ != 0 && tail_ == size_)
  {
    for(size_t i = head_; i < size_; i++)
    {
      array_[i - head_] = array_[i];
    }
    tail_ -= head_;
    head_ = 0;
  }
  array_[tail_] = e;
  tail_ += 1;
}

template <typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow("There is nothing to delete"); // очередь пуста
  }

  T temp = array_[head_];
  array_[head_] = 0;
  head_ += 1;
  return temp;

}

#endif //INC_4_1_BINARYTREE_QUEUE_HPP
