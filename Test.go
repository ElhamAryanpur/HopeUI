package main

import (
	HopeUI "HopeUI/lib/core"
	time "time"
)

func main() {
	println("HAHA after 5 seconds")
	time.Sleep(5 * time.Second)
	
	hui := HopeUI.New()
	hui.Init(800, 600, "Hope", hui.NewColor(255, 255, 255, 255), func() {
		hui.Label("Heyooo", -5, -5, 25, hui.NewColor(15, 15, 15, 255))
	})
}
