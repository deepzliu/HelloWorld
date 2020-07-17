package main

import "fmt"

// define struct
type Point struct{
	x int
	y int
}

func structs() {
	fmt.Println(Point{2,3})
	p := Point{3, 5}

	// struct pointer
	q := &p
	q.y = 8

	fmt.Println(p.x, p.y)

	p1 := Point{y:2}
	fmt.Println(p1)
	p2 := Point{}
	fmt.Println(p2)
}
