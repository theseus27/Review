import time

def test1(arg):
    start = time.time()
    
    end = time.time()
    print("__ runtime: ", end-start)
    
def test2(arg):
    start = time.time()
    
    end = time.time()
    print("__ runtime: ", end-start)
    
def main():
    #Make Data
    arg1 = [i for i in range(100000)]
    #Stop Making Data
    
    #Call Tests
    test1(arg1)
    test2(arg1)
    
main()