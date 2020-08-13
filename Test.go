package main

import (
	HopeUI "HopeUI/core"
)

func main() {
	hui := HopeUI.New()
	hui.Init(800, 600, "Hope", hui.NewColor(255, 255, 255, 255), func() {
		hui.Label("Heyooo", -5, -5, 25, hui.NewColor(15, 15, 15, 255))
	})
}
