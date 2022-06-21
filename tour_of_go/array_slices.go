package main

import "fmt"
import "strings"

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}

func printSlice2(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n",
		s, len(x), cap(x), x)
}

func array_slices() {

	// array
	var a [2]string
	a[0] = "hello"
	a[1] = "world"
	fmt.Println(a)

	n := [6]int{1,2,3,4,5}
	fmt.Println(n)

	// slice
	var s []int = n[1:3]
	fmt.Println(s)
	s1 := n[3:5]
	s1[0]++
	fmt.Println(s1)

	// 如下会创建一个数组，再构建一个引用它的切片
	q := []int{2, 3, 5, 7, 11, 13}
	fmt.Println(q)

	// 切片下界的默认值为 0，上界则是该切片的长度。
	s2 := []int{2, 3, 5, 7, 11, 13}
	s2 = s2[1:4]
	fmt.Println(s2)
	s2 = s2[:2]
	fmt.Println(s2)
	s2 = s2[1:]
	fmt.Println(s2)

	// 切片的长度: 包含的元素个数。
	// 切片的容量: 从第一个元素开始数，到其底层数组元素末尾的个数。
	s = s[:0] // 截取切片使其长度为 0
	printSlice(s)
	s = s[:4] // 拓展其长度
	printSlice(s)
	s = s[2:] // 舍弃前两个值
	printSlice(s)
	s = append(s, 100, 200) // 追加元素
	printSlice(s)

	// range
	for i, v := range(s) {
		fmt.Printf("%d: %d\n", i, v)
	}
	for _, v := range s {
		fmt.Printf("%d\n", v)
	}

	var s3 []int
	fmt.Println(s3, len(s3), cap(s3))
	if s3 == nil {
		fmt.Println("nil!")
	}

	b := make([]int, 5)
	printSlice2("b", b)

	c := make([]int, 0, 5)
	printSlice2("c", c)

	// 切片的切片
	// 创建一个井字板（经典游戏）
	board := [][]string{
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
	}

	// 两个玩家轮流打上 X 和 O
	board[0][0] = "X"
	board[2][2] = "O"
	board[1][2] = "X"
	board[1][0] = "O"
	board[0][2] = "X"

	for i := 0; i < len(board); i++ {
		fmt.Printf("%s\n", strings.Join(board[i], " "))
	}
}

