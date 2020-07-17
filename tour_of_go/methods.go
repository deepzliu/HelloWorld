package main
import (
	"fmt"
	"math"
)

func (p Point) distance() float64 {
	p.x++
	p.y++
	return math.Sqrt(float64(p.x * p.x + p.y * p.y))
}

// 使用指针接收者的原因：
// 1.方法能够修改其接收者指向的值。
// 2.避免在每次调用方法时复制该值。

// 指针接收者
func (p *Point) scale(n int) {
	p.x *= n
	p.y *= n
}

func distance(p Point) float64 {
	return math.Sqrt(float64(p.x * p.x + p.y * p.y))
}

func scale(p *Point, n int) {
	p.x *= n
	p.y *= n
}

func test_method() {
	p := Point{3, 4}
	fmt.Println(p)
	fmt.Println(p.distance())
	fmt.Println(p)
	p.scale(2)
	fmt.Println(p)

	fmt.Println(distance(p))
	scale(&p, 2)
	fmt.Println(p)
}
