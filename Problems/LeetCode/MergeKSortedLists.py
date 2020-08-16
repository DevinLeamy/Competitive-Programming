# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        nums = []
        for list in lists:
            while (not list == None):
                nums.append(list.val);
                list = list.next
        
        nums.sort()
        ans = None
        for i in range(len(nums)-1, -1, -1):
            node = ListNode(nums[i])
            node.next = ans
            ans = node
        return ans
