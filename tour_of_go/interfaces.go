package main
import (
	"fmt"
	"math"
	"time"
	"strconv"
)

type I interface{
	M()
	M1()
}

type T struct{
	S string
}

func (t T) M() {
	fmt.Println(t.S)
}

func (t *T) M1() {
	if t == nil {
		fmt.Println("<nil>")
		return
	}
	t.S += " world"
	fmt.Println(t.S)
}

type F float64

func (f F) M() {
	fmt.Println(f)
}
func (f F) M1() {
	fmt.Println(f)
}

func describe(i interface{}) {
	fmt.Printf("(%v, %T)\n", i, i)
}

type IPAddr [4]byte

func (ip IPAddr) String() string {
	return fmt.Sprintf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3])
}

type MyError struct {
	When time.Time
	What string
}

func (err *MyError) Error() string {
	return fmt.Sprintf("at %v %s", err.When, err.What)
}

func test_myerror() error {
	return &MyError{time.Now(), "it didn't work"}
}

func do(i interface{}) {
	switch v := i.(type) {
		case int:
			fmt.Printf("int: %v\n", v)
		case string:
			fmt.Printf("string: %v\n", v)
		default:
			fmt.Printf("unknown: %T\n", v)
	}
}

func test_interface() {
	var i I = &T{"hello"}
	describe(i)
	i.M()
	i.M1()

	i = F(math.Pi)
	describe(i)
	i.M()

	var t *T
	i = t
	describe(i)
	i.M1()

	var i1 I
	describe(i1)
	//i1.M()

	var i2 interface{}
	describe(i2)

	i2 = 42
	describe(i2)

	i2 = "hello"
	describe(i2)

	var i3 interface{} = "hello"
	s, ok := i3.(string)
	fmt.Println(s, ok)

	f, ok1 := i3.(float64)
	fmt.Println(f, ok1)

	//f = i3.(float64) // error

	do(21)
	do("hello")
	do(true)

	// Stringer
	ip := IPAddr{192,168,0,100}
	fmt.Println(ip.String())

	// Error
	ii, err := strconv.Atoi("42")
	if err != nil {
	    fmt.Printf("couldn't convert number: %v\n", err)
	    return
	}
	fmt.Println("Converted integer:", ii)

	if err := test_myerror(); err != nil {
		fmt.Println(err)
	}
}
