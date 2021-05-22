package TwoSum

import "testing"

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
	nums := []int{2, 7, 11, 15}
	target := 9
	r := TwoSum(nums, target)
	expected := []int{0, 1}
	if !testEq(r, expected) {
		t.Errorf("failed 1: %v != %v", r, expected)
	}
}

func TestCase2(t *testing.T) {
	nums := []int{3, 2, 4}
	target := 6
	r := TwoSum(nums, target)
	expected := []int{1, 2}
	if !testEq(r, expected) {
		t.Errorf("failed 1: %v != %v", r, expected)
	}
}
