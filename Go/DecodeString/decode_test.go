package decodestrings

import "testing"

func TestDecodeString1(t *testing.T) {
	s := "3[a]2[bc]"
	r := decodeString(s)
	if r != "aaabcbc" {
		t.Error("r is wrong: ", r)
	}
}

func TestDecodeString2(t *testing.T) {
	s := "3[a2[c]]"
	r := decodeString(s)
	if r != "accaccacc" {
		t.Error("r is wrong: ", r)
	}
}

func TestDecodeString3(t *testing.T) {
	s := "2[abc]3[cd]ef"
	r := decodeString(s)
	if r != "abcabccdcdcdef" {
		t.Error("r is wrong: ", r)
	}
}

func TestDecodeString4(t *testing.T) {
	s := "abc3[cd]xyz"
	r := decodeString(s)
	if r != "abccdcdcdxyz" {
		t.Error("r is wrong: ", r)
	}
}
