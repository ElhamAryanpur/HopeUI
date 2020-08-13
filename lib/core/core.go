package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"
	Helper "HopeUI/lib/helper"
	Basic "HopeUI/lib/components/Basic"
	Draw "HopeUI/lib/components/Draw"
)

// HopeUI is core Class and Hub for all other features
type HopeUI struct{
	*Basic.Basic
	*Draw.Draw
	*Helper.Helper
}

// Used for callbacks
type fn func()

// New is constructor
func New() HopeUI {
	return HopeUI{}
}

// Init will initialize main things
func (h *HopeUI) Init(width int32, height int32, title string, background Helper.Color, callback fn) {

	RayLib.SetConfigFlags(RayLib.FlagWindowUndecorated)

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
