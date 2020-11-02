package insertionsortlist

/**
 * Definition for singly-linked list.
 */

// ListNode is a predefined type
type ListNode struct {
	Val  int
	Next *ListNode
}

func insertionSortList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	last := head
	for {
		current := last.Next
		if current == nil {
			break
		}
		if current.Val >= last.Val {
			last = current
			continue
		}
		var prev *ListNode = nil
		for it := head; it != current; it = it.Next {
			if it.Val > current.Val {
				last.Next = current.Next
				if prev == nil {
					current.Next = head
					head = current
				} else {
					current.Next = prev.Next
					prev.Next = current
				}
				break
			}
			prev = it
		}
	}
	return head
}
