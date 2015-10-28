package main
import (
        "fmt"
        "net/http"
)
const CONTENT = "Web Server Activated"
const ADDRESS = ":1024"
func main() {
        fmt.Println("Web Server Activating ...")
        http.HandleFunc("/", display)
        http.ListenAndServe(ADDRESS, nil)
}
func display(w http.ResponseWriter, r *http.Request) {
        w.Header().Set("Content-Type", "text/plain")
        fmt.Fprintf(w, CONTENT)
}
