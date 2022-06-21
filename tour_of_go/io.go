package main

import (
	"fmt"
	"io"
	"strings"
	"errors"
)

type MyReader struct{}

func (myreader MyReader) Read(b []byte) (n int, err error){
	if b == nil {
		fmt.Println("b is nil")
		return 0, errors.New("b is nil")
	}
	b[0] = 'A'
	return 1, nil
}

func test_io() {

	r := strings.NewReader("Hello, Reader!")
	b := make([]byte, 8)
	for {
		n, err := r.Read(b)
		fmt.Printf("n = %v err = %v b = %v\n", n, err, b)
		fmt.Printf("b[:n] = %q\n", b[:n])
		if err == io.EOF {
			break
		}
	}

	var b1 []byte
	b1 = make([]byte, 1)
	var myreader MyReader
	for i := 0; i < 10; i++ {
		n, err := myreader.Read(b1)
		fmt.Printf("n = %v err = %v b = %c\n", n, err, b1)
		if err != nil {
			break
		}
	}
}
