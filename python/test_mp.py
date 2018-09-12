import os
import multiprocessing


class W(object):
    def __init__(self, q, s):
        global mp
        print(mp)
        self.p = mp.Process(target=self.foo, args=(q, s))
        self.p.daemon = True

    def foo(self, q, s):
        while True:
            pass
            #q.put(s)

    def start(self):
        self.p.start()
        return self
    
    def close(self):
        self.p.join()
        return self.q.get()
    

if __name__ == '__main__':
    mp = multiprocessing.get_context('spawn')
    print(mp)
    q = mp.Queue()
    w1 = W(q, "hello world 1").start()
    w2 = W(q, "hello world 2").start()
    w3 = W(q, "hello world 3").start()
    w4 = W(q, "hello world 4").start()
    while True:
        pass
        #q.get()
        #print(q.get())

