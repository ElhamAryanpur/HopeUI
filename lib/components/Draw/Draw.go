package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"
	Helper "HopeUI/lib/helper"
)

// Draw contains functions for drawing
type Draw struct {}

// Rectangle will draw Rectangle shape on screen
func (d *Draw) Rectangle(x int32, y int32, width int32, height int32, color Helper.Color){
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	RayLib.DrawRectangle(x, y, width, height, newColor)
}