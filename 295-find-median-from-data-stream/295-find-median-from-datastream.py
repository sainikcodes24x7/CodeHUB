import heapq
class MedianFinder:

    def __init__(self):
        self.min_heap = []
        self.max_heap = []

        heapq.heapify(self.min_heap)
        heapq.heapify(self.max_heap)

    def balanceHeaps(self):
        if len(self.min_heap) > len(self.max_heap):
            val = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -val)

        elif len(self.min_heap)+1 < len(self.max_heap):
            val = heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, -val)
    def addNum(self, num: int) -> None:
        if self.min_heap and num > self.min_heap[0]:
            heapq.heappush(self.min_heap, num)
        else:
            heapq.heappush(self.max_heap, -num)
            
        self.balanceHeaps()
            
    def findMedian(self) -> float:
        if len(self.min_heap) == len(self.max_heap):
            mid1 = -self.max_heap[0]
            mid2 = self.min_heap[0]
            
            return (mid1+mid2)/2
        else:
            
            mid1 = -self.max_heap[0]
            return mid1


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()