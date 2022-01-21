package main

import (
	"fmt"
	"sync"
)

func main() {
	num := 10
	var wg sync.WaitGroup
	ch := make(chan int)
	wg.Add(2)
	go func() {
		defer wg.Done()
		for i := 0; i < num; i++ {
			ch <- -1
			if i%2 == 0 {
				fmt.Print(i, " ")
			}
		}
	}()
	go func() {
		defer wg.Done()
		for i := 0; i < num; i++ {
			<-ch
			if i%2 == 1 {
				fmt.Print(i, " ")
			}
		}
	}()
	wg.Wait()
}
