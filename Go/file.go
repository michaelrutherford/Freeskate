package main
import (
	"fmt";
	"io/ioutil";
)
type File struct {
	Name string
	Content []byte
	Filetype string
}
func main() {
	var input string = ""
	userfile := new(File)
	fmt.Println("Input:")
	fmt.Scan(&input)
	fmt.Println("Name:")
	fmt.Scan(&userfile.Name)
	userfile.Content = []byte(input)
	fmt.Println("File type:")
	fmt.Scan(&userfile.Filetype)
	userfile.savefile()
	fmt.Println("File saved as: " + userfile.Name + "." + userfile.Filetype)
}
func (f *File) savefile() error {
	filename := f.Name + "." + f.Filetype
	return ioutil.WriteFile(filename, f.Content, 0644)
}
