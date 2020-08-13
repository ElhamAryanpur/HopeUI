package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"
	Helper "HopeUI/lib/helper"
)

var fontSize int
var spacing int

// Basic contains all basic components
type Basic struct{
	fontSize int
	spacing int
}

// SetFontSize will change the font size
func (b *Basic) SetFontSetting(size int, space int){
	b.fontSize = size
	b.spacing = space
}

// New will initialize basic values
func New() Basic{
	return Basic{fontSize: 25, spacing: 13}
}

//===========================================================================//
//===========================================================================//

// Label will draw a text
func (b *Basic) Label(text string, x int32, y int32, color Helper.Color) {
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	RayLib.DrawText(text, x, y, int32(b.fontSize), newColor)
}

// Button will be used for button events
func (b *Basic) Button(Text string, x int32, y int32, width int32, height int32, color Helper.Color){
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	RayLib.DrawRectangle(x, y, width, height, newColor)

	textSize := RayLib.MeasureText(Text, int32(b.fontSize))

	println(textSize)
}

//===========================================================================//
//===========================================================================//
