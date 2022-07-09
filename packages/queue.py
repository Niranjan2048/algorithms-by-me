from DS.queueds import queue

q = queue()
print("Program to implement queue functions")
q.enqueue(10)
q.enqueue(29)
q.enqueue(9)
q.enqueue(63)
q.enqueue(51)
q.enqueue(87)

q.display()

q.dequeue()
q.dequeue()
q.dequeue()

print("After removing 3 element")
q.display()
