package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"
)

// HopeUI is core Class and Hub for all other features
type HopeUI struct{}

// Used for callbacks
type fn func()

// Color type, RGBA (32bit)
type Color struct {
	R uint8
	G uint8
	B uint8
	A uint8
}

// NewColor used to generate a color object
func (h *HopeUI) NewColor(R uint8, G uint8, B uint8, A uint8) Color {
	return Color{R: R, G: G, B: B, A: A}
}

// New is constructor
func New() HopeUI {
	return HopeUI{}
}

// Init will initialize main things
func (h *HopeUI) Init(width int32, height int32, title string, background Color, callback fn) {

	// init Window and settings
	RayLib.InitWindow(width, height, title)
	RayLib.SetTargetFPS(60)

	// Listen For Window Closing
	for !RayLib.WindowShouldClose() {

		// Start Drawing Things On Screen
		RayLib.BeginDrawing()

		// Clean Background
		newColor := RayLib.Color{R: background.R, G: background.G, B: background.B, A: background.A}
		RayLib.ClearBackground(newColor)

		// Rest Of Code
		callback()

		// Don't Draw Anymore
		RayLib.EndDrawing()
	}

	// Close Window When Done
	RayLib.CloseWindow()
}

// Label will draw a text
func (h *HopeUI) Label(text string, x int32, y int32, fontSize int32, color Color) {
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	RayLib.DrawText(text, x, y, fontSize, newColor)
}
