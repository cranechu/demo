import os
import multiprocessing


class W(object):
    def __init__(self, q, s):
        global mp
        print(mp)
        self.q = q
        self.p = mp.Process(target=self.foo, args=(q, s))
        self.p.daemon = True

    def foo(self, q, s):
        q.put(s)

    def start(self):
        self.p.start()
        return self
    
    def close(self):
        self.p.join()
        return self.q.get()
    
def func():
    q = mp.Queue()

    w1 = W(q, "hello world 1"*1000).start()
    w2 = W(q, "hello world 2"*1000).start()
    w3 = W(q, "hello world 3"*1000).start()
    w4 = W(q, "hello world 4"*1000).start()

    w1.close()
    w2.close()
    w3.close()
    w4.close()


mp = multiprocessing.get_context('spawn')
    
if __name__ == '__main__':
    for i in range(100000):
        print(i)
        func()
