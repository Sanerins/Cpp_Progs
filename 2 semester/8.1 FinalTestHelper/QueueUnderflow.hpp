#ifndef QUEUE_QUEUEUNDERFLOW_HPP
#define QUEUE_QUEUEUNDERFLOW_HPP

#include <exception>

class QueueUnderflow: public std::exception {
public:
  const char *what();
};

const char *QueueUnderflow::what()
{
  return "Queue Underflow";
}

#endif //QUEUE_QUEUEUNDERFLOW_HPP
