package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"
	Helper "HopeUI/lib/helper"
)

// Basic contains all basic components
type Basic struct{}

// Label will draw a text
func (b *Basic) Label(text string, x int32, y int32, fontSize int32, color Helper.Color) {
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	RayLib.DrawText(text, x, y, fontSize, newColor)
}
