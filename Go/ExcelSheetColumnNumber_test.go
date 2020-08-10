package main

import "testing"

func TestCase1(t *testing.T) {
	r := titleToNumber("AB")
	if r != 28 {
		t.Error("failure") // to indicate test failed

	}
}
