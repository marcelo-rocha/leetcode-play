package TwoSum

func merge(a, b, m, n []int) (result, imap []int) {
	size, i, j := len(a)+len(b), 0, 0
	result = make([]int, size)
	imap = make([]int, size)
	for k := 0; k < size; k++ {
		switch {
		case i == len(a):
			//all the elements of a already been judged
			//assuming a and b both are sorted, this happens because
			//some cases will have not equal a and b, so it might
			// be a possibility that one array got finished earlier.
			result[k], imap[k] = b[j], n[j]
			j += 1
		case j == len(b):
			//alll the elements of a already been judged
			//assuming a nd b both are sorted
			result[k], imap[k] = a[i], m[i]
			i += 1
		case a[i] > b[j]:
			result[k], imap[k] = b[j], n[j]
			//increment the index of b array because its present index
			//is already appended to the result array
			j += 1
		case a[i] < b[j]:
			//increment the index of a array because its present index
			//element is already appended to the result array
			result[k], imap[k] = a[i], m[i]
			i += 1
		case a[i] == b[j]:
			//in case of equality
			result[k], imap[k] = b[j], n[j]
			j += 1
		}
	}
	return result, imap
}

func mergeSort(numbers, imap []int) ([]int, []int) {
	if len(numbers) < 2 {
		return numbers, imap
	}
	middle := int(len(numbers) / 2)
	a, m := mergeSort(numbers[middle:], imap[middle:])
	b, n := mergeSort(numbers[:middle], imap[:middle])
	return merge(a, b, m, n)
}

func binarySearch(a []int, search int) (result int) {
	mid := len(a) / 2
	switch {
	case len(a) == 0:
		result = -1 // not found
	case a[mid] > search:
		result = binarySearch(a[:mid], search)
	case a[mid] < search:
		result = binarySearch(a[mid+1:], search)
		if result >= 0 { // if anything but the -1 "not found" result
			result += mid + 1
		}
	default: // a[mid] == search
		result = mid // found
	}
	return
}

func TwoSum(nums []int, target int) []int {
	seq := make([]int, len(nums))
	for i := range nums {
		seq[i] = i
	}
	anums, amap := mergeSort(nums, seq)

	for x := 0; x < len(anums)-1; x++ {
		m := anums[x]
		n := target - m
		y := binarySearch(anums[x+1:], n)
		if y >= 0 {
			return []int{amap[x], amap[x+1+y]}
		}
	}
	return []int{}
}
