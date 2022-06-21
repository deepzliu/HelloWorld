package main

import(
	"fmt"
	"time"
	"runtime"
)

func defer_test() {
	fmt.Println("Do something")
}

func flowcontrol() {

	// for
	var sum int
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)

	for ; sum < 1000; {
		sum += sum
	}
	fmt.Println(sum)

	// for is while
	n := 10
	for n > 0 {
		n--
	}
	fmt.Println("for end")

	// loop and if
	m := 5
	for {
		m--
		//time.Sleep(1e9)
		fmt.Printf("m = %d in loop\n", m)
		if m < 0 {
			break
		}
	}

	if fmt.Println("output before 'if' statement"); m > 0 {
		fmt.Println("output in 'if' statement")
	}else{
		fmt.Println("output in 'else' statement")
	}

	// switch
	fmt.Print("Go runs on ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s.\n", os)
	}

	fmt.Println("When's Saturday?")
	today := time.Now().Weekday()
	switch time.Saturday {
	case today + 0:
		fmt.Println("Today.")
	case today + 1:
		fmt.Println("Tomorrow.")
	case today + 2:
		fmt.Println("In two days.")
	default:
		fmt.Println("Too far away.")
	}

	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}

	// defer
	defer defer_test()
	fmt.Println("define defer")

	fmt.Println("counting")
	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}
	fmt.Println("done")
}

