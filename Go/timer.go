package main
import "fmt"
import "time"
func main() {
        restart:
        fmt.Println("Enter the number of seconds.")
        var input int = 0
        fmt.Scan(&input)
        if input < 0 {
                fmt.Println("Duration can not be negative.")
                goto restart
        }
        for i := 0; i < input; i++ {
                fmt.Println("Time Remaining: ", (input - i))
                time.Sleep(time.Second)
        }
        fmt.Println("Time's up.")
}
