#ifndef QUEUE_WRONGQUEUESIZE_HPP
#define QUEUE_WRONGQUEUESIZE_HPP

#include <exception>

class WrongQueueSize: public std::exception {
public:
  const char *what();
};

const char *WrongQueueSize::what()
{
  return "Wrong Queue Size";
}

#endif //QUEUE_WRONGQUEUESIZE_HPP
