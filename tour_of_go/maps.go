package main

import "fmt"

func test_map() {
	var m map[string] Point
	m = make(map[string] Point)
	m["aaa"] = Point{3, 5}
	m["bbb"] = Point{2, 1}
	fmt.Println(m["aaa"])
	fmt.Println(m)

	var m1 = map[string] Point {
		"key1": Point{1,2},
		"key2": Point{3,4},
		"key3": Point{5,6},
	}
	fmt.Println(m1)

	//var m2 map[string] Point
	//m2 = make(map[string] Point)
	m2 := map[string] Point {
		"key1": {1,2},
		"key2": {3,4},
		"key3": {5,6},
	}
	m2["key2"] = Point {300, 400} // set
	delete(m2, "key1") // delete
	_, ok := m2["key3"]
	if ok == true {
		fmt.Println("key3 is found")
	}
	fmt.Println(m2)

	for k, v := range m2 {
		fmt.Printf("key: %s, value: %d:%d\n", k, v.x, v.y)
	}
}

