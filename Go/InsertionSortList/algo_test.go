package insertionsortlist

import (
	"testing"
)

func toSlice(head *ListNode) []int {
	r := make([]int, 0)
	node := head
	for node != nil {
		r = append(r, node.Val)
		node = node.Next
	}
	return r
}

func testEq(a, b []int) bool {

	// If one is nil, the other must also be nil.
	if (a == nil) != (b == nil) {
		return false
	}

	if len(a) != len(b) {
		return false
	}

	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}

func TestCase1(t *testing.T) {
	head := &ListNode{4, &ListNode{2, &ListNode{1, &ListNode{3, nil}}}}

	sortedList := insertionSortList(head)
	expectedValues := []int{1, 2, 3, 4}
	values := toSlice(sortedList)
	if testEq(values, expectedValues) == false {
		t.Error("list sort error", expectedValues, values)
	}

}

func TestCase2(t *testing.T) {
	head := &ListNode{-1, &ListNode{5, &ListNode{3, &ListNode{4, &ListNode{0, nil}}}}}
	sortedList := insertionSortList(head)
	expectedValues := []int{-1, 0, 3, 4, 5}
	values := toSlice(sortedList)
	if testEq(values, expectedValues) == false {
		t.Error("list sort error", expectedValues, values)
	}
}
