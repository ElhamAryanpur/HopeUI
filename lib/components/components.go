package HopeUI

import (
	Helper "HopeUI/lib/helper"

	RayLib "github.com/gen2brain/raylib-go/raylib"
)

var fontSize int
var spacing int

// Basic contains all basic components
type Basic struct {
	font     RayLib.Font
	fontSize int
	spacing  int
}

// SetFontSize will change the font size
func (b *Basic) SetFontSetting(newFont RayLib.Font, size int, space int) {
	b.font = newFont
	b.fontSize = size
	b.spacing = space
}

// New will initialize basic values
func New() Basic {
	return Basic{font: RayLib.GetFontDefault(), fontSize: 25, spacing: 2}
}

//===========================================================================//
//===========================================================================//

// NewElement creates a new element to render

//===========================================================================//
//===========================================================================//

// Label will draw a text
func (b *Basic) Label(text string, x int32, y int32, color Helper.Color) {
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	pos := RayLib.Vector2{X: float32(x), Y: float32(y)}
	RayLib.DrawTextEx(b.font, text, pos, float32(b.fontSize), float32(b.spacing), newColor)
}

// Button will be used for button events
func (b *Basic) Button(Text string, x, y, width, height int32, background, foreground Helper.Color) {
	newBackground := RayLib.Color{R: background.R, G: background.G, B: background.B, A: background.A}
	newForeground := RayLib.Color{R: foreground.R, G: foreground.G, B: foreground.B, A: foreground.A}
	textSize := RayLib.MeasureTextEx(b.font, Text, float32(b.fontSize), float32(b.spacing))

	var targetX int32 = 0
	var targetY int32 = 0
	if int32(textSize.X) < width {
		targetX = width/2 - int32(textSize.X)/2
		targetX = x + targetX
	} else {
		targetX = x
	}
	if int32(textSize.Y) < height {
		targetY = height/2 - int32(textSize.Y)/2
		targetY = y + targetY
	} else {
		targetY = y
	}

	RayLib.DrawRectangle(x, y, width, height, newBackground)
	b.Label(Text, targetX, targetY, foreground)

	mousePos := RayLib.GetMousePosition()
	mx := int32(mousePos.X)
	my := int32(mousePos.Y)

	if mx > x && mx < x+width && my > y && my < y+height {
		if RayLib.IsMouseButtonDown(0) == true {
			RayLib.DrawRectangle(x, y, width, height, newForeground)
			b.Label(Text, targetX, targetY, background)
		}
	}
}

//===========================================================================//
//===========================================================================//
