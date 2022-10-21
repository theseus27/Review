import time

def test1(nums, target):
    start = time.time()
    for i in range(len(nums)):
        for j in range(len(nums)):
            if nums[i] + nums[j] == target: 
                end = time.time()
                print("N Squared Runtime (Found): ", end-start)
                return [i,j]
    end = time.time()
    print("N Squared Runtime (Not Found): ", end-start)
    
def test2(nums, target):
    start = time.time()
    i = 0
    j = len(nums)-1
    while (i < j):
        if nums[i] + nums[j] == target:
            end = time.time()
            print("N Runtime (Found): ", end-start) 
            return [i,j]
        elif nums[i] + nums[j] < target: i += 1
        elif nums[i] + nums[j] > target: j -= 1
    end = time.time()
    print("N Runtime (Not Found): ", end-start)
    
def main():
    #Make Data
    nums = [i for i in range(10000) if i%3 == 0]
    #Stop Making Data
    
    #Call Tests
    test1(nums, 1356982)
    test2(nums, 1356982)

main()