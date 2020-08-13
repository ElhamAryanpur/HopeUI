package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"
	Helper "HopeUI/lib/helper"
	Widget "HopeUI/lib/components/Basic"
)

// HopeUI is core Class and Hub for all other features
type HopeUI struct{
	*Helper.Helper
	Widget Widget.Basic
}

// Used for callbacks
type fn func()

// New is constructor
func New() HopeUI {
	return HopeUI{}
}

// Init will initialize main things
func (h *HopeUI) Init(width int32, height int32, title string, background Helper.Color, callback fn) {

	RayLib.SetConfigFlags(RayLib.FlagWindowResizable)

	// init Window and settings
	RayLib.InitWindow(width, height, title)
	RayLib.SetTargetFPS(60)

	h.Widget = Widget.New()
	h.Widget.SetFontSetting(25, 13)

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
