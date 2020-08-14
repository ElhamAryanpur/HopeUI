package HopeUI

import RayLib "github.com/gen2brain/raylib-go/raylib"

// Helper contains helpful functions
type Helper struct{}

// Function is used as type func
type Function func()

// Color type, RGBA (32bit)
type Color struct {
	R uint8
	G uint8
	B uint8
	A uint8
}

// Style defines styling of elements
type Style struct {
	x          int32
	y          int32
	width      int32
	height     int32
	background Color
	foreground Color
	font       RayLib.Font
	fontSize   int
	spacing    int
	visible    bool
}

// Element defines main details about each widget
type Element struct {
	id      string
	element string
	content string
	style   Style
	zIndex  int
}

// NewColor used to generate a color object
func (h *Helper) RGBA(R uint8, G uint8, B uint8, A uint8) Color {
	return Color{R: R, G: G, B: B, A: A}
}
