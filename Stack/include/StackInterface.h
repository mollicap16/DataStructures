#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

class StackInterface {
public:
  virtual ~StackInterface() {}

  virtual bool Push(int32_t value)=0;
  virtual int32_t Pop()=0;
  virtual int32_t Peek()=0;
  virtual bool IsEmpty()=0;
};

#endif //STACKINTERFACE_H
