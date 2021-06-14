#ifndef QUEUE_QUEUEOVERFLOW_HPP
#define QUEUE_QUEUEOVERFLOW_HPP

#include <exception>

class QueueOverflow: public std::exception {
public:
  const char *what();
};

const char *QueueOverflow::what()
{
  return "Queue Overflow";
}

#endif //QUEUE_QUEUEOVERFLOW_HPP
