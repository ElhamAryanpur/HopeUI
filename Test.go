package main

import (
	HopeUI "HopeUI/core"
)

func main() {
	hui := HopeUI.New()

	backgroundColor := hui.NewColor(18, 25, 32, 1)
	elementBackgroundColor := hui.NewColor(60, 125, 217, 1)
	fontColor := hui.NewColor(141, 189, 255, 1)

	hui.Init(800, 600, "Hope", backgroundColor, func() {
		hui.Widget.Label("Heyooo", 5, 5, fontColor)
		hui.Widget.Button("Button", 50, 50, 50, 50, elementBackgroundColor)
	})
}
