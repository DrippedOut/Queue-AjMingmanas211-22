#include "node.h"

class Queue {
  NodePtr headPtr;
  NodePtr tailPtr;
  int size;

public:
  void enqueue(int);
  int dequeue();
  Queue();
  ~Queue(); // dequeue all
};

Queue::Queue(){
  size=0;
  headPtr=NULL;
  tailPtr=NULL;
}

Queue::~Queue(){
 int i;
 int n=size;

  //while(size>0)
  for(i=0;i<n;i++)
    dequeue();
  
}
void Queue::enqueue(int x) {
  NodePtr new_node = new NODE(x); 
  
  if (size==0) {
    headPtr = new_node; // change head
  } 
  else {
    tailPtr->set_next(new_node); // connect tail
  }
  tailPtr = new_node; // change tail
  ++size;
}


int Queue::dequeue() {
  int value;
  NodePtr t;
 if(headPtr){
   t = headPtr;
   headPtr = headPtr->get_next();
   value = t->get_value();
   
  if(size==1) tailPtr=NULL;
   
  size --;
  delete t;
  return value;
  }
  return -1;
}