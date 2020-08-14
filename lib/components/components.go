package HopeUI

import (
	RayLib "github.com/gen2brain/raylib-go/raylib"

	Helper "HopeUI/lib/helper"
)

// Basic contains all basic components
type Basic struct{}

// New will initialize basic values
func New() Basic {
	return Basic{}
}

//===========================================================================//
//===========================================================================//

// Style defines styling of elements
type Style struct {
	x          int32
	y          int32
	width      int32
	height     int32
	background Helper.Color
	foreground Helper.Color
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

// NewElement creates a new element to render
func (b *Basic) NewElement(elementName string) Element {
	s := Style{
		x:          0,
		y:          0,
		width:      100,
		height:     50,
		background: Helper.Color{R: 255, G: 255, B: 255, A: 255},
		foreground: Helper.Color{R: 0, G: 0, B: 0, A: 255},
		font:       RayLib.GetFontDefault(),
		fontSize:   25,
		spacing:    2,
		visible:    true,
	}
	return Element{
		id:      "undefined",
		element: elementName,
		content: "",
		style:   s,
		zIndex:  0,
	}
}

// Render function will render the element on the viewport
func (b *Basic) Render(e Element) {
	switch {
	case e.element == "Label":
		{
			b.Label(e)
		}
	case e.element == "Button":
		{
			b.Button(e)
		}
	}
}

//===========================================================================//

// SetColor will change foreground and background of element
func (e *Element) SetColor(background, foreground Helper.Color){
	e.style.foreground = foreground
	e.style.background = background
}

// SetPosition will change X and Y of the element
func (e *Element) SetPosition(X, Y int32){
	e.style.x = X
	e.style.y = Y
}

// SetContent will change the content value of the element
func (e *Element) SetContent(text string){
	e.content = text
}

//===========================================================================//
//===========================================================================//

// Label will draw a text
func (b *Basic) Label(data Element) {
	ds := data.style
	color := data.style.foreground
	newColor := RayLib.Color{R: color.R, G: color.G, B: color.B, A: color.A}
	pos := RayLib.Vector2{X: float32(ds.x), Y: float32(ds.y)}
	RayLib.DrawTextEx(ds.font, data.content, pos, float32(ds.fontSize), float32(ds.spacing), newColor)
}

// Button will be used for button events
func (b *Basic) Button(data Element) {
	Text := data.content
	ds := data.style
	x := ds.x
	y := ds.y
	width := ds.width
	height := ds.height
	background := ds.background
	foreground := ds.foreground

	newBackground := RayLib.Color{R: background.R, G: background.G, B: background.B, A: background.A}
	newForeground := RayLib.Color{R: foreground.R, G: foreground.G, B: foreground.B, A: foreground.A}
	textSize := RayLib.MeasureTextEx(ds.font, Text, float32(ds.fontSize), float32(ds.spacing))

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
	labelData := data
	labelData.style.x = targetX
	labelData.style.y = targetY
	b.Label(labelData)

	mousePos := RayLib.GetMousePosition()
	mx := int32(mousePos.X)
	my := int32(mousePos.Y)

	if mx > x && mx < x+width && my > y && my < y+height {
		if RayLib.IsMouseButtonDown(0) == true {
			RayLib.DrawRectangle(x, y, width, height, newForeground)
			mouseClickData := data
			mouseClickData.style.foreground = data.style.background
			mouseClickData.style.x = targetX
			mouseClickData.style.y = targetY
			b.Label(mouseClickData)
		}
	}
}

//===========================================================================//
//===========================================================================//
