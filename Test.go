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
		Label := hui.Widget.NewElement("Label")
		Label.SetColor(elementBackgroundColor, fontColor)
		Label.SetPosition(100, 100)
		Label.SetContent("Hello World!")

		hui.Widget.Render(Label)
	})
}
