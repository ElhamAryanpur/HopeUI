package main

import (
	HopeUI "HopeUI/core"
)

func main() {
	hui := HopeUI.New()

	backgroundColor := hui.RGBA(18, 25, 32, 255)
	elementBackgroundColor := hui.RGBA(60, 125, 217, 255)
	fontColor := hui.RGBA(141, 189, 255, 255)

	hui.Init(800, 600, "Hope", backgroundColor, func() {
		hui.Widget.Label("Heyooo", 5, 5, fontColor)
		hui.Widget.Button("Button", 300, 300, 200, 100, elementBackgroundColor, fontColor)
	})
}
