package decodestrings

import (
	"strconv"
	"strings"
	"unicode"
)

func decodeStr(s string, start int) (string, int) {
	var buffer string
	index := start
	for {
		foundNum := false
		var runeValue rune
		for index, runeValue = range s[start:] {
			if unicode.IsDigit(runeValue) {
				foundNum = true
				break
			}
			if runeValue == ']' {
				e := start + index
				buffer += s[start:e]
				return buffer, e + 1
			}
		}

		if !foundNum {
			buffer += s[start:]
			return buffer, len(s)
		}
		e := start + index
		buffer += s[start:e]
		var word string
		word, start = decodeKStr(s, start+index)
		buffer += word
	}
}

func decodeKStr(s string, start int) (string, int) {

	var index int
	var runeValue rune
	for index, runeValue = range s[start:] {
		if runeValue == '[' {
			break
		}
	}
	e := start + index
	qty, _ := strconv.Atoi(s[start:e])
	var word string
	word, start = decodeStr(s, start+index+1)
	return strings.Repeat(word, qty), start
}

func decodeString(s string) string {
	r, _ := decodeStr(s, 0)
	return r
}
