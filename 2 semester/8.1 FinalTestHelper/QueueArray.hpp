#ifndef QUEUE_QUEUEARRAY_HPP
#define QUEUE_QUEUEARRAY_HPP

#include "Queue.hpp"
#include "QueueOverflow.hpp"
#include "QueueUnderflow.hpp"
#include "WrongQueueSize.hpp"

template<typename T>
class QueueArray final: public Queue<T> // модификатор final запрещает наследование от класса
{
public:
  explicit QueueArray(size_t size);

  QueueArray(const QueueArray<T> &src) = delete;

  QueueArray(QueueArray<T> &&src) noexcept;

  QueueArray<T> &operator=(QueueArray<T> &&src) noexcept; // оператор перемещающего присваивания

  ~QueueArray() override;

  void enQueue(const T &e) override;

  T deQueue() override;

  bool isEmpty() const override;

  void swap(QueueArray<T> &right);

private:
  T *array_;         // массив элементов очереди
  size_t head_{};  // Очередь пуста, если  head[Q] = tail[Q].
  size_t tail_{};  // Первоначально: head[Q] = tail[Q] = 0;
  size_t size_{};      // размер очереди
//  void swap(QueueArray<T> &right);
};

template<typename T>
QueueArray<T>::QueueArray(size_t size):
  head_(0),
  tail_(0),
  size_(size + 1)
{
  try
  {
    array_ = new T[size + 1];
  }
  catch (std::bad_alloc &ex)
  {
    throw WrongQueueSize();
  }

}

template<typename T>
void QueueArray<T>::swap(QueueArray<T> &right)
{
  std::swap((*this).array_, right.array_);
  std::swap((*this).head_, right.head_);
  std::swap((*this).tail_, right.tail_);
  std::swap((*this).size_, right.size_);

}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T> &&src) noexcept
{
  swap(src);
}

template<typename T>
QueueArray<T> &QueueArray<T>::operator=(QueueArray<T> &&src) noexcept
{
  if (this != &src)
  {
    delete this->array_;
    swap(src);
  }
  return *this;
}

template<typename T>
void QueueArray<T>::enQueue(const T &e)
{
  if (head_ == tail_ + 1)
  {
    throw QueueOverflow();
  }
  array_[tail_] = e;
  tail_ = (tail_ + 1) % size_;
}

template<typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow();
  }
  size_t index = head_;
  head_ = (head_ + 1) % size_;
  return std::move(array_[index]);
}

template<typename T>
QueueArray<T>::~QueueArray()
{
  delete[] array_;
}

template<typename T>
bool QueueArray<T>::isEmpty() const
{
  return head_ == tail_;
}

#endif //QUEUE_QUEUEARRAY_HPP
