#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

class QueueInterface {
public:
  virtual ~QueueInterface() {}

  virtual bool Enqueue(int32_t value)=0;
  virtual int32_t Dequeue()=0;
  virtual int32_t PeekFront()=0;
  virtual int32_t PeekRear()=0;
  virtual bool IsEmpty()=0;
};

#endif //QUEUEINTERFACE_H
