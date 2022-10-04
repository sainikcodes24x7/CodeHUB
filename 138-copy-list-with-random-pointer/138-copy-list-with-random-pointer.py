"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        
        node = head
        
        if node == None:
            return None
        
        while node!=None:
            
            copy = Node(node.val, None, None)
            
            temp = node.next
            
            node.next = copy
            
            copy.next = temp
            
            node = temp
            
        copy_head = head.next
        
        node = head
        
        while node!=None:
            
            copy = node.next
            
            if node.random == None:
                rand_copy = None
            else:
                rand = node.random

                rand_copy = rand.next
            
            copy.random = rand_copy
            
            node = node.next.next
            
        node = head
        copy = node.next
        
        while node!= None:
            
            node.next = copy.next
            
            if copy.next != None:
                copy.next = node.next.next
                
            node = node.next
            copy = copy.next
            
        return copy_head