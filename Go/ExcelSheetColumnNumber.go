package main

var multiples = [...]int{1, 26, 676, 17576, 456976, 11881376, 308915776}

func titleToNumber(s string) int {
	r := 0
	n := len(s)
	for i := 0; i < n; i++ {
		r += int(s[n-i-1]-'A'+1) * multiples[i]
	}

	return r
}
