package main
import (
	"fmt"
	"time"
	"math"
	"math/rand"
	"math/cmplx"
)

//func add(x int, y int) int {
func add(x, y int) int {
	return x+y
}

func swap(x, y string) (string, string) {
	return y, x
}

func split(sum int) (x, y int) {
	x = sum * 3 / 7
	y = sum - x
	return
}

var c, python, java bool = true, false, true

func test1() {
    fmt.Printf("hello, world\n")
	fmt.Println("The time is", time.Now())

	rand.Seed(time.Now().Unix())
	fmt.Println("My favorite number is", rand.Intn(10))

	fmt.Printf("Now you have %g problems.\n", math.Sqrt(float64(rand.Intn(10))))

	fmt.Println("Pi: ", math.Pi)

	fmt.Println(add(42,15))

	a, b := swap("hello", "world")
	fmt.Println(a, b)

	fmt.Println(split(15))

	var i, j int = 3, 5
	k := 9
	fmt.Println(i, j, k, c, python, java)
}


/*	
基本类型:

	bool
	
	string
	
	int  int8  int16  int32  int64
	uint uint8 uint16 uint32 uint64 uintptr
	
	byte // uint8 的别名
	
	rune // int32 的别名
	    // 表示一个 Unicode 码点
	
	float32 float64
	
	complex64 complex128
*/
var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

func test_types() {
	fmt.Printf("Type: %T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type: %T Value: 0x%x\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n", z, z)

	// 类型转换
	var i int = 42
	var f float64 = float64(i)
	var u uint = uint(f)
	ii := 42
	ff := float64(ii)
	uu := uint(ff)
	fmt.Printf("u: %d, uu: %d\n", u, uu)

	// 类型推导
	x := 32 
	y := 3.14 
	z := 5 + 0.5i
	fmt.Printf("x is of type %T\n", x)
	fmt.Printf("y is of type %T\n", y)
	fmt.Printf("z is of type %T\n", z)
}

const (
	Big = 1 << 100
	Small = Big >> 99
)

func needInt(x int) int { return x*10 + 1 }
func needFloat(x float64) float64 {
	return x * 0.1
}

func test_var(){
	// 常量
	const Pi = 3.14
	const TIPS = "It's a good day"
	fmt.Println(Pi, TIPS)

	// 数值常量
	fmt.Println(needInt(Small))
	//fmt.Println(needInt(Big)) // overflows int
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))
}
