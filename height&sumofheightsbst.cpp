#!/bin/python3

import os
import sys
sys.setrecursionlimit(10000)

# Complete the function below.
class Node():
     
    # A constructor to create a new node 
    def __init__(self, data):
        self.data = data 
        self.left = None
        self.right = None

def getPreIndex():
    return constructTreeUtil.preIndex
def incrementPreIndex():
    constructTreeUtil.preIndex += 1
def constructTreeUtil(pre, low, high, size):
    if( getPreIndex() >= size or low > high):
        return None

    root = Node(pre[getPreIndex()])
    incrementPreIndex()

    if low == high :
        return root 

    for i in range(low, high+1):
        if (pre[i] > root.data):
            break

    root.left = constructTreeUtil(pre, getPreIndex(),  i-1 , size) 
    root.right = constructTreeUtil(pre, i, high, size) 
    return root
def maxDepth(node):
    if node is None:
        return -1 ; 
 
    else :
 
        # Compute the depth of each subtree
        lDepth = maxDepth(node.left)
        rDepth = maxDepth(node.right)
 
        # Use the larger one
        if (lDepth > rDepth):
            return lDepth+1
        else:
            return rDepth+1
def constructTree(pre):
    size = len(pre) 
    constructTreeUtil.preIndex = 0
    return constructTreeUtil(pre, 0, size-1, size)
def T_sum(root):
 
    if root:
        return (maxDepth(root)+T_sum(root.left)+T_sum(root.right))
    return 0


def heightAndTotalHeight(arr):
    # Write your code here.
    root = constructTree(arr)
    a= maxDepth(root)
    b=T_sum(root)
    return ([a,b])
def Remove(duplicate):
    final_list = []
    for num in duplicate:
        if num not in final_list:
            final_list.append(num)
    return final_list
    


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    arr_size = int(input())

    arr = list(map(int, input().rstrip().split()))
    

    result = heightAndTotalHeight(Remove(arr))

    
    f.write("\n".join(map(str, result)))
    

    f.write('\n')

    f.close()
