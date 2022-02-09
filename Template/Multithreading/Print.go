package main

import (
	"fmt"
	"sync"
)

// PrintOddEven, 启动两个协程分别打印奇偶数
func PrintOddEven() {
	num := 10
	var wg sync.WaitGroup
	ch := make(chan struct{})
	wg.Add(2)
	go func() {
		fmt.Println("PrintEven Goroutine start...")
		defer func() {
			wg.Done()
			fmt.Println("PrintEven Goroutine end!")
		}()
		for i := 0; i < num; i++ {
			ch <- struct{}{}
			if i%2 == 0 {
				fmt.Println("PrintEven Goroutine: ", i)
			}
		}
	}()
	go func() {
		fmt.Println("PrintOdd  Goroutine start...")
		defer func() {
			wg.Done()
			fmt.Println("PrintOdd  Goroutine end!")
		}()
		for i := 0; i < num; i++ {
			<-ch
			if i%2 == 1 {
				fmt.Println("PrintOdd  Goroutine: ", i)
			}
		}
	}()
	wg.Wait()
	fmt.Println()
}

// PrintOddEven, 启动三个协程分别打印ABC
func PrintABC() {
	var wg sync.WaitGroup
	a, b, c := make(chan struct{}), make(chan struct{}), make(chan struct{})
	wg.Add(3)
	num := 3
	go func() {
		fmt.Println("PrintA Goroutine start...")
		defer func() {
			wg.Done()
			fmt.Println("PrintA Goroutine end!")
		}()
		for i := 0; i < num; i++ {
			<-a
			fmt.Println("PrintA Goroutine: A")
			b <- struct{}{}
		}
		// <-a
	}()
	go func() {
		fmt.Println("PrintB Goroutine start...")
		defer func() {
			wg.Done()
			fmt.Println("PrintB Goroutine end!")
		}()
		for i := 0; i < num; i++ {
			<-b
			fmt.Println("PrintB Goroutine: B")
			c <- struct{}{}
		}
	}()
	go func() {
		fmt.Println("PrintC Goroutine start...")
		defer func() {
			wg.Done()
			fmt.Println("PrintC Goroutine end!")
		}()
		for i := 0; i < num; i++ {
			<-c
			fmt.Println("PrintC Goroutine: C")
			if i != 2 {
				a <- struct{}{}
			}
		}
	}()
	a <- struct{}{}
	wg.Wait()
}

// PrintOddEven, 启动N个协程按顺序打印数字
func PrintNum() {
	num := 102
	exitChan := make(chan struct{})
	chanNum := 10
	chanQueue := make([]chan struct{}, chanNum)

	for i := 0; i < chanNum; i++ {
		chanQueue[i] = make(chan struct{})
	}
	lastPos := (num - 1 + chanNum) % chanNum
	fmt.Println("End Pos is: ", lastPos)
	for i := 0; i < chanNum; i++ {
		go func(i int) {
			cur := chanQueue[i]
			next := chanQueue[(i+1)%chanNum]
			name := fmt.Sprintf("%d Goroutine", i)
			fmt.Printf("%s start...\n", name)
			defer fmt.Printf("%s end!\n", name)
			len := num / chanNum
			if i <= lastPos && lastPos != chanNum-1 {
				len += 1
			}
			for j := 0; j < len; j++ {
				<-cur
				fmt.Printf("%s: %d\n", name, j*(num/chanNum)+i)
				if i == lastPos && j == len-1 {
					exitChan <- struct{}{}
					continue
				}
				next <- struct{}{}
			}
		}(i)
	}
	chanQueue[0] <- struct{}{}
	<-exitChan
}

func main() {
	// PrintOddEven()
	// PrintABC()
	PrintNum()
}
