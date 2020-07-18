package main
import(
	"fmt"
	"time"
	"sync"
)

func say(s string) {
	for i := 0; i < 5; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func sum(s []int, c chan int){
	sum := 0
	for _, v := range s {
		sum += v
	}
	c <- sum
}

func fibonacci(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		fmt.Println("fibonacci", x)
		c <- x
		fmt.Println("fibonacci send end")
		x, y = y, x+y
	}
	close(c)
}

func fibonacci1(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case c <- x:
			x, y = y, x+y
		case <- quit:
			fmt.Println("quit")
			return
		default:
			fmt.Println("chan not ready")
			time.Sleep(time.Millisecond)
		}
	}
}

type SafeCounter struct {
	v map[string] int
	mux sync.Mutex
}

func (c *SafeCounter) Inc(key string) {
	c.mux.Lock()
	c.v[key]++
	c.mux.Unlock()
}

func (c *SafeCounter)Value(key string) int {
	c.mux.Lock()
	defer c.mux.Unlock()
	return c.v[key]
}

// A首先被a阻塞，A()结束后关闭b，使b可读
func A(a, b chan struct{}) {
    <-a
    fmt.Println("A()!")
    time.Sleep(time.Second)
    close(b)
}

// B首先被a阻塞，B()结束后关闭b，使b可读
func B(a, b chan struct{}) {
    <-a
    fmt.Println("B()!")
    close(b)
}

// C首先被a阻塞
func C(a chan struct{}) {
    <-a
    fmt.Println("C()!")
}

func concurrency() {
	go say("world")
	say("hello")

	s := []int{1,3,5,7,9,2,4,6,8,10}
	c := make(chan int)
	go sum(s[:len(s)/2], c)
	go sum(s[len(s)/2:], c)
	x, y := <-c, <-c // 没懂这里的机制，两个协程用同一个chan?
	fmt.Println(x, y, x+y)

	ch := make(chan int, 3)
	ch <- 1
	ch <- 2
	//ch <- 3
	fmt.Println(<-ch)
	fmt.Println(<-ch)

	c1 := make(chan int, 10)
	go fibonacci(cap(c1), c1)
	for i := range c1 {
		fmt.Println(i)
	}

	c2 := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-c2)
		}
		quit <- 0
	}()
	fibonacci1(c2, quit)

	c3 := SafeCounter{v: make(map[string]int)}
	for i := 0; i < 1000; i++ {
		go c3.Inc("key1")
	}
	//time.Sleep(time.Second)
	fmt.Println(c3.Value("key1"))

	// 指定goroutine执行顺序: A()-->B()-->C()
	x1 := make(chan struct{})
	y1 := make(chan struct{})
	z1 := make(chan struct{})

	go C(z1)
	go A(x1, y1)
	go C(z1)
	go B(y1, z1)
	go C(z1)

	// 关闭x，让x可读
	close(x1)
	time.Sleep(3 * time.Second)
}

