package main

import (
	"fmt"
	"sync"
)

func PrintOddEven() {
	num := 10
	var wg sync.WaitGroup
	ch := make(chan struct{})
	wg.Add(2)
	go func() {
		defer wg.Done()
		for i := 0; i < num; i++ {
			ch <- struct{}{}
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
	fmt.Println()
}

func PrintABC() {
	num := 3
	var wg sync.WaitGroup
	a, b, c := make(chan struct{}), make(chan struct{}), make(chan struct{})
	wg.Add(num)
	go func() {
		defer wg.Done()
		for i := 0; i < num; i++ {
			<-a
			fmt.Print("A")
			b <- struct{}{}
		}
		// <-a
	}()
	go func() {
		defer wg.Done()
		for i := 0; i < num; i++ {
			<-b
			fmt.Print("B")
			c <- struct{}{}
		}
	}()
	go func() {
		defer wg.Done()
		for i := 0; i < num; i++ {
			<-c
			fmt.Print("C")
			if i != 2 {
				a <- struct{}{}
			}
		}
	}()
	a <- struct{}{}
	wg.Wait()
}
func PrintNum() {
	num := 100
	exitChan := make(chan struct{})
	chanNum := 10
	chanQueue := make([]chan struct{}, chanNum)

	for i := 0; i < chanNum; i++ {
		chanQueue[i] = make(chan struct{})
	}
	go func() {
		chanQueue[0] <- struct{}{}
	}()
	for i := 0; i < chanNum; i++ {
		curChan := chanQueue[i]
		nextChan := chanQueue[(i+1)%chanNum]
		go func(i int, cur, next chan struct{}) {
			for j := 0; j < num/chanNum; j++ {
				<-cur
				fmt.Print(i*num/chanNum+j, " ")
				next <- struct{}{}
			}
			if i == chanNum-1 {
				exitChan <- struct{}{}
			}
		}(i, curChan, nextChan)
	}
	<-exitChan
}
func main() {
	// PrintOddEven()
	// PrintABC()
	PrintNum()
}
